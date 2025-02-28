from asyncio import tasks

from jinja2.runtime import identity

from datetime import datetime

class TaskManager:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append(task)

    def make_sep(self):
        for _ in range(256):
            print("_", end = "")
        print()

    # def remove_task(self, task):
    #     self.tasks.remove(task)

    def show_tasks(self):
        if not self.tasks:
            print("Список задач пуст")

        for index, task in enumerate(self.tasks, start=1):
            self.make_sep()
            print(f"Задача: {index}",
                  f"Заголовок: {task.title}",
                  f"Описание задачи: {task.description}",
                  f"Статус: {task.status}",
                  f"Дата добавления: {task.date}",
                  f"Дедлайн: {task.deadline}",
                  sep = "\n"
                  )
            self.make_sep()



class Task:
    def __init__(self, title, description, status, date, deadline):
        self.title = title
        self.description = description
        self.status = status
        self.date = date
        self.deadline = deadline




class Menu:
    def __init__(self, task_manager):
        self.task_manager = task_manager
        self.actions = {
            '1': "Добавить задачу",
            '2': "Показать список задач",
            '3': "Изменить статус задачи",
            '4': "Удалить задачу",
            '5': "Выйти"
        }

    def show_actions(self):
        for (key,value) in self.actions.items():
            print(f"{key}. {value}")

    def identify_status(self):
        print("Статус (1 - выполнено, 2 - не выполнено, любая клавиша - свой статус)")
        choice = input("Статус: ")
        if choice == "1":
            status = "Выполнено"
        elif choice == "2":
            status = "Не выполнено"
        else:
            status = input(">> Введите личный статус: ")
        return status

    def identify_date(self):
        print("Дата добавления(1 - текущая дата, любая клавиша - своя дата): ")
        date_choice = input(">> ")
        if date_choice == "1":
            date = datetime.now().date()
        else:
            date = input(">>")
        return date


    def get_task_titles(self):
        for index, self.task in enumerate(self.task_manager.tasks, start=1):
            print(f"{self.task.title} - {index}")


    def choice(self, action):
        if action in self.actions:
            print(f">> Вы выбрали: {self.actions[action]}")

            if action == '1':
                title = input("Заголовок задачи: ")
                description = input("Описание задачи: ")

                status = self.identify_status()

                date = self.identify_date()

                deadline = input("Дедлайн: ")

                new_task = Task(title, description, status, date, deadline)
                self.task_manager.add_task(new_task)
                print(">> Задача успешно добавлена!")

            elif action == '2':
                self.task_manager.show_tasks()

            elif action == '3':
                print("Статус какой задачи вы желаете изменить?")
                self.get_task_titles()
                status_change_choice = int(input(">> "))

                if status_change_choice <= len(self.task_manager.tasks):
                    self.task_manager.tasks[status_change_choice - 1].status =  self.identify_status()
                else:
                    print("Нет задачи с таким номером")

            elif action == '4':
                self.get_task_titles()
                print("Какую задачу вы хотите удалить?")
                task_to_delete = input(">> ")
                if int(task_to_delete) <= len(self.task_manager.tasks):
                    self.task_manager.tasks.pop(int(task_to_delete)-1)
                else:
                    print("Нет задачи с таким номером")


            elif action == '5':
                print("Выход...")
                return False
        else:
            print("Неизвестная команда. Попробуйте снова.")

        return True




def main():
    task_manager = TaskManager()
    menu = Menu(task_manager)
    while True:
        print("Выберите действие:")
        menu.show_actions()
        user_action = input("Введите номер: ")
        if not menu.choice(user_action):
            break


if __name__ == '__main__':
    main()


# игра со временем