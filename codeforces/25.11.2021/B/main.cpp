/*----------------------------*|     written by STILSIK       |
*----------------------------*/
#include <bits/stdc++.h>

using  namespace std;

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

template<typename T>
T bin_pow (T a, int k)
{
    T ans (1);
    T st = a;
    if (k == 1) return ans;
    while (k != 0) {
        if (k % 2) ans = ans * st;
        st = st * st;
        k /= 2;
    }
    return ans;
}

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

int solve (ll a, ll b)
{
    //    ll a, b;
    //    cin >> a >> b;
    return min (a, min (b, (a + b) / 4));
}

int lox (ll n, ll m)
{
    ll t = 0;
    //            cin >> n >> m;
    while (n > 0 && m > 0 && n + m > 3) {
        if (n > m * 3) {
            t = m;
            break;
        }
        if (m > n * 3) {
            t = n;
            break;
        }
        if (n - m == 1 || m - n == 1) {
            if (n < m) {
                t += n / 2;
                break;
            } else {
                t += m / 2;
                break;
            }
        }
        if (n > m) {
            if (n - m > 1) {
                int q = (n - m) / 2;
                n -= q * 3;
                m -= q;
                t += q;
                continue;
            }
            n -= 3;
            m--;
            t++;
            continue;
        } else if (m > n && m > 2) {
            if (m - n > 1) {
                int q = (m - n) / 2;
                m -= q * 3;
                n -= q;
                t += q;
                continue;
            }
            m -= 3;
            n--;
            t++;
            continue;
        } else if (n == m) {
            t += n / 2;
            n %= 2;
            m %= 2;
            break;
        }
    }
    return t;
}


int main()
{
    //    speed;
    ll t = 1;
    //    cin >> t;
    forin (0, 1e4) {
        forjn (0, 1e4) {
            ll a = rand() % 1000000000,
               b = rand() % 1000000000;
            if (lox (a, b) != solve (a, b)) {
                cout << a << " " << b << "\n";
            }
        }
    }
    cout << "stop";

    return 0;
}
