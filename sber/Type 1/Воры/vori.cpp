#include "bits/stdc++.h"

using namespace std;

vector <int> getResult(vector<int> cash,int k){
    multiset<int> mas(cash.begin(), cash.end());
    vector<int> ans;
    auto it = --mas.end();
    int mmax = *it;
    k = min(k, *it);
    if (*it == 0) return ans;
    mas.insert(*it - min(*it, k));
    mas.erase(it);
    for (int i = 0; i < cash.size(); ++i)
        if(mas.lower_bound(cash[i] + k) == mas.end()) ans.push_back(i+1);
    if (*(--(--mas.end())) == 0){
        for(int i = 0; i < cash.size(); ++i)
            if (cash[i] == mmax){
                ans.push_back(i + 1);
                break;
            }
    }
    return ans;
}

//int main(){
//    vector<int> cash = {4, 3, 4, 8};
//    int k = 2;
//    for(auto x : getResult(cash, k)) cout << x << " ";
//    return 0;
//}
