This solution to the multithreaded primes lab uses 
long-running QThread-derived classes and QWaitCondition.

If you monitor the CPU usage, you will probably see that
when this program is fully utilizing n threads, the usage
is often more than n*100% because there is also the main GUI
thread which is handling the communication between threads
as well as the collection of the actual results, and it
accounts for a significant amount of CPU usage.

Contrast the results of running this version to the qtconcurrent version which behaves 
better with respect to CPU usage as well as scalability when adding more threads.

