
#include <iostream>
#include <string>

using namespace std;
//Объявить структуру Node с полями name, 
// age и salary типов string, int и double соответственно, 
//а также указателем на следующий элемент списка.
struct Node {
    string name;
    int age;
    double salary;
    Node* next;
};

//Объявить класс LinkedList с приватным полем head типа Node*,
// указывающим на голову списка.
class LinkedList {
private:
    Node* head;
    Node* createNode(string name, int age, double salary) { //Описать в классе метод createNode,
        Node* newNode = new Node(); //который возвращает указатель на новый элемент
        // типа Node со значениями переданных аргументов.
        newNode->name = name;
        newNode->age = age;  
        newNode->salary = salary;
        newNode->next = NULL;
        return newNode;
    }

    
   //Описать в классе конструктор LinkedList, который инициализирует head значением NULL.
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtBeginning(string name, int age, double salary) {
        Node* newNode = createNode(name, age, salary);

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(string name, int age, double salary) {
        Node* newNode = createNode(name, age, salary);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAfterNode(string name, int age, double salary, string key) {
        Node* newNode = createNode(name, age, salary);

        if (head == NULL) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp != NULL && temp->name != key) {
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Cannot find key " << key << " in list." << endl;
            }
            else {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void insertBeforeNode(string name, int age, double salary, string key) {
        Node* newNode = createNode(name, age, salary);

        if (head == NULL) {
            head = newNode;
        }
        else if (head->name == key) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* prev = head;
            Node* temp = head->next;
            while (temp != NULL && temp->name != key) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Cannot find key " << key << " in list." << endl;
            }
            else {
                newNode->next = temp;
                prev->next = newNode;
            }
        }
    }

    void deleteNode(string name) {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            Node* prev = head;
            Node* temp = head->next;
            while (temp != NULL && temp->name != name) {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL) {
                cout << "Cannot find node with name " << name << " in list." << endl;
            }
            else {
                prev->next = temp->next;
                delete temp;
            }
        }
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty." << endl;
        }
        else {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->name << " " << temp->age << " " << temp->salary << endl;
                temp = temp->next;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList *list = new LinkedList;

    bool exit = false;

    while (!exit) 
    {
        cout << "Выберите дейстивие:" << endl;
        cout << "1  -  Добавить элемент в начало" << endl;
        cout << "2  -  Добавить элемент в конец" << endl;
        cout << "3  -  Добавить элемент после" << endl;
        cout << "4  -  Добавить элемент до" << endl;
        cout << "5  -  Удалить элемент(по имени)" << endl;
        cout << "6  -  Вывести весь лист" << endl;
        cout << "7  -  Выход" << endl;

        int c;
        cin >> c;

        switch (c)
        {
        case 1:
        {
            cout << "Введите имя, возраст, зарплату , что добавить в начало" << endl;

            Node temp;

            cin >> temp.name;
            cin >> temp.age;
            cin >> temp.salary;

            list->insertAtBeginning(temp.name, temp.age, temp.salary);

            break;
        }
        case 2: 
        {
            cout << "Введите имя, возраст, зарплату , что добавить в конец" << endl;

            Node temp;

            cin >> temp.name;
            cin >> temp.age;
            cin >> temp.salary;

            list->insertAtEnd(temp.name, temp.age, temp.salary);

            break;
        }
        case 3:
        {
            cout << "Введите имя, возраст, зарплату , что добавить в после какого-то элемента. Далее само имя, после которого добавить." << endl;

            Node temp;
            string aim_name;

            cin >> temp.name;
            cin >> temp.age;
            cin >> temp.salary;

            cin >> aim_name;

            list->insertAfterNode(temp.name, temp.age, temp.salary, aim_name);

            break;
        }
        case 4:
        {
            cout << "Введите имя, возраст, зарплату , что добавить до какого-то элемента. Далее само имя, до которого добавить." << endl;

            Node temp;
            string aim_name;

            cin >> temp.name;
            cin >> temp.age;
            cin >> temp.salary;

            cin >> aim_name;

            list->insertBeforeNode(temp.name, temp.age, temp.salary, aim_name);

            break;
        }
        case 5:
        {
            cout << "Введите имя элемента, которое требуется удалить." << endl;

            string aim_name;

            list->deleteNode(aim_name);

            break;
        }
        case 6:
        {
            list->printList();
            break;
        }
        case 7:
        {
            cout << "ВЫХОД" << endl;
            exit = true;
            break;
        }
        default:
            break;
        }
    }
    delete list;
    return 0;
}
