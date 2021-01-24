///Author : Mursaleen
///Date :
///Problem topic : (practice) Find primes in range [L,R];
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
ll L, R, i, j;

int main ()
{
   ///sometimes we need to find all prime numbers in a range [L,R]
   ///of some small size (e.g. R−L+1≈1e7), where R can be very large
   ///(e.g. 1e12).
   ///To solve such a problem, we can use the idea of the Segmented
   ///sieve. We pre-generate all prime numbers up to sqrt(R) and use
   ///those primes to mark all composite numbers in the segment [L,R].

  /// cin >> L >> R; ///taking input of range
   ///lim = sqrt(R); let R = 1e12, so lim = 1e6; so size of bitset is 1e6
   ///const ll lim = 1000000; ///1e6
   ///bitset < lim > b; vector < ll > prime; ///prime.push_back(2);
   /*for(i = 3; i <= lim; i += 2)
   {
      if(!b[i])
      {
         prime.push_back(i);
         for(j = i * i; j <= lim; j += i << 1) b[j] = 1;
      }
   } */
   ///now we got all primes till sqrt(R). now we will use these to mark composite
   ///numbers in range [L, R];
   ///bitset < 10000000 > b2; ///R-L+1 = 1e7
   /*for(auto it : prime)
   {
      for(j = max(it * it, ((L+it-1)/it) * it); j <= R; j += it << 1) b[j-L] = 1; ///marking composite numbers
   }
   if(L == 1) b2[0] = 1; */

   ///if we want to know the number of primes in range [L,R], we have got
   ///get the total no. of odd nums in this range and subtract no. of marked
   ///composite nums.
   ///then, if L >= 2 and R <= 2, add 1 to ans



   ///other than this way of pregenerating all primes till root(R), there's another way.
   ///Here goes
   /*for(i = 3; i <= lim; i += 2)
   {
      for(j = max(i * i, ((L + i - 1) / i) * i); j <= R; j += i << 1) b[j-L] = 1; ///marking composite nums. initially all bits of bitset should be 0
   }
   if(L == 1) b[0] = 1; */

   ///now if we want to get the total num of primes in range [L,R], we've to get the total
   ///num of odd nums in range [L,R], and the subtract num of marked composite nums.
   ///then if L >= 2 and R <= 2, add 1 to ans;
}

