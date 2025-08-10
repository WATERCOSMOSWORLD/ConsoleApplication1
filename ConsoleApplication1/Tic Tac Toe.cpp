#if 0

#include <iostream>
#include <vector>
#include <locale>

// Универсальная функция для очистки экрана
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Функция для вывода игрового поля
void drawBoard(const std::vector<std::vector<char>>& board) {
    std::cout << "\n-------------\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "| ";
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

// Функция для проверки победы
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // Проверка строк
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // Проверка столбцов
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // Проверка диагоналей
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// Функция для проверки ничьей
bool checkDraw(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// ====================================================================

int main() {
    setlocale(LC_ALL, "Russian");

    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    std::cout << "Добро пожаловать в игру 'Крестики-нолики'!" << std::endl;
    std::cout << "Игрок 'X' ходит первым.\n";
    std::cout << "Нажмите Enter для начала...";
    std::cin.get(); // Ожидаем нажатия Enter

    while (true) {
        clearScreen(); // Очистка экрана
        drawBoard(board);

        int row, col;
        std::cout << "Ходит игрок " << currentPlayer << ". Введите номер строки (0-2) и столбца (0-2): ";
        std::cin >> row >> col;

        // Проверка корректности хода
        if (std::cin.fail() || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cin.clear(); // Сбрасываем флаг ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем остаток строки

            clearScreen();
            drawBoard(board);
            std::cout << "Некорректный ход! Введите числа от 0 до 2 для пустой клетки.\n";
            std::cout << "Нажмите Enter для продолжения...";
            std::cin.get(); // Ожидаем Enter
            std::cin.get(); // Ожидаем Enter
            continue; // Начинаем цикл заново
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            clearScreen();
            drawBoard(board);
            std::cout << "Игрок " << currentPlayer << " победил!" << std::endl;
            break;
        }

        if (checkDraw(board)) {
            clearScreen();
            drawBoard(board);
            std::cout << "Ничья!" << std::endl;
            break;
        }

        // Смена игрока
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    std::cout << "Нажмите любую клавишу, чтобы завершить...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
#endif