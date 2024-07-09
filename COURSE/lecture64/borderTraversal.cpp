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
    std::cout << "Enter the number"<<endl;
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
            std::cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        std::cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

void inorder2(node * root){
    if (root == NULL) return;
    inorder2(root->left);
    std::cout << root->data << " ";
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
            std::cout << current->data << " ";
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
        std::cout << t->data << " ";
        s2.pop();
    }
    std::cout << endl;
}

void preorder(node * root){
    if (root == NULL) return ;
    stack<node *> s1, s2;
    s1.push(root);
    while(!s1.empty()){
        node * temp = s1.top();
        s1.pop();
        std::cout << temp->data << " ";

        if (temp->right) s1.push(temp->right);
        if (temp->left) s1.push(temp->left);
    }
    std::cout << endl;
}


node * buildFromLevelOrder(node * root){
    queue<node * > q;
    int data ;
    std::cout << "Enter the data for root" << endl;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        std::cout << "Enter the left node of "<< temp->data << endl;
        cin >> data;
        if (data != -1) {
            temp->left = new node(data);
            q.push(temp->left);
        }
        std::cout << "Enter the right node of "<< temp->data << endl;
        cin >> data;
        if (data != -1) {
            temp->right = new node(data);
            q.push(temp->right);
        }
        
    }
    return root;
}
struct Node
{
    int data;
    Node* left, * right;
};

void leaf(node * root, vector<int>& ans){
    if (root == NULL) return ;
    if (root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
}

void print(vector<int> arr){
    for(auto ele:arr){
        std::cout << ele << " ";
    }
    std::cout << endl;
}

vector<int> leafNode(node * root){
    vector<int> ans;
    leaf(root, ans);
    return ans;
}

void printleft(node * root, vector<int>& ans){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        return;
    }
    ans.push_back(root->data);
    printleft(root->left, ans);    
};

void printRight(node * root, vector<int>& ans){
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL){
        return;
    }
    printleft(root->right, ans);    
    ans.push_back(root->data);
};


int main(int argc, char const *argv[])
{
    node * root = buildTree(NULL);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelorder(root);
    std::cout << endl;
    // root = buildFromLevelOrder(NULL);
    // levelorder(root);
    std::cout << endl;
    vector<int> ans = leafNode(root);
    vector<int> temp;
    printleft(root, temp);
    vector<int> temp2;
    printRight(root, temp2);
    print(temp);
    print(ans);
    print(temp2);
    return 0;
}
