#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Trip {
    char* fio;
    char* date_out;
    char* date_back;
    char* destination;
    char* purpose;
    double daily;
    Trip* next;
};

// Создание новой записи
Trip* createTrip() {
    Trip* t = new Trip;
    char buf[256];

    cout << "ФИО (5-60 символов): ";
    cin.getline(buf, 256);
    if (strlen(buf) < 5 || strlen(buf) > 60) ? (cout << "Ошибка длины ФИО!\n", delete t, t = nullptr) :
    (t->fio = new char[strlen(buf)+1], strcpy(t->fio, buf));

    if (!t) return nullptr;

    cout << "Дата выезда (ДД.ММ.ГГГГ): ";
    cin.getline(buf, 256);
    t->date_out = new char[strlen(buf)+1];
    strcpy(t->date_out, buf);

    cout << "Дата возвращения (ДД.ММ.ГГГГ): ";
    cin.getline(buf, 256);
    t->date_back = new char[strlen(buf)+1];
    strcpy(t->date_back, buf);

    cout << "Место назначения: ";
    cin.getline(buf, 256);
    t->destination = new char[strlen(buf)+1];
    strcpy(t->destination, buf);

    cout << "Цель поездки: ";
    cin.getline(buf, 256);
    t->purpose = new char[strlen(buf)+1];
    strcpy(t->purpose, buf);

    cout << "Суточные: ";
    cin >> t->daily;
    cin.ignore();

    t->next = nullptr;
    return t;
}

// Добавление в конец
Trip* addToEnd(Trip* head) {
    Trip* t = createTrip();
    if (!t) return head;
    if (!head) return t;
    Trip* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = t;
    return head;
}

// Добавление в начало (срочная)
Trip* addToBegin(Trip* head) {
    Trip* t = createTrip();
    if (!t) return head;
    t->next = head;
    return t;
}

// Вывод всех
void printAll(Trip* head) {
    if (!head) {
        cout << "Список пуст\n\n";
        return;
    }
    cout << "\n" << string(140, '-') << "\n";
    cout << setw(5) << "№"
         << setw(25) << "ФИО"
         << setw(15) << "Выезд"
         << setw(15) << "Возврат"
         << setw(25) << "Куда"
         << setw(40) << "Цель"
         << setw(12) << "Суточные" << "\n";
    cout << string(140, '-') << "\n";

    int i = 1;
    Trip* cur = head;
    while (cur) {
        cout << setw(5) << i++
             << setw(25) << cur->fio
             << setw(15) << cur->date_out
             << setw(15) << cur->date_back
             << setw(25) << cur->destination
             << setw(40) << cur->purpose
             << setw(12) << fixed << setprecision(2) << cur->daily << "\n";
        cur = cur->next;
    }
    cout << string(140, '-') << "\n\n";
}

// Освобождение памяти
void freeList(Trip*& head) {
    while (head) {
        Trip* temp = head;
        head = head->next;
        delete[] temp->fio;
        delete[] temp->date_out;
        delete[] temp->date_back;
        delete[] temp->destination;
        delete[] temp->purpose;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Trip* head = nullptr;
    int choice;

    do {
        cout << "Меню:\n";
        cout << "1. Добавить командировку (в конец)\n";
        cout << "2. Добавить срочную командировку (в начало)\n";
        cout << "3. Просмотреть все\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: head = addToEnd(head); break;
            case 2: head = addToBegin(head); break;
            case 3: printAll(head); break;
            case 0: freeList(head); cout << "Память освобождена. Пока!\n"; break;
            default: cout << "Неверный пункт!\n";
        }
        cout << "\n";
    } while (choice != 0);

    return 0;
}