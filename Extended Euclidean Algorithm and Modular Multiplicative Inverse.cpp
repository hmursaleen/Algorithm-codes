#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl

int x, y, a, b, ans, M = 1e9+7; ///int inv[M];
///while Euclidean algorithm only calculates gcd of two numbers a,b. The Extended Euclidean
///Algorithm(egcd in short) finds values of x and y in the equation ax + by = gcd(a,b).
///at the same time it can also find gcd of two numbers a and b.
///This algorithm is used in Modular Multiplicative inverse, because the value of x is needed for that.
void egcd(int a, int b)
{
    if(b == 0)
    {
        ans = a;
        x = 1, y = 0;
    }
    else
    {
        egcd(b, a % b);
        int temp = x;
        x = y;
        y = temp - ((a / b) * y);
    }
}

int main ()
{
    cin >> a >> b;
    egcd(a, b);
    cout << "The GCD of a and b is : " << ans << endl;
    cout << "X and Y coefficients are : " << x << ' ' << y << endl;

/// Modular multiplicative inverse
///------------------------------------------------------///
///What is a multiplicative inverse? If, you are required to find B such that it satisfies
///the equation A * B = 1. The solution is simple. The value of B is 1/A or A^-1. Here,
///B is the multiplicative inverse of A.

///What is modular multiplicative inverse? If you have two numbers A and M, you are
///required to find B such it that satisfies the following equation: (A * B) % M = 1
///Here B is the modular multiplicative inverse of A under modulo M.
///An inverse exists only when A and M are coprime i.e. GCD(A, M) = 1

///Given a and M, We can find Mod inverse the following way.
    egcd(a, M);
    cout << "The mod inverse of A under modulo M : " << (x% M + M) % M; /// as x can be negative

///Finding the modular inverse for every number modulo m
///---------------------------------------------------------------///
///The problem is the following: we want to compute the modular inverse for every number in the range [1,m−1].
///for this specific algorithm we require that the modulus m is prime.
   ///inv[1] = 1;
   ///for(int i = 2; i < M; ++i) inv[i] = M - (M/i) * inv[M%i] % M;

///Proof:
///-----------------------------------------///
///We have: m mod i = m − (m/i)*i
///Taking both sides modulo m yields:
///m mod i ≡ − (m/i)*i mod m
///Multiply both sides by i^-1(m mod i)^−1 yields
///(m mod i) * i^−1 * (m mod i)^−1 ≡ −(m/i)* i * i^−1 * (m mod i)^−1 mod m,
///which simplifies to: i^−1 ≡ −(m/i) * (m mod i)^−1 mod m
}
