#include <algorithm>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

/**
 * Implement function getResult
 */

vector <int> getResult (vector<int> cash, int k)
{
    multiset<int> mas (cash.begin(), cash.end());
    set<int> ans;
    ans.insert(1 + distance (cash.begin(), max_element (cash.begin(), cash.end())));
    k = min (k, *mas.rbegin());
    mas.insert (* (--mas.end()) - k);
    mas.erase (--mas.end());
    // if (cash.size() == 1) ;
    int n_max = *mas.rbegin();

    for (int i = 0; i < cash.size(); ++i)
        if ((cash[i] + k) > n_max)
            ans.insert (i + 1);

    return vector<int>(ans.begin(), ans.end());
}


void runCode()
{
    // Entrypoint to debug your function
}