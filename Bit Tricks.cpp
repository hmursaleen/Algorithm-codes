#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " : " << x << endl
int n, pos, a, b, c, d, e, f;
int main ()
{
    cin >> n;
    /// set a bit in a number
    cin >> pos;
    /// All pos should be counted from right side starting from 0;
    a = n;
    a |= (1 << pos);
    ///cout << a << endl;

    /// Unset/clear a bit in a number
    b = n;
    b &= (~(1 << pos));
    ///cout << b << endl;

    /// Toggling a bit in a number
    c = n;
    c ^= (1 << pos);
    ///cout << c << endl;

    /// Checking if a bit is set or unset
    d = n;
    d &= (1 << pos);
    ///cout << ((d > 0) ? '1' : '0')<< endl;

    ///striping off the lowest set bit / unsetting the lowest set bit
    e = n;
 +   e &= (e - 1);
    ///cout << e << endl;

    /// Getting lowest set bit of a number
    f = n;
    f &= -f;
    cout << f << endl;
}
