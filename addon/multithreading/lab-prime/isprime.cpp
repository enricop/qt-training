#include <qmath.h>


/* Yes, this method could be faster, but we want
 * it to be reentrant, so we can use it in a parallel algorithm.
 * If it accesses shared memory, it needs to be thread-safe and
 * therefore will be slower when used in more threads.
 * You might want to slow it down by adding extra calculations here,
 * so you can observe a better speedup with multiple threads. 
 */
bool isPrime(qlonglong toCheck) {
   qlonglong sqtocheck = qSqrt(toCheck) + 1;
   if (toCheck == 1) return false;
   if (toCheck == 2) return true;
   if (toCheck % 2 ==0) return false;
   for (qlonglong i = 3; i < sqtocheck; i += 2) {
       if (toCheck % i == 0) {
           return false;
       }
   }
   return true;
}
