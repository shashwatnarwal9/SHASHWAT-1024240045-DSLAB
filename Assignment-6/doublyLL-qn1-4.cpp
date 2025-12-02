#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = NULL;
    }

    void insertFront(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertBack(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAfterValue(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Value not found\n";
            return;
        }

        if (temp == tail) {
            insertBack(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBeforeValue(int key, int val) {
        if (!head) return;

        if (head->data == key) {
            insertFront(val);
            return;
        }

        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Value not found\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    void deleteValue(int key) {
        if (!head) return;

        if (head->data == key) {
            Node* del = head;
            head = head->next;
            if (head) head->prev = NULL;
            else tail = NULL;
            delete del;
            return;
        }

        Node* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;

        if (!temp) {
            cout << "Value not found\n";
            return;
        }

        if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    bool search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) return true;
            temp = temp->next;
        }
        return false;
    }

    int size() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            temp = temp->next;
            count++;
        }
        return count;
    }

    bool isPalindrome() {
        Node* left = head;
        Node* right = tail;

        while (left && right && left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList d;

    d.insertFront(1);
    d.insertBack(4);
    d.insertAfterValue(1, 2);
    d.insertBeforeValue(4, 3);

    cout << "DLL: ";
    d.display();

    cout << "Size: " << d.size() << endl;
    cout << "Search 3: " << (d.search(3) ? "Found" : "Not Found") << endl;

    cout << "Palindrome: " << (d.isPalindrome() ? "Yes" : "No") << endl;

    d.deleteValue(4);
    d.display();
}
