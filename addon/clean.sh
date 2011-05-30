#! /bin/sh
make clean
rm -rf $(find . -name 'Makefile')
for f in $(find . -type f -and -perm 755 -and -not -name '*.*'); do rm $f; done
