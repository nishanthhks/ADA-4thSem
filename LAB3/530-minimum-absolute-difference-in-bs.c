#include <limits.h>
#include <stddef.h> // Add this line to include the necessary header file for 'NULL'

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int arr[100000];
int j = 0;

void inOrder(struct TreeNode* root){
    if(root != NULL){
        inOrder(root->left);
        arr[j] = root->val;
        j++;
        inOrder(root->right);
    }
} 

int getMinimumDifference(struct TreeNode* root) {
    j = 0;
    inOrder(root);
    int min = INT_MAX;
    for(int i = 0; i < j - 1; i++){
        int diff = arr[i+1] - arr[i];
        if(diff<min && diff > 0){
            min = diff;
        }
    }
    return min;
}