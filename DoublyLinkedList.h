
/**
 * @file DoublyLinkedList.h
 * @brief Implementacja szablonu listy dwukierunkowej.
 *
 * Klasa umożliwia dodawanie i usuwanie elementów na początku
 * oraz na końcu listy, wyświetlanie elementów w obu kierunkach
 * i czyszczenie całej listy.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "Node.h"
#include "Iterator.h"

// Główna klasa listy dwukierunkowej działająca na stercie
template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
        /// Konstruktor i destruktor
    DoublyLinkedList();
    ~DoublyLinkedList();

    /// Sprawdzenie, czy lista jest pusta
    bool isEmpty() const;

    /// Dodawanie elementów
    void addFront(const T& val);
    void addBack(const T& val);

    // Usuwanie elementów
    void removeFront();
    void removeBack();

    /// Czyszczenie całej listy
    void clear();

    /// Wyświetlanie elementów
    void display() const;
    void displayReverse() const;

    /// Zwraca iterator początkowy listy
    ListIterator<T> getIterator() const;
};

#endif
