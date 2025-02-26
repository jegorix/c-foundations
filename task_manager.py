from asyncio import tasks

class TaskManager:
    def __init__(self):
        self.tasks = []

    def add_task(self, task):
        self.tasks.append(task)

    # def remove_task(self, task):
    #     self.tasks.remove(task)

    def show_tasks(self):
        if not self.tasks:
            print("Список задач пуст")

        for index, task in enumerate(self.tasks, start=1):
            print(f"Задача:{index}",
                  f"Заголовок:{task.title}",
                  f"Описание задачи:{task.description}",
                  f"Статус:{task.status}",
                  f"Дата добавления: {task.date}",
                  f"Дедлайн: {task.deadline}",
                  sep = "\n"
                  )



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
            '3': "Выйти"
        }

    def show_actions(self):
        for (key,value) in self.actions.items():
            print(f"{key}. {value}")

    def choice(self, action):
        if action in self.actions:
            print(f">> Вы выбрали: {self.actions[action]}")

            if action == '1':
                title = input("Заголовок задачи: ")
                description = input("Описание задачи: ")
                status = input("Статус: ")
                date = input("Дата добавления: ")
                deadline = input("Дедлайн: ")

                new_task = Task(title, description, status, date, deadline)
                self.task_manager.add_task(new_task)
                print(">> Задача успешно добавлена!")

            elif action == '2':
                self.task_manager.show_tasks()



            elif action == '3':
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
