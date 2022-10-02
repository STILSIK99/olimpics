#include <bits/stdc++.h>
using namespace std;

bool getResult(vector<int> arr, int w){
    int sum = 0;
    for (auto x : arr) sum += x;
    multiset<int> m(arr.begin(), arr.end());
    int iters = 0;
    while (true){
        auto it = *(--m.end());
        m.erase(--m.end());
        if (iters >= it) break;
        sum -= (it - it / 2);
        m.insert(it / 2);
    }
    if (sum > w) return false;
    return true;
}


int main(){
    cout << getResult(vector<int>{2,3,4,5,6,7,9}, 9);
    //    set<int> m{2,3,4,5,6,7,9};
    return 0;
}
