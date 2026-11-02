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
#include "iterator.h"

/**
 * @brief Lista dwukierunkowa działająca na stercie.
 *
 * Klasa przechowuje wskaźniki na początek (@c head) i koniec (@c tail)
 * listy oraz licznik elementów (@c count). Umożliwia dodawanie
 * i usuwanie elementów z obu końców, wyświetlanie listy w obu
 * kierunkach oraz zwrócenie iteratora.
 *
 * @tparam T Typ wartości przechowywanej w liście.
 */
template <typename T>
class DoublyLinkedList
{
private:
    Node<T>* head;   ///< Wskaźnik na pierwszy element listy (nullptr dla pustej).
    Node<T>* tail;   ///< Wskaźnik na ostatni element listy (nullptr dla pustej).
    int count;       ///< Liczba elementów aktualnie przechowywanych w liście.

public:
    /**
     * @brief Konstruktor tworzący pustą listę.
     *
     * Ustawia @c head i @c tail na @c nullptr oraz @c count na 0.
     */
    DoublyLinkedList();

    /**
     * @brief Destruktor zwalniający całą pamięć listy.
     *
     * Wywołuje clear(), aby usunąć wszystkie węzły.
     */
    ~DoublyLinkedList();

    /**
     * @brief Sprawdza, czy lista jest pusta.
     *
     * @return @c true jeśli lista nie zawiera elementów, @c false w przeciwnym razie.
     */
    bool isEmpty() const;

    /**
     * @brief Dodaje element na początek listy.
     *
     * @param val Wartość do dodania.
     */
    void addFront(const T& val);

    /**
     * @brief Dodaje element na koniec listy.
     *
     * @param val Wartość do dodania.
     */
    void addBack(const T& val);

    /**
     * @brief Usuwa element z początku listy.
     *
     * Jeśli lista jest pusta, metoda nic nie robi.
     */
    void removeFront();

    /**
     * @brief Usuwa element z końca listy.
     *
     * Jeśli lista jest pusta, metoda nic nie robi.
     */
    void removeBack();

    /**
     * @brief Usuwa wszystkie elementy z listy.
     *
     * Zwalnia pamięć wszystkich węzłów, pozostawiając listę pustą.
     */
    void clear();

    /**
     * @brief Wyświetla elementy listy od początku do końca.
     */
    void display() const;

    /**
     * @brief Wyświetla elementy listy od końca do początku.
     */
    void displayReverse() const;

    /**
     * @brief Zwraca iterator ustawiony na początek listy.
     *
     * @return Iterator wskazujący na pierwszy element listy (lub nieprawidłowy, jeśli lista jest pusta).
     */
    ListIterator<T> getIterator() const;
};

// Dla szablonów definicje muszą być widoczne przy kompilacji
#include "DoublyLinkedList.cpp"

#endif // DOUBLY_LINKED_LIST_H