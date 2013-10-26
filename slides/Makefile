all: fundamentals.pdf qq-training.pdf qt-widgets.pdf qt-additional.pdf

# run each command twice to get toc and page numbers

fundamentals.pdf: fundamentals/fundamentals.tex
	xelatex fundamentals/fundamentals.tex
	xelatex fundamentals/fundamentals.tex

qq-training.pdf: course/qq-training.tex
	  xelatex course/qq-training.tex 
	  xelatex course/qq-training.tex 

qt-widgets.pdf: course/qt-widgets.tex
	xelatex course/qt-widgets.tex
	xelatex course/qt-widgets.tex

qt-additional.pdf: course/qt-additional.tex
	xelatex course/qt-additional.tex
	xelatex course/qt-additional.tex

clean:
	$(RM) *.aux *.log *.nav *.out *.pdf *.pdfsync *.snm *.toc *.vrb *~

