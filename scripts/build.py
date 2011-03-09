#! /usr/bin/env python

import sys, os, subprocess, shutil, argparse

HORIZ_BAR="---------------------------------------------------------"

def tool_name():
    return os.path.basename(sys.argv[0]).split('.')[0]

def log(line):
    print "(%s) %s" % (tool_name(), line)

def enumerate_module(output_path, module_name, module_count, dry_run):
    pdf_path = os.path.join(output_path, "%s.pdf" % module_name)
    log_path = os.path.join(output_path, "%s.log" % module_name)
    enumerated_pdf_path = os.path.join(output_path, "%02d_%s.pdf" % (module_count, module_name))
    enumerated_log_path = os.path.join(output_path, "%02d_%s.log" % (module_count, module_name))
    log("mv %s %s" % (pdf_path, enumerated_pdf_path))
    log("mv %s %s" % (log_path, enumerated_log_path))
    if not dry_run:
        shutil.move(pdf_path, enumerated_pdf_path)
        shutil.move(log_path, enumerated_log_path)

def cleanup_auxiliaries(output_path, module_name, dry_run):
    ext_list = ["pdfsync", "snm", "toc", "nav", "aux", "out", "tex", "vrb"]
    for ext in ext_list:
        path = os.path.join(output_path, "%s.%s" % (module_name, ext))
        if not os.access(path, os.F_OK):
            continue
        log("rm %s" % path)
        if dry_run: continue
        os.unlink(path)

def copy_addons(output_path, module_name, module_count, dry_run):
    src = os.path.join("..", "addon", module_name)
    dst = os.path.join(output_path, "addon", "%02d_%s" % (module_count, module_name))
    if not os.access(src, os.F_OK): return
    if os.access(dst, os.F_OK):
        log("rm -rf %s" % dst)
        if not dry_run:
            shutil.rmtree(dst)
    log("cp -a %s %s" % (src, dst))
    if not dry_run:
        shutil.copytree(src, dst)

def lookup_module(module_path):
    if "QT_TRAINING_SOURCES" in os.environ:
       sources = os.environ["QT_TRAINING_SOURCES"].split(";")
       for prefix in sources:
           candidate = os.path.join(prefix, "slides", module_path)
           if os.access(candidate, os.F_OK):
               module_path = candidate
               break;
    return module_path

def compile_module(module_path, output_path, module_count, verbose, dry_run, once):
    module_path = lookup_module(module_path)
    super_path = os.path.dirname(module_path)
    module_name = os.path.basename(module_path)
    pdf_path = "%s/%s.tex" % (module_name, module_name)
    print module_path, super_path, module_name
    if os.getcwd() != super_path:
        log("cd %s" % super_path)
        os.chdir(super_path)
    args = [
        "pdflatex",
        "-output-directory", output_path,
        pdf_path
    ]
    times = 1 + (not once)
    while times > 0:
        times = times - 1
        log("%s" % ' '.join(args))
        if dry_run: continue
        p = subprocess.Popen(args, bufsize=1, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        if verbose:
            print HORIZ_BAR
        for line in p.stdout:
            if verbose:
                sys.stdout.write(line)
                sys.stdout.flush()
            else:
                sys.stdout.write('.')
                sys.stdout.flush()
        if verbose:
            print HORIZ_BAR
        else:
            sys.stdout.write('\n')
        exit_code = p.wait()
        if exit_code != 0:
            log("FAILED, exit_code = %d" % exit_code)
            # TODO: throw exception here!
    enumerate_module(output_path, module_name, module_count, dry_run)
    cleanup_auxiliaries(output_path, module_name, dry_run)
    copy_addons(output_path, module_name, module_count, dry_run)

parser = argparse.ArgumentParser(
    description = '''
        Compiles lists of training modules into enumerated PDF files.
        Each FILE contains a list of module paths for each module to be compiled.
        The QT_TRAINING_SOURCES environment variable allows to provide default locations
        for training material.
    ''',
    epilog = "Report bugs to ext-frank.mertens@nokia.com"
);

parser.add_argument('lists', metavar='FILE', type=file, nargs='+', help='Contains list of module paths')
parser.add_argument('-d', '--dry-run', action='store_true', help='Print all commands without executing')
parser.add_argument('-1', '--once', action='store_true', help='Run pdflatex just once, instead twice')
parser.add_argument('-s', '--sources', type=str, default="", help='Override QT_TRAINING_SOURCES environment variable')
parser.add_argument('-v', '--verbose', action='store_true', help='Verbose log output')

args = parser.parse_args()

if args.sources != "":
    os.environ["QT_TRAINING_SOURCES"] = args.sources

cwd_saved = os.getcwd()
try:
    module_count = 1
    for list in args.lists:
        for line in list:
            compile_module(line.rstrip(), cwd_saved, module_count, args.verbose, args.dry_run, args.once)
            module_count = module_count + 1
finally:
    os.chdir(cwd_saved)
