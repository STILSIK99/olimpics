#include <bits/stdc++.h>
using namespace std;

int recur(string a, int it_a, string b, int it_b, int k, int len){
    if (it_a == a.size() || it_b == b.size()) return len;
    if (a[it_a] == b[it_b]) return recur(a,it_a + 1, b, it_b + 1, k, len + 1);
    int ans1 =  0, ans2 = 0;
    int step = a.substr(it_a, a.length() - it_a).find_first_of(b[it_b]);
    if (step != -1 && (k - step) >= 0)
        ans2 = recur(a, it_a + step, b, it_b, k - step, len);
    ans1 = recur(a, it_a + 1, b, it_b + 1, k, len + ((a[it_a] == b[it_b]) ? 1 : 0));
    return max(ans1, ans2);
}


int getResult (string s, int k, string stringGoal){
    return recur(s, 0, stringGoal, 0, k, 0);
}

//int main(){
//    cout << getResult("acegh", 4, "bdfjh");
//    return 0;
//}
