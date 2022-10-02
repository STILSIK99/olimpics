#include <bits/stdc++.h>
using namespace std;

int getResult(vector<int> passerby){
    sort(passerby.begin(), passerby.end());
    int l = 0, r = passerby.size() - 1;
    int cash = 0;
    while(l < r){
        if (passerby[l] >= passerby[r]) break;
        cash += (passerby[r--] - passerby[l++]);
    }
    return cash;
}


int main(){
    cout << getResult(vector<int> {5, 12, 6});
    return 0;
}
