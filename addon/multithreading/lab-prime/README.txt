This directory contains a starting point for writng a multithreaded prime number finder.

Step1 is to make the cancel button show up and work during the actual calculation, as well as show progress.

Step2 is to parallelize the calculaton, somehow. Using QRunnable or QThread, and optionally QThreadPool.

There are many ways to do this.
2 completely different approaches are shown as solutions
in sol-prime-threadpool and sol-prime-qthread.

