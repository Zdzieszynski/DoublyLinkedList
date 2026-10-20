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
};

#endif