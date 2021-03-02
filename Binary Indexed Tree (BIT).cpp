#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 200001
///every index i in the BIT array stores the cumulative sum from the index
///i to i - (2^r) + 1 (both inclusive), where r represents the last set bit in the index i.
///e.g. at index 12, the sum of 9-12 is stored. 12 in binary is 1100. the last set bit
///is at 2nd pos from right(0 based). so, 12 - (2^2) + 1 = 9. that's how we see that
///at BIT[12], the cumulative sum of index 9-12 is stored. now, how do we know the rest
///(1-8) ? well, keep on traversing. we knew till 9, let's see what 8 has stored.
///8 in binary is 1000. last set bit is at 3rd. so, 8-(2^3)+1 = 1. so ind 8 has stored
///sum of 1-8(that's what we need). so, in general all we need to do is, keep going on
///as i - (2^r), till 1. and thus, while updating, we need to do the same thing, but from
///that index to nth index.
ll n, i, arr[M], BIT[M], l, r;
void upd(ll x, ll val)
{
   for(; x <= n; x += x & -x) BIT[x] += val; ///building the binary indexded tree
   ///we're getting the last set bit of x by x&-x.
}

ll query(ll x)
{
   ll sum = 0;
   for(; x; x -= x & -x) sum += BIT[x];///getting the partial sum of [1,x]
   return sum;
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++)
   {
      cin >> arr[i];
      upd(i, arr[i]);
   }
   cin >> i; ///we want to know partial sum of [1,i];
   cout << query(i) << endl;
   ///as we have the partial sum, we can get the range sum of any range
   ///we can also make poll update, just using the upd function
   ///and the range sum of any range [l,r] = query(r) - query(l-1)
   ///let's see an example
   cin >> l >> r;
   cout << query(r) - query(l-1) << endl;
}
