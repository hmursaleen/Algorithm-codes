#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
///'fill' keyword in c++ does almost the same job as memset. but 'fill' is way better.
///because memset can't set any value to an array, but 'fill' can, and 'fill' is easier to
///use. an example follows:
int a[10], i;
int main ()
{
   ///memset(a, 5, sizeof(a)); ///try using memset
   ///for(i = 0; i < 10; i++) cout << a[i] << ' '; ///no index has value 5.
   ///fill(a, a + 10, 5); ///now try using fill
   ///for(i : a) cout << i << ' '; ///yes, all the values are '5'.
   ///so now we'll be using 'fill' instead of memset.
}
