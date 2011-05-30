#! /usr/bin/env python

import sys, os, subprocess, shutil

HORIZ_BAR="---------------------------------------------------------"

global_options = {}

def tool_name():
    return os.path.basename(sys.argv[0]).split('.')[0]

def log(line):
    print "(%s) %s" % (tool_name(), line)

def enumerate_module(output_path, module_name, module_count, verbose, dry_run):
    pdf_path = os.path.join(output_path, "%s.pdf" % module_name)
    log_path = os.path.join(output_path, "%s.log" % module_name)
    enumerated_pdf_path = os.path.join(output_path, "%02d_%s.pdf" % (module_count, module_name))
    enumerated_log_path = os.path.join(output_path, "%02d_%s.log" % (module_count, module_name))
    log("mv %s %s" % (pdf_path, enumerated_pdf_path))
    if verbose:
        log("mv %s %s" % (log_path, enumerated_log_path))
    if not dry_run:
        shutil.move(pdf_path, enumerated_pdf_path)
        if verbose:
            shutil.move(log_path, enumerated_log_path)

def cleanup(path, dry_run):
    if os.access(path, os.F_OK):
        log("rm %s" % path)
        if not dry_run:
            os.unlink(path)

def cleanup_auxiliaries(output_path, module_name, verbose, dry_run):
    ext_list = ["pdfsync", "snm", "toc", "nav", "aux", "out", "tex", "vrb", "idx"]
    if not verbose:
        ext_list.append("log")
    for ext in ext_list:
        path = os.path.join(output_path, "%s.%s" % (module_name, ext))
        cleanup(path, dry_run)
    cleanup(os.path.join(output_path, "qtcxx.aux"), dry_run)

def copy_addons(output_path, module_name, module_count, dry_run):
    src = os.path.join("..", "addon", module_name)
    dst = os.path.join(output_path, "addon", "%02d_%s" % (module_count, module_name))
    if not os.path.isdir(src): return
    if os.path.exists(dst):
        log("rm -rf %s" % dst)
        if not dry_run:
            shutil.rmtree(dst)
    log("cp -a %s %s" % (src, dst))
    if not dry_run:
        shutil.copytree(src, dst, ignore = shutil.ignore_patterns(".svn", "Makefile", "*.o", "*.so", "*.a", "*.obj"))

def exec_and_show_progress(args, verbose):
    p = subprocess.Popen(args, bufsize=1, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    cached_output = []
    if verbose:
        print HORIZ_BAR
    for line in p.stdout:
        if verbose:
            sys.stdout.write(line)
            sys.stdout.flush()
        else:
            sys.stdout.write('.')
            cached_output.append(line)
            sys.stdout.flush()
    if verbose:
        print HORIZ_BAR
    else:
        sys.stdout.write('\n')
    exit_code = p.wait()
    if exit_code != 0 and not verbose:
        for line in cached_output:
            sys.stdout.write(line)
        sys.stdout.flush()
    return exit_code

def compile_module(module_path, output_path, module_count, verbose, dry_run, once):
    """ Compiles the given module with pdflatex into a file prefixed with the module_count
        into the output_path folder.
    """
    super_path = os.path.dirname(module_path)
    module_name = os.path.basename(module_path)
    pdf_path = "%s/%s.tex" % (module_name, module_name.lower())
    module_name = module_name.lower()
    if os.getcwd() != super_path:
        log("cd %s" % super_path)
        os.chdir(super_path)
    args = [
        "pdflatex",
        "-interaction=nonstopmode",
        "-output-directory", output_path,
        # "-interaction", "errorstopmode",
        pdf_path
    ]
    times = 1 + (not once)
    for stage in range(times):
        log("%s" % ' '.join(args))
        if dry_run: continue
        exit_code = exec_and_show_progress(args, verbose)
        if exit_code != 0:
            log("FAILED, exit_code = %d" % exit_code)
            return exit_code
    enumerate_module(output_path, module_name, module_count, verbose, dry_run)
    cleanup_auxiliaries(output_path, module_name, verbose, dry_run)
    copy_addons(output_path, module_name, module_count, dry_run)
    return 0
