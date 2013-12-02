This is a "how not to" solution of the multithreaded prime number finder lab,
while it does properly use QRunnable and QThreadPool, 
does not perform well. 

This is probably because the overhead of processEvents combined
with the short lifetime of each QRunnable, which is also a QObject,
creates too much overhead per calculation.  

The work function, or the lifetime of the QRunnable, has to be longer lasting.

