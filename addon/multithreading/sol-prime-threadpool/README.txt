This solution of the multithreaded prime number finder lab, 
using QRunnable and QThreadPool, does not show much of a speedup 
when adding threads.

This is probably because the overhead of processEvents combined
with the short lifetime of each QRunnable outweighs
the benefits of having multiple threads. 

The work function has to be longer-running to show a significant speedup. 
Perhaps if each QRunnable took 5-10 numbers to check, instead of just 1...
