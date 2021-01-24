///Author : Mursaleen
///Date :
///Problem topic : Rabin-Karp Algorithm for string matching
///Verdict :
///Platform :
///--------------------------------------------------------///
///Given two strings - a pattern s and a text t, determine if the pattern appears
///in the text and if it does, enumerate all its occurrences in O(|s|+|t|) time.
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl
ll p = 31, mod = 1e9+9, S, T, i, j, h_s, cur_h; string s, t;

int main ()
{
   cin >> s >> t; ///string s is pattern and string t is the text
   S = s.size(), T = t.size();
   vector < ll > p_pow(max(S, T)), h(T+1, 0), occurrences; p_pow[0] = 1;
   for(i = 1; i < p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * p) % mod;
   for(i = 0; i < T; i++) h[i+1] = (h[i] + (t[i]-'a'+1) * p_pow[i]) % mod;
   for(i = 0; i < S; i++) h_s = (h_s + (s[i]-'a'+1) * p_pow[i]) % mod;
   for(i = 0; i + S - 1 < T; i++)
   {
      cur_h = (h[i+S] + mod - h[i]) % mod;
      if(cur_h == (h_s * p_pow[i]) % mod) occurrences.push_back(i);
   }
   for(auto it : occurrences) cout << it << ' '; cout << endl;
}

