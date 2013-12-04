This version uses QRunnable and does not create QThread.
It uses the QThreadPool to manage threads.

The performance is related to the duration of the QRunnable,
which can be adjusted by changing the granularity.
Our observations seem to be that a granularity of at least 40 is
recommended.

