#include <bits/stdc++.h>
using namespace std;

int main()
{
    /// A way of expressing numbers in binary
    ///cout << bitset <8> (13) << endl;

    ///We can also check the positions of '1's in the binary
    ///representation of a number. position counting starts from 0
    ///from RHS.
    ///Here's an example
    ///by this technique we can also check if a bit is '0' or '1'
    ///in a specific position. (position counting starts from 0
    ///from RHS.)
    ///int x = 16;
    ///for(int i = 0; (1 << i) <= x; i++) if(x & (1 << i)) cout << i << " ";


    /*now consider another problem. given an array of <= 20 numbers
    and a target sum x, you're to determine whether there's a subset
    which sums equals x;

    It can be solved with recursion but there's a very elegant
    iterative approach that iterates over every number x from
    0 to 2^n−1 and considers x to be a binary number of length
    n, where bit 1 means taking a number and bit 0 is not taking.
    */
    /*int n, S; cin >> n >> S; int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int mask = 0; mask < (1 << n); mask++) {
	long long sum_of_this_subset = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			sum_of_this_subset += a[i];
		}
	}
	cout << sum_of_this_subset << ' ';
	if(sum_of_this_subset == S) {
		puts("YES");
		return 0;
	}
	cout << endl;
    }

    puts("NO"); */

    ///built-in functions
    ///in c++ there are built in functions by which we can count
    ///the number of ones in the binary format of a number
    ///here is the code
    /*int x; /// the number
    cin >> x;
    cout << __builtin_popcount(x) << endl; ///where x is an integer
    */
    /// and when x is long long, then the function is
    /*long long a;
    cin >> a;
    cout << __builtin_popcountll(a) << endl;
    */

    ///there are also functions both to calculate number of leading
    /// and trailing zeros in binary format of a positive number
    /// here's the code
    /*int a; cin >> a;
    cout << __builtin_clz(a) << endl; /// prints no. of leading zeros
    /// actually it shows 32-no. of bits in binary format

    cout << __builtin_ctz(a) << endl; ///prints no. of trailing zeros
    */

    ///there's a function of check the parity of a number
    ///the function return true if the parity is odd, else
    ///returns true, here's the code

    ///int a; cin >> a;
    ///cout << __builtin_parity(a) << endl;
    int s; cin >> s;
    bitset < 100 > b(s);
    ///cout << b[3] << ' ';
    cout << b.count() << endl;

}
