/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// morris traversal //just function
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> sol;
        TreeNode *current = root;
        while (current)
        {
            if (!current->left)
            {
                sol.push_back(current->val);
                current = current->right;
            }
            else
            {
                TreeNode *p = current->left;
                while (p->right && p->right != current)
                    p = p->right;
                if (!p->right)
                {
                    p->right = current;
                    current = current->left;
                }
                else
                {
                    p->right = NULL;
                    sol.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return sol;
    }
};
/*
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        inorder(root,sol);
        return sol;
    }
    void inorder(TreeNode* root,vector<int> &sol)
    {
        if (root)
        {
            inorder(root->left,sol);
            sol.push_back(root->val);
            inorder(root->right,sol);
        }
        else
        {
            return;
        }
    }
};
*/