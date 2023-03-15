#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5;

vector<int> parent(inf);
vector<int> sizze(inf);

void make(int node)
{
    parent[node] = node;
    sizze[node] = 1;
}

int find(int node)
{
    if (node == parent[node])
    {
        return node;
    }
    else
    {
        return parent[node] = find(parent[node]);
    }
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sizze[a] < sizze[b])
        {
            swap(a, b);
        }
        parent[b] = parent[a];
        sizze[a] = sizze[a] + sizze[b];
        sizze[b] = 0;
    }
}

int main()
{

    set<pair<int, pair<int, int>>> g;
    set<pair<int, pair<int, int>>> ans;
    int n;
    cout << "enter the no of nodes";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        make(x);
    }
    int e;
    cout << "enter the no of edges";

    cin >> e;

    for (int j = 0; j < e; j++)
    {
        int wt, a, b;
        cout << "enter the weight of the edge and the nodes connected by edge no " << j + 1;
        cin >> wt >> a >> b;
        g.insert({wt, {a, b}});
    }

    int cost = 0;
    for (auto node : g)
    {

        if (find(node.second.first) == find(node.second.second))
            continue;

        Union(node.second.first, node.second.second);
        cout << node.second.first << " and " << node.second.second << " is connected by a edge of wt " << node.first << "\n";
        cost += node.first;
    }
}