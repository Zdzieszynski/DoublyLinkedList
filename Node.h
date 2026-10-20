#ifndef NODE_H
#define NODE_H

// Pojedynczy element listy dwukierunkowej
template <typename T>
struct Node {
    T data;         // wartość
    Node* next;     // wskaźnik na następny element
    Node* prev;     // wskaźnik na poprzedni element

    // Konstruktor do tworzenia węzła
    Node(const T& wartosc) {
        data = wartosc;
        next = nullptr;
        prev = nullptr;
    }
};

#endif