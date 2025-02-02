#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tasks {
private:
    string name; 
    string description; 
    string dueDate; 
    bool completed; 

public:
    
    Tasks(const string& name, const string& description,
         const string& dueDate)
        : name(name)
        , description(description)
        , dueDate(dueDate)
        , completed(false)
    {
    }

    
    string getName() const { return name; }

    string getDescription() const { return description; }

    
    string getDueDate() const { return dueDate; }

    
    bool isCompleted() const { return completed; }

    
    void setName(const string& name) { this->name = name; }

    
    void setDescription(const string& description)
    {
        this->description = description;
    }

    
    void setDueDate(const string& dueDate)
    {
        this->dueDate = dueDate;
    }

    
    void markCompleted() { completed = true; }

    
    void displayTask() const
    {
        cout << name << " ("
             << (completed ? "Completed" : "Pending")
             << ") - Due: " << dueDate << endl
             << "   Description: " << description << endl;
    }
};


class ToDoList {
private:
    vector<Tasks> tasks; 

public:

    void displayMenu()
    {
        cout
            << "\n---------- To-Do List Menu -----------\n";
        cout << "1. Add Task\n";
        cout << "2. Delete Task\n";
        cout << "3. Display Tasks\n";
        cout << "4. Mark Task as Completed\n";
        cout << "5. Exit\n"<<endl;
    }


    void addTask()
    {
        string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (YYYY-MM-DD): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }


    void deleteTask()
    {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }


    void displayTasks()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }


    void markTaskCompleted()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as "
                "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }


    void run()
    {
        int choice;
        do {
            displayMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                deleteTask();
                break;
            case 3:
                displayTasks();
                break;
            case 4:
                markTaskCompleted();
                break;
            case 5:
                cout << "Exiting program. Bye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again!"
                     << endl;
            }
        } while (choice != 5);
    }
};

int main(){
    ToDoList toDoList;
    toDoList.run();
    return 0;
}
