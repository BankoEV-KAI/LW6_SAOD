#include "structList.h"
#include <iostream>

int countMain{ 0 }, countSecond{ 0 };
listNode* mainListHeader = nullptr;
listNode* secondaryListHeader = nullptr;

bool isListEmpty(listNode*& current) {
    return (current == nullptr);
}

void addNode(listNode*& listHeader, int newData, int index) {
    listNode* newNode = new listNode{ newData, nullptr };

    if (listHeader == nullptr || index == -1) {
        newNode->next = listHeader;
        listHeader = newNode;
        std::cout << "Ёлемент " << newData << " добавлен в начало списка" << std::endl;
        return;
    }
    else if (index == -2) {
        listNode* current = listHeader;
        while (current->next != nullptr) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        std::cout << "Ёлемент " << newData << " добавлен в конец списка" << std::endl;
        return;
    }
    else {
        listNode* current = listHeader;
        for (int i = 0; i < index && current->next != nullptr; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    std::cout << "Ёлемент " << newData << " добавлен на позицию " << index + 1 << std::endl;
}

//нужно будет еще допом минусовать эл-т где-то в мейне
void deleteNode(listNode*& listHeader, int index) {
    listNode* current = listHeader;

    if (index == 0) {
        listNode* removedNode = listHeader;
        listHeader = listHeader->next;
        delete removedNode;
    }
    else {
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        listNode* removedNode = current->next;
        current->next = removedNode->next;
        delete removedNode;
    }
}

int findIndexByValue(listNode* listHeader, int value) {
    listNode* current = listHeader;
    int index = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return index; 
        }
        current = current->next;
        index++;
    }
    return -1; 
}

int printDataFromIndex(listNode* listHeader, int index) {
    listNode* current = listHeader;
    for (int i{ 0 }; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

void removeNodeByIndex(listNode*& listHeader, int index) {
    listNode* current = listHeader;
    if (isListEmpty(current)) {
        std::cout << "—писок пуст" << std::endl;
        return;
    }

    if (index == -1) {
        std::cout << "»скомый элемент отсутствует в списке." << std::endl;
        return;
    }

    if (index == 0) {
        listNode* removedNode = listHeader;
        listHeader = listHeader->next;
        removedNode->next = secondaryListHeader;
        secondaryListHeader = removedNode;

        std::cout << "Ёлемент перемещен во вспомогательный список" << std::endl;
        countMain--;
        countSecond++;
        return;
    }

    for (int i = 0; i < index - 1 && current->next != nullptr; ++i) {
        current = current->next;
    }

    if (current->next == nullptr) {
        std::cout << "»скомый элемент отсутствует в списке." << std::endl;
        return;
    }

    listNode* removedNode = current->next;
    current->next = removedNode->next;
    removedNode->next = secondaryListHeader;
    secondaryListHeader = removedNode;

    std::cout << "Ёлемент перемещен во вспомогательный список" << std::endl;
    countMain--;
    countSecond++;
}

void removeNodeByData(listNode*& current, int searchData) {
    removeNodeByIndex(current, findIndexByValue(current, searchData));
}

void printList(listNode*& listHeader) {
    listNode* current = listHeader;
    std::cout << "элементы списка: (";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << ")" << std::endl;
}

void clearList(listNode*& current) {
    while (current != nullptr) {
        listNode* temp = current;
        current = current->next;
        delete temp;
    }
}

void addFewItems(listNode*& listHeader, int count) {
    srand(time(0));
    for (int i{ 0 }; i < count; i++) {
        addNode(listHeader, rand() % 100, -2);
    }
}