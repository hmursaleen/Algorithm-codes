///Author : Mursaleen
///Date :
///Problem topic : Linear Diophantine Equation (Practice)
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
///A Linear Diophantine Equation (in two variables) is an equation of the general form:
///ax + by = c, where a, b, c are given integers, and x, y are unknown integers.
///***When the solution exists : If a = b = 0, but c != 0, then it has no solutions.
///And, if a = b = 0, and c = 0, then it has infinitely many solutions (any value for x and y will do then)
///Generally, the case of a = b = 0 is ignored in coding part
///***If c is not divisible by gcd(a,b) then it has no solution.
///If a or b is 0, the it has only one solution, i.e. if a = 0, then bx = c. b = c/x.
///and if b = 0, then ax = c. a = c/x.

///We can find solutions for x and y using the egcd algorithm. Because in egcd, for two
///numbers a and b we find values of x and y, such that, ax + by = gcd(a,b)
///-> ax + by = cn (as if there's any solution, then c is divisible by gcd(a,b)
///then if we get values of x and y, we can easily get the solutions and egcd does so.
///suppose, g = gcd(a,b). then ax + by = g.
///multiplying both side by c/g, we get : ax*c/g + by*c/g = c
///so clearly one solution is {x*c/g, y*c/g}
///The above idea still works when a or b or both of them are negative. We only need
///to change the sign of x and y when necessary.
ll a, b, c, ans, x, y, g;
int main ()
{
   cin >> a >> b >> c;
   egcd(abs(a), abs(b)); g = ans;
   if(!a and !b)
   {
      if(!c) cout << "Infinite solutions" << endl;
      else cout << "No solutions" << endl;
      exit(0);
   }
   if(!a or !b)
   {
      if(!a) cout << "y : " << c/b << endl;
      else cout << "x : " << c/a << endl;
      exit(0);
   }
   if(c % g)
   {
      cout << "No solutions" << endl;
      exit(0);
   }
   x *= c/g;
   y *= c/g;
   if(a < 0) x = -x;
   if(b < 0) y = -y;

///Getting all solutions :
///-----------------------------------------------------///
///From one solution (x ,y), we can obtain all the solutions of the given equation.
///Let g = gcd(a,b) and let x,y be integers which satisfy the following: ax + by = c
///Now, we should see that adding b/g to x, and, at the same time subtracting a/g from y
///will not break the equality:
///a(x+b/g) + b(y−a/g) = ax + by + a*b/g − b*a/g = c
///Obviously, this process can be repeated again, so all the numbers of the form:
///x = x + k*b/g
///y = y − k*a/g are solutions of the given Diophantine equation.
}
