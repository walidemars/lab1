#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Bus {
private:
    int busNumber;
    char driverName[50];
    int routeNumber;
public:
    Bus(): busNumber(0), routeNumber(0) {
        strcpy(driverName, "");
    }

    Bus(int num, const char* name, int route): busNumber(num), routeNumber(route) {
        strncpy(driverName, name, 49);
        driverName[49] = '\0';
    }

    int getBusNumber() const {
        return busNumber;
    }

    const char* gerDriverName() const {
        return driverName;
    }

    int getRouteNumber() const {
        return routeNumber;
    }

    bool operator==(int key) const {
        return busNumber == key;
    }

    bool operator!=(int key) const {
        return busNumber != key;
    }

    friend ostream& operator<<(ostream& os, const Bus& bus) {
        os << "Автобус №" << setw(4) << bus.busNumber
        << "\nВодитель: " << setw(20) << left << bus.driverName
        << "\nМаршрут №" << setw(3) << bus.routeNumber << endl;
        return os;
    }
};


template <class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& d): data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t size;

public:
    LinkedList(): head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {
        clear();
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head -> next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    size_t getSize() const {
        return size;
    }

    void addFirst(const T& data) {
        head = new Node(data);
        tail = head;
        size = 1;
    }

    void addToEnd(const T& data) {
        Node * newNode = new Node(data);

        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    T* find(int key) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == key) {
                return  &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

    bool remove(int key) {
        if (isEmpty()) return false;

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->data == key) {
                break;
            }
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        if (previous == nullptr) {
            head = current->next;
            if (head == nullptr) {
                tail = nullptr;
            }
        } else {
            previous->next = current->next;
            if (current == tail) {
                tail = previous;
            }
        }
        delete current;
        size--;
        return true;
    }

    bool insertAfter(int key, const T& data) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data == key) {
                break;
            }
            current = current->next;
        }

        if (current == nullptr) {
            return false;
        }

        Node* newNode = new Node(data);
        newNode->next = current->next;
        current->next = newNode;

        if (current == tail) {
            tail = newNode;
        }

        size++;
        return true;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Список пуст" << endl;
            return;
        }

        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". " << current->data << endl;
            current = current->next;
        }
    }

    static bool moveElement(LinkedList<T>& from, LinkedList<T>& to, int key) {
        T* data = from.find(key);
        if (data == nullptr) {
            return false;
        }

        T tempData = *data;
        from.remove(key);
        to.addToEnd(tempData);
        return true;
    }

    Node* getHead() const {
        return head;
    }
};

class BusPark {
private:
    LinkedList<Bus> inPark;
    LinkedList<Bus> onRoute;

public:
    void initialize() {

        int count;
        cout << "Введите количество автобусов: ";
        cin >> count;
        cin.ignore();

        for (int i = 0; i < count; i++) {
            cout << "\nАвтобус №" << (i + 1) << ":\n";

            int busNum, routeNum;
            char driver[50];

            cout << "Номер автобуса: ";
            cin >> busNum;
            cin.ignore();

            cout << "Фамилия и инициалы водителя: ";
            cin.getline(driver, 50);

            cout << "Номер маршрута: ";
            cin >> routeNum;
            cin.ignore();

            Bus bus(busNum, driver, routeNum);

            if (inPark.isEmpty()) {
                inPark.addFirst(bus);
            } else {
                inPark.addToEnd(bus);
            }
        }
        cout << "\nАвтобусов в парке: "
             << inPark.getSize() << "\n";
    }

    void busDeparture() {

        if (inPark.isEmpty()) {
            cout << "В парке нет автобусов!\n";
            return;
        }

        cout << "Автобусы в парке:\n";
        inPark.display();

        int busNum;
        cout << "Введите номер выезжающего автобуса: ";
        cin >> busNum;

        if (LinkedList<Bus>::moveElement(inPark, onRoute, busNum)) {
            cout << "Автобус №" << busNum << " выехал на маршрут.\n";
            cout << "Осталось в парке: " << inPark.getSize() << "\n";
            cout << "На маршруте: " << onRoute.getSize() << "\n";
        } else {
            cout << "Автобус №" << busNum << " не найден в парке!\n";
        }
    }

    void busArrival() {
        if (onRoute.isEmpty()) {
            cout << "На маршруте нет автобусов!\n";
            return;
        }

        cout << "Автобусы на маршруте:\n";
        onRoute.display();

        int busNum;
        cout << "Введите номер возвращающегося автобуса: ";
        cin >> busNum;

        if (LinkedList<Bus>::moveElement(onRoute, inPark, busNum)) {
            cout << "Автобус №" << busNum << " вернулся в парк.\n";
            cout << "В парке: " << inPark.getSize() << "\n";
            cout << "Осталось на маршруте: " << onRoute.getSize() << "\n";
        } else {
            cout << "Автобус №" << busNum << " не найден на маршруте!\n";
        }
    }

    void showInfo() {
        cout << "1. Автобусы в парке\n";
        cout << "2. Автобусы на маршруте\n";
        cout << "Выберите опцию: ";

        int choice;
        cin >> choice;

        cout << "\n";
        switch (choice) {
            case 1:
                cout << "Автобусы в парке (" << inPark.getSize() << ")\n";
                inPark.display();
                break;
            case 2:
                cout << "Автобусы на маршруте (" << onRoute.getSize() << ")\n";
                onRoute.display();
                break;
            default:
                cout << "Неверный выбор!\n";
        }
    }

    void menu() {
        int choice;

        do {
            cout << "1. Начальное формирование данных\n";
            cout << "2. Выезд автобуса на маршрут\n";
            cout << "3. Возврат автобуса в парк\n";
            cout << "4. Показать сведения\n";
            cout << "0. Выход\n";
            cout << "----------------------------------------\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            switch (choice) {
                case 1: initialize(); break;
                case 2: busDeparture(); break;
                case 3: busArrival(); break;
                case 4: showInfo(); break;
                case 0: cout << "Программа завершена.\n"; break;
                default: cout << "Неверный выбор! Попробуйте снова.\n";
            }
        } while (choice != 0);
    }
};

void demoIntList() {

    LinkedList<int> list;

    list.addFirst(1);
    for (int i = 2; i < 6; i++) {
        list.addToEnd(i);
    }
    cout << "Исходный список: \n";
    list.display();

    if (list.insertAfter(2, 200)) {
        cout << "\nПосле вставки 200 после 2: \n";
        list.display();
    }

    if (list.remove(5)) {
        cout << "\nПосле удаления 5: \n";
        list.display();
    } else {
        cout << "\nЭлемент 5 не найден!\n";
    }
    cout << "\nРазмер списка: " << list.getSize() << endl;
}

int main() {

    demoIntList();

    cout << "\n";
    BusPark park;
    park.menu();

    return 0;
}