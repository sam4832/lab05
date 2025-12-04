// Добавляем getDays() как выше

Trip* createTripWithRules() {
    Trip* t = new Trip;
    // ... (ввод как обычно)

    int days = getDays(t->date_out, t->date_back);
    if (days > 45) {
        cout << "Ошибка: командировка более 45 дней — запрещена!\n";
        // освобождаем память
        delete[] t->fio; delete[] t->date_out; delete[] t->date_back;
        delete[] t->destination; delete[] t->purpose;
        delete t;
        return nullptr;
    }
    if (days > 15) {
        t->daily *= 1.10;  // +10%
        cout << "Длительность >15 дней → суточные увеличены на 10%\n";
    }
    return t;
}

// Сортировка пузырьком по destination
void sortByDestination(Trip* head) {
    if (!head || !head->next) return;
    bool swapped;
    do {
        swapped = false;
        Trip* cur = head;
        while (cur->next) {
            if (strcmp(cur->destination, cur->next->destination) > 0) {
                // меняем все поля
                swap(cur->fio, cur->next->fio);
                swap(cur->date_out, cur->next->date_out);
                swap(cur->date_back, cur->next->date_back);
                swap(cur->destination, cur->next->destination);
                swap(cur->purpose, cur->next->purpose);
                swap(cur->daily, cur->next->daily);
                swapped = true;
            }
            cur = cur->next;
        }
    } while (swapped);
}