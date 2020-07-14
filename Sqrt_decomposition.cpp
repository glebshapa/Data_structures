#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll N = 10e5 + 5;
 
ll n, a[100001], s[100001], d, q;
 
ll Sum(ll l, ll r) {
    ll ans = 0;
    while (l <= r) {
        if (l % d == 0 and l + d - 1 <= r) {
            ans += s[l / d];
            l += d;
        }
        else {
            ans += a[l];
            l++;
        }
    }
    return ans;
}
 
void Update(ll pos, ll k) {
    s[pos / d] += (k - a[pos]);
    a[pos] = k;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    d = sqrt(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i / d] += a[i];
    }
 
    while (q--) {
        ll type;
        cin >> type;
        if (type == 0) {
            ll l, r;
            cin >> l >> r;
            cout << Sum(l - 1, r - 1) << '\n';
        }
        else {
            ll x, y;
            cin >> x >> y;
            x--;
            Update(x, y);
            
        }
 
    }
}
