/**
 * @file ListFactory.cpp
 * @brief Implementacja metod szablonu ListFactory.
 *
 * Plik jest dołączany przez ListFactory.h (poprzez
 * #include "ListFactory.cpp" na końcu nagłówka).
 * Nie kompiluj go osobno.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#include "ListFactory.h"

/**
 * @brief Tworzy nową listę dwukierunkową na stercie.
 *
 * @return Wskaźnik na nowo utworzoną listę.
 */
template <typename T>
DoublyLinkedList<T>* ListFactory<T>::createList() {
    return new DoublyLinkedList<T>();
}