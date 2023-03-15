#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int val;
    node *next = NULL;
    node(int v = 0)
    {
        val = v;
    }
};

int main()
{

    int s;
    cout << "enter the no of nodes ";
    cin >> s;
    vector<node> g(s, node());
    for (int i = 0; i < s; i++)
    {
        int n;
        cout << "enter the no nodes which are connected to node " << i + 1;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cout << "node no " << j + 1;
            int x;
            cin >> x;
            node *cur;
            cur = &g[i];
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new node(x);
        }
    }

    for (node i : g)
    {
        node *cur = &i;

        while (cur->next != NULL)

        {
            cur = cur->next;
            cout << cur->val << ' ';
        }
        cout << '\n';
    }

    return 0;
}