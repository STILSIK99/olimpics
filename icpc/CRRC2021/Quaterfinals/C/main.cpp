/*----------------------------*\
|     written by STILSIK       |
\*----------------------------*/
#include <bits/stdc++.h>

using  namespace std;

typedef unsigned long long ul;
typedef long long ll;
typedef long double ld;
typedef vector<ll> v_ll;
typedef vector<int> v_i;
typedef pair<ll, ll> p_ll;
typedef pair<int, int> p_ii;
typedef vector<pair<ll, ll>> vp_ll;



#define forina(a,n) for (auto i = a; i != n; ++i)
#define forin(a,n) for (ll i = a; i < n; ++i)
#define forins(a,n,s) for (ll i = a; i < n; i+=s)
#define forjn(a,n) for (ll j = a; j < n; ++j)
#define forni(n,a) for (ll i = n; i >= a; --i)
#define speed ios::sync_with_stdio (0);cin.tie (0);cout.tie(0)

const int INF = 1e9;
const ll minn = -1e18;
const ll maxx = 1e18;



template<int D>
struct simple_nums {
    static constexpr int N = D;
    vector<ll> mas;
    simple_nums()
    {
        vector<bool> used (N, false);
        forjn (2, N) {
            if (used[j] == false) {
                mas.push_back (j);
                forins (j + j, N, j) {
                    used[i] = true;
                }
            }
        }
    }
};


struct matr_2x2 {
    ll mas[4];

    matr_2x2 (int a)
    {
        if (a == 1) {
            mas[0] = 1, mas[1] = 1, mas[2] = 1, mas[3] = 0;
        }
    }

    matr_2x2 umnoj (const matr_2x2 &b, ll p)
    {
        matr_2x2 ans (1);
        ans.mas[0] = (mas[0] * b.mas[0] + mas[1] * b.mas[2]) % p,
                     ans.mas[1] = (mas[0] * b.mas[1] + mas[1] * b.mas[3]) % p,
                                  ans.mas[2] = (mas[2] * b.mas[0] + mas[3] * b.mas[2]) % p,
                                               ans.mas[3] = (mas[2] * b.mas[1] + mas[3] * b.mas[3]) % p;
        //        mas[0] = k1, mas[1] = k2, mas[2] = k3, mas[3] = k4;
        return ans;
    }
};

struct matr_1x2 {
    ll mas[2];
    matr_1x2()
    {
        mas[0] = 0, mas[1] = 0;
    }
    matr_1x2 (ll a, ll b)
    {
        mas[0] = a, mas[1] = b;
    }

    matr_1x2 umnoj (const matr_2x2 &b, ll p)
    {
        matr_1x2 ans;
        ans.mas[0] = (mas[0] * b.mas[0] + mas[1] * b.mas[2])  % p,
                     ans.mas[1] = (mas[0] * b.mas[1] + mas[1] * b.mas[3])  % p;
        //        mas[0] = k1, mas[1] = k2;
        return ans;
    }

};



template<typename T>
T bin_pow (T a, int k, ll p)
{
    T ans (1);
    T st = a;
    if (k == 1) return ans;
    while (k != 0) {
        if (k % 2) ans = ans.umnoj (st, p);
        st = st.umnoj (st, p);
        k /= 2;
    }
    return ans;
}

template<int D>
vector<ll> simple_numbers (ll n)
{
    vector<ll> ans;
    vector<bool> used (n, false);
    forjn (2, n) {
        if (used[j] == false) {
            ans.push_back (j);
            forins (j + j, n, j) {
                used[i] = true;
            }
        }
    }
    return ans;
}

template <class T, class X>
ll bin_search_upper (const vector<X> &mas, T n)
{
    ll left = 0;
    ll right = mas.size() - 1;
    while (left < right) {
        ll middle = (left + right) / 2;
        if (mas[middle] < n) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return left;
}

template <class T, class X>
ll bin_search_lower (const vector<X> &mas, T n)
{
    ll left = 0;
    ll right = mas.size() - 1;
    while (left < right) {
        ll middle = (left + right) / 2. + 0.5;
        if (mas[middle] > n) {
            right = middle - 1;
        } else {
            left = middle;
        }
    }
    return left;
}
template <class L, class V>
//V - вершина, L - расстояние
L Dijkstra (vector<vector<pair<V, L>>> &matrix, V start, V finish)
{
    int n = matrix.size();
    vector<L> lengths (n, INF),  p (n);
    lengths[start] = 0;
    set < pair<V, L> > mas;
    mas.insert (make_pair (lengths[start], start));
    while (!mas.empty()) {
        V v = mas.begin()->second;
        L len = mas.begin()->first;
        mas.erase (mas.begin());
        if (len > lengths[v]) continue;
        forin (0, matrix[v].size()) {
            V n_v = matrix[v][i].first;
            L n_len = len + matrix[v][n_v];
            if (lengths[n_v] > n_len) {
                mas.erase (make_pair (lengths[n_v], n_v));
                lengths[n_v] = n_len;
                mas.insert (make_pair (n_len, n_v));
            }
        }
    }
    return lengths[finish];
};

void change_line (string &str, ll left, ll right)
{
    forin (0, (left + right) / 2 + 1 - left) {
        swap (str[left + i], str[right - i]);
    }
}

ll gcd (ll a, ll b)
{
    return b ? gcd (b, a % b) : a;
}

void solve()
{
    ll p;
    cin >> p;
    ll ans = (p == 2) ? 3 : 20;
    if (p == 2 || p == 5) {
        cout << ans << "\n";
        return;
    }
    ul last = 1, prev = 0;
    ll k = 0;
    if (p % 5 == 2 || p % 5 == 3)
        k = 2 * p + 2;
    else k = p - 1;
    ans = k;
    set<ll> mnoj;
    forin (2, sqrt (k) + 1) {
        if (k % i == 0) {
            mnoj.insert (i);
            mnoj.insert (k / i);
        }
    }
    matr_1x2 start (0, 1);
    for (auto i : mnoj) {
        auto x = bin_pow (matr_2x2 (1), i - 1, p);
        matr_1x2 fib = start.umnoj (x, p);
        if (fib.mas[0] == 0 && fib.mas[1] == 1) {
            ans = i;
            break;
        }
    }
    cout << ans << "\n";
}



int main()
{
    //    speed;
    ll t = 1;
    //    cin >> t;
    while (t-- > 0) {
        solve();
        //        break;
    }
    return 0;
}
