#include <bits/stdc++.h>
using namespace std;


int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
    return max(left,right)+1;
    }
}


void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void reverseLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++) 
        printGivenLevel(root, i);
}

