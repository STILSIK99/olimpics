#include <bits/stdc++.h>

using namespace std;

int getResult(vector<int> a, vector<int> b){
    int i = 0;
    int ans = 0;
    map<int, int> place;
    for (int i = 0; i < b.size(); ++i) place[b[i]] = i;
    while (i < a.size()){
        if (i == place[a[i]]) ++i;
        else{
            ++ans;
            int l = b[i], n = a[i];
            swap(b[i],b[place[a[i]]]);
            place[l] = place[n];
            place[n] = i;
        }
    }
    return ans;
}

int main()
{
    cout << getResult(vector<int>{1, 2, 3, 4, 5, 6, 7}, vector<int>{3, 4 ,5 ,6 ,7 , 2, 1});
    return 0;
}
