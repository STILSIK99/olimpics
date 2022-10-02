#include <bits/stdc++.h>
using namespace std;

bool check_name(const string &name_1, const string &name_2, int it_1, int it_2, bool mistake){
    while (it_1 < name_1.size() && it_2 < name_2.size()){
        if (name_1[it_1] == name_2[it_2]) {
            ++it_1, ++it_2;
            continue;
        }
        else{
            if (mistake) return false;
            return check_name(name_1, name_2, it_1 + 1, it_2, true) ||
                    check_name(name_1, name_2, it_1 + 1, it_2 + 1, true) ||
                    check_name(name_1, name_2, it_1, it_2 + 1, true);
        }
    }
    if (it_1 == name_1.size() && it_2 == name_2.size()) return true;
    else{
        if (mistake || max(name_1.size() - it_1, name_2.size() - it_2) > 1) return false;
    }
    return true;
}

bool getResult(int calendar, int dateOfBirth, string name,
    vector<string>phrases) {
    int years = calendar - dateOfBirth;
    int old = stoi(phrases[0]);
    if (years - old < 0 || years - old > 1)
        return false;
    return check_name(name, phrases[1], 0, 0, false);
};

//int main() {
//    cout << getResult(1984, 1950, "Anna", vector<string>{"32","Ana"});
//    return 0;
//}

