#define ll long long
#include <cstdio>

// returns a^b
ll binPow(ll a, ll b) {
   ll answer = 1;
   while (b) {
      if (b & 1)
         answer *= a;
      a *= a;
      b >>= 1;
   }
   return answer;
}

// returns a^b % M
ll binPow(ll a, ll b, ll M) {

   ll answer = 1;
   while (b) {
      if (b & 1)
         answer = (answer * a) % M;
      a = (a * a) % M;
      b >>= 1;
   }
   return answer;
}

// returns a^b % M but runs faster with fermat's little theorem
ll binPowPrimeMod(ll a, ll b, ll M) {

   // Fermat's little theorem trick to speed up alg
   b = b % (M - 1);
   ll answer = 1;
   while (b) {
      if (b & 1)
         answer = (answer * a) % M;
      a = (a * a) % M;
      b >>= 1;
   }
   return answer;
}
