// ... (те же функции createTrip, addToEnd, printAll, freeList из варианта 3)

void searchByDestination(Trip* head) {
    char dest[256];
    cout << "Введите место назначения для поиска: ";
    cin.getline(dest, 256);

    cout << "\nРезультаты поиска по \"" << dest << "\":\n";
    cout << string(140, '-') << "\n";
    cout << setw(25) << "ФИО" << setw(15) << "Выезд" << setw(15) << "Возврат" << setw(40) << "Цель" << setw(12) << "Суточные" << "\n";
    cout << string(140, '-') << "\n";

    Trip* cur = head;
    bool found = false;
    while (cur) {
        if (strcmp(cur->destination, dest) == 0) {
            cout << setw(25) << cur->fio
                 << setw(15) << cur->date_out
                 << setw(15) << cur->date_back
                 << setw(40) << cur->purpose
                 << setw(12) << fixed << setprecision(2) << cur->daily << "\n";
            found = true;
        }
        cur = cur->next;
    }
    if (!found) cout << "Записи не найдены\n";
    cout << string(140, '-') << "\n\n";
}

// В main добавить пункт 4:
case 4: searchByDestination(head); break;