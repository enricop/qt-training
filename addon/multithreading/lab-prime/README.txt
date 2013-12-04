This directory contains a starting point for writing a multithreaded prime number finder.

Step1 is all related to the user interface. 
If you do not want to work with widgets, you can skip this step and start with 
step 2, where the widgets are separate from the calculation code. 

Step2 is to parallelize the calculaton, somehow. Using QRunnable or QThread, and optionally QThreadPool. There are many ways to do this.

2 different approaches are shown as solutions
in sol-prime-threadpool and sol-prime-qthread.
