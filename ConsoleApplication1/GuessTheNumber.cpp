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

    std::cout << "����� ���������� � ���� '������ �����'!" << std::endl;
    std::cout << "� ������� ����� �� 1 �� 100. �������� �������!" << std::endl;

    // ��� ����� ���������� ���� ����
    do {
        std::cout << "������� ���� �������������: ";
        std::cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            std::cout << "������!" << std::endl;
        }
        else if (guess < randomNumber) {
            std::cout << "������!" << std::endl;
        }
        else {
            std::cout << "����������! �� ������ ����� " << randomNumber << " �� " << attempts << " �������!" << std::endl;
        }

    } while (guess != randomNumber); // ���� ����� �����������, ���� guess �� ����� randomNumber

    // ��������� �����, ����� ������� �� �����������
    std::cout << "������� ����� �������, ����� ���������...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
#endif