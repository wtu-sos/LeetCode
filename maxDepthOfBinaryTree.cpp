//ven a binary tree, find its maximum depth.
//
//The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//
//Subscribe to see which companies asked this question
//
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */



class Solution {
	public:
	int maxDepth(TreeNode* root) {
		int maxLv = 0;
		NtreeTravesal(root, maxLv, 1);
		return maxLv;
	}
	void NtreeTravesal(TreeNode* node, int& num, int lv) {
		if (NULL == node)
		{
			return;
		}
		if (num < lv)
			num = lv;

		NtreeTravesal(node->left, num, lv+1);
		NtreeTravesal(node->right, num, lv+1);
	}
};
