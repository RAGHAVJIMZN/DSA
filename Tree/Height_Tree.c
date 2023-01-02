#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};
struct Node *MakeNode(int x)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}
int height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    struct Node *root = NULL;
    root = MakeNode(1);
    root->left = MakeNode(2);
    root->right = MakeNode(3);
    root->right->left = MakeNode(4);
    root->right->right = MakeNode(5);
    root->right->left->left = MakeNode(6);
    root->right->left->left->right = MakeNode(7);
    printf("Height of Tree is %d\n", height(root));
    return 0;
}