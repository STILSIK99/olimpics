#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, n;
    cin >> a >> b >> n;
    if ((a < b) || ((a - b) / 2 < n) || ((a - b) % 2 != 0)) cout << "NO";
    else cout << "YES";

    return 0;
}
