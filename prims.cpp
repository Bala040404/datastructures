#include <bits/stdc++.h>

using namespace std;

int getMin(vector<int> v, vector<bool> is)
{
    int min = 1e6;
    int ver;
    for (int i = 0; i < v.size(); i++)
    {
        if ((v[i] < min) && (is[i] == false))
        {

            min = v[i];
            ver = i;
        }
    }
    return ver;
}

int main()
{

    cout << "enter no of nodes";
    int n;
    cin >> n;

    vector<int> value(n, 1e5);
    value[0] = 0;
    vector<bool> isSet(n, false);
    vector<int> parent(n, -1);

    vector<vector<int>> g(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        int n;
        cout << "enter the  no of nodes to which node " << i << " is connected";
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int x;
            int wt;
            cout << "enter node no amd wt " << j;
            cin >> x >> wt;

            g[i][x] = wt;
        }
    }

    for (int l = 0; l < n - 1; l++)
    {
        int cur = getMin(value, isSet);
        isSet[cur] = true;
        for (int i = 0; i < n; i++)
        {
            if ((g[cur][i] != 0) && (g[cur][i] < value[i]) && (isSet[i] == false))
            {
                value[i] = g[cur][i];
                parent[i] = cur;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << "->" << i << " wt " << g[parent[i]][i] << "\n";
    }

    return 0;
}