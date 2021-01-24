///Author : Mursaleen
///Date :
///Problem topic : Hash keyword in C++
///Verdict :
///Platform :
///--------------------------------------------------------///

///Apparently the job of hashing can be done by a default keyword in c++. the keyword is
///"hash". it provides a unique value for each string or any data type.
///it can be defined as : hash < je type er datar hash korbo > has_name;
///e.g. hash < string > h;
///and we can pass values to it like : hash_name(name of variable whose hash we want to get)
///e.g. hash < string > h; string s = "good"; cout << h(s) << endl;


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl


int main ()
{
   string s; cin >> s; ///the string we wanna get hash of
   hash < string > h; /// define the hash
   cout << h(s) << endl; ///printing the hash value
}

