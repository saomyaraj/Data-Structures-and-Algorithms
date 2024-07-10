#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to generate all structurally unique BSTs
struct TreeNode** generateTrees(int A, int* returnSize) {
    if (A == 0) {
        *returnSize = 0;
        return NULL;
    }
    return generateTreesHelper(1, A, returnSize);
}

// Helper function to generate all structurally unique BSTs recursively
struct TreeNode** generateTreesHelper(int start, int end, int* returnSize) {
    struct TreeNode** trees = (struct TreeNode**)malloc(sizeof(struct TreeNode*));
    int treeCount = 0;
    if (start > end) {
        trees = (struct TreeNode**)realloc(trees, sizeof(struct TreeNode*));
        trees[0] = NULL;
        *returnSize = 1;
        return trees;
    }

    for (int i = start; i <= end; i++) {
        struct TreeNode** leftTrees = generateTreesHelper(start, i - 1, returnSize);
        struct TreeNode** rightTrees = generateTreesHelper(i + 1, end, returnSize);

        for (int j = 0; j < *returnSize; j++) {
            for (int k = 0; k < *returnSize; k++) {
                struct TreeNode* root = newNode(i);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                trees = (struct TreeNode**)realloc(trees, (treeCount + 1) * sizeof(struct TreeNode*));
                trees[treeCount++] = root;
            }
        }
    }

    *returnSize = treeCount;
    return trees;
}

// Function to print a binary tree in preorder traversal
void printTree(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    int A = 3;
    int returnSize;
    struct TreeNode** result = generateTrees(A, &returnSize);
    
    // Printing the generated trees
    for (int i = 0; i < returnSize; i++) {
        printTree(result[i]);
        printf("\n");
    }

    // Freeing memory
    for (int i = 0; i < returnSize; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
