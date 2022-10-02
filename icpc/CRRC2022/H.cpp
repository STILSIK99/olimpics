#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Item {
    int n;
    string country;
    string date;
    string dd;
    Item (int a, string b): n (a)
    {
        date = "";
        dd = "";
        int pos = b.find_first_of (' ');
        country = b.substr (0, pos);
        b = b.substr (pos + 1, b.length() - pos - 1);
        for (int i = 0; i < 3; ++i) {
            int pos = b.find_first_of (' ');
            date += b.substr (0, 2);

            switch (i) {
                case 0:
                    date += ".";
                    dd += b.substr (0, 2);
                    break;
                case 1:
                    date += ".2113 ";
                    dd = b.substr (0, 2) + dd;
                    break;
                case 2:
                    date += ":";
                    dd += b.substr (0, 2);
                    break;
                default:
                    {}
            }
            b = b.substr (pos + 1, b.length() - pos - 1);
        }
        dd += b;
        date += b;
    }

    string toString()
    {
        stringstream str;
        str << n << " " << country << " " << date;
        return str.str();
    }
};

bool operator< (const Item &a, const Item &b)
{
    if (a.country > b.country) return false;
    if (a.country < b.country) return true;
    if (a.dd > b.dd) return false;
    if (a.dd < b.dd) return true;
    return a.n < b.n;
}

int main()
{
    cin.sync_with_stdio (false);
    vector<Item> mas;
    string s;
    int i = 1;
    while (getline (cin, s)) {
        mas.push_back (Item (i, s));
        ++i;
    }
    sort (mas.begin(), mas.end());
    for (auto it : mas) {
        cout << it.toString() << "\n";
    }

    return 0;
}