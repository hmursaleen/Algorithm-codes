#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
int sum, L, R, block = sqrt(M) + 1;
///sqrt decomposition is a technique which let us calculate value of a function e.g. sum, max
///min, no. of elements strictly less or greater that a value and much more functions within
///a range. we can answer each query in log(N) in this way because, we will divide the array
///into sqrt(N) blocks, where each block contains sqrt(N) elements. And, when a query is
///asked in range [l, r], we'll get answers for each block from l/block from r/block. the
///first and the last block may not be covered entirely by the query borders, so we will
///bruteforce for the first and last blocks, and get answers for middle blocks from
///precalculations.
int main ()
{
   L = l / block, R = r / block;
   if(L == R)
   {
      for(i = l; i <= r; ++i) sum += a[i];
   }
   else
   {
      for(i = l; i <= (L+1)*block-1; ++i) sum += a[i];
      for(i = L+1; i < R; ++i) sum += b[i];
      for(i = R*block; i <= r; ++i) sum += a[i];
   }
}
