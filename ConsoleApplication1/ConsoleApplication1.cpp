#if 0

#include <iostream>
#include <locale> // Необходима для работы с русским языком

int main() {
    // Устанавливаем русскую локаль для консоли
    setlocale(LC_ALL, "Russian");

    double число1, число2;
    char операция;

    std::cout << "Введите первое число: ";
    std::cin >> число1;

    std::cout << "Введите операцию (+, -, *, /): ";
    std::cin >> операция;

    std::cout << "Введите второе число: ";
    std::cin >> число2;

    double результат;

    switch (операция) {
    case '+':
        результат = число1 + число2;
        std::cout << "Сумма: " << результат << std::endl;
        break;
    case '-':
        результат = число1 - число2;
        std::cout << "Разность: " << результат << std::endl;
        break;
    case '*':
        результат = число1 * число2;
        std::cout << "Произведение: " << результат << std::endl;
        break;
    case '/':
        if (число2 != 0) {
            результат = число1 / число2;
            std::cout << "Частное: " << результат << std::endl;
        }
        else {
            std::cout << "Ошибка! Деление на ноль невозможно." << std::endl;
        }
        break;
    default:
        std::cout << "Ошибка! Неверная операция." << std::endl;
        break;
    }

    std::cout << "Нажмите любую клавишу, чтобы завершить...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}

#endif