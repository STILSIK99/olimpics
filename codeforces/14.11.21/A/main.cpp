/*------------------------------
     written by STILSIK        |
--------------------------------*/
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
#define pb push_back
#define mp make_pair

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

vector<string> nop (string a, string b, string cur)
{
    vector< vector<int> > simb_a (256, vector<int>()), simb_b (256, vector<int>());
    forin (0, a.size()) {
        simb_a[a[i]].pb (i);
    }
    forin (0, b.size()) {
        simb_b[b[i]].pb (i);
    }
    ll ind_a = 0, ind_b = 0;
    //множество решений
    vector<string> anss (2 * min (a.size(), b.size()), "");
    ll ans_count = 0;
    string ans = "";
    while (true) {
        //условие выхода из цикла
        if (ind_a == a.size() || ind_b == b.size()) break;
        //если символы под указателями равны, то сдвигаемся
        if (a[ind_a] == b[ind_b]) {
            ans += a[ind_a];
            ++ind_a, ++ ind_b;
            continue;
        }
        ll delta_a = -1, delta_b = -1;
        //проверяем есть ли в слове а символ из слова б
        if (simb_a[b[ind_b]].size() != 0) {
            //если есть, то смотрим по индексу, чтобы не превосходил указатель по слову а
            ll ind = simb_a[b[ind_b]][bin_search_upper (simb_a[b[ind_b]], ind_a)];
            if (b[ind_b] == a[ind] && ind > ind_a)
                //получаем расстояние от ind_a  до символа b[ind_b] в слове a
                delta_a = ind - ind_a;
        }
        //если дельту не рассчитали, то сдвигаем указатель по слову б
        if (delta_a == -1) {
            ++ind_b;
            continue;
        }

        //аналогично по со словом б по символу a[ind_a]
        if (simb_b[a[ind_a]].size() != 0) {
            ll ind = simb_b[a[ind_a]][bin_search_upper (simb_b[a[ind_a]], ind_b)];
            if (b[ind] == a[ind_a] && ind > ind_b)
                delta_b = ind - ind_b;
        }
        if (delta_b == -1) {
            ++ind_a;
            continue;
        }

        //если перемещение по слову a больше перемещению по б, то
        //сдвигаем указатель по слову б (то есть символ из слова б дальше)
        if (delta_a > delta_b) ++ind_b;
        //иначе по слову а (то есть символ из слова а дальше )
        if (delta_a < delta_b) ++ind_a;
        //если дельты равны, то получается разветвление решений
        if (delta_a == delta_b) {
            //сдвигаем по слову а и получаем список ветвей одного решения
            for (string str : nop (a.substr (ind_a + 1, a.size() - ind_a - 1), b.substr (ind_b, b.size() - ind_b), "")) {
                //конкатенируем ответы и добавляем в итоговый список
                anss[ans_count++] = ans + str;
            };
            //аналогично другой ветви
            //сдвигаем по слову б
            for (string str : nop (a.substr (ind_a, a.size() - ind_a), b.substr (ind_b + 1, b.size() - ind_b - 1), "")) {
                anss[ans_count++] = ans + str;
            };
            //все решения получены путем рекурсии
            return anss;
            //поэтому вызовем функцию рекурсивно, от разных вариантов
            //потом полученные рекурсивно ответы конкатенируем с полученными
        }
    }
    if (ans.size() != 0)
        anss[ans_count++] = (ans);
    return anss;
}

bool cmp_len_str (const string &a, const string &b)
{
    return (a.size() < b.size()) || (a.size() == b.size() && a < b);
}

void solve()
{
    ll len;
    cin >> len;
    set<string, function<bool (const string &, const string &)>> mas_str (cmp_len_str);
    forin (0, len) {
        string x;
        cin >> x;
        mas_str.insert (x);
    }
    if (mas_str.size() == 1) {
        cout << mas_str.begin()->size() << "\n";
        if (mas_str.begin()->size())
            cout << * (mas_str.begin()) << "\n";
        return;
    }
    auto it = mas_str.begin();
    set<string> *mas_ans = new set<string> (nop (* (++it), *mas_str.begin(), ""));
    forin (2, mas_str.size()) {
        //перебираем считанные строки
        ++it;
        //для каждого полученного решения из nop получаем новый список ответов
        set<string> *next_ans = new set<string>;
        for (auto str : *mas_ans) {
            //получаем НОП для совокупности с учетом новой строки
            for (auto sstr : nop (*it, str, "")) {
                next_ans->insert (sstr);
            }
        }
        //перезаписываем mas_ans
        delete mas_ans;
        mas_ans = next_ans;
    }
    //после всех операций выводим ответ максимальной длины
    ll size = 0;
    string ans = "";
    for (auto str : *mas_ans) {
        if (str.size() > size) {
            size = str.size();
            ans = str;
        }
    }
    cout << size << "\n";
    if (size)
        cout << ans << "\n";
    delete mas_ans;
}

int main()
{
    //    speed;
    ll t = 1;
    cin >> t;
    while (t-- > 0) {
        solve();
        //        break;
    }
    return 0;
}
