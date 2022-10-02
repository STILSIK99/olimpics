#include <bits/stdc++.h>
using namespace std;

int check_xo (vector<string> &pole)
{
    if (pole[0] == "XXX" || pole[1] == "XXX" || pole[2] == "XXX" ||
        (pole[0][0] == 'X' && pole[1][1] == 'X' && pole[2][2] == 'X') ||
        (pole[2][0] == 'X' && pole[1][1] == 'X' && pole[0][2] == 'X') ||
        (pole[0][0] == 'X' && pole[1][0] == 'X' && pole[2][0] == 'X') ||
        (pole[0][0] == 'X' && pole[1][1] == 'X' && pole[2][2] == 'X') ||
        (pole[0][2] == 'X' && pole[1][2] == 'X' && pole[2][2] == 'X')) {
        return 1;
    }
    if (pole[0] == "OOO" || pole[1] == "OOO" || pole[2] == "OOO" ||
        (pole[0][0] == 'O' && pole[1][1] == 'O' && pole[2][2] == 'O') ||
        (pole[2][0] == 'O' && pole[1][1] == 'O' && pole[0][2] == 'O') ||
        (pole[0][0] == 'O' && pole[1][0] == 'O' && pole[2][0] == 'O') ||
        (pole[0][0] == 'O' && pole[1][1] == 'O' && pole[2][2] == 'O') ||
        (pole[0][2] == 'O' && pole[1][2] == 'O' && pole[2][2] == 'O')) {
        return 2;
    }
    return 0;
}



void task1()
{

}


void task2()
{
    vector<string> game (3, "   ");
    string g = "XO";
    int i = 0;
    int s;
    for (int i = 0; i < 9; ++i) {
        s = check_xo (game);
        if (s != 0) break;
        cout << "Input col and row of " << g[i % 2]  <<  ": ";
        int col, row;
        cin >> col >> row;
        if (col < 0 || col > 2 || row < 0 || row > 2 || game[row][col] != ' ') {
            --i;
            continue;
        }
        game[row][col] = g[i % 2];
        cout << "-----\n";
        for (auto x : game)
            cout << x << "\n";
        cout << "-----\n";
    }
    if (s == 0) cout << "Nobody\n";
    if (s == 1) cout << "X won\n";
    if (s == 2) cout << "0 won\n";
}

void task3()
{
    int mas[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            mas[i][j] = (i + i % 2) * 5 - (i % 2) + j * int (pow (-1, i % 2));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j)
            cout << mas[i][j] << " ";
        cout << "\n";
    }
}

bool cmpMatrix (int a[4][4], int b[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (a[i][j] != b[i][j]) return false;
    return true;
}

void task4()
{
    int a[4][4];
    int b[4][4];
    cout << "Input first matrix:\n";
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> a[i][j];
    cout << "Input second matrix:\n";
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> b[i][j];
    if (cmpMatrix (a, b)) {
        cout << "Equalent\n";
    } else cout << "Different\n";
}


void task5()
{
    float m[4][4];
    cout << "Input matrix M:\n";
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> m[i][j];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (i != j) m[i][j] = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}

void task6()
{

}

int main()
{


    task5();


    return 0;
}
