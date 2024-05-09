/*
设计思想：
采用结构模拟树，从根节点开始递归遍历，每往下一层加入该节点的权重，若遇到叶子节点则推出本次遍历，计算该节点的路径，最后将每个叶子节点的权重相加得到树的WPL值。
*/
// 树的定义
struct TreeNode
{
    TreeNode *left;
    int weight;
    TreeNode *right;
    TreeNode(TreeNode *l, int w, TreeNode *r) : left(l), weight(w), right(r) {}
};

// WPL递归函数
int WPL(TreeNode *root, int depth)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return root->weight * depth;
    return WPL(root->left, depth + 1) + WPL(root->right, depth + 1);
}
