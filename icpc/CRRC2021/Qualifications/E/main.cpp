#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> p_l;
typedef tuple<int, int, int> t_i;

#define forin for (ll i = 0; i < n; ++i)
#define forni for (ll i = n-1; i >= 0; --i)

int main()
{

    ll n, k, m;
    ll lower = 0, upper = 0, ravn = 0;
    cin >> n >> k >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        if (x > k) upper++;
        if (x == k) ravn++;
        if (x < k) lower++;
    }
    if (upper >= n) cout << "no chance";
    else if ((upper + ravn + 1) <= n) cout << "enter";
    else cout << "entrance exams";


    return 0;
};
