///Author : Mursaleen
///Date :
///Problem topic :
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
#define M 100001
int n, m, i, j, a[M], b[M], c[2*M], ans[M];
int main ()
{
///motivation problem: given two arrays a and b sorted in non-decreasing order, merge them
///into a single array with sorted as non-decreasing order in O(n)
   cin >> n >> m;
   for(i = 0; i < n; i++) cin >> a[i]; ///0-based indexing is better here
   for(i = 0; i < m; i++) cin >> b[i];
   while(i < n or j < m)
   {
       if(j == m or (i < n and a[i] < b[j])) c[i+j] = a[i], i++; ///The index of the transfered element(either from a or b) in array c will always be i+j
       else c[i+j] = b[j], j++;
   }

///--------------------- Another Problem -----------------------------
///motivation problem: given two arrays a and b sorted in non-decreasing order. now, for
///each element of b, print how many elements in a are less then that.
///idea : idea is almost like the previous problem. if we merge the arrays into a single
///one sorted in non-decreasing order, then it can be calculated easily. how? because for
///each element of b, i.e. when b[j] >= a[i],we need to know the no. of elements of array
///c so far that are less than b[j], and i is the number we're looking for. because we took
/// elements from array only when a[i] < b[j], so total no. of elements taken from array
///so far is the answer, which is i. below is the implementation.

    for(i = j = 0; j < m; j++)
    {
       while(i < n and a[i] < b[j]) i++;
       ans[j] = i;
    }
}

