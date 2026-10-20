#include <iostream>
#include "ListFactory.h"

int main() {
    std::cout << "=== URUCHOMIENIE PROGRAMU TESTOWEGO LISTY DWUKIERUNKOWEJ ===\n\n";

    // Tworzenie listy na stercie przy użyciu wzorca Factory
    DoublyLinkedList<int>* myList = ListFactory<int>::createList();

    // Test dodawania elementów
    myList->addBack(10);
    myList->addBack(20);
    myList->addFront(5);
    myList->display(); // Powinno być: 5 10 20

    myList->addBack(30);
    myList->display(); // Powinno być: 5 10 20 30

    // Test wyświetlania w odwrotnej kolejności
    myList->displayReverse(); // Powinno być: 30 20 10 5

    // Test usuwania elementów
    std::cout << "\n--- Usuwanie elementów ---\n";
    myList->removeFront();
    myList->display(); // Powinno być: 10 20 30

    myList->removeBack();
    myList->display(); // Powinno być: 10 20

    // Test wzorca Iteratora
    std::cout << "\n--- Testowanie Iteratora ---\n";
    myList->addBack(50);
    myList->addBack(100);
    myList->display(); // Powinno być: 10 20 50 100

    ListIterator<int> it = myList->getIterator();
    if (it.isValid()) {
        std::cout << "Początkowy element iteratora: " << it.getCurrent() << "\n";
        
        if (it.hasNext()) {
            std::cout << "Następny element: " << it.next() << "\n";
        }
        if (it.hasNext()) {
            std::cout << "Następny element: " << it.next() << "\n";
        }
        if (it.hasPrev()) {
            std::cout << "Poprzedni element: " << it.prev() << "\n";
        }
    }

    // Czyszczenie pamięci
    std::cout << "\n--- Czyszczenie pamięci (sterfa) ---\n";
    myList->clear();
    myList->display();

    // Zwolnienie pamięci samej fabrykowanej listy
    delete myList;

    std::cout << "\nKoniec testów pomyślny!\n";
    return 0;
}