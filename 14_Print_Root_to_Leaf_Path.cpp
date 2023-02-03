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

bool isLeaf(TreeNode * root) {
    return (root->left == NULL && root->right == NULL);
}

void rootToLeafPaths(TreeNode * root, vector<vector<int>>& paths, vector<int>& pathSoFar) {
    if (root == NULL) {
        return;
    }
    pathSoFar.push_back(root->val);
    if (isLeaf(root)) {
        paths.push_back(pathSoFar);
    } else {
        rootToLeafPaths(root->left, paths, pathSoFar);
        rootToLeafPaths(root->right, paths, pathSoFar);
    }
    // backtracking step
    pathSoFar.pop_back();
}

vector<vector<int>> rootToLeafPaths(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    vector<vector<int>> paths;
    vector<int> pathSoFar;

    rootToLeafPaths(root, paths, pathSoFar);
    return paths;
}