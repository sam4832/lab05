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

Trip* createTrip() {
    Trip* newTrip = new Trip;
    char buffer[256];

    cout << "FIO: ";
    cin.getline(buffer, 256);
    newTrip->fio = new char[strlen(buffer) + 1];
    strcpy(newTrip->fio, buffer);

    cout << "Date out (DD.MM.YYYY): ";
    cin.getline(buffer, 256);
    newTrip->date_out = new char[strlen(buffer) + 1];
    strcpy(newTrip->date_out, buffer);

    cout << "Date back (DD.MM.YYYY): ";
    cin.getline(buffer, 256);
    newTrip->date_back = new char[strlen(buffer) + 1];
    strcpy(newTrip->date_back, buffer);

    cout << "Destination: ";
    cin.getline(buffer, 256);
    newTrip->destination = new char[strlen(buffer) + 1];
    strcpy(newTrip->destination, buffer);

    cout << "Purpose: ";
    cin.getline(buffer, 256);
    newTrip->purpose = new char[strlen(buffer) + 1];
    strcpy(newTrip->purpose, buffer);

    cout << "Daily allowance: ";
    cin >> newTrip->daily;
    cin.ignore();

    newTrip->next = nullptr;
    return newTrip;
}

Trip* addToEnd(Trip* head) {
    Trip* newTrip = createTrip();
    if (head == nullptr) return newTrip;
    Trip* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newTrip;
    return head;
}

void printAll(Trip* head) {
    if (head == nullptr) {
        cout << "No records" << endl;
        return;
    }
    Trip* curr = head;
    cout << left << setw(20) << "FIO" << setw(12) << "Date out" << setw(12) << "Date back" << setw(20) << "Destination" << setw(50) << "Purpose" << setw(10) << "Daily" << endl;
    while (curr) {
        cout << left << setw(20) << curr->fio << setw(12) << curr->date_out << setw(12) << curr->date_back << setw(20) << curr->destination << setw(50) << curr->purpose << setw(10) << curr->daily << endl;
        curr = curr->next;
    }
}

void freeList(Trip* head) {
    Trip* temp;
    while (head) {
        temp = head;
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
    Trip* head = nullptr;
    int choice;
    do {
        cout << "1. Add trip\n2. View all\n0. Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                head = addToEnd(head);
                break;
            case 2:
                printAll(head);
                break;
            case 0:
                freeList(head);
                break;
        }
    } while (choice != 0);
    return 0;
}