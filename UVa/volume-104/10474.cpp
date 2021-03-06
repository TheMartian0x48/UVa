/*
 *TheMartian0x48
 */

#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define per(i, a, b) for (int i = a; i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rll(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<long long>;
// (* math *)
ll eea(ll a, ll b, ll &x, ll &y) {if (b == 0){x = 1,y = 0;return a;}
ll x1, y1;  ll g = eea(b, a % b, x1, y1);x = y1;y = x1 - y1 * (a / b);return g;}
// (* read and write *)
template <class T>
void re(vector<T> &v, int n) {v.resize(n); for (auto &e : v) cin >> e;}
template <class T> 
void re(vector<T> &v){for (auto &e : v) cin >> e;}
template <class T>
void pr(vector<T> &v, char sep = ' ') {for (auto e : v) cout << e << sep;}
// clang-format on

// ---------------- (* Extract here *)
// ----------------

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, q;
  vector<int> v;
  int t = 1;
  while (cin >> n >> q, n || q) {
    v.resize(n);
    rep(i,0,n) {
      cin >> v[i];
    }
    sort(all(v));
    cout << "CASE# " << t++ << ":\n";
    while(q--) {
      int a; cin >> a;
      int l = -1, r = n, m;
      while (l + 1 < r) {
        m = (l + r) / 2;
        if (v[m] < a) l = m;
        else r = m;
      }
      if (r == n || v[r] != a) cout << a << " not found\n";
      else cout << a << " found at " << r + 1 <<"\n";
    }
  }
}