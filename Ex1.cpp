#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, можно ли разместить предметы в контейнерах
bool canPlaceItems(vector<int>& containers, vector<int>& items, int itemIndex) {
    // Базовый случай: все предметы были размещены успешно
    if (itemIndex == items.size()) {
        return true;
    }

    // Попытка разместить текущий предмет в каждом контейнере
    for (int i = 0; i < containers.size(); ++i) {
        // Если текущий контейнер высоты больше или равен высоте предмета,
        // то размещаем предмет в этом контейнере и рекурсивно пытаемся разместить оставшиеся предметы
        if (containers[i] >= items[itemIndex]) {
            containers[i] -= items[itemIndex]; // Уменьшаем высоту контейнера
            if (canPlaceItems(containers, items, itemIndex + 1)) {
                return true; // Предмет размещен успешно
            }
            containers[i] += items[itemIndex]; // Восстанавливаем высоту контейнера
        }
    }

    // Если не удалось разместить предмет ни в одном контейнере
    return false;
}

int main() {
    // Ввод данных
    int N, H;
    cout << "Введите количество контейнеров: ";
    cin >> N;
    cout << "Введите высоту каждого контейнера: ";

    vector<int> containers(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> containers[i];
    }

    int M;
    cout << "Введите количество предметов: ";
    cin >> M;
    cout << "Введите высоту каждого предмета: ";

    vector<int> items(M);

    for (int i = 0; i < M; ++i) {
        cin >> items[i];
    }

    // Проверяем, можно ли разместить предметы в контейнерах
    if (canPlaceItems(containers, items, 0)) {
        cout << "Предметы можно разместить в контейнерах без выступов." << endl;
    } else {
        cout << "Предметы не могут быть размещены в контейнерах без выступов." << endl;
    }

    return 0;
}
