#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyList {
    Node* head;
    Node* tail;

public:
    DoublyList() {
        head = tail = nullptr;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << "-";
            temp = temp->next;
        }
        cout << "null\n";
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void pop_front() {
        if (head == nullptr) {
            cout << "Linked list is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; // list became empty
        delete temp;
    }

    void pop_back() {
        if (tail == nullptr) {
            cout << "Linked list is empty\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // list became empty
        delete temp;
    }

    void insert(int val, int position) {
        if (position < 0) return;
        if (position == 0) return push_front(val);

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    int search(int val) {
        Node* temp = head;
        int idx = 0;
        while (temp != nullptr) {
            if (temp->data == val) return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        // swap next and prev for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // move to next node in original list
        }

        // swap head and tail
        if (temp != nullptr) head = temp->prev;
    }
};

int main() {
    DoublyList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_back(4);
    dll.push_back(5);

    // dll.print();      // 1-2-3-4-5-null
    // dll.push_front(0);
    // dll.print();      // 0-1-2-3-4-5-null

    // dll.pop_front();
    // dll.print();      // 1-2-3-4-5-null

    // dll.pop_back();
    // dll.print();      // 1-2-3-4-null

    // dll.insert(10, 2);
    // dll.print();      // 1-2-10-3-4-null

    // cout << "Index of 10: " << dll.search(10) << "\n";

    // dll.reverse();
    // dll.print();      // 4-3-10-2-1-null

    return 0;
}
