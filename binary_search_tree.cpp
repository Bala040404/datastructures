#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;

    node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class bst
{
public:
    node *root = NULL;
    void insert(int val)
    {
        node *n = new node(val);
        if (root == NULL)
        {
            root = n;
        }
        else
        {
            node *cur = root;
            node *prev = NULL;
            while (cur != NULL)
            {
                if (cur->value > val)
                {
                    prev = cur;
                    cur = cur->left;
                }
                else if (cur->value < val)
                {
                    prev = cur;
                    cur = cur->right;
                }
                else
                {
                    return;
                }
            }
            if (prev->value > val)
            {
                prev->left = n;
            }
            else if (prev->value < val)
            {
                prev->right = n;
            }
        }
    }

    void inorder(node *r)
    {
        if (r != NULL)
        {
            inorder(r->left);
            cout << r->value << "\n";
            inorder(r->right);
        }
    }

    // void insert(int value, node *hd, node *prev = NULL)
    // {

    //     node *cur = hd;
    //     if (cur != NULL)
    //     {
    //         if (cur->value < value)
    //         {
    //             insert(value, cur->right, cur);
    //         }
    //         else if (cur->value > value)
    //         {
    //             insert(value, cur->left, cur);
    //         }
    //     }

    //     else
    //     {
    //         node *x = new node(value);

    //         if (root == NULL)
    //         {
    //             root = x;
    //         }
    //         else
    //         {
    //             if (prev->value > value)
    //             {
    //                 prev->left = x;
    //             }

    //             else if (prev->value < value)
    //             {
    //                 prev->right = x;
    //             }
    //         }
    //     }
    // }
};

int main()
{
    bst b;
    b.insert(5);
    b.insert(4);
    b.insert(6);
    b.insert(7);
    b.insert(8);
    b.insert(9);
    b.insert(1);
    b.insert(3);
    b.inorder(b.root);
    return 0;
}