from asyncio import tasks

from jinja2.runtime import identity

from datetime import datetime, timedelta

class TaskManager:
    def __init__(self):
        self.tasks = []
        self.priorities = {
            "1": "Задача низкой важности",
            "2": "Задача умеренной важности",
            "3": "Задача высокой важности",
        }

        self.priority_order = {
            "Задача низкой важности": 1,
            "Задача умеренной важности": 2,
            "Задача высокой важности": 3

        }

        self.status_order = {
            "выполнено": 1,
            "не выполнено": 2
        }


    def add_task(self, task):
        self.tasks.append(task)

    def make_sep(self):
        for _ in range(256):
            print("_", end = "")
        print()

    def show_tasks(self):
        if not self.tasks:
            print("Список задач пуст (добавьте задачу)")

        for index, task in enumerate(self.tasks, start=1):
            self.make_sep()
            print(f"Задача: {index}",
                  f"Заголовок: {task.title}",
                  f"Описание задачи: {task.description}",
                  f"Статус: {task.status}",
                  f"Дата добавления: {task.date}",
                  f"Дедлайн: {task.deadline}",
                  f"Приоритет: {task.priority}",
                  sep = "\n"
                  )
            self.make_sep()



class Task:
    def __init__(self, title, description, status, date, deadline, priority):
        self.title = title
        self.description = description
        self.status = status
        self.date = date
        self.deadline = deadline
        self.priority = priority




class Menu:
    def __init__(self, task_manager):
        self.task_manager = task_manager
        self.actions = {
            '1': "Добавить задачу",
            '2': "Показать список задач",
            '3': "Изменить статус задачи",
            '4': "Изменить приоритет задачи",
            '5': "Удалить задачу",
            '6': "Выйти"
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
            date = f"{datetime.now().date()} (Время: {datetime.now().strftime("%H:%M")})"
        else:
            date = input(">> Ваша дата: ")
        return date

    def set_deadline(self, added_date):
        while True:
            print("Дедлайн(1 - смещения от даты добавления, любая клавиша - дата пользователя)")
            show_date_choice = input(">> ")
            if show_date_choice == "1":
                print("Сколько дней вы даете на выполнение задачи?")
                user_input_days = int(input(">> "))
                try:
                    data_obj = datetime.strptime(added_date, "%Y-%m-%d (Время: %H:%M)")
                    new_date_obj = data_obj + timedelta(days=user_input_days)
                    date = f"{new_date_obj.date()} (Время: {new_date_obj.strftime("%H:%M")})"
                    return date
                except ValueError:
                    print("Невозможно прибавить дни к текущей дате")
            else:
                date = input("Введите дату: ")
                return date



    def set_priority(self):
        print("Выберите приоритет:", "3 - Задача высокой важности", "2 - Задача умеренной важности", "1 - Задача низкой важности", sep = "\n")
        while True:
            priority = input(">> ")
            if priority == "1":
                priority = self.task_manager.priorities["1"]
                break

            elif priority == "2":
                priority = self.task_manager.priorities["2"]
                break

            elif priority == "3":
                priority = self.task_manager.priorities["3"]
                break
            else:
                print("Неизвестный выбор", "Попробуйте еще раз:", sep = "\n")

        return priority

    # ДОБАВИТЬ СОРТИРОВКИ
    def tasks_sort(self, user_input):
        if user_input == "1":
            self.task_manager.tasks.sort(key = lambda task: self.task_manager.priority_order[task.priority], reverse = True)
            self.task_manager.show_tasks()
        elif user_input == "2":
            self.task_manager.tasks.sort(key = lambda task: datetime.strptime(task.date, "%Y-%m-%d (Время: %H:%M)") , reverse = True )
            self.task_manager.show_tasks()




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

                deadline = self.set_deadline(date)

                priority = self.set_priority()

                new_task = Task(title, description, status, date, deadline, priority)
                self.task_manager.add_task(new_task)
                print(">> Задача успешно добавлена!")

            elif action == '2':
                print("Сортировать задачи?", "1 - По приоритету", "2 - По дате добавления",
                      "3 - По дедлайну", "4 - По статусу", "5 - не сортировать", sep = "\n")

                user_input_sort = input(">> ")

                if user_input_sort == "5":
                    self.task_manager.show_tasks()
                else:
                    self.tasks_sort(user_input_sort)

            elif action == '4':
                if len(self.task_manager.tasks) > 0:
                    print("Приоритет какой задачи вы желаете изменить?")
                    self.get_task_titles()
                    while True:
                        try:
                            priority_change_choice = int(input(">> "))
                            break
                        except ValueError:
                            print("Введите корректный номер задачи")

                    if priority_change_choice <= len(self.task_manager.tasks):
                        self.task_manager.tasks[priority_change_choice - 1].priority = self.set_priority()
                        print(f"Приоритет задачи '{self.task_manager.tasks[priority_change_choice - 1].title}' успешно изменен ")
                    else:
                        print("Нет задачи с таким номером")
                else:
                    print("Список задач пуст (добавьте задачу)")

            elif action == '3':
                if len(self.task_manager.tasks) > 0:
                    print("Статус какой задачи вы желаете изменить?")
                    self.get_task_titles()
                    while True:
                        try:
                            status_change_choice = int(input(">> "))
                            break
                        except ValueError:
                            print("Введите корректный номер задачи")

                    if status_change_choice <= len(self.task_manager.tasks):
                        self.task_manager.tasks[status_change_choice - 1].status =  self.identify_status()
                        print(f"Статус задачи '{self.task_manager.tasks[status_change_choice - 1].title}' успешно изменен")
                    else:
                        print("Нет задачи с таким номером")
                else:
                    print("Список задач пуст (добавьте задачу)")


            elif action == '5':
                if len(self.task_manager.tasks) > 0:
                    self.get_task_titles()
                    print("Какую задачу вы хотите удалить?")
                    while True:
                        try:
                            task_to_delete = int(input(">> "))
                            break
                        except ValueError:
                            print("Введите корректный номер задачи")

                    if task_to_delete <= len(self.task_manager.tasks):
                        print(f"Задача '{self.task_manager.tasks[task_to_delete - 1].title}' успешно удалена")
                        self.task_manager.tasks.pop(task_to_delete-1)
                    else:
                        print("Нет задачи с таким номером")
                else:
                    print("Список задач пуст (добавьте задачу)")


            elif action == '6':
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

# сортировка по
# приоритету
# дате добавления
# названию

# сохранение в файл

# графический интерфейс

# api django(rest) или telegram