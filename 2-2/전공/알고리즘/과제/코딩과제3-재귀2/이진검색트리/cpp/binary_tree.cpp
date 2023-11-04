/***********************
20203152 최정민 이진검색트리 10/04
***********************************/

#include<iostream>
using namespace std;

struct node//노드
{
    int data;
    node* left;
    node* right;
};

node* new_node(int data)//새로운 노드 동적할당
{
    node* n = new(node);
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node* insert(node* root, int data)//새로운 원소 삽입
{
    if (root == NULL)//끝까지 내려오면 새로운 노드 생성
    {
        return new_node(data);
    }
    else//맞는 자리를 찾아 내려가기
    {
        if (data < root->data)
        {
            root->left = insert(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
    }
    return root;
}
void preOrder(struct node* root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    else
        return;
}
void inOrder(struct node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    else
        return;
}
void postOrder(struct node* root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
    else 
        return;
}
int size(struct node* root)
{
    if (root == NULL) { return 0; }
    else
        return size(root->left) + size(root->right) + 1;
}
int height(struct node* root)
{
    if (root == NULL) { return -1; }
    else
    {
        int L = height(root->left);
        int R= height(root->right);
        int tmp = 1;
        (L > R) ? tmp += L : tmp += R;
        return tmp;
    }
}
int sumOfWeight(struct node* root)
{
    if (root == NULL) { return 0; }
    else
        return sumOfWeight(root->left) + sumOfWeight(root->right)+ root->data;
}
int maxPathWeight(struct node* root)
{
    if (root == NULL) { return 0; }
    else
    {
        int k;
        int R = maxPathWeight(root->right);
        int L = maxPathWeight(root->left);
        (R > L) ? k = R + root->data : k = L + root->data;
        return k;
    }
}
node* mirror(struct node* root)//뒤집기
{
    if (root == NULL) { return NULL; }
    else
    {
        node* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
        return root;
    }
}
node* destruct(struct node* root)//해체
{
    if (root == NULL) { return NULL; }
    else {
        root->left = destruct(root->left);
        root->right = destruct(root->right);
        delete(root);
        return NULL;
    }
}
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int num, i;
        node* root = new(node);
        root = NULL;
        cin >> num;
        for (i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            root = insert(root, data);
        }
        cout << size(root) << "\n";
        cout << height(root) << "\n";
        cout << sumOfWeight(root) << "\n";
        cout << maxPathWeight(root) << "\n";
        mirror(root);
        preOrder(root);
        cout << "\n";
        inOrder(root); cout << "\n";
        postOrder(root); cout << "\n";
        root = destruct(root); // BST의 모든 노드의 동적 메모리 해제
        if (root == NULL)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}