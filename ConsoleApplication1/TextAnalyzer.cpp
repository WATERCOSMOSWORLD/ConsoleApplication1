#if 0

#include <iostream>
#include <string>
#include <fstream> // Для работы с файлами
#include <locale>
#include <sstream> // Для подсчета слов (опционально, но удобно)

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filename;
    std::cout << "Введите имя файла для анализа: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return 1;
    }

    long long charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    std::string line;
    while (std::getline(inputFile, line)) {
        // Здесь твоя логика для подсчета символов, слов и строк
        // ...
    }

    // Здесь вывод результатов
    // ...

    inputFile.close();
    return 0;
}
#endif