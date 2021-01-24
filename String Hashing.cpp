///Author : Mursaleen
///Date :
///Problem topic : String Hashing (Practice)
///Verdict :
///Platform :
///--------------------------------------------------------///
///The goal of it is to convert a string into an integer, the so-called hash
///of the string. The following condition has to hold: if two strings s
///and t are equal (s=t), then also their hashes have to be equal (hash(s)=hash(t))
///Notice, the opposite direction doesn't have to hold. If the hashes are
///equal (hash(s)=hash(t)), then the strings do not necessarily have to be equal
///usually we want the hash function to map strings onto numbers of a fixed
///range [0,m), then comparing strings is just a comparison of two integers
///with a fixed length

///if the input is composed of only lowercase letters of the English alphabet
///,p=31 is a good choice. If the input may contain both uppercase and
///lowercase letters, then p=53 is a possible choice.
/// A good choice for m is some large prime number. The code in this article
/// will just use m = 10^9+9
///.......................................................................///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl

string s; ll _hash, cnt, p_pow = 1, p = 31, mod = 1e9+9, i, j, l, n;
/// hash(s) = sum of ((s[i]-'a'+1) * p^i) mod m
///The job of hashing can also be done by the default keyword "hash" in c++.
///to know about that, open the file named : Hash Keyword in C++.cpp
int main ()
{
   cin >> s; ///the string to calculate hash for
   /*for(char c : s)
   {
      _hash += (_hash + (c - 'a' + 1) * p_pow) % mod;
      p_pow = (p_pow * p) % mod;
   }
   cout << _hash << endl; */

   ///fast calculation of substrings of a string
   ///--------------------------------------------------------------
   ///hash of some substring in range [i,j] can be defined as :
   ///hash(i...j) = sum of ((s[k]-'a'+1) * p^(k-i)) mod m, where i <= k <= j
   ///multiplying both side by p^i, we get :
   ///hash(i...j) * p^i = sum of ((s[k]-'a'+1) * p^k) mod m, where i <= k <= j
   ///                  = sum of hash[j] - hash[i-1] mod m.
   ///so, when we compare two substrings' hashes, we need to make sure both of them are
   ///multiplied by the same power of p. what we can do to make that sure is :
   ///suppose substring a = hash(i1, j1) * p^i, and substring b = hash(i2, j2) * p^j
   ///then, if i < j, a = a * p^(j-i), else b = b * p^(i-j)
   ///then we can compare those two substrings.


   ///count no. of unique substrings of a string
   ///--------------------------------------------///

   /*n = s.size();
   vector < ll > p_pow(n), h(n+1, 0); p_pow[0] = 1;
   for(i = 1; i < n; i++) p_pow[i] = (p_pow[i-1] * p) % mod;
   for(i = 0; i < n; i++) h[i+1] = (h[i] + (s[i]-'a'+1) * p_pow[i]) % mod;
   for(l = 1; l <= n; l++)
   {
      set < ll > hs;
      for(i = 0; i <= n-l; i++)
      {
         ll cur_h = (h[i+l] + mod - h[i]) % mod;
         cur_h = (cur_h * p_pow[n-i-1]) % mod;
         hs.insert(cur_h);
      }
      cnt += hs.size();
   }
   cout << cnt << endl; */

   ///to improve no collision probability we can use two different p and mod.
}
