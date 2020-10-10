#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/rope>

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) ((ll)(x).size())
#define unq(x) (x.resize(unique(all(x)) - x.begin()))

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//template<class T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;

const ld PI = 3.1415926535;
const ll N = 4e6 + 7;
const ll INF = 1e18 + 7;

vector<ll> a(N);

struct node {
    node *le = nullptr, *ri = nullptr;
    ll sum = 0;
};

void Merge(node *tree) {
    tree->sum = 0;
    if (tree->le)
        tree->sum += tree->le->sum;
    if (tree->ri)
        tree->sum += tree->ri->sum;
}

void Update(node *tree, ll tl, ll tr, ll pos, ll x) {
    if (tr - tl == 1) {
        tree->sum = x;
        return;
    }
    ll c = (tl + tr) / 2;
    if (pos < c) {
        if (tree->le == nullptr)
            tree->le = new node();
        Update(tree->le, tl, c, pos, x);
    }
    else {
        if (tree->ri == nullptr)
            tree->ri = new node();
        Update(tree->ri, c, tr, pos, x);
    }
    Merge(tree);
}

ll Sum(node *tree, ll tl, ll tr, ll l, ll r) {
    if (tree == nullptr)
        return 0;
    if (tl == l && tr == r)
        return tree->sum;
    ll c = (tl + tr) / 2, ans = 0;
    if (l < c)
        ans += Sum(tree->le, tl, c, l, min(c, r));
    if (c < r)
        ans += Sum(tree->ri, c, tr, max(l, c), r);
    return ans;
}

void Solve() {
    ll n, q;
    cin >> n >> q;
    node *root = new node();
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Update(root, 0, n, i, a[i]);
    }

    for (int i = 0; i < q; i++) {
        bool type;
        cin >> type;
        if (type) {
            ll pos, x;
            cin >> pos >> x;
            Update(root, 0, n, pos - 1, x);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << Sum(root, 0, n, l - 1, r) << '\n';
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
