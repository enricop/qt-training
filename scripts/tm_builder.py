#! /usr/bin/env python

import os, optparse, tm_utils

class Module:
    def __init__(self, name, source = None):
        self.name = name
        self.source = source

class Course:
    def __init__(self):
        self.sources = { None: None }
        self.fallback_list = []
        self.modules = []

    def add_source(self, name, path):
        path = os.path.expanduser(path)
        if not os.path.isabs(path):
            path = os.path.abspath(path)
        path = os.path.realpath(path)
        self.sources[name] = path
        self.fallback_list.append(path)

    def add_module(self, name, source = None):
        self.modules.append(Module(name, source))

    def module_path(self, module):
        source = self.sources[module.source]
        if source == None:
            for source in self.fallback_list:
                if os.path.isdir(os.path.join(source, "slides", module.name)):
                    break
        return os.path.join(source, "slides", module.name)

    def compile(self):
        global options
        cwd_saved = os.getcwd()
        module_count = 0
        try:
            for module in self.modules:
                module_count += 1
                exit_code = tm_utils.compile_module(
                    self.module_path(module),
                    options.output,
                    module_count,
                    options.verbose,
                    options.dry_run,
                    options.once
                )
                if exit_code != 0:
                    if not options.resilent:
                        break
        finally:
            os.chdir(cwd_saved)

options = None

def main():
    global options

    parser = optparse.OptionParser(
        usage = "Usage: %s.py [options] [COURSE]..." % tm_utils.tool_name(),
        description = '''Compiles lists of training modules into enumerated PDF files.
Each COURSE file contains a training course description in Python syntax.
Take a look at the example_course.py for an example COURSE file.''',
        epilog = "Report bugs to ext-frank.mertens@nokia.com"
    )

    parser.add_option('-d', '--dry-run', action='store_true', help='Print all commands without executing')
    parser.add_option('-1', '--once', action='store_true', help='Run pdflatex just once, instead twice')
    parser.add_option('-o', '--output', type='string', default=os.getcwd(), help='Output directory')
    parser.add_option('-r', '--resilent', action='store_true', help='Continue on error')
    parser.add_option('-v', '--verbose', action='store_true', help='Verbose log output')

    (options, courses) = parser.parse_args()

    if not os.path.isabs(options.output):
        options.output = os.path.abspath(options.output)
    if not os.path.isdir(options.output):
        tm_utils.log("mkdir %s" % options.output)
        if not options.dry_run:
            os.mkdir(options.output)

    module_count = 1
    for path in courses:
        path = os.path.expanduser(path)
        outputSaved = options.output
        options.output = os.path.join(options.output, os.path.basename(path).split('.')[0])
        if not os.path.isdir(options.output):
            os.mkdir(options.output)
        execfile(path)
        options.output = outputSaved

if __name__ == "__main__":
    main()
