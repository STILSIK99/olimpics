#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a (n + 1), b (n + 1);
    b[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int start = n, finish = 0;
    int size = n;
    vector<int> lengths (n + 1, 1e9);
    lengths[start] = 0;
    set < pair<int, int>> mas; // ver, len
    mas.insert (make_pair (lengths[start], start));
    while (!mas.empty()) {
        int v = mas.begin()->second;
        int len = mas.begin()->first;
        mas.erase (mas.begin());
        if (len > lengths[v]) continue;
        for (int i = 1; i <= a[v]; ++i ) {
            int n_v = v - i + b[v - i];
            int n_len = len + 1;
            if (lengths[n_v] > n_len) {
                mas.erase (make_pair (lengths[n_v], n_v));
                lengths[n_v] = n_len;
                mas.insert (make_pair (n_len, n_v));
            }
        }
    }
    if (lengths[finish] == 1e9) cout << -1;
    else cout << lengths[finish];
    return 0;
}
