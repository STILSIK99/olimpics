#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{

    ll ans = 1e18;
    ll flag = false;
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (b >= k) {
            flag = true;
            ans = min (ans, max (a, k) * c);
        }
    }
    if (!flag) cout << -1;
    else cout << ans;
    return 0;
}