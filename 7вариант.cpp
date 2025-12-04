// Инвертировать список
Trip* reverseList(Trip* head) {
    Trip *prev = nullptr, *cur = head, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

// Статистика по местам назначения
void showStatistics(Trip* head) {
    if (!head) {
        cout << "Список пуст\n";
        return;
    }

    struct DestCount {
        char* dest;
        int count;
        DestCount* next;
    };

    DestCount* stats = nullptr;

    Trip* cur = head;
    while (cur) {
        DestCount* node = stats;
        bool found = false;
        while (node) {
            if (strcmp(node->dest, cur->destination) == 0) {
                node->count++;
                found = true;
                break;
            }
            node = node->next;
        }
        if (!found) {
            DestCount* newNode = new DestCount;
            newNode->dest = new char[strlen(cur->destination)+1];
            strcpy(newNode->dest, cur->destination);
            newNode->count = 1;
            newNode->next = stats;
            stats = newNode;
        }
        cur = cur->next;
    }

    cout << "\nСтатистика по местам назначения:\n";
    DestCount* s = stats;
    while (s) {
        cout << s->dest << " — " << s->count << " поезд";
        if (s->count % 10 == 1 && s->count % 100 != 11) cout << "ка\n";
        else if (s->count % 10 >= 2 && s->count % 10 <= 4 && (s->count % 100 < 10 || s->count % 100 >= 20)) cout << "ки\n";
        else cout << "ок\n";
        s = s->next;
    }

    // очистка статистики
    while (stats) {
        DestCount* temp = stats;
        stats = stats->next;
        delete[] temp->dest;
        delete temp;
    }
}