#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> v_ll;

#define forin(a,n) for(ll i = a; i < n;++i)


int main()
{
    map<char, ll> has;
    string s;
    cin >> s;
    forin (0, s.size()) {
        if (has.count (s[i]) == 0) has[s[i]] = 1;
        else ++has[s[i]];
    }
    forin (0, has['\\']) {
        cout << ":-\\\n";
    }
    has[':'] -= has['\\'];

    forin (0, has['P']) {
        cout << ":-P\n";
    }
    has[':'] -= has['P'];

    forin (0, has['D']) {
        cout << ":D\n";
    }
    has[':'] -= has['D'];

    forin (0, has['C']) {
        cout << ":C\n";
    }
    has[':'] -= has['C'];

    forin (0, has['8']) {
        cout << "8-0\n";
    }
    has['0'] -= has['8'];

    forin (0, has['E']) {
        cout << ":-E\n";
    }
    has[':'] -= has['E'];

    forin (0, has['%']) {
        cout << "%0\n";
    }
    has['0'] -= has['%'];

    forin (0, has['~']) {
        cout << ":~(\n";
    }
    has[':'] -= has['~'];
    has['('] -= has['~'];

    forin (0, has['X']) {
        cout << ":-X\n";
    }
    has[':'] -= has['X'];
    has['-'] -= has['X'];

    forin (0, has['[']) {
        cout << "[:|||:]\n";
    }
    has[':'] -= 2 * has['['];
    has['|'] -= 3 * has['['];

    forin (0, has['0']) {
        cout << ":-0\n";
    }
    has[':'] -= has['0'];

    forin (0, has['|']) {
        cout << ":-|\n";
    }
    has[':'] -= has['|'];

    forin (0, has[';']) {
        if (i >= has[')']) cout << ";-(\n";
        else cout << ";-)\n";
    }
    ll k = min (has[';'], has[')']);
    has[')'] -= k;
    has['('] -= (has[';'] - k);
    forin (0, has[':']) {
        if (i >= has[')']) cout << ":(\n";
        else cout << ":)\n";
    }
    cout << "LOL";
    return 0;
}
