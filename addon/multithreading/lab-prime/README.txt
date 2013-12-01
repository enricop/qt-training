This directory contains a starting point for writing a multithreaded prime number finder.

Step1 is to make a working cancel button show during the actual calculation, as well as show progress. For those who are not familiar with widgets, they can start with the lab-prime-step2 instead of this.

Step2 is to parallelize the calculaton, somehow. Using QRunnable or QThread, and optionally QThreadPool. There are many ways to do this.

2 completely different approaches are shown as solutions
in sol-prime-threadpool and sol-prime-qthread.
