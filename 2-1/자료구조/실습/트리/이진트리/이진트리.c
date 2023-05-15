#include<stdio.h>
#include<stdlib.h>
////////////////////init
typedef int element;
#define N 10

typedef struct TreeNode
{
    element key;
    struct TreeNode* left;
    struct TreeNode* right;
    
}TreeNode;


TreeNode* makeNode(element key, TreeNode* left, TreeNode* right)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = left;
    node->right = right;
    return node;
}
//////스택을 이용한 중위 순회
typedef struct
{
    TreeNode* Stack[N];
    int top;
    
}StackType;

void initStack(StackType* S)
{
    S->top = -1;
}

void push(StackType* S, TreeNode* e)
{
    if (S->top < N - 1)
        S->Stack[++S->top] = e;
}

TreeNode* pop(StackType* S)
{
    TreeNode* e = NULL;

    if (S->top >= 0)
        e = S->Stack[S->top--];
    
    return e;
}

void iterOrder(TreeNode* root)
{
    StackType S;
    initStack(&S);

    while (1)
    {
        for (; root != NULL; root = root->left)
            push(&S, root);
        root = pop(&S);

        if (root == NULL)
            break;

        printf("[%d] ", root->key);

        root = root->right;
    }
}

//////////전후 순회
void preOrder(TreeNode* root)
{
    if (root !=NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);

    }
}

void inOrder(TreeNode* root)
{
    if (root !=NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);

    }
}

void postOrder(TreeNode* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}
//////////큐
typedef struct
{
    TreeNode* Queue[N];
    int front, rear;
}QueueType;

void initQueue(QueueType* Q)
{
    Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q)
{
    return Q->front == (Q->rear + 1) %N;
}

void enqueue(QueueType* Q, TreeNode* e)
{
    Q->rear = Q->rear;
    Q->Queue[Q->rear] = e;
}

TreeNode* dequeue(QueueType* Q)
{
    Q->front = (Q->front + 1) % N;
    return Q->Queue[Q->front];
}

void levelOrder(TreeNode* root)
{
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, root);
    while (!isEmpty(&Q))
    {
        root = dequeue(&Q);
        printf("[%d] ", root->key);
        
        if (root->left != NULL)// = if(root->left)
            enqueue(&Q, root->left);

        if (root->right)
            enqueue(&Q, root->right);
    }
}
////////////////이진탐색트리
TreeNode* makeNode1(element key)
{

    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insertNode(TreeNode* root, element key)
{
    if (root == NULL)
    {
        return makeNode1(key);
    }
    if (key < root->key)
        root->left = insertNode(root->left, key);
    else if (key > root->key)
        root->right = insertNode(root->right, key);
    
    return root;
}
///////////////////delete
TreeNode* minValueNode(TreeNode* root)
{
    TreeNode* p = root;

    while (p->left != NULL)
        p = p->left;

    return p;
}

TreeNode* deleteNode(TreeNode* root, element key)
{
    if (root == NULL)
        return NULL;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {

            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            TreeNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);

        }
    }
    return root;
}

int getNodeCount(TreeNode* root)
{
    int count = 0;

    if (root != NULL)
        count = 1 + getNodeCount(root->left) + getNodeCount(root->right);

    return count;
}

int getLeafCount(TreeNode* root)
{
    int count = 0;

    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            count = getLeafCount(root->left) + getLeafCount(root->right);
    }
        
    return count;

}






//////////////////메인
int main()
{
    TreeNode* root = NULL;
    root = insertNode(root, 35);
    root = insertNode(root, 68);
    root = insertNode(root, 99);
    root = insertNode(root, 18);
    root = insertNode(root, 7);
    root = insertNode(root, 3);
    root = insertNode(root, 12);
    root = insertNode(root, 26);
    root = insertNode(root, 22);
    root = insertNode(root, 30);
    /*
    TreeNode* N4 = makeNode(1, NULL, NULL);
    TreeNode* N6 = makeNode(16, NULL, NULL);
    TreeNode* N7 = makeNode(25, NULL, NULL);
    TreeNode* N2 = makeNode(4, N4, NULL);
    TreeNode* N3 = makeNode(20, N6, N7);
    TreeNode* N1 = makeNode(15, N2, N3);
    */
    /*
    printf("pre: "); preOrder(N1); printf("\n");
    printf("in: "); inOrder(N1); printf("\n");
    printf("post: "); postOrder(N1); printf("\n");

    iterOrder(N1);
    
    
    levelOrder(N1);//에러 있음 고쳐야함
    */
    preOrder(root); printf("\n"); getchar();

    printf("%d %d\n", getNodeCount(root), getLeafCount(root));
    return 0;
}