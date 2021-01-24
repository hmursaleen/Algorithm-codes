/*x =  ( &Sum; (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of
         pp[i] with respect to num[i]

Example:

Let us take below example to understand the solution
   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
   prod  = 60
   pp[]  = {20, 15, 12}
   inv[] = {2,  3,  3}  /// (20*2)%3 = 1, (15*3)%4 = 1
                        /// (12*3)%5 = 1

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
        rem[2]*pp[2]*inv[2]) % prod
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     = (40 + 135 + 36) % 60
     = 11

/// A C++ program to demonstrate working of Chinese remainder theorem
*/



#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl
const int M = 2e5+1;
int num[M], rem[M], n, i, cnt;
typedef long long ll;

int inv(int a, int b)
{
    int x = 1, y = 0, b2 = b;
    if(b == 1) return 0;
    while(a > 1)
    {
        int q = a / b, t = b;
        b = a % b, a = t;
        t = x;
        x = y;
        y = t - (q * y);
    }
    return (x < 0) ? x += b2 : x;
}

int crt()
{
    ll prod = 1, res = 0, pp;
    for(i = 1; i <= n; i++) prod *= num[i];
    for(i = 1; i <= n; i++)
    {
        pp = prod / num[i];
        res += rem[i] * inv(pp, num[i]) * pp;
    }
    return res %= prod;
}

int main ()
{
    cin >> n;
    for(i = 1; i <= n; i++) cin >> num[i];
    for(i = 1; i <= n; i++) cin >> rem[i];
    cout << crt() << endl;
}
