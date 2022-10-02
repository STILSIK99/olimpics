#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> graf (n + 1);
        for (int i = 1; i < n; ++i) {
            cin >> graf[i];
        }
        --n;
    }

    return 0;
}
