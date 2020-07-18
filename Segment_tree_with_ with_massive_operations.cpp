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
const ll N = 2e5 + 7;
const ll INF = 1e18 + 7;
const ll d2x[4] = {0, 1, 0, -1};
const ll d2y[4] = {1, 0, -1, 0};
const ll d3x[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const ll d3y[8] = {1, 0, -1, -1, -1, 0, 1, 1};

void indent() {
    cerr << "\n\n\n";
}

vector<ll> tree, g;

void Push(ll v, ll tl, ll tr, ll x) {
    ll c = (tr + tl) / 2;
    tree[v * 2 + 1] += x * (c - tl);
    g[v * 2 + 1] += x;
    tree[v * 2 + 2] += x * (tr - c);
    g[v * 2 + 2] += x;
    g[v] = 0;
}

void Update (ll v, ll tl, ll tr, ll l, ll r, ll x) {
    if(tl == l && tr == r) {
        tree[v] += x * (tr - tl);
        g[v] += x;
        return;
    }
    Push(v, tl, tr, g[v]);
    ll c = (tl + tr) / 2;
    if(l < c)
        Update(v * 2 + 1, tl, c, l, min(c, r), x);
    if(c < r)
        Update(v * 2 + 2, c, tr, max(l, c), r, x);

    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

ll Sum(ll v, ll tl, ll tr, ll l, ll r) {
    if(tl == l && tr == r)
        return tree[v];
    Push(v, tl, tr, g[v]);
    ll c = (tl + tr) / 2, ans = 0;
    if(c > l)
        ans += Sum(v * 2 + 1, tl, c, l, min(c, r));
    if(c < r)
        ans += Sum(v * 2 + 2, c, tr, max(l, c), r);
    return ans;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    tree.resize(n * 4);
    g.resize(n * 4);
    for (int i = 0; i < m; i++) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r, k;
            cin >> l >> r >> k;
            Update(0, 0, n, l, r, k);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << Sum(0, 0, n, l, r) << '\n';
        }
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
