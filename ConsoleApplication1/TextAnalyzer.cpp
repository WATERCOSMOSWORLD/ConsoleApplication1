#if 0

#include <iostream>
#include <string>
#include <fstream> // ��� ������ � �������
#include <locale>
#include <sstream> // ��� �������� ���� (�����������, �� ������)

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filename;
    std::cout << "������� ��� ����� ��� �������: ";
    std::cin >> filename;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "������: �� ������� ������� ���� " << filename << std::endl;
        return 1;
    }

    long long charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    std::string line;
    while (std::getline(inputFile, line)) {
        // ����� ���� ������ ��� �������� ��������, ���� � �����
        // ...
    }

    // ����� ����� �����������
    // ...

    inputFile.close();
    return 0;
}
#endif