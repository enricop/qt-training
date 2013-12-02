This solution to the concurrent primefinder lab 
uses a concurrent filter, QFuture and QFutureWatcher.

It shows a predictable speedup when adding threads where n<=c
where c=number of cores on your system, and n=the number of threads. 
Interestingly, when n > c, the performance does not degrade, like it does with sol-prime-qthread

It also shows predictable CPU usage during the entire running of the app.
