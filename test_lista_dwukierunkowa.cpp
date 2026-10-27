#include <iostream>

// ==========================================
// 1. KLASA WĘZŁA (Node) - pojedynczy "wagon"
// ==========================================
class Node {
private:
    int data;       // Wartość przechowywana w węźle
    Node* next;     // Wskaźnik na następny element
    Node* prev;     // Wskaźnik na poprzedni element

public:
    // Konstruktor
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }

    // Gettery i Settery
    int getData() const { return data; }
    
    Node* getNext() const { return next; }
    void setNext(Node* node) { next = node; }

    Node* getPrev() const { return prev; }
    void setPrev(Node* node) { prev = node; }
};

// ==========================================
// 2. KLASA LISTY DWUKIERUNKOWEJ (DoublyLinkedList)
// ==========================================
class DoublyLinkedList {
private:
    Node* head; // Wskazuje na początek listy
    Node* tail; // Wskazuje na koniec listy

public:
    // Konstruktor - pusta lista
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Destruktor - sprząta pamięć ze sterty po usunięciu listy
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->getNext();
            delete current; // Zwalnianie pamięci (sterta!)
            current = nextNode;
        }
    }

    // DODawanie elementu na koniec listy (pushBack)
    void pushBack(int value) {
        // Tworzymy nowy węzeł dynamicznie na stercie za pomocą 'new'
        Node* newNode = new Node(value);

        // Jeśli lista jest pusta
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            // Podłączamy nowy węzeł na końcu
            tail->setNext(newNode);
            newNode->setPrev(tail);
            tail = newNode; // Nowy węzeł staje się nowym ogonem
        }
    }

    // WYŚWIETLANIE listy od początku do końca
    void displayForward() {
        Node* current = head;
        std::cout << "Lista (od przodu): ";
        while (current != nullptr) {
            std::cout << "[" << current->getData() << "] <-> ";
            current = current->getNext();
        }
        std::cout << "nullptr" << std::endl;
    }

    // WYŚWIETLANIE listy od końca do początku (wykorzystujemy wskaźnik 'tail' i 'prev'!)
    void displayBackward() {
        Node* current = tail;
        std::cout << "Lista (od tyłu):   ";
        while (current != nullptr) {
            std::cout << "[" << current->getData() << "] <-> ";
            current = current->getPrev();
        }
        std::cout << "nullptr" << std::endl;
    }
};

// ==========================================
// 3. FUNKCJA MAIN - testujemy działanie
// ==========================================
int main() {
    DoublyLinkedList myList;

    std::cout << "Dodajemy elementy: 10, 20, 30\n";
    myList.pushBack(10);
    myList.pushBack(20);
    myList.pushBack(30);

    // Testujemy chodzenie w przód
    myList.displayForward();

    // Testujemy chodzenie w tył (magia listy dwukierunkowej!)
    myList.displayBackward();

    return 0;
}