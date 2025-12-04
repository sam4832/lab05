// Добавляем функцию расчёта длительности (упрощённая — по количеству дней)
int getDays(const char* d1, const char* d2) {
    int day1, mon1, year1, day2, mon2, year2;
    sscanf(d1, "%d.%d.%d", &day1, &mon1, &year1);
    sscanf(d2, "%d.%d.%d", &day2, &mon2, &year2);

    // Примерный расчёт (без високосных и т.п.)
    int totalDays1 = year1 * 365 + mon1 * 30 + day1;
    int totalDays2 = year2 * 365 + mon2 * 30 + day2;
    return totalDays2 - totalDays1 + 1;
}

void printAll(Trip* head) {
    if (!head) {
        cout << "Список пуст\n\n";
        return;
    }

    double totalSum = 0.0;
    Trip* cur = head;
    int i = 1;
    cout << "\n" << string(150, '-') << "\n";
    cout << setw(5) << "№" << setw(25) << "ФИО" << setw(15) << "Выезд" << setw(15) << "Возврат"
         << setw(25) << "Куда" << setw(12) << "Суточные" << setw(10) << "Дней" << setw(15) << "Сумма" << "\n";
    cout << string(150, '-') << "\n";

    while (cur) {
        int days = getDays(cur->date_out, cur->date_back);
        double sum = days * cur->daily;
        totalSum += sum;

        cout << setw(5) << i++
             << setw(25) << cur->fio
             << setw(15) << cur->date_out
             << setw(15) << cur->date_back
             << setw(25) << cur->destination
             << setw(12) << fixed << setprecision(2) << cur->daily
             << setw(10) << days
             << setw(15) << sum << "\n";
        cur = cur->next;
    }
    cout << string(150, '-') << "\n";
    cout << "ОБЩАЯ СУММА СУТОЧНЫХ: " << totalSum << " руб.\n\n";
}