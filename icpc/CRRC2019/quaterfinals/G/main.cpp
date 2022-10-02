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

int vars;

struct Node {
    vector<char> times;
    map<char, bool> changes;
    char step;
    Node *parent;
    char next_t;
    short cur_t;
    Node () {};
};

bool next_childs (Node *par, vector<char> &noms, vector<Node *> &qq, short &finish)
{
    auto f = par->times;
    forin (0, f.size()) f[i] = min (0, f[i] - par->next_t);
    ll size = qq.size();
    forin (0, vars) {
        Node *k = new Node();
        k->times = f;
        char kk = 1;
        char next_t = 50;
        //генерируем новое состояние постановки часов
        forjn (0, k->times.size()) {
            if ((i & kk) != 0) {
                k->times[j] = noms[j] - k->times[j];
                k->changes[j] = 1;
            }
            //времени до следующего шага
            if (k->times[j] != 0)
                next_t = min (next_t, k->times[j]);
            kk <<= 1;
        }
        //если все часы на нулях
        //        cout << (next_t == 50) << " " << (par->cur_t + par->next_t > finish) << "\n";
        if (next_t == 50 || par->cur_t + par->next_t > finish) continue;
        k->next_t = next_t;
        k->step = par->step + 1;
        k->cur_t = par->cur_t + par->next_t;
        k->parent = par;
        cout << k->cur_t << " - cur_t| step - " << k->step << "\n";
        //найден ответ
        if (k->cur_t == finish) {
            return false;
        }
        qq.push_back (k);
    }
    return true;
}


void solve()
{
    ll n;
    cin >> n;
    vector<char> noms (n); //номиналы часов
    vars = bin_pow (2, n);
    forin (0, n) {
        cin >> noms[i];
        noms[i] -= 48;
    }
    short finish;
    cin >> finish;

    Node *start = new Node();
    start->cur_t = 0;
    start->times = vector<char> (n, 0);
    start->next_t = 0;
    start->step = 0;

    vector<Node *> qq (1, start);
    int start_qq = 0;
    while (start_qq != qq.size()) {
        if (!next_childs (qq[start_qq], noms, qq, finish)) break;
        ++start_qq;
    };

    if (qq[qq.size() - 1]->cur_t + qq[qq.size() - 1]->next_t != finish) cout << -1;
    else {
        Node *next = qq.back();
        vector<int> ans_t (qq.back()->step + 1, 0);
        vector<Node *> ans (qq.back()->step + 1);
        while (true) {
            ans[next->step] = next;
            ans_t[next->step] = next->next_t;
            if (next->step == 0) break;
            next = next->parent;
        }
        forin (0, ans_t.size()) cout << ans_t[i] << " ";
        cout << "\n";
        forin (0, ans.size()) {
            cout << ans[i]->cur_t << " " << ans[i]->changes.size() << " ";
            for (auto x : ans[i]->changes) cout << x.first << " ";
            cout << "\n";
        }
    }
    forni (qq.size() - 1, 0) {
        delete qq[i];
    }

}



int main()
{
    //    speed;
    ll t = 1;
    //    cin >> t;
    while (t-- > 0) {
        solve();
        break;
    }
    return 0;
}
