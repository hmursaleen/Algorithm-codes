///Author : Mursaleen
///Date :
///Problem topic :
///Verdict :
///Platform :
///--------------------------------------------------------///

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define show(x) cout << #x << " : " << x << endl


int main ()
{
   ///size of bitset has to be constant. it can't be changed later
   ///bitset data store kore dan dik theke, indexing o dan dik theke.
   ///mane bitset[0] mane hocche dan dik theke first bit.

   bitset < 32 > b1;
   ///cout << b1 << endl; /// prints 32 zeros. so janlam je by default, shurute sob bit 0 thake.

   ///jodi chai je bitset e ekta integer er binary representation rakhbo, setao kora jay evabe.
   bitset < 32 > b2(9);
   ///cout << b2 << endl

   ///abar ekta binary string o rakha jay bitset e nicher upaye
   bitset < 32 > b3(string("0101001"));
   ///cout << b3 << endl;

   ///kono ekta bit 0 ba 1 korte chaile seta index diye direct access kore kora jay.
   ///mone rakhte hobe, indexing ta hoy dan dik theke and 0 theke shuru hoy
   ///ekhon jodi amra b1 bitset er dan thik theke 2nd bit ta 1 korte chai, evabe korte pari
   ///b1[1] = 1; cout << b1 << endl;


   ///ekhon bitset er kichu built-in function er kaj dekhbo.
   ///jodi jante chai bitset e total koyta bit 1, seta evabe kora jay
   ///cout << b2.count() << endl;

   ///jodi eksathe bitset er sob bit 1 kore dite chai, evabe korbo
   ///b1.set(); cout << b1 << endl;


   ///bitset declare korar somoy sob bit 0 thake. but jodi erpor kono karone sobgula bit
   /// 0 korar dorakar hoy, evabe korbo
   ///b3.reset(); cout << b3 << endl;

   ///flip() diye eksathe sobgula bit flip kora jay. (ulte dey, i.e. 0 -> 1, 1 -> 0)
   ///b3.flip(); cout << b3 << endl;



   ///Operator : Duita bitset er moddhe comparison operation( ==, != ), bitwise operator
   ///(&, |, ^) , left and right shifting ( <<, >> ), not operator - ei sob gulai use kora
   ///jay. example dekhi :
   ///cout << (b1 != b3) << endl;
   ///cout << (b1 == b3) << endl;
   ///cout << (b2 & b3) << endl; /// bitwise AND er result dekhabe binary te
   ///cout << (b2 | b3) << endl; /// bitwise OR er result dekhabe binary te
   ///cout << (b2 ^ b3) << endl; /// bitwise XOR er result dekhabe binary te

   ///cout << (b2 << 1) << endl; /// left shifting er result dekhabe binary te
   ///cout << (b2 >> 1) << endl; /// right shifting er result dekhabe binary te
}
