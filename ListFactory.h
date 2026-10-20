#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

#include "DoublyLinkedList.h"

// Wzorzec Projektowy Factory (Fabryka) do tworzenia listy na stercie
template <typename T>
class ListFactory {
public:
    static DoublyLinkedList<T>* createList() {
        return new DoublyLinkedList<T>();
    }
};

#endif