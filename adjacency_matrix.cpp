#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "enter no of nodes";
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int n;
        cout << "enter the  no of nodes to which node " << i + 1 << " is connected";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            cout << "enter node no  " << j + 1;
            cin >> x;
            v[i][x - 1] = 1;
        }
    }

    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}
