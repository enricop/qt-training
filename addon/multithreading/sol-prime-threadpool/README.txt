This version uses QRunnable and does not create QThread.
It uses the QThreadPool to manage threads.

The performance is related to the duration of the QRunnable,
which can be adjusted by increasing the # of values to check per runnable.
Our observations seem to be that a value of at least 25 is recommended.

Known issues: 
Canceling the calculation currently causes a segmentation fault.
This is because our cancel() method is not thread-safe yet.
I will fix this once I come up with a nice way to do it. 

If you monitor the CPU usage, you will probably see that
when this program is fully utilizing n threads, the usage
is often more than n*100% because there is also the main GUI
thread which is handling the communication between threads
as well as the collection of the actual results, and it
accounts for a significant amount of CPU usage.
