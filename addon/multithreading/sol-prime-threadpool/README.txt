This version of the multithreaded prime number finder
does not show much of a speedup when adding threads.

This is probably because the overhead of processEvents combined
with the short lifetime of each QRunnable outweighs
the benefits of having multiple threads.

