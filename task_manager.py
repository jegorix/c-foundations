
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

            if action == '1':
                #print("Вам необходимо ответить на несколько вопросов:")
                title = input("Заголовок задачи: ")
                description = input("Описание задачи: ")
                status = input("Статус: ")
                date = input("Дата добавления: ")
                deadline = input("Дедлайн: ")
                new_task = Task(title, description, status, date, deadline)
                return new_task




            if action == '3':
                print("Выход...")
                return False
        else:
            print("Неизвестная команда. Попробуйте снова.")




class Task():
    def __init__(self, title, description, status, date, deadline):
        self.title = title
        self.description = description
        self.status = status
        self.date = date
        self.deadline = deadline

    def crate_task(self):
        new_task = f"Задача: {self.title}\n Описание:{self.description}\n Статус: {self.status} Дата добавления: {self.date} Дедлайн: {self.deadline}"
        return new_task





def main():
    menu = Menu()
    while True:
        print("Выберите действие:")
        menu.show_actions()
        user_action = input("Введите номер: ")

        user_choice = menu.choice(user_action)

        if not user_choice:
            break






if __name__ == '__main__':
    main()
