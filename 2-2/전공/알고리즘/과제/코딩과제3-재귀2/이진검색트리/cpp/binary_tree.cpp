/***********************
20203152 최정민 이진검색트리 09/20\5
***********************************/

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void insert(struct node** root, int data)
{
    if (root == NULL)
    {
        node* new_node = new(node);
        new_node->data = data;
        new_node->left == NULL;
        new_node->right == NULL;
    }
    else
    {
        if (data < root->data)
        {

        }
    }

}
/*
size(root)
height(root)
sumOfWeight(root)
maxPathWeight(root)
mirror(&root);
preOrder(root);
inOrder(root)
postOrder(root)
destruct(&root)


*/
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int num, i;
        struct node* root = NULL;
        cin >> num;
        for (i = 0; i < num; i++)
        {
            int data;
            cin >> data;
            insert(&root, data);
        }
        /*
        cout << size(root) << "\n";
        cout << height(root) << "\n";
        cout << sumOfWeight(root)<< "\n";
        cout << maxPathWeight(root) << "\n";
        mirror(&root);
        preOrder(root); 
        cout << "\n";
        inOrder(root); cout << "\n";
        postOrder(root); cout << "\n";
        destruct(&root); // BST의 모든 노드의 동적 메모리 해
        */
        if (root == NULL)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}