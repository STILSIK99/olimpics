/*------------------------------
     written by STILSIK        |
--------------------------------*/
#include <bits/stdc++.h>

using  namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> v_ll;
typedef vector<int> v_i;
typedef vector<v_i> vv_i;
typedef vector<string> v_s;
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

bool check (const v_s &strings, const v_i &mas_id)
{
    bool br = false;
    forin (0, strings.size()) {
        if (mas_id[i] >= strings[i].size()) {
            br = true;
            break;
        }
    }
    return br;
}

string lcs_ans (const v_s &mas)
{
    string ans = "";
    forin (0, mas.size()) {
        if (ans.size() < mas[i].size()) ans = mas[i];
    }
    return ans;
}

void change_masses (v_i &used, int simbol, v_s &strings, vector<vv_i> &matr, v_i &mas_id)
{
    //возвращем индексы от прошлого изменения
    forjn (0, used.size()) --mas_id[used[j]];
    //чистим использованные
    used.clear();
    //изменяем новые
    forjn (0, strings.size()) {
        if (strings[j][mas_id[j]] - 65 != simbol) {
            used.pb (j);
            ++mas_id[j];
        };
    }
};

string lcs (v_s &strings, vector<vv_i> &matr, v_i &mas_id)
{
    vector<string> answers;
    string ans = "";
    while (true) {
        if (check (strings, mas_id)) break;
        set<p_ii> set_sdvigs;
        map<char, int> next_sdvig;
        v_i anss;
        ll min_sdvig (1e9);
        forin (0, strings.size()) {
            ll max_sdv = -1;
            char ssimb = strings[i][mas_id[i]] - 65;
            forjn (0, strings.size()) {
                //если текущий символ равен искомому, то мы ищем ближайший следующий
                if (strings[i][mas_id[i]] == strings[j][mas_id[j]]) {
                    int next_simb = matr[i][ssimb].back();
                    if (next_sdvig.count (ssimb) == 0) {
                        if (next_simb != mas_id[i])
                            next_sdvig[ssimb] = next_simb;
                        else {
                            next_sdvig[ssimb] = -1;
                        }
                    } else {
                        if (next_sdvig[ssimb] != -1 && next_simb != mas_id[i])
                            next_sdvig[ssimb] = max (next_simb, next_sdvig[ssimb]);
                    }
                    max_sdv = max (max_sdv, 0ll);
                    continue;
                };
                ll sdv = -1;
                for (int k (0); k < matr[j][ssimb].size(); ++k) {
                    sdv = matr[j][ssimb][k] - mas_id[j];
                    if (sdv >= 0) break;
                }
                if (sdv < 0) {
                    max_sdv = -1;
                    break;
                }
                max_sdv = max (max_sdv, sdv);
                if (max_sdv == 0) {
                    break;
                }
            }
            if (max_sdv != -1) {
                set_sdvigs.insert (mp (max_sdv, ssimb));
                min_sdvig = min (max_sdv, min_sdvig);
            }
            if (min_sdvig == 0) break;

        }
        if (min_sdvig == 0) {
            //добавить символ в ответ
            ans += strings[0][mas_id[0]];
            forjn (0, mas_id.size()) ++mas_id[j];
            continue;
        }
        int max_next = -1;
        char next_sdv;
        //проверяем количество ветвей
        forina (set_sdvigs.begin(), set_sdvigs.end()) {
            if (set_sdvigs.begin()->first == i->first)
                if (next_sdvig[i->second] == -1) {
                    anss.pb (i->second);
                    break;
                } else {
                    if (max_next < next_sdvig[i->second]) {
                        next_sdv = i->second;
                        max_next = next_sdvig[i->second];
                    }
                }
        }
        if (anss.size() == 0) anss.pb (next_sdv);
        //явный ответ
        forin (0, mas_id.size()) if (strings[i][mas_id[i]] != anss[0] + 65) ++mas_id[i];
    }
    return ans;
}

void solve()
{
    ll len;
    cin >> len;
    //считываем все строки и превращаем их в матрицу
    v_s mas (len);
    v_i mas_id (len, 0);
    vector<vv_i> matr (len, vv_i (58, v_i()));
    forin (0, len) {
        cin >> mas[i];
        forjn (0, mas[i].size()) matr[i][mas[i][j] - 65].pb (j);
    }
    string ans = lcs (mas, matr, mas_id);
    cout << ans.size() << "\n";
    if (ans.size() != 0)
        cout << ans << "\n";
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
