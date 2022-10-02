#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> p_i;
typedef long long ll;
typedef tuple<int, int, int> t_i;

#define x first
#define y second
#define mt make_tuple

bool cmp (t_i &a, t_i &b)
{
    if (get<2> (a) < get<2> (b)) return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> mas (n, vector<ll> (m, 0));
    mas[0][0] = 1;
    set<t_i> s;
    s.insert (mt (0, 0, 0));
    while (!s.empty()) {
        t_i c = *s.begin();
        ll k = mas[get<0> (c)][get<1> (c)];
        s.erase (c);
        if (get<0> (c) + 2 < n && get<1> (c) + 1 < m) {
            s.insert (mt (get<0> (c) + 2, get<1> (c) + 1, get<2> (c) + 1));
            mas[get<0> (c) + 2][get<1> (c) + 1] += k;
        }
        if (get<0> (c) + 1 < n && get<1> (c) + 2 < m) {
            s.insert (mt (get<0> (c) + 1, get<1> (c) + 2, get<2> (c) + 1));
            mas[get<0> (c) + 1][get<1> (c) + 2] += k;
        }
    }
    cout << mas[n - 1][m - 1];
    return 0;
}
