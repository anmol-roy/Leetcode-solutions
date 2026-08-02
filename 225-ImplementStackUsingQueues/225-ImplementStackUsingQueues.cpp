// Last updated: 02/08/2026, 09:01:44
class Node  {
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class MyStack {
    Node* head;
public:
    MyStack() {
        head = nullptr;
    }
    
    void push(int x) {
       Node* node = new Node(x);
       node->next = head;
       head = node; 
    }
    
    int pop() {
        if (!head) return -1 ;
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        return value;
    }
    
    int top() {
        return head->data;
    }
    
    bool empty() {
        return head == nullptr;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */