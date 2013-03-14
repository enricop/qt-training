all: fundamentals.pdf qq-training.pdf qt-widgets.pdf

fundamentals.pdf: fundamentals/fundamentals.tex
	xelatex fundamentals/fundamentals.tex

qq-training.pdf: course/qq-training.tex
	  xelatex course/qq-training.tex 

qt-widgets.pdf: course/qt-widgets.tex
	xelatex course/qt-widgets.tex

clean:
	$(RM) *.aux *.log *.nav *.out *.pdf *.pdfsync *.snm *.toc *.vrb
