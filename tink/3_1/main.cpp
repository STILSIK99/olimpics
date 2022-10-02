#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int > > arr (n, vector<int> (m, 0));
    deque <pair<int, int>> qq;
    qq.push_back (make_pair (0, 0));
    while (!qq.empty()) {
        pair<int, int> pp = qq.front();
        ++arr[pp.first][pp.second];
        qq.pop_front();
        if (pp.first + 2 < n && pp.second + 1 < m)
            qq.push_back (
                make_pair (pp.first + 2, pp.second + 1));
        if (pp.first + 1 < n && pp.second + 2 < m)
            qq.push_back (
                make_pair (pp.first + 1, pp.second + 2));
    }
    cout << arr[n - 1][m - 1];
    return 0;
}
