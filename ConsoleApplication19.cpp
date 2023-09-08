#include <iostream>


struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    
    void remove(int value) {
        if (head == nullptr) {
            return; 
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    ~LinkedList() {
        clear(); 
    }
};

int main() {
    LinkedList myList;

    
    myList.append(1);
    myList.append(2);
    myList.append(3);

    // Виведення списку на екран
    std::cout << "Spisok: ";
    myList.print();

    // Видалення елементу зі значенням 2
    myList.remove(2);
    std::cout << "Spisok pislya vydalennya 2: ";
    myList.print();

    // Очищення списку
    myList.clear();
    std::cout << "Spisok pislya ochishennya: ";
    myList.print();

    return 0;
}
