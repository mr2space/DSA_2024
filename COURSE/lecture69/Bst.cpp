#include<iostream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
    Node(){
        data = 0;
        left = right = NULL;
    }
};




Node * insertNode(Node * root, int data){
    if (root == NULL){
        return new Node(data);
    }
    if(root->data > data){
        root->left = insertNode(root->left, data);
        return root;
    }else{
        root->right = insertNode(root->right, data);
        return root;
    }
}


void takeInput(Node * &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertNode(root, data);
        cin >> data;
    }
}

void levelorder(Node * root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}


Node * targetNode(Node * root, int ele, Node* pred, Node * suc){
    if (root == NULL) return NULL;
    if (root->data == ele){
        return root;
    };
    if (root->data > ele) {
        pred = root;
        return targetNode(root->left, ele, pred, suc);
    }
    if (root->data < ele){
        suc = root;
        return targetNode(root->right, ele, pred, suc);
    }
}

Node * minimum(Node * root){
    if (root == NULL || root->right == NULL){
        return NULL;
    }
    root = root->right;
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}



TreeNode * maximum(TreeNode * root){
    if (root == NULL || root->left == NULL){
        return NULL;
    }
    root = root->left;
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

void inorder(Node * root){
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* deleteNode(Node * root, int ele){
    if (root == NULL) return NULL;
    if (root->data == ele){
        // no child
        if (root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }else if (root->left != NULL && root->right == NULL){
            Node * temp = root->left;
            delete root;
            return temp;
        }else if (root->right != NULL && root->left == NULL){
            Node * temp = root->right;
            delete root;
            return temp;
        }else{
            Node * success = minimum(root);
            root->data = success->data;
            root->right = deleteNode(root->right, success->data);
        }
    }
    if (root->data > ele){
        root->left = deleteNode(root->left, ele);
    }else{
        root->right = deleteNode(root->right, ele);
    }
    return root;
}



int main(){
    Node* root = NULL;
    cout << "Enter the node: "<< endl;
    takeInput(root);
    inorder(root);
    int de;
    cout << endl << "Enter ele to delete: ";
    cin >> de;
    root = deleteNode(root, de);
    inorder(root);
    return 0;
}