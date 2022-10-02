#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int recur (short position,
           set<pair<short, short>> &used,
           int sum, int step,
           vector< map<short, short>> &graph,
           int &k)
{
    if (step == k) return sum;
    auto roads = graph[position];
    int ans = -1;
    for (auto road : roads) {
        auto p = make_pair (
                     min (position, road.first),
                     max (position, road.first));
        //шаг обратно
        if (used.count (p) == 1) ans = max (ans, recur (road.first, used, sum, step + 1, graph, k));
        else {
            //новая дорога
            used.insert (p);
            ans = max (ans, recur (road.first, used, sum + road.second, step + 1, graph, k));
            used.erase (p);
        }
    }
    return ans;
}


int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector< map<short, short>> graph (n, map<short, short>());
    for (int i = 0; i < m; ++i) {
        short a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = c;
        graph[b - 1][a - 1] = c;
    }


    set<pair<short, short>> used;
    int result = recur (0, used, -1, 0, graph, k);
    if (result != -1) ++result;
    cout << result;

    return 0;
}