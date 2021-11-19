
#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void printv(vector<int>path , int i){
    for(int j=i;j<path.size();j++){
        cout<<path[j]<<" ";
    }
    cout<<endl;
}
void printKPaths(Node *root , vector<int>& path , int k){
    if(!root)return;
    path.push_back(root->data);
    printKPaths(root->left,path,k);
    printKPaths(root->right,path,k);
    int p=0;
    for(int i= path.size() - 1 ; i>=0;i--){
        p+=path[i];
        if(p==k)printv(path,i);
    }
    path.pop_back();
}
void printKPath(Node *root , int k){
    vector<int> path;
    printKPaths(root,path,k);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
 
    int k = 5;
    printKPath(root, k);

    return 0;
}
