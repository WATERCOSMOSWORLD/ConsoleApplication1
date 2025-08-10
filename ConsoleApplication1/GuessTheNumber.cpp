#if 0

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    std::cout << "Добро пожаловать в игру 'Угадай число'!" << std::endl;
    std::cout << "Я загадал число от 1 до 100. Попробуй угадать!" << std::endl;

    // Вот здесь начинается цикл игры
    do {
        std::cout << "Введите свое предположение: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "Меньше!" << std::endl;
        }
        else if (guess < randomNumber) {
            std::cout << "Больше!" << std::endl;
        }
        else {
            std::cout << "Поздравляю! Ты угадал число " << randomNumber << " за " << attempts << " попыток!" << std::endl;
        }

    } while (guess != randomNumber); // Цикл будет повторяться, пока guess не равен randomNumber

    // Добавляем паузу, чтобы консоль не закрывалась
    std::cout << "Нажмите любую клавишу, чтобы завершить...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
#endif