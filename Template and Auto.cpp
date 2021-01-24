///so, we saw the job of template can be done by auto. so from now on, when you write
///a function, use auto instead of actual variable type.
///we can use auto in place of return type of function, even in place of void

#include <sbits/stdc++.h>
using namespace std;
#define ll long long

/*template < typename T >
T mx(T a, T b)
{
   return a > b ? a : b;
} */

auto mx(auto a, auto b)
{
   return a > b ? a : b;
}

int main ()
{
   int a, b; double c, d;
   cin >> a >> b >> c >> d;
   cout << mx(a, b) << endl << mx(c, d) << endl;
   string x, y;
   cin >> x >> y;
   cout << mx(x, y) << endl;
}
