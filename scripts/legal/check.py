#! /usr/bin/env python
# -*- coding: utf-8 -*-

# license policy root (where to find headers and licenses)
POLICY_ROOT = ""
HEADERS_PATH = "headers"
LICENSES_PATH = "licenses"

# if a license file needs to be shipped, name of the license file
LICENSE_FILENAME = "LICENSE.txt"

# ignore file paths containing given components
IGNORE = [ ".git", ".svn", "LICENSE.txt", "legal", "disclaimer.tex" ]

# directory where to start scanning
TOPLEVEL = "../.."

# automatically fix license headers / license distribution
# WARNING: Setting AUTFIX to "True" may destroy your files!
AUTOFIX = False

import os, sys

def usage():
    print "Usage: %s [TOPLEVEL]" % os.path.basename(sys.argv[0])
    print ""
    print "Checks all files under directory TOPLEVEL for copyright notices"
    print "and license headers."
    sys.exit(1)

def loadHeaderByExt(policyRoot):
    headerByExt = {}
    headersPath = os.path.join(policyRoot, HEADERS_PATH)
    for name in os.listdir(headersPath):
        ext = name.split(".")[-1]
        headerByExt[ext] = open(os.path.join(headersPath, name)).readlines()
    return headerByExt

def loadLicenseByExt(policyRoot):
    licenseByExt = {}
    licensesPath = os.path.join(policyRoot, LICENSES_PATH)
    for name in os.listdir(licensesPath):
        ext = name.split(".")[-1]
        licenseByExt[ext] = open(os.path.join(licensesPath, name)).read()
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
POLICY_ROOT = os.path.dirname(sys.argv[0])
print "Loading license policy from %s" % POLICY_ROOT

headerByExt = loadHeaderByExt(POLICY_ROOT)
licenseByExt = loadLicenseByExt(POLICY_ROOT)

print "Scanning %s..." % TOPLEVEL
errorCount = 0
autofixCount = 0

for root, dirs, files in os.walk(TOPLEVEL):
    for name in files:
        #############################################################################
        # check if license header is correct
        path = os.path.join(root, name)
        ignore = False
        for part in path.split(os.sep):
            if part in IGNORE:
                ignore = True
        if ignore: continue
        copyrights = filterCopyrights(path)
        ext = name.split(".")[-1]
        header = []
        missingHeader = False
        if ext in headerByExt:
            header = headerByExt[ext]
            if not checkHeader(path, header):
                print "Error: Missing or wrong copyright header in %s" % path
                missingHeader = True
                errorCount = errorCount + 1
        uncoveredCopyright = False
        for lc in copyrights:
            if missingHeader or lc >= len(header):
                print "Error: Uncovered copyright statement in %s:%d" % (path, lc)
                errorCount = errorCount + 1
                uncoveredCopyright = True
        if AUTOFIX and missingHeader:
            lines = open(path, 'r').readlines()
            # delete existing header
            ya = -1
            yb = -1
            y = 0
            for line in lines:
                isBorder = False
                borderChars = [ '*', '#', '%', '-', '=' ]
                for ch in borderChars:
                    if line.count(ch) > 10:
                        isBorder = True
                        break
                if isBorder:
                    if ya == -1:
                        ya = y
                    elif yb == -1:
                        yb = y
                    else: # separators used in code
                        ya = -1
                        yb = -1
                        break
                y = y + 1
            if ya != -1 and yb != -1 and ya < 2:
                for y in range(ya, yb + 1):
                    lines.pop(ya)
                    if ya < len(lines):
                        if lines[ya] == "\n":
                            lines.pop(ya)
                if uncoveredCopyright:
                    coveredCount = 0
                    for lc in copyrights:
                        if lc <= yb:
                            coveredCount = coveredCount + 1
                    if coveredCount == len(copyrights):
                        uncoveredCopyright = False
                        autofixCount = autofixCount + 1
                print "Fix: Deleted existing header from %s" % path
            # add new header
            if not uncoveredCopyright:
                headerText = "".join(header)
                while len(lines) > 0:
                    if lines[0] == "\n":
                        lines.pop(0)
                    else:
                        break
                sourceText = "".join(lines)
                open(path, 'w').write(headerText + "\n" + sourceText)
                print "Fix: Added new copyright header to %s" % path
                autofixCount = autofixCount + 1
        #############################################################################
        # check if license file is shipped correctly (if required)
        wrongLicense = False
        missingLicense = False
        licensePath = os.path.join(root, LICENSE_FILENAME)
        for line in header:
            if line.find(LICENSE_FILENAME) != -1:
                if not LICENSE_FILENAME in os.listdir(root):
                    print "Error: Missing %s in %s" % (LICENSE_FILENAME, root)
                    missingLicense = True
                    errorCount = errorCount + 1
                else:
                    licenseUsed = open(licensePath, "r").read()
                    if licenseByExt[ext] != licenseUsed:
                        print "Error: Wrong license file shipped in %s" % root
                        wrongLicense = True
                        errorCount = errorCount + 1
        if AUTOFIX:
            if wrongLicense:
                os.unlink(licensePath)
            if wrongLicense or missingLicense:
                open(licensePath, "w").write(licenseByExt[ext])
                if wrongLicense:
                    print "Fix: Replaced license file %s" % licensePath
                else:
                    print "Fix: Added license file %s" % licensePath
                autofixCount = autofixCount + 1

if AUTOFIX:
    print "NOTE: %d problems automatically fixed" % autofixCount
    errorCount = errorCount - autofixCount

if errorCount == 0:
    print "SUCCESS: No license policy violations detected/left"
    sys.exit(0)
else:
    print "FAILED: %d violations against license policy detected/left" % errorCount
    sys.exit(2)
