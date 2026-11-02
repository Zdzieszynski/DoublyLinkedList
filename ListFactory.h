/**
 * @file ListFactory.h
 * @brief Wzorzec projektowy Factory do tworzenia listy dwukierunkowej na stercie.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

#include "DoublyLinkedList.h"

/**
 * @brief Fabryka tworząca listy dwukierunkowe na stercie.
 *
 * Wzorzec projektowy Factory — centralizuje tworzenie obiektów
 * DoublyLinkedList<T>, dzięki czemu klient nie musi znać szczegółów
 * alokacji.
 *
 * @tparam T Typ wartości przechowywanej w tworzonej liście.
 */
template <typename T>
class ListFactory {
public:
    /**
     * @brief Tworzy nową listę dwukierunkową na stercie.
     *
     * @return Wskaźnik na nowo utworzoną listę. Klient jest odpowiedzialny
     *         za zwolnienie pamięci (delete).
     */
    static DoublyLinkedList<T>* createList();
};

// Dla szablonów definicje muszą być widoczne przy kompilacji
#include "ListFactory.cpp"

#endif // LIST_FACTORY_H