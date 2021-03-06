Welcome to the opensource repository for qt-training material !

Building the Presentations (PDF)
================================

Prequisites
===========

The training slides are produced in Latex. The resulting PDF files can
be displayed with any PDF viewer. On Ubuntu/Debian systems you have to
install the following packages:

apt-get install texlive-xetex texlive-science texlive-pictures
apt-get install texlive-latex-extra texlive-formats-extra
apt-get install latex-beamer pdfjam transfig graphicsmagick


Available Material
==================

- Qt5: master branch
- Qt4: qt4-material branch

Compile your own course
=======================

The pre-defined courses are available under slides/courses. They are simple tex-files
which include other tex-files. 

To compile your PDF please use 'xelatex' or 'lulatex' from your preferred latex-distro.

$ cd slides
$ xelatex course/qq-training.tex

builds the QtQuick training course as qq-training.pdf. For a successfull training you
need also to add the addons to your training package. The addon folder contains the examples
labs and solutions used during the training. 

Please make yourself comfortable with the PDF and addon material before giving a training. Just knowing Qt will not be enough.

Contributing Changes
====================

Once you have up a working Latex setup check out the "Contributors Guide".
You can build it from the 'slides' subfolder:

cd slides
xelatex contributors-guide/contributors-guide.tex

Legal Notice
============

See disclaimer.tex for legal notice.

