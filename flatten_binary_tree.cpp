//flatten binary tree to linked list
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node*buildTree(vector<int>arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }
    Node*root=new Node(arr[idx]);
    root->left=buildTree(arr);
    root->right=buildTree(arr);
    return root;
}
Node*NR=NULL;
void level(Node*root){
    if(root==NULL){
        return;
    }
    level(root->right);
    level(root->left);
    root->left=NULL;
    root->right=NR;
    NR=root;
}
int main(){
    vector<int>arr={1,2,3,-1,-1,4,-1,-1,5,-1,6,-1,-1};
    Node*root=buildTree(arr);
    level(root);
    Node*temp=root;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }
  return 0;
}
