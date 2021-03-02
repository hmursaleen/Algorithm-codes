#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl

void f(int *b, int n)
{
   for(int i = 0; i < n; i++) b[i] *= 2;
   return;
}

int main ()
{
   int a[2]; cin >> a[0] >> a[1];
   f(a, 2);
   for(int i = 0; i < 2; i++) cout << a[i] << ' ';
}
