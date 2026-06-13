#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Основна структура за елемент от стек или списък
struct Node {
    int data;
    Node* next;
};

// Функция за добавяне в стек (в началото)
void push(Node* &top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Функция за добавяне в списък в нарастващ ред
void insertSorted(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    // Ако списъкът е празен или новото число е най-малко
    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Намиране на мястото за вмъкване
    Node* current = head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Функция за проверка дали число съществува в стека
bool existsInStack(Node* top, int value) {
    Node* temp = top;
    while (temp != NULL) {
        if (temp->data == value) return true;
        temp = temp->next;
    }
    return false;
}

// Функция за принтиране
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    srand(time(0)); // За различни произволни числа при всяко пускане

    int N;
    cout << "Въведете брой елементи N: ";
    cin >> N;

    Node* p = NULL;
    Node* q = NULL;
    Node* resultList = NULL;

    // 1. Пълним двата стека с произволни числа (от 1 до 50 за прегледност)
    for (int i = 0; i < N; i++) {
        push(p, rand() % 50 + 1);
        push(q, rand() % 50 + 1);
    }

    cout << "Стек p: ";
    printList(p);
    cout << "Стек q: ";
    printList(q);

    // 2. Логика: Елементи от p, които ги няма в q
    Node* tempP = p;
    while (tempP != NULL) {
        if (!existsInStack(q, tempP->data)) {
            insertSorted(resultList, tempP->data);
        }
        tempP = tempP->next;
    }

    // 3. Извеждане на резултата
    cout << "Резултатен сортиран списък (елементи от p, които ги няма в q):" << endl;
    if (resultList == NULL) {
        cout << "(няма такива елементи)" << endl;
    } else {
        printList(resultList);
    }

    return 0;
}
