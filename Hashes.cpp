///Gleb is Always Right

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define sqr(x) ((x)*(x))
#define count_one __builtin_popcount(x)

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

/*indexed_set s;
s.insert(a);
cout << *s.find_by_order(i) << '\n';
cout << s.order_of_key(k);*/

typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const int N = 2e5 + 7;
const ll INF = 1e18 + 7;
const int d2x[4] = {0, 1, 0, -1};
const int d2y[4] = {1, 0, -1, 0};
const int d3x[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int d3y[8] = {1, 0, -1, -1, -1, 0, 1, 1};
const int P = 239;
const int MOD = 228228227;

void indent() {
    cerr << "\n\n\n";
}

int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    else
        return a + b;
}

int sub(int a, int b) {
    if (a - b < 0)
        return a - b + MOD;
    else
        return a - b;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}

ll h[1000001], p[1000001];

void Hash(string s) {
    ll c = 0;
    for (int i = 0; i < sz(s); i++) {
        c = add(mul(c, P), s[i]);
        h[i] = c;
    }
    p[0] = 1;
    for (int i = 1; i <= sz(s); i++)
        p[i] = mul(p[i - 1], P);
}

ll get(ll l, ll r) {
    ll ans = h[r];
    if (l)
        ans = sub(ans, mul(h[l - 1], p[r - l + 1]));
    return ans;
}

void Solve() {
    string s;
    cin >> s;
    Hash(s);
    ll q;
    cin >> q;
    while (q--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1--; r1--; l2--; r2--;
        if (get(l1, r1) == get(l2, r2))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tests = 1;
    //cin >> tests;
    while(tests--)
        Solve();
    return 0;
}
