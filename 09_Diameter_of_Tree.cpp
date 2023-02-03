#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findMax(TreeNode* node, int &maxi) {
    if(node == NULL) return 0;

    int lh = findMax(node -> left, maxi);
    int rh = findMax(node -> right, maxi);

    maxi = max(maxi, lh+rh);

    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    findMax(root, diameter);
    return diameter;
}

int main() {
    
}