///Author : Mursaleen
///Date :
///Problem topic : Modular binary exponentiation (practice)
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
///suppose we've to calculate a^b mod m, where each of a, b, m is large (<=1e9)
ll a, b, res = 1, mod = 1e9+7;
int main ()
{
   cin >> a >> b; a %= mod;
   while(b)
   {
      if(b & 1) res = (res * a) % mod;
      a = (a * a) % mod;
      b >>= 1;
   }
   cout << res << endl;
}
