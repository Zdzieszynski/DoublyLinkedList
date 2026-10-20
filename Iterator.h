#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

// Wzorzec Iteratora do przechodzenia po liście dwukierunkowej
template <typename T>
class ListIterator {
private:
    Node<T>* current; // aktualny węzeł, na którym stoi iterator

public:
    // Konstruktor przyjmujący początkowy węzeł
    ListIterator(Node<T>* startNode) {
        current = startNode;
    }

    // Sprawdzenie czy jest następny element
    bool hasNext() const {
        return current != nullptr && current->next != nullptr;
    }

    // Sprawdzenie czy jest poprzedni element
    bool hasPrev() const {
        return current != nullptr && current->prev != nullptr;
    }

    // Przejście do następnego elementu i zwrócenie jego wartości
    T next() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
        }
        return current ? current->data : T();
    }

    // Przejście do poprzedniego elementu i zwrócenie jego wartości
    T prev() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
        }
        return current ? current->data : T();
    }

    // Pobranie wartości aktualnego elementu
    T getCurrent() const {
        return current ? current->data : T();
    }

    // Sprawdzenie czy iterator wskazuje na poprawny element
    bool isValid() const {
        return current != nullptr;
    }
};

#endif