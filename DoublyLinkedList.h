#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"

// Główna klasa listy dwukierunkowej działająca na stercie
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head; // początek listy
    Node<T>* tail; // koniec listy
    int count;     // licznik elementów

public:
    // Konstruktor - tworzy pustą listę
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    // Destruktor
    ~DoublyLinkedList() {
        // na razie pusty, dorobimy czyszczenie później
    }

    // Sprawdzenie czy lista jest pusta
    bool isEmpty() const {
        return head == nullptr;
    }

    // Dodanie elementu na początek listy
    void addFront(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    // Dodanie elementu na koniec listy
    void addBack(const T& val) {
        Node<T>* newNode = new Node<T>(val);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    // Wyświetlanie listy od początku
    void display() const {
        Node<T>* current = head;
        std::cout << "Lista: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif