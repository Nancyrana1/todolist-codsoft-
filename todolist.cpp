#ifndef TODO
#define TODO

#include <string>
#include <cstdint>

using std::string;
using std::int16_t;

static int positionInList = 0;
static int listSize = 0;

struct MyToDo {
    string description;
    int priority;
    string dueDate;
};

#endif




#include <iostream>
#include <string>
// #include <19ToDo.h>

using namespace std;

struct MyToDo ToDoList[100];

bool addToList(string description, int priority, string dueDate) {
    if (listSize < 101) {
        MyToDo y = { description, priority, dueDate };
        ToDoList[listSize] = y;
        listSize++;
        return true;
    } else {
        return false;
    }
}

bool getNextItem(MyToDo &mytodo) {
    if (listSize == 0) {
        return false;
    } else if (positionInList < listSize) {
        mytodo = ToDoList[positionInList];
        positionInList++;
    } else {
        positionInList = 0;
        mytodo = ToDoList[positionInList];
        positionInList++;
    }
    return true;
}

bool getByPriority(MyToDo matches[100], int search) {
    int count = 0;
    for (int i = 0; i < listSize; i++) {
        if (ToDoList[i].priority == search) {
            matches[count] = ToDoList[i];
            count++;
        }
    }
    return true;
}

void printToDo() {
    for (int i = 0; i < listSize; i++) {
        cout << ToDoList[i].description << endl;
        cout << ToDoList[i].priority << endl;
        cout << ToDoList[i].dueDate << endl;
        cout << "" << endl;
    }
}


#include <iostream>
#include <string>
// #include <19ToDo.h>

using namespace std;

int main() {
    int choice = 0;
    char nextmove = 'y';

    while (nextmove == 'y') {
        cout << "This will keep track of the things you need to do!" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add to my to-do list" << endl;
        cout << "2. Display the next item in my list" << endl;
        cout << "3. Search for activities of a certain priority" << endl;
        cout << "4. Print out my whole list" << endl;
        cin >> choice;

        if (choice == 1) {
            string description;
            int priority;
            string dueDate;

            cout << "What is the description of the activity? ";
            cin.ignore(); // To clear the newline character
            getline(cin, description);

            cout << "What is the priority (integer value)? ";
            cin >> priority;

            cout << "When is it due? ";
            cin.ignore(); // To clear the newline character
            getline(cin, dueDate);

            addToList(description, priority, dueDate);
        } else if (choice == 2) {
            MyToDo nextItem;
            if (getNextItem(nextItem)) {
                cout << "Next item: " << nextItem.description << endl;
            } else {
                cout << "No items in the list." << endl;
            }
        } else if (choice == 3) {
            int searchPriority;
            cout << "Enter the priority to search for: ";
            cin >> searchPriority;

            MyToDo matches[100];
            if (getByPriority(matches, searchPriority)) {
                cout << "Matching items:" << endl;
                for (int i = 0; i < listSize; i++) {
                    cout << matches[i].description << endl;
                }
            } else {
                cout << "No items with that priority." << endl;
            }
        } else if (choice == 4) {
            printToDo();
        }

        cout << "Continue? (y/n): ";
        cin >> nextmove;
    }

    return 0;
}
