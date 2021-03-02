///Q : what is inversion in an array?
///A : suppose, A[i] and A[j] (i != j) are two elements in an array A.
/// Then, if i < j and a[i] > a[j], this is called an inversion.
///The no. of inversions in an array is the total no. of pairs of index
///{i,j} (i != j) such that i < j and A[i] > A[j]
///we can count no. of total inversions by using merge sort tree.
///But, it can also be counted using Binary Indexed tree (BIT) a.k.a. Fenwick
///Tree, and it's short in code and use much less memory.

///when we are implementing counting inversions, it's necessary to map the
///original values of the array to a new range with values between [1,N],
///where N is the size of the array. This is due to the following reasons:
///(1) The values of one or more A[i] entry are too high or too low.
///(2) The values of one or more A[i] entry are negative.

///we start iterating our target array in reverse order, at each point
///we should ask ourselves the following question "How many numbers
///less than A[i] have already occurred in the array so far?"


///so here goes the full code.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define M 100005
ll n, i, ans, cnt, in, a[M], bit[M]; map < int, int > b;
void upd(ll x, ll v)
{
   for(; x <= n; x += x & -x) bit[x] += v;
}

ll query(ll x)
{
   ll sum = 0;
   for(; x; x -= x & -x) sum += bit[x];
   return sum;
}

int main ()
{
   cin >> n;
   for(i = 1; i <= n; i++)
   {
      cin >> a[i];/// array input
      b[a[i]] = 0;/// making copy of main array
   }
   ///bringing all numbers of array in range [1,n] maintaining the relative order of elements.
   for(auto it = b.begin(); it != b.end(); it++) it -> second = ++cnt;
   for(i = n; i; i--)
   {
      ans += query(a[i]-1); ///counting for each elements, how many elements have we already got less than a[i] in the BIT array
      upd(a[i], 1);/// updating the bit array for this element.
   }
   cout << ans << endl;
}
