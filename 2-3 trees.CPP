#include <stdio.h>
#include <stdlib.h>

// Structure for 2-3 Tree Node
struct TreeNode
{
    int data[2];               // Data values (sorted)
    struct TreeNode *child[3]; // Child pointers
};

struct TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data[0] = value;
    newNode->data[1] = -1;
    newNode->child[0] = newNode->child[1] = newNode->child[2] = NULL;
    return newNode;
}

struct TreeNode *insert(struct TreeNode *root, int value);

struct TreeNode *split(struct TreeNode *node, int value)
{
    struct TreeNode *newNode = createNode(node->data[1]);

    newNode->child[0] = node->child[1];
    newNode->child[1] = node->child[2];
    node->data[1] = -1;
    node->child[1] = NULL;
    node->child[2] = NULL;

    if (value < node->data[0])
    {
        newNode->data[0] = node->data[0];
        node->data[0] = value;
        node->child[1] = newNode;
    }
    else
    {
        newNode->data[0] = value;
        node->child[1] = node->child[0];
        node->child[0] = newNode;
    }

    return node;
}

struct TreeNode *insertIntoNode(struct TreeNode *node, int value)
{
    if (node->data[1] == -1)
    {
        if (value < node->data[0])
        {
            node->data[1] = node->data[0];
            node->data[0] = value;
        }
        else
        {
            node->data[1] = value;
        }
    }
    else
    {
        if (value < node->data[0])
        {
            node->child[0] = insert(node->child[0], value);
        }
        else if (value > node->data[1])
        {
            node->child[2] = insert(node->child[2], value);
        }
        else
        {
            node->child[1] = insert(node->child[1], value);
        }

        if (node->child[2] != NULL)
        {
            node = split(node, value);
        }
    }
    return node;
}

struct TreeNode *insert(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    root = insertIntoNode(root, value);

    if (root->data[1] != -1)
    {
        struct TreeNode *newRoot = createNode(root->data[1]);
        newRoot->child[0] = root;
        newRoot->child[1] = split(root, root->data[0]);
        return newRoot;
    }

    return root;
}

struct TreeNode *search(struct TreeNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value == root->data[0] || value == root->data[1])
    {
        return root;
    }
    else if (value < root->data[0])
    {
        return search(root->child[0], value);
    }
    else if (root->data[1] != -1 && value > root->data[1])
    {
        return search(root->child[2], value);
    }
    else
    {
        return search(root->child[1], value);
    }
}

void printTree(struct TreeNode *root)
{
    if (root)
    {
        printTree(root->child[0]);
        printf("%d ", root->data[0]);
        printTree(root->child[1]);
        if (root->data[1] != -1)
        {
            printf("%d", root->data[1]);
            printTree(root->child[2]);
        }
    }
}

int main()
{
    int key;
    struct TreeNode *root = NULL;

    // Insert values
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);

    // Print the tree
    printf("INORDER TRAVERSAL OF 2-3 Tree: ");
    printTree(root);
    printf("\n");

    // Search for a value
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    struct TreeNode *searchResult = search(root, key);
    if (searchResult)
        printf("Value %d found in the tree.\n", key);
    else
        printf("Value %d not found in the tree.\n", key);

    return 0;
}
