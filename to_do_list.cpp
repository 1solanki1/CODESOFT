#include <iostream>
#include <vector>
#include <string>

using namespace std;

class ToDoList
{
private:
    vector<pair<string, bool>> tasks;

public:
    void addTask(string task)
    {
        tasks.push_back({task, false});
        cout << "Task added successfully!" << endl;
    }

    void viewTasks()
    {
        cout << "To-Do List:" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << "[" << (i + 1) << "] " << tasks[i].first << " - " << (tasks[i].second ? "Completed" : "Pending") << endl;
        }
    }

    void markTaskAsCompleted(int taskNumber)
    {
        if (taskNumber > 0 && taskNumber <= tasks.size())
        {
            tasks[taskNumber - 1].second = true;
            cout << "Task marked as completed!" << endl;
        }
        else
        {
            cout << "Invalid task number!" << endl;
        }
    }

    void removeTask(int taskNumber)
    {
        if (taskNumber > 0 && taskNumber <= tasks.size())
        {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully!" << endl;
        }
        else
        {
            cout << "Invalid task number!" << endl;
        }
    }
};

int main()
{
    ToDoList todo;
    int choice;
    string task;
    int taskNumber;

    while (true)
    {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, task);
            todo.addTask(task);
            break;
        case 2:
            todo.viewTasks();
            break;
        case 3:
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            todo.markTaskAsCompleted(taskNumber);
            break;
        case 4:
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            todo.removeTask(taskNumber);
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}