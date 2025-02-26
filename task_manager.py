
class Menu:
    def __init__(self):
        self.actions = {
            '1': "Добавить задачу",
            '2': "Показать список задач",
            '3': "Выйти"
        }

    def show_actions(self):
        for (key,value) in self.actions.items():
            print(f"{key}. {value}")

    def choice(self, action):
        if action in self.actions:
            print(f"Вы выбрали: {self.actions[action]}")
            if action == '3':
                print("Выход...")
                return False
        else:
            print("Неизвестная команда. Попробуйте снова.")






def main():
    menu = Menu()
    while True:
        print("Выберите действие:")
        menu.show_actions()
        user_action = input("Введите номер: ")

        if not menu.choice(user_action):
            break




if __name__ == '__main__':
    main()
