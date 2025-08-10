#if 0

#include <iostream>
#include <vector>
#include <string>
#include <locale>
#include <limits> // Для std::numeric_limits
#include <iomanip> // Для форматирования вывода

// ======================= Класс Student =======================

class Student {
public:
    int id;
    std::string name;
    std::string lastName;
    int age;
    double gpa; // Средний балл

    // Конструктор по умолчанию
    Student() : id(0), name(""), lastName(""), age(0), gpa(0.0) {}

    // Метод для вывода информации о студенте
    void display() const {
        std::cout << std::left << std::setw(5) << id
            << std::left << std::setw(15) << name
            << std::left << std::setw(15) << lastName
            << std::left << std::setw(8) << age
            << std::left << std::setw(5) << std::fixed << std::setprecision(2) << gpa << std::endl;
    }
};

// ======================= Функции для управления =======================

// Функция для добавления нового студента
void addStudent(std::vector<Student>& students, int& nextId) {
    Student newStudent;
    newStudent.id = nextId++;

    std::cout << "Введите имя: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
    std::getline(std::cin, newStudent.name);

    std::cout << "Введите фамилию: ";
    std::getline(std::cin, newStudent.lastName);

    std::cout << "Введите возраст: ";
    std::cin >> newStudent.age;

    std::cout << "Введите средний балл: ";
    std::cin >> newStudent.gpa;

    students.push_back(newStudent);
    std::cout << "Студент успешно добавлен!\n";
}

// Функция для вывода всех студентов
void viewStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "Список студентов пуст.\n";
        return;
    }

    std::cout << "\n--- Список студентов ---\n";
    std::cout << std::left << std::setw(5) << "ID"
        << std::left << std::setw(15) << "Имя"
        << std::left << std::setw(15) << "Фамилия"
        << std::left << std::setw(8) << "Возраст"
        << std::left << std::setw(5) << "GPA" << std::endl;
    std::cout << "--------------------------------------------------------\n";

    for (const auto& student : students) {
        student.display();
    }
}

// Функция для поиска студента по ID
void findStudent(const std::vector<Student>& students) {
    int id;
    std::cout << "Введите ID студента для поиска: ";
    std::cin >> id;

    for (const auto& student : students) {
        if (student.id == id) {
            std::cout << "\n--- Найденный студент ---\n";
            student.display();
            return;
        }
    }
    std::cout << "Студент с ID " << id << " не найден.\n";
}

// Функция для удаления студента по ID
void deleteStudent(std::vector<Student>& students) {
    int id;
    std::cout << "Введите ID студента для удаления: ";
    std::cin >> id;

    for (size_t i = 0; i < students.size(); ++i) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            std::cout << "Студент с ID " << id << " успешно удален.\n";
            return;
        }
    }
    std::cout << "Студент с ID " << id << " не найден.\n";
}

// ======================= Главная функция =======================

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Student> students;
    int nextId = 1;

    int choice;
    while (true) {
        std::cout << "\n--- Система управления студентами ---\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Показать всех студентов\n";
        std::cout << "3. Найти студента по ID\n";
        std::cout << "4. Удалить студента по ID\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите действие: ";

        // Обработка некорректного ввода
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0; // Некорректный выбор
        }

        if (choice == 5) {
            std::cout << "До свидания!\n";
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
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    }

    return 0;
}
#endif