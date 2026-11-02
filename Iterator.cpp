/**
 * @file iterator.cpp
 * @brief Implementacja metod szablonu ListIterator.
 *
 * Plik jest dołączany przez iterator.h (poprzez #include "iterator.cpp"
 * na końcu nagłówka). Nie kompiluj go osobno.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#include "iterator.h"

/**
 * @brief Konstruktor przyjmujący początkowy węzeł.
 *
 * @param startNode Wskaźnik na węzeł, od którego iterator rozpoczyna pracę.
 */
template <typename T>
ListIterator<T>::ListIterator(Node<T>* startNode)
    : current(startNode) {
}

/**
 * @brief Sprawdza, czy istnieje następny element.
 *
 * @return @c true jeśli można przejść do następnego elementu.
 */
template <typename T>
bool ListIterator<T>::hasNext() const {
    return current != nullptr && current->next != nullptr;
}

/**
 * @brief Sprawdza, czy istnieje poprzedni element.
 *
 * @return @c true jeśli można przejść do poprzedniego elementu.
 */
template <typename T>
bool ListIterator<T>::hasPrev() const {
    return current != nullptr && current->prev != nullptr;
}

/**
 * @brief Przechodzi do następnego elementu i zwraca jego wartość.
 *
 * @return Wartość następnego elementu.
 */
template <typename T>
T ListIterator<T>::next() {
    current = current->next;
    return current->data;
}

/**
 * @brief Przechodzi do poprzedniego elementu i zwraca jego wartość.
 *
 * @return Wartość poprzedniego elementu.
 */
template <typename T>
T ListIterator<T>::prev() {
    current = current->prev;
    return current->data;
}

/**
 * @brief Zwraca wartość aktualnego elementu (bez przesuwania iteratora).
 *
 * @return Wartość elementu, na którym aktualnie stoi iterator.
 */
template <typename T>
T ListIterator<T>::getCurrent() const {
    return current->data;
}

/**
 * @brief Sprawdza, czy iterator wskazuje na poprawny element.
 *
 * @return @c true jeśli iterator wskazuje na istniejący węzeł.
 */
template <typename T>
bool ListIterator<T>::isValid() const {
    return current != nullptr;
}