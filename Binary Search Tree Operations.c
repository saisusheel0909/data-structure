#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert duplicates always go to the right subtree
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

void inorderTraversalHelper(struct TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraversalHelper(root->left);
    printf("%d ", root->val);
    inorderTraversalHelper(root->right);
}

void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    inorderTraversalHelper(root);
    printf("\n");
}

void preorderTraversalHelper(struct TreeNode* root) {
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorderTraversalHelper(root->left);
    preorderTraversalHelper(root->right);
}

void preorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    preorderTraversalHelper(root);
    printf("\n");
}

void postorderTraversalHelper(struct TreeNode* root) {
    if (root == NULL)
        return;
    postorderTraversalHelper(root->left);
    postorderTraversalHelper(root->right);
    printf("%d ", root->val);
}

void postorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty\n");
        return;
    }
    postorderTraversalHelper(root);
    printf("\n");
}

struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node, sets found flag to 1 if node found and deleted, else 0
struct TreeNode* deleteNode(struct TreeNode* root, int val, int* found) {
    if (root == NULL)
        return NULL;

    if (val < root->val)
        root->left = deleteNode(root->left, val, found);
    else if (val > root->val)
        root->right = deleteNode(root->right, val, found);
    else {
        *found = 1;
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children: replace with inorder successor
        struct TreeNode* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val, found);
    }
    return root;
}

void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}






int main() {
    struct TreeNode* root = NULL;
    int choice, data;

    while (1) {
        printf("1. Insert Node\n");
        printf("2. In-Order Traversal\n");
        printf("3. Pre-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Delete Node\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                inorderTraversal(root);
                break;
            case 3:
                preorderTraversal(root);
                break;
            case 4:
                postorderTraversal(root);
                break;
            case 5: {
                printf("Delete: ");
                scanf("%d", &data);
                int found = 0;
                root = deleteNode(root, data, &found);
                if (!found) {
                    printf("Value not found\n");
                }
                break;
            }
            case 6:
                freeTree(root);
                exit(0);
            default:
                printf("Invalid choice\n");
        }
}
