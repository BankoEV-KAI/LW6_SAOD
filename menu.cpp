#include "menu.h"
#include <iostream>


void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;
    switch (operation)
    {
    case 1:
        std::cout << std::endl
            << "1. Проверка пустоты списка; " << std::endl
            << "2. Добавление элемента в список;" << std::endl
            << "3. Удаление элемента из списка; " << std::endl
            << "4. Поиск элемента в списке; " << std::endl
            << "5. Вывод текущего состояния списка; " << std::endl
            << "6. Вывод текущего состояния ДОПОЛНИТЕЛЬНОГО списка; " << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 2:
        std::cout << std::endl
            << "1. Перемещение элемента по индексу; " << std::endl
            << "2. Перемещение элемента по значению;" << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 3:
        std::cout << std::endl
            << "1. Поиск элемента по индексу; " << std::endl
            << "2. Поиск элемента по значению;" << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 4:
        std::cout << std::endl
            << "1. Добавить один элемент; " << std::endl
            << "2. Случайное заполнение;" << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    case 5:
        std::cout << std::endl
            << "1. Вставить до" << std::endl
            << "2. Вставить после" << std::endl
            << "0. Вернуться в начало" << std::endl;
        break;
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}