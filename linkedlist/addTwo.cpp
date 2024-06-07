    
template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }
};


Node<int> * reverseLL(Node<int> * head){
    if (head && head->next != NULL) return head;
    Node<int> * current = head;
    Node<int> * prev = NULL;
    Node<int> * next = head->next;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}


void print(Node<int> * root){
    Node<int> * p = root;
    while(p!= NULL){
        cout << p->data << " ";
        p = p->next;
    }
}


Node<int> *addTwoNumbers(Node<int> *num1, Node<int> *num2)
{
    Node<int> * result = new Node<int>(0);
    Node<int> * p = result;
    num1 = reverseLL(num1);
    num2 = reverseLL(num2);
    int data = 0;
    int carry = 0;
    while(num1 != NULL && num2 != NULL){
        data = num1->data + num2->data + carry;
        carry = data/10;
        int num = data%10;
        p->next = new Node<int>(num);
        p = p->next;
        num1 = num1->next;
        num2 = num2->next;
    }

    if (num1 == NULL && num2 == NULL && carry == 0){
        return result->next;
    }

    while (num1 != NULL){
        data = num1->data + carry;
        carry = data/10;
        int num = data % 10;
        p->next = new Node<int>(num);
        p = p->next;
        num1 = num1->next;
    }

    while (num2 != NULL){
        data = num2->data + carry;
        carry = data/10;
        int num = data % 10;
        p->next = new Node<int>(num);
        p = p->next;
        num2 = num2->next;
    }

    if (num1 == NULL && num2 == NULL && carry > 0){
        p->next = new Node<int>(carry);
    }
    result = reverseLL(result->next);
    return result;
};