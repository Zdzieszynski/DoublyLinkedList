/**
 * @file DoublyLinkedList.cpp
 * @brief Implementacja metod szablonu DoublyLinkedList.
 *
 * Plik jest dołączany przez DoublyLinkedList.h (poprzez
 * #include "DoublyLinkedList.cpp" na końcu nagłówka).
 * Nie kompiluj go osobno.
 *
 * @author Krzysztof Zdzieszyński
 * @date 2026-10-27
 */

#include "DoublyLinkedList.h"

/**
 * @brief Konstruktor tworzący pustą listę.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
    : head(nullptr), tail(nullptr), count(0) {
}

/**
 * @brief Destruktor zwalniający całą pamięć listy.
 */
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

/**
 * @brief Sprawdza, czy lista jest pusta.
 *
 * @return @c true jeśli lista nie zawiera elementów.
 */
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

/**
 * @brief Dodaje element na początek listy.
 *
 * @param val Wartość do dodania.
 */
template <typename T>
void DoublyLinkedList<T>::addFront(const T& val) {
    Node<T>* newNode = new Node<T>(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

/**
 * @brief Dodaje element na koniec listy.
 *
 * @param val Wartość do dodania.
 */
template <typename T>
void DoublyLinkedList<T>::addBack(const T& val) {
    Node<T>* newNode = new Node<T>(val);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

/**
 * @brief Usuwa element z początku listy.
 */
template <typename T>
void DoublyLinkedList<T>::removeFront() {
    if (isEmpty()) return;
    Node<T>* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr; // lista stała się pusta
    }
    delete temp;
    count--;
}

/**
 * @brief Usuwa element z końca listy.
 */
template <typename T>
void DoublyLinkedList<T>::removeBack() {
    if (isEmpty()) return;
    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr; // lista stała się pusta
    }
    delete temp;
    count--;
}

/**
 * @brief Usuwa wszystkie elementy z listy.
 */
template <typename T>
void DoublyLinkedList<T>::clear() {
    while (!isEmpty()) {
        removeFront();
    }
}

/**
 * @brief Wyświetla elementy listy od początku do końca.
 */
template <typename T>
void DoublyLinkedList<T>::display() const {
    Node<T>* current = head;
    std::cout << "Lista: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

/**
 * @brief Wyświetla elementy listy od końca do początku.
 */
template <typename T>
void DoublyLinkedList<T>::displayReverse() const {
    Node<T>* current = tail;
    std::cout << "Lista od tylu: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

/**
 * @brief Zwraca iterator ustawiony na początek listy.
 *
 * @return Iterator wskazujący na pierwszy element listy.
 */
template <typename T>
ListIterator<T> DoublyLinkedList<T>::getIterator() const {
    return ListIterator<T>(head);
}