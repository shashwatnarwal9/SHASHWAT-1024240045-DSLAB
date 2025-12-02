#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;

        if(head == NULL) tail = NULL;
    }

    void pop_back(){
        if(head == NULL){
            cout << "List is empty\n";
            return;
        }

        if(head->next == NULL){ 
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    // Insert after a particular value
    void insertAfterValue(int val, int key){
        Node* temp = head;
        while(temp != NULL && temp->data != key){
            temp = temp->next;
        }

        if(temp == NULL){
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == tail) tail = newNode;
    }

    // Insert before a specific value
    void insertBeforeValue(int val, int key){
        if(head == NULL){
            cout << "List is empty\n";
            return;
        }

        if(head->data == key){
            push_front(val);
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != key){
            temp = temp->next;
        }

        if(temp->next == NULL){
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a specific value
    void deleteValue(int key){
        if(head == NULL){
            cout << "List is empty\n";
            return;
        }

        if(head->data == key){
            pop_front();
            return;
        }

        Node* temp = head;
        while(temp->next != NULL && temp->next->data != key){
            temp = temp->next;
        }

        if(temp->next == NULL){
            cout << "Value not found\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        if(del == tail) tail = temp;
        delete del;
    }

    // Search element
    int search(int key){
        Node* temp = head;
        int pos = 1;

        while(temp != NULL){
            if(temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    // Display nodes
    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Count occurrences & delete them
    int countAndDelete(int key){
        int count = 0;

        while(head != NULL && head->data == key){
            pop_front();
            count++;
        }

        Node* temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->next->data == key){
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                count++;
            } else {
                temp = temp->next;
            }
        }

        return count;
    }

    int middleElement(){
        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void reverseList(){
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }
};

int main(){
    List l1;

    int arr[] = {1,2,3,4,5};
    for(int val : arr) l1.push_back(val);

    l1.printList();
    cout << "Middle = " << l1.middleElement() << endl;

    l1.reverseList();
    l1.printList();

    return 0;
}
