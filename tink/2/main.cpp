#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    while (n != 0 && m != 0) {
        ans += 1;
        if (m > n) m -= n;
        else n -= m;
    }
    cout << ans;
    return 0;
}
