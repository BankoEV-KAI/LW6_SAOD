//шестая лаба 1.3.5 - линейный динамический список с добавлением во вспомогательный список

#include "menu.h"
#include"structList.h"
#include <iostream>

int main()
{

    setlocale(LC_ALL, "ru");
    int data{ 0 }, operation{ 0 }, index{ 0 };
    while (true) {
        printMenu(1);
        enteringNumber(0, 6, operation);
        switch (operation)
        {
        case 0:
            clearList(mainListHeader); clearList(secondaryListHeader);
            return 0;
        case 1:
            std::cout << (isListEmpty(mainListHeader) ? "Список пуст." : "Список не пуст.") << std::endl;
            break;
        case 2: //добавление элемента
            printMenu(4);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                if (isListEmpty(mainListHeader)) {
                    std::cout << "Список пуст. Элемент будет добавлен в начало списка" << std::endl;
                    index = 0;
                }
                else {
                    printMenu(5);
                    enteringNumber(0, 2, operation);
                    switch (operation)
                    {
                    case 0: break;
                    case 1:
                        std::cout << "Ввод индекса элемента, до которого нужно вставить или -1, чтобы вставить в начало списка или -2, для вставки в конец" << std::endl;
                        enteringNumber(-2, countMain - 1, index);
                        index = index - 1;
                        break;
                    case 2:
                        std::cout << "Ввод индекса элемента, после которого нужно вставить или -1, чтобы вставить в начало списка или -2, для вставки в конец" << std::endl;
                        enteringNumber(-2, countMain - 1, index);
                        break;
                    default:
                        break;
                    }
                    
                }
                std::cout << "Ввод значения элемента списка" << std::endl;
                enteringNumber(1, 100, data);
                addNode(mainListHeader, data, index);
                countMain++;
                break;
            case 2:
                addFewItems(mainListHeader, 10);
                countMain += 10;
                break;
            default:
                break;
            }
            printList(mainListHeader);
            break;
        case 3: //перемещение элемента
            printMenu(2);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                std::cout << "Ввод индекса элемента для перемещения: " << std::endl;
                enteringNumber(0, countMain-1, index);
                removeNodeByIndex(mainListHeader, index);
                break;
            case 2:
                std::cout << "Ввод значения элемента для перемещения: " << std::endl;
                enteringNumber(1, 100, data);
                removeNodeByData(mainListHeader, data);
                break;
            default:
                break;
            }
            std::cout << "Главный список: ";
            printList(mainListHeader);
            std::cout << "Дополнительный список: ";
            printList(secondaryListHeader);
            break;
        case 4: //поиск элемента
            printMenu(3);
            enteringNumber(0, 2, operation);
            switch (operation)
            {
            case 0:
                break;
            case 1:
                printList(mainListHeader);
                std::cout << "Ввод индекса элемента для поиска: " << std::endl;
                enteringNumber(0, countMain-1, index);
                std::cout << "Значение элемента по заданному индексу: " << printDataFromIndex(mainListHeader,index) << std::endl;
                break;
            case 2:
                printList(mainListHeader);
                std::cout << "Ввод значения элемента для поиска: " << std::endl;
                enteringNumber(1, 100, data);
                index = findIndexByValue(mainListHeader, data);
                (index != -1) ? std::cout << "Элемент найден на позиции: " << index << std::endl : std::cout << "Искомый элемент отсутствует в списке." << std::endl;
                break;
            default:
                break;
            }
            break;
        case 5:
            printList(mainListHeader);
            break;
        case 6:
            printList(secondaryListHeader);
            break;
        default:
            break;
        }
    }
}

