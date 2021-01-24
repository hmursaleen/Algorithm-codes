///Author : Mursaleen
///Date :
///Problem topic : Discrete Logarithm (Practice)
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
///The discrete logarithm is an integer x satisfying the equation : a^x ≡ b(mod m)
///for given integers a, b and m, where a and m are co-prime.
///The discrete logarithm does not always exist, for instance there is no solution
///to 2^x ≡ 3(mod 7). There is no simple condition to determine if the discrete
///logarithm exists. In this article, we describe the Baby-step giant-step algorithm
///Consider the equation: a^x ≡ b(mod m), where a and m are relatively prime.
///Let x = np − q, where n is some pre-selected constant. p is known as giant step
///since increasing it by one increases x by n. Similarly, q is known as baby step.
///Obviously, any number x in the interval [0;m) can be represented in this form.
///Then, the equation becomes: a^np − q ≡ b(mod m).
///Using the fact that a and m are relatively prime, we obtain: a^np ≡ b*a^q(mod m)
///This new equation can be rewritten in a simplified form: f1(p) = f2(q).
///This problem can be solved using the meet-in-the-middle method as follows:
///1.Calculate f1 for all possible arguments p. Sort the array of value-argument pairs.
///2.For all possible arguments q, calculate f2 and look for the corresponding p
///in the sorted array using binary search.


///Problems often ask for the minimum x which satisfies the solution.
///It is possible to get all answers and take the minimum, or reduce the first
///found answer using Euler's theorem, but we can be smart about the order in
///which we calculate values and ensure the first answer we find is the minimum.
///The complexity of this algorithm is O(sqrt(m))
ll a, b, m, n, i, an = 1, cur, p, q;
int main ()
{
   cin >> a >> b >> m; a %= m, b %= m;
   if(a == 0)
   {
      cout << (b == 0 ? "1" : "No Solution") << endl;
      exit(0);
   }
   ///normally, for this kinda problem, we assume 0^0 = 1, i.e. we compute 0 as solution
   ///for the equation 0^x ≡ 1(mod m) and also as solution for 0^x ≡ 0(mod 1). This is
   ///an often used convention in algebra, but it's also not universally accepted in all
   ///areas. Sometimes 0^0 is simply undefined. If you don't like this convention, then
   ///you need to handle the case a = 0 the way showed above.

   n = sqrt(m) + 1; ///highest possible value of n
   for(i = 1; i <= n; i++) an = (an * a) % m; ///precalculating a^n. then if we need
   ///to calculate a^np, we'll just multiply a^n p times.

   unordered_map < ll, ll > vals; ///to store which val of q gives us what value of b*a^q
   ///so that, we can apply binary search on it later.

   for(q = 0, cur = b; q <= n; q++)
   {
      vals[cur] = q; ///storing values of b*a^q, for each q in range[0,n]
      cur = (cur * 1ll * a) % m; ///calculating a^q for each q
   }

   for(p = 1, cur = 1; p <= n; p++)
   {
      cur = (cur * an) % m; ///calculating a^np
      if(vals.count(cur)) ///checking if it exists as some b*a^q for some q
      {
         cout << n * p - vals[cur] << endl; ///thats the value for x, our solution
         exit(0);
      }
   }
   cout << "Solution doesn't exist" << endl;
}
