#if 0

#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <limits> // ��� std::numeric_limits
#include <iomanip> // ��� �������������� ������

// ======================= ����� Student =======================

class Student {
public:
    int id;
    std::string name;
    std::string lastName;
    int age;
    double gpa; // ������� ����

    // ����������� �� ���������
    Student() : id(0), name(""), lastName(""), age(0), gpa(0.0) {}

    // ����� ��� ������ ���������� � ��������
    void display() const {
        std::cout << std::left << std::setw(5) << id
            << std::left << std::setw(15) << name
            << std::left << std::setw(15) << lastName
            << std::left << std::setw(8) << age
            << std::left << std::setw(5) << std::fixed << std::setprecision(2) << gpa << std::endl;
    }
};

// ======================= ������� ��� ���������� =======================

// ������� ��� ���������� ������ ��������
void addStudent(std::vector<Student>& students, int& nextId) {
    Student newStudent;
    newStudent.id = nextId++;

    std::cout << "������� ���: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������
    std::getline(std::cin, newStudent.name);

    std::cout << "������� �������: ";
    std::getline(std::cin, newStudent.lastName);

    std::cout << "������� �������: ";
    std::cin >> newStudent.age;

    std::cout << "������� ������� ����: ";
    std::cin >> newStudent.gpa;

    students.push_back(newStudent);
    std::cout << "������� ������� ��������!\n";
}

// ������� ��� ������ ���� ���������
void viewStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "������ ��������� ����.\n";
        return;
    }

    std::cout << "\n--- ������ ��������� ---\n";
    std::cout << std::left << std::setw(5) << "ID"
        << std::left << std::setw(15) << "���"
        << std::left << std::setw(15) << "�������"
        << std::left << std::setw(8) << "�������"
        << std::left << std::setw(5) << "GPA" << std::endl;
    std::cout << "--------------------------------------------------------\n";

    for (const auto& student : students) {
        student.display();
    }
}

// ������� ��� ������ �������� �� ID
void findStudent(const std::vector<Student>& students) {
    int id;
    std::cout << "������� ID �������� ��� ������: ";
    std::cin >> id;

    for (const auto& student : students) {
        if (student.id == id) {
            std::cout << "\n--- ��������� ������� ---\n";
            student.display();
            return;
        }
    }
    std::cout << "������� � ID " << id << " �� ������.\n";
}

// ������� ��� �������� �������� �� ID
void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "������� ID �������� ��� ��������: ";
    std::cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            std::cout << "������� � ID " << id << " ������� ������.\n";
            return;
        }
    }
    std::cout << "������� � ID " << id << " �� ������.\n";
}

// ======================= ������� ������� =======================

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> students;
    int nextId = 1;

    int choice;
    while (true) {
        std::cout << "\n--- ������� ���������� ���������� ---\n";
        std::cout << "1. �������� ��������\n";
        std::cout << "2. �������� ���� ���������\n";
        std::cout << "3. ����� �������� �� ID\n";
        std::cout << "4. ������� �������� �� ID\n";
        std::cout << "5. �����\n";
        std::cout << "�������� ��������: ";

        // ��������� ������������� �����
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // ������������ �����
        }

        if (choice == 5) {
            std::cout << "�� ��������!\n";
            break;
        }

        switch (choice) {
        case 1:
            addStudent(students, nextId);
            break;
        case 2:
            viewStudents(students);
            break;
        case 3:
            findStudent(students);
            break;
        case 4:
            deleteStudent(students);
            break;
        default:
            std::cout << "�������� �����. ���������� ��� ���.\n";
            break;
        }
    }

    return 0;
}
#endif