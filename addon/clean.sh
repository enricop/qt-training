#! /bin/sh
make clean
for f in $(find . -type f -and -perm 755 -and -not -name '*.*'); do rm $f; done
