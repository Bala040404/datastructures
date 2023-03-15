#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *left;
    node *right;
    int height = 1;
    node(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }
};

class avl
{
public:
    node *rightrotate(node *root)
    {
        node *x = root->left->right;
        node *y = root->left;
        y->right = root;
        root->left = x;
        root->height = 1 + max(height(root->left), height(root->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    node *leftrotate(node *root)
    {
        node *y = root->right;
        node *x = root->right->left;
        y->left = root;
        root->right = x;
        root->height = 1 + max(height(root->left), height(root->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    node *insert(node *root, int value)
    {
        if (root == NULL)
        {

            root = new node(value);
        }
        else
        {
            if (root->value > value)
            {

                root->left = insert(root->left, value);
            }
            else if (root->value < value)
            {

                root->right = insert(root->right, value);
            }

            root->height = max(height(root->left), height(root->right)) + 1;
        }

        int bf = balancefactor(root);
        if ((bf > 1) && (root->left->value > value))
        {
            return rightrotate(root);
        }
        else if ((bf < -1) && (root->right->value < value))
        {
            return leftrotate(root);
        }

        else if ((bf > 1) && (root->left->value < value))
        {
            root->left = leftrotate(root->left);
            return rightrotate(root);
        }

        else if ((bf < -1) && (root->right->value > value))
        {
            root->right = rightrotate(root->right);
            return leftrotate(root);
        }
        return root;
    }

    void preorder(node *root)
    {
        if (root != NULL)
        {
            cout << root->value << "\n";
            preorder(root->left);
            preorder(root->right);
        }
    }

    int height(node *n)
    {
        if (n == NULL)
        {
            return 0;
        }
        else
        {
            return n->height;
        }
    }

    int balancefactor(node *root)
    {
        return height(root->left) - height(root->right);
    }
};

int main()
{

    node *root = NULL;
    avl a = avl();
    root = a.insert(root, 10);
    root = a.insert(root, 20);
    root = a.insert(root, 30);
    root = a.insert(root, 40);
    root = a.insert(root, 50);
    root = a.insert(root, 25);
    // root = a.insert(root, 7);
    // root = a.insert(root, 6);
    // cout << root->value;
    // cout << root->left->value;
    // cout << root->left->left->value;
    a.preorder(root);

    return 0;
}
