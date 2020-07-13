#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 10e5 + 5;

vector<ll> tree, a(N);

void Init(ll v, ll tl, ll tr)
{
    if(tr - tl == 1)
    {
        tree[v] =a[tl];
        return;
    }
    int c = (tl + tr) / 2;
    Init(2 * v + 1, tl, c);
    Init(2 * v + 2, c, tr);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

void Update(ll v, ll tl, ll tr, ll pos, ll k)
{
    if(tr - tl == 1)
    {
        tree[v] = k;
        return;
    }
    ll c = (tl + tr) / 2;
    if(pos < c)
        Update(2 * v + 1, tl, c, pos, k);
    else
        Update(2 * v + 2, c, tr, pos, k);
    tree[v] = tree[v * 2 + 1] + tree[v * 2 + 2];
}

ll Sum(ll v, ll tl, ll tr, ll l, ll r)
{
    if(tl == l && tr == r)
        return tree[v];
    ll c = (tl + tr) / 2, ans = 0;
    if(c > l)
        ans += Sum(v * 2 + 1, tl, c, l, min(c, r));
    if(c < r)
        ans += Sum(v * 2 + 2, c, tr, max(l, c), r);
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    tree.resize(4 * n);
    Init(0, 0, n);
    ll w;
    cin >> w;
    while(w--)
    {
        ll type;
        cin >> type;
        if(type == 1)
        {
            ll pos, k;
            cin >> pos >> k;
            pos--;
            Update(0, 0, n, pos, k);
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            l--;
            cout << Sum(0, 0, n, l, r) << '\n';
        }
    }
}