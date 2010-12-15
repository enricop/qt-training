#! /usr/bin/env python
# -*- coding: utf-8 -*-

HEADERS_PATH = "headers"
LICENSES_PATH = "licenses"
LICENSE_FILENAME = "LICENSE.txt"
IGNORE = [ ".git", "LICENSE.txt", "licenses", "legal" ]
TOPLEVEL = "../.."

import os, sys

def usage():
    print "Usage: %s [TOPLEVEL]" % os.path.basename(sys.argv[0])
    print ""
    print "Checks all files under directory TOPLEVEL for copyright notices"
    print "and license headers."
    sys.exit(1)

def loadHeaderByExt():
    headerByExt = {}
    for name in os.listdir(HEADERS_PATH):
        ext = name.split(".")[-1]
        headerByExt[ext] = open(os.path.join(HEADERS_PATH, name)).readlines()
    return headerByExt

def loadLicenseByExt():
    licenseByExt = {}
    for name in os.listdir(LICENSES_PATH):
        ext = name.split(".")[-1]
        licenseByExt[ext] = open(os.path.join(LICENSES_PATH, name)).read()
    return licenseByExt

def parseArgs(toplevel):
    if len(sys.argv) == 2:
        if sys.argv[1] == "-h" or sys.argv[1] == "--help":
            usage()
        toplevel = sys.argv[1]
    toplevel = os.path.abspath(toplevel)
    return toplevel

def filterCopyrights(path):
    copyrights = {}
    f = open(path, "r")
    lc = 1
    for line in f:
        lineLower = line.lower()
        copyrightPatterns = [ "(c)", "copyright" ] # , u"©" ]
        for pattern in copyrightPatterns:
            if lineLower.find(pattern) != -1:
                copyrights[lc] = line
        lc = lc + 1
    return copyrights

def checkHeader(path, header):
    f = open(path, "r")
    lc = 0
    for line in f:
        if lc >= len(header) or line != header[lc]:
           break;
        lc = lc + 1
    return lc == len(header)

TOPLEVEL = parseArgs(TOPLEVEL)
headerByExt = loadHeaderByExt()
licenseByExt = loadLicenseByExt()

print "Scanning %s..." % TOPLEVEL
exitCode = 0

for root, dirs, files in os.walk(TOPLEVEL):
    for name in files:
        path = os.path.join(root, name)
        ignore = False
        for part in path.split(os.sep):
            if part in IGNORE:
                ignore = True
        if ignore: continue
        copyrights = filterCopyrights(path)
        ext = name.split(".")[-1]
        header = []
        if ext in headerByExt:
            header = headerByExt[ext]
            if not checkHeader(path, header):
                print "Missing or wrong copyright header in %s" % path
                exitCode = 2
        for lc in copyrights:
            if lc >= len(header):
                print "Warning: Uncovered copyright statement in %s:%d" % (path, lc)
        for line in header:
            if line.find(LICENSE_FILENAME) != -1:
                if not LICENSE_FILENAME in os.listdir(root):
                    print "Missing %s in %s" % (LICENSE_FILENAME, root)
                    exitCode = 3
                else:
                    licenseUsed = open(os.path.join(root, LICENSE_FILENAME), "r").read()
                    if licenseByExt[ext] != licenseUsed:
                        print "Wrong license file shipped in %s" % root
                        exitCode = 4
sys.exit(exitCode)
