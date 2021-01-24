#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a, d;
	a = "geeksforgeeks";
	///initilization by part of another string
	///from 5th indx, 3 chars;
	string b(a, 5, 3);
	cout << b << "\n";
	string c(a.begin() + 5, a.begin() + 8);
	cout << c << "\n";
	a.append(" good");
	///same as a += " good";
	b.append(a, 13, 5);
	///another version of append, which appends part
   ///of another string
	cout << b << "\n";
	string e = "I love you";
	string f = e.substr(2, 4);
	cout << f << "\n";
	///substr (a,b) function returns a substring
	///of b length starting from indx a;
	string g = e.substr(2);
	cout << g << "\n"; /// if second argument is not
	///taken, string till end is taken as substring
	e.erase(6, 4);
	cout << e << "\n";/// erase (a,b) deletes b chars
	///starting from indx a;
	string h = "i love you more";
	h.erase(h.begin() + 6, h.end() - 5);
	cout << h << "\n";
	string i = "i love you";
	i.replace(2, 4, "hate ");///replace (a,b,str)
	///replaces b chars starting from a by str, length of str if arbitrary.
	cout << i << "\n";
}
