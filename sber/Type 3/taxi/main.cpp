#include <bits/stdc++.h>

using namespace std;

int getResult (vector<int> weight)
{
    sort (weight.begin(), weight.end());
    int more_210 = 0;
    for (auto x : weight) if (x > 210) ++more_210;
    int startCount = max (int ((weight.size() + 3) / 4), more_210);
    multimap<int, set<int>> weis;
    set <pair<int, set<int>>> q;
    set<set<int>> usedSet;
    q.insert (make_pair (210, set<int>()));
    while (!q.empty()) {
        auto x = * (q.begin());
        q.erase (q.begin());
        if (x.second.size() == 3 || x.first < 0) continue;
        for (int i = 0; i < weight.size(); ++i) {
            if ((x.second.count (i) != 0) || (x.first - weight[i] < 0)) continue;
            set<int> n = x.second;
            n.insert (i);
            if (usedSet.count (n) != 0) continue;
            else usedSet.insert (n);
            q.insert (make_pair (x.first  - weight[i], n));
            weis.insert (make_pair (x.first  - weight[i], n));
            usedSet.insert (n);

        }
    }

    for (auto x : weis) {
        cout << "sum: " << x.first;
        for (auto f : x.second) cout << " " << f;
        cout << "\n";
    }


    const int len = weight.size();
    while (true) {
        vector<bool> used (len, 0);
        for (int j = len - startCount - 1; j < len; ++j) used[j] = true;
        int cars = startCount;
        auto it = weis.begin();
        while (cars > 0 && it != weis.end()) {
            bool fl = false;
            for (auto p : it->second)
                if (used[p] == 1) fl = true;
            if (fl) {
                ++it;
                continue;
            }
            --cars;
            for (auto p : it->second) used[p] = true;
        }
        if (used == vector<bool> (len, 1)) return startCount;
        ++startCount;
    }
}

int main()
{
    cout << getResult (vector<int> {89, 46, 134, 78, 79, 67, 63, 81, 66});
    return 0;
}
