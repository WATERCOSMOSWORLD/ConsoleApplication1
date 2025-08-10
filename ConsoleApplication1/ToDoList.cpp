#if 0

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <locale>

struct Task {
    int id;
    std::string text;
    bool isDone;
};

// ======================= ���������� ������� =======================

// ������� ��� ���������� ����� � ����
void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.id << "," << task.text << "," << task.isDone << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������.\n";
    }
}

// ������� ��� �������� ����� �� �����
std::vector<Task> loadTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    if (file.is_open()) {
        int id;
        std::string text;
        bool isDone;
        std::string line;

        while (std::getline(file, line)) {
            // ����� ������� ����������, ����� ��������
            // ����� �� ������ ��������� ������, �����������, ��� ��� � ���������� �������
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            id = std::stoi(line.substr(0, pos1));
            text = line.substr(pos1 + 1, pos2 - pos1 - 1);
            isDone = (line.substr(pos2 + 1) == "1");

            tasks.push_back({ id, text, isDone });
        }
        file.close();
    }
    return tasks;
}

// ������� ��� ���������� ����� ������
void addTask(std::vector<Task>& tasks) {
    std::string text;
    std::cout << "������� ����� ����� ������: ";
    std::cin.ignore(); // ������� ����� �����
    std::getline(std::cin, text);

    int newId = 1;
    if (!tasks.empty()) {
        newId = tasks.back().id + 1;
    }
    tasks.push_back({ newId, text, false });
    std::cout << "������ ���������!\n";
}

// ������� ��� ������ ���� �����
void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- ������ ����� ---\n";
    if (tasks.empty()) {
        std::cout << "������ ����� ����.\n";
        return;
    }
    for (const auto& task : tasks) {
        std::cout << task.id << ". [" << (task.isDone ? "X" : " ") << "] " << task.text << std::endl;
    }
}

// ������� ��� ������� ������ ��� �����������
void completeTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "������� ID ������, ������� ����� �������� ��� �����������: ";
    std::cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            task.isDone = true;
            std::cout << "������ #" << id << " �������� ��� �����������.\n";
            return;
        }
    }
    std::cout << "������ � ID #" << id << " �� �������.\n";
}

// ������� ��� �������� ������
void deleteTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "������� ID ������ ��� ��������: ";
    std::cin >> id;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            std::cout << "������ #" << id << " �������.\n";
            return;
        }
    }
    std::cout << "������ � ID #" << id << " �� �������.\n";
}

// ====================================================================

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Task> tasks = loadTasksFromFile("tasks.txt");

    int choice;
    while (true) {
        std::cout << "\n--- �������� ����� ---\n";
        std::cout << "1. �������� ������\n";
        std::cout << "2. �������� ������\n";
        std::cout << "3. �������� ������ ��� �����������\n";
        std::cout << "4. ������� ������\n";
        std::cout << "5. �����\n";
        std::cout << "�������� ��������: ";
        std::cin >> choice;

        // ��������� ������ ������������
        switch (choice) {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            completeTask(tasks);
            break;
        case 4:
            deleteTask(tasks);
            break;
        case 5:
            saveTasksToFile(tasks, "tasks.txt");
            std::cout << "������ ���������. �� ��������!\n";
            return 0;
        default:
            std::cout << "�������� �����. ���������� ��� ���.\n";
            break;
        }
    }

    return 0;
}
#endif