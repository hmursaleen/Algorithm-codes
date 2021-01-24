
1. No. of divisors : If a prime factor p appears e times in the
   prime factorization of n, then we can use the factor p up to
   e times in the subset. Which means we have e+1 choices.

   A way of thinking about it is the following:

   If there is only one distinct prime divisor,  n = P1^e1
   then there are obviously e1+1 divisors (1,p1,p1^2,…,p1^e1).

   Therefore if the prime factorization of n is
   p1^e1 * p2^e2 * ... *pk^ek, where pi are distinct prime numbers,
   then the number of divisors is:
   d(n)=(e1+1)+(e2+1)+ ... +(ek+1)



2. Sum of Divisors:
   If there is only one distinct prime divisor, n = p1^e1, then the sum is:
   1 + p1 + p1^2 + ... + p1^e1 = (p1^(e1+1) - 1) / (p1 - 1) ///gunottor dharar first n ta poder sum er formula

   In general, for n = p1^e1 * p2^e2 * ... * pk^ek we receive the formula:
   σ(n) = (pi^(ei+1) - 1) / (pi - 1) * ... * (pk^(ek+1) - 1) / (pk - 1)
   for 1 <= i <= k, where k is the num of prime factor of n. pi are distinct prime factors
   and ei are powers of pi.

///Multiplicative functions
///A multiplicative function is a function f(x) which satisfies
///f(ab) = f(a)*f(b),  if a and b are co-prime.
///Both d(n) and σ(n) are multiplicative functions.
