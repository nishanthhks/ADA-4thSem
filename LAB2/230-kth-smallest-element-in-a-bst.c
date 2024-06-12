#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int count = 0, result = -1;

void inorder(struct TreeNode* root, int k) {
    if (root == NULL || count >= k) return;
    inorder(root->left, k);
    count++;
    if (count == k) {
        result = root->val;
        return;
    }
    inorder(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k) {
    count = 0; 
    result = -1; 
    inorder(root, k);
    return result;
}