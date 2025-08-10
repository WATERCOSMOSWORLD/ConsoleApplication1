#if 0

#include <iostream>
#include <vector>
#include <locale>

// ������������� ������� ��� ������� ������
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// ������� ��� ������ �������� ����
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

// ������� ��� �������� ������
bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    // �������� �����
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }
    // �������� ��������
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {
            return true;
        }
    }
    // �������� ����������
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

// ������� ��� �������� ������
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

    std::cout << "����� ���������� � ���� '��������-������'!" << std::endl;
    std::cout << "����� 'X' ����� ������.\n";
    std::cout << "������� Enter ��� ������...";
    std::cin.get(); // ������� ������� Enter

    while (true) {
        clearScreen(); // ������� ������
        drawBoard(board);

        int row, col;
        std::cout << "����� ����� " << currentPlayer << ". ������� ����� ������ (0-2) � ������� (0-2): ";
        std::cin >> row >> col;

        // �������� ������������ ����
        if (std::cin.fail() || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cin.clear(); // ���������� ���� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���������� ������� ������

            clearScreen();
            drawBoard(board);
            std::cout << "������������ ���! ������� ����� �� 0 �� 2 ��� ������ ������.\n";
            std::cout << "������� Enter ��� �����������...";
            std::cin.get(); // ������� Enter
            std::cin.get(); // ������� Enter
            continue; // �������� ���� ������
        }

        board[row][col] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            clearScreen();
            drawBoard(board);
            std::cout << "����� " << currentPlayer << " �������!" << std::endl;
            break;
        }

        if (checkDraw(board)) {
            clearScreen();
            drawBoard(board);
            std::cout << "�����!" << std::endl;
            break;
        }

        // ����� ������
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }
    }

    std::cout << "������� ����� �������, ����� ���������...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
#endif