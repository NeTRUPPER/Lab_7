def can_place_items(containers, items, item_index):
    # Базовый случай: все предметы были размещены успешно
    if item_index == len(items):
        return True

    # Попытка разместить текущий предмет в каждом контейнере
    for i in range(len(containers)):
        # Если текущий контейнер высоты больше или равен высоте предмета,
        # то размещаем предмет в этом контейнере и рекурсивно пытаемся разместить оставшиеся предметы
        if containers[i] >= items[item_index]:
            containers[i] -= items[item_index]  # Уменьшаем высоту контейнера
            if can_place_items(containers, items, item_index + 1):
                return True  # Предмет размещен успешно
            containers[i] += items[item_index]  # Восстанавливаем высоту контейнера

    # Если не удалось разместить предмет ни в одном контейнере
    return False

def main():
    # Ввод данных
    N = int(input("Введите количество контейнеров: "))
    print("Введите высоту каждого контейнера: ")
    containers = [int(input()) for _ in range(N)]

    M = int(input("Введите количество предметов: "))
    print("Введите высоту каждого предмета: ")
    items = [int(input()) for _ in range(M)]

    # Проверяем, можно ли разместить предметы в контейнерах
    if can_place_items(containers, items, 0):
        print("Предметы можно разместить в контейнерах без выступов.")
    else:
        print("Предметы не могут быть размещены в контейнерах без выступов.")

if __name__ == "__main__":
    main()
