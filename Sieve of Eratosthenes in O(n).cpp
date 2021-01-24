///Author : Mursaleen
///Date :
///Problem topic : (Practice) Sieve of Eratosthenes Having Linear Time Complexity
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
const int M = 10000001; ///1e7+1
int lp[M], i, j; ///lowest prime factor of i
vector < int > pr; ///list of primes

int main ()
{
   for(i = 2; i < M; i++)
   {
      if(!lp[i]) ///if prime
      {
         lp[i] = i; ///then its lowest prime factor is itself.
         pr.push_back(i); ///adding to the prime list
      }
      for(j = 0; j < pr.size() and pr[j] <= lp[i] and i * pr[j] < M; j++) lp[i * pr[j]] = pr[j];
   }
}

///this algorithm has the same runtime as the optimized version of sieve of eratosthenes
///and has worse memory limit than that.
///but the advantage of this technique is this gives us the lowest prime factor of each
///number till n, by which we can prime factorization of any number with worst complexity of log2(num)
