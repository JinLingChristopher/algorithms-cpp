//
// Created by Edison King on 2021/3/9.
//



#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// return the max value's index in this range, [low, high]
int findMax(const vector<int>& nums, int low, int high) {
    int curr = nums[low], result = low;
    for (int i = low; i <= high; ++i) {
        if (nums[i] > curr) {
            curr = nums[i];
            result = i;
        }
    }
    return result;
}

TreeNode* helper(const vector<int>& nums, int low, int high) {
    auto i = findMax(nums, low, high);
    TreeNode* root = new TreeNode(nums[i]);

    if (i > low) {
        root->left = helper(nums, low, i - 1);
    }

    if (i < high) {
        root->right = helper(nums, i + 1, high);
    }

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

void printTree(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    vector<int> nums{3, 1, 2, 6, 0, 5};
    auto tree = constructMaximumBinaryTree(nums);

    printTree(tree);

    return 0;
}
