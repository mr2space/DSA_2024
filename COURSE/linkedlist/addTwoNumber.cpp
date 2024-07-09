#include<iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node * reverseLL(Node * head){
    if (head && head->next != NULL) return head;
    Node * current = head;
    Node * prev = NULL;
    Node * next = head->next;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


void print(Node * root){
    Node * p = root;
    while(p!= NULL){
        cout << p->data << " ";
        p = p->next;
    }
}


Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node * result = new Node();
    Node * p = result;
    num1 = reverseLL(num1);
    num2 = reverseLL(num2);
    int data = 0;
    int carry = 0;
    while(num1 != NULL && num2 != NULL){
        data = num1->data + num2->data + carry;
        carry = data/10;
        int num = data%10;
        p->next = new Node(num);
        p = p->next;
    }

    if (num1 == NULL && num2 == NULL && carry == 0){
        return result->next;
    }

    while (num1 != NULL){
        data = num1->data + carry;
        carry = data/10;
        int num = data % 10;
        p->next = new Node(num);
        p = p->next;
    }

    while (num2 != NULL){
        data = num2->data + carry;
        carry = data/10;
        int num = data % 10;
        p->next = new Node(num);
        p = p->next;
    }

    if (num1 == NULL && num2 == NULL && carry > 0){
        p->next = new Node(carry);
    }
    return result->next;
};