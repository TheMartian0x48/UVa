// author : the__martian
// 11230
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


long _sieve_size = 10000000;
bitset<10000005> sieve;
vector<long> primes;

void Sieve(long long n = 1e6){
  _sieve_size = n + 1;
  sieve.set();
  sieve.reset(0), sieve.reset(1);
  for (long long i = 2; i < _sieve_size; i++) {
    if (sieve[i]) {
      for (long long j = i * i; j < _sieve_size; j += i){
        sieve.reset(j);
      }
      primes.push_back(i);
    }
  }
}

bool IsPrime(long long n){
  if (n < _sieve_size){
    return sieve[n];
  }
  for (auto p : primes){
    if (p * p > n) return true;
    if (n % p == 0) return false;
  }
  return true;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);


  Sieve(1e4);
  vector<int> sum(1e4+5, 0);

  int n = sz(primes);
  for (int i = 0; i < n;i++) {
    int tmp = primes[i];
    if (IsPrime(tmp))
      sum[tmp]++;
    for (int j = i + 1; j < n; j++) {
      tmp += primes[j];
      if (tmp > 10000) break;
      sum[tmp]++;
    }
  }
  int p;
  while (cin >> p, p) {
    cout << sum[p] << "\n";
  }
}
