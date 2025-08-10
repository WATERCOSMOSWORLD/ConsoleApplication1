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

// ======================= Реализация функций =======================

// Функция для сохранения задач в файл
void saveTasksToFile(const std::vector<Task>& tasks, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.id << "," << task.text << "," << task.isDone << std::endl;
        }
        file.close();
    }
    else {
        std::cerr << "Не удалось открыть файл для записи.\n";
    }
}

// Функция для загрузки задач из файла
std::vector<Task> loadTasksFromFile(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream file(filename);
    if (file.is_open()) {
        int id;
        std::string text;
        bool isDone;
        std::string line;

        while (std::getline(file, line)) {
            // Очень простая реализация, можно улучшить
            // Здесь мы просто считываем данные, предполагая, что они в правильном формате
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

// Функция для добавления новой задачи
void addTask(std::vector<Task>& tasks) {
    std::string text;
    std::cout << "Введите текст новой задачи: ";
    std::cin.ignore(); // Очищаем буфер ввода
    std::getline(std::cin, text);

    int newId = 1;
    if (!tasks.empty()) {
        newId = tasks.back().id + 1;
    }
    tasks.push_back({ newId, text, false });
    std::cout << "Задача добавлена!\n";
}

// Функция для вывода всех задач
void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "\n--- Список задач ---\n";
    if (tasks.empty()) {
        std::cout << "Список задач пуст.\n";
        return;
    }
    for (const auto& task : tasks) {
        std::cout << task.id << ". [" << (task.isDone ? "X" : " ") << "] " << task.text << std::endl;
    }
}

// Функция для пометки задачи как выполненной
void completeTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "Введите ID задачи, которую нужно отметить как выполненную: ";
    std::cin >> id;

    for (auto& task : tasks) {
        if (task.id == id) {
            task.isDone = true;
            std::cout << "Задача #" << id << " отмечена как выполненная.\n";
            return;
        }
    }
    std::cout << "Задача с ID #" << id << " не найдена.\n";
}

// Функция для удаления задачи
void deleteTask(std::vector<Task>& tasks) {
    int id;
    std::cout << "Введите ID задачи для удаления: ";
    std::cin >> id;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            std::cout << "Задача #" << id << " удалена.\n";
            return;
        }
    }
    std::cout << "Задача с ID #" << id << " не найдена.\n";
}

// ====================================================================

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<Task> tasks = loadTasksFromFile("tasks.txt");

    int choice;
    while (true) {
        std::cout << "\n--- Менеджер задач ---\n";
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Показать задачи\n";
        std::cout << "3. Отметить задачу как выполненную\n";
        std::cout << "4. Удалить задачу\n";
        std::cout << "5. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        // Обработка выбора пользователя
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
            std::cout << "Задачи сохранены. До свидания!\n";
            return 0;
        default:
            std::cout << "Неверный выбор. Попробуйте еще раз.\n";
            break;
        }
    }

    return 0;
}
#endif