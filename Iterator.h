/**
 * @file iterator.h
 * @brief Iterator dla listy dwukierunkowej.
 *
 * Plik zawiera szablon klasy ListIterator<T>, który umożliwia
 * przechodzenie po liście dwukierunkowej w obu kierunkach.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

/**
 * @brief Iterator do przechodzenia po liście dwukierunkowej.
 *
 * Klasa udostępnia operacje przechodzenia do następnego i poprzedniego
 * elementu oraz pobierania wartości aktualnego elementu. Iterator
 * przechowuje wskaźnik na aktualny węzeł listy.
 *
 * @tparam T Typ wartości przechowywanej w liście.
 */
template <typename T>
class ListIterator {
private:
    Node<T>* current;   ///< Wskaźnik na aktualny węzeł, na którym stoi iterator.

public:
    /**
     * @brief Konstruktor przyjmujący początkowy węzeł.
     *
     * @param startNode Wskaźnik na węzeł, od którego iterator rozpoczyna pracę.
     */
    explicit ListIterator(Node<T>* startNode);

    /**
     * @brief Sprawdza, czy istnieje następny element.
     *
     * @return @c true jeśli można przejść do następnego elementu, @c false w przeciwnym razie.
     */
    bool hasNext() const;

    /**
     * @brief Sprawdza, czy istnieje poprzedni element.
     *
     * @return @c true jeśli można przejść do poprzedniego elementu, @c false w przeciwnym razie.
     */
    bool hasPrev() const;

    /**
     * @brief Przechodzi do następnego elementu i zwraca jego wartość.
     *
     * @return Wartość następnego elementu.
     */
    T next();

    /**
     * @brief Przechodzi do poprzedniego elementu i zwraca jego wartość.
     *
     * @return Wartość poprzedniego elementu.
     */
    T prev();

    /**
     * @brief Zwraca wartość aktualnego elementu (bez przesuwania iteratora).
     *
     * @return Wartość elementu, na którym aktualnie stoi iterator.
     */
    T getCurrent() const;

    /**
     * @brief Sprawdza, czy iterator wskazuje na poprawny element.
     *
     * @return @c true jeśli iterator wskazuje na istniejący węzeł, @c false w przeciwnym razie.
     */
    bool isValid() const;
};

// Dla szablonów definicje muszą być widoczne przy kompilacji
#include "iterator.cpp"

#endif // ITERATOR_H