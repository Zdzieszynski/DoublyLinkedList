/**
 * @file Node.h
 * @brief Definicja pojedynczego węzła listy dwukierunkowej.
 *
 * Plik zawiera szablon struktury Node<T>, który przechowuje wartość
 * oraz wskaźniki na poprzedni i następny element listy.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#ifndef NODE_H
#define NODE_H

/**
 * @brief Pojedynczy element (węzeł) listy dwukierunkowej.
 *
 * Struktura przechowuje wartość typu T oraz wskaźniki na sąsiednie
 * węzły, co umożliwia przechodzenie po liście w obu kierunkach.
 *
 * @tparam T Typ przechowywanej wartości.
 */
template <typename T>
struct Node {
    T data;         ///< Wartość przechowywana w węźle.
    Node* next;     ///< Wskaźnik na następny węzeł (nullptr dla ostatniego).
    Node* prev;     ///< Wskaźnik na poprzedni węzeł (nullptr dla pierwszego).

    /**
     * @brief Konstruktor tworzący węzeł z podaną wartością.
     *
     * Inicjalizuje pole @c data oraz ustawia wskaźniki @c next i @c prev
     * na @c nullptr.
     *
     * @param wartosc Wartość, która zostanie zapisana w węźle.
     */
    Node(const T& wartosc) {
        data = wartosc;
        next = nullptr;
        prev = nullptr;
    }
};

#endif // NODE_H