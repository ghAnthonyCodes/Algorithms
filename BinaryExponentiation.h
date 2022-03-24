#define ll long long

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
