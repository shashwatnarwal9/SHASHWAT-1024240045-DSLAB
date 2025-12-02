#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularList {
public:
    Node* head;

    CircularList() {
        head = NULL;
    }

    void insert(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void deleteValue(int key) {
        if (!head) return;

        Node* curr = head;
        Node* prev = NULL;

        while (curr->data != key) {
            if (curr->next == head) {
                cout << "Value not found\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        if (curr == head && curr->next == head) {
            head = NULL;
            delete curr;
            return;
        }

        if (curr == head) {
            prev = head;
            while (prev->next != head)
                prev = prev->next;
            head = curr->next;
            prev->next = head;
            delete curr;
        } else if (curr->next == head) {
            prev->next = head;
            delete curr;
        } else {
            prev->next = curr->next;
            delete curr;
        }
    }

    bool search(int key) {
        if (!head) return false;

        Node* temp = head;
        do {
            if (temp->data == key) return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    int size() {
        if (!head) return 0;
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void display() {
        if (!head) { cout << "Empty"; return; }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << head->data << endl;  
    }

    bool isCircular() {
        if (!head) return true;

        Node* temp = head->next;
        while (temp && temp != head)
            temp = temp->next;

        return (temp == head);
    }
};

int main() {
    CircularList cl;

    cl.insert(20);
    cl.insert(100);
    cl.insert(40);
    cl.insert(80);
    cl.insert(60);

    cl.display();

    cout << "Size: " << cl.size() << endl;
    cout << "Search 80: " << (cl.search(80) ? "Found" : "Not Found") << endl;
    cout << "Is Circular: " << (cl.isCircular() ? "Yes" : "No") << endl;
}
