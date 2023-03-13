// just a function
int depthOfANode(TreeNode *root, TreeNode *cur)
{
    if (root == NULL || cur == NULL)
        return -1;
    if (root == cur)
        return 0;
    int l_val = depthOfANode(root->left, cur);
    int r_val = depthOfANode(root->right, cur);
    if (l_val == r_val) // both ==-1
        return -1;
    else
        return 1 + max(l_val, r_val);
}