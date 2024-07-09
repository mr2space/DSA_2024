#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = NULL;
    }
    node(){
        data = 0;
        left = right = NULL;
    }
};

node * buildTree(node * root){
    cout << "Enter the number"<<endl;
    int temp ;
    cin >> temp;
    if (temp == -1){
        return NULL;
    }
    root = new node(temp);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void levelorder(node * root){
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
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

void inorder2(node * root){
    if (root == NULL) return;
    inorder2(root->left);
    cout << root->data << " ";
    inorder2(root->right);
}

void inorder(node * root){
    stack<node *> s;
    node * current = root;
    while(!s.empty() || current != NULL){
        if(current != NULL){
            s.push(current);
            current = current->left;
        }else{
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
}


void postorder(node * root){
    if (root == NULL) return ;
    stack<node *> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        node * temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left) s1.push(temp->left);
        if (temp->right) s1.push(temp->right);
    }
    while(!s2.empty()){
        node * t = s2.top();
        cout << t->data << " ";
        s2.pop();
    }
    cout << endl;
}

void preorder(node * root){
    if (root == NULL) return ;
    stack<node *> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        node * temp = s1.top();
        s1.pop();
        cout << temp->data << " ";

        if (temp->right) s1.push(temp->right);
        if (temp->left) s1.push(temp->left);
    }
    cout << endl;
}


node * buildFromLevelOrder(node * root){
    queue<node * > q;
    int data ;
    cout << "Enter the data for root" << endl;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        cout << "Enter the left node of "<< temp->data << endl;
        cin >> data;
        if (data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }
        cout << "Enter the right node of "<< temp->data << endl;
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
        
    }
    return root;
}

int main(int argc, char const *argv[])
{
    node * root = buildTree(NULL);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelorder(root);
    cout << endl;
    root = buildFromLevelOrder(NULL);
    levelorder(root);
    cout << endl;
    return 0;
}
