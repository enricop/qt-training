#include <qmath.h>


/* Yes, this method could be faster, but we want
 * it to be reentrant, so we can use it in a parallel algorithm.
 * If it accesses shared memory, it needs to be thread-safe and
 * therefore will be slower when used in more threads.
 * We will notice more of a speedup if this method takes a bit longer.
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
