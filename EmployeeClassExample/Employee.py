class Employee:

    salary = 0
    name = ""
    surname = ""
    age = 0

    def __init__(self, name_, surname_, age_, salary_):
        global salary, name, surname, age

        self.salary = salary_
        self.name = name_
        self.surname = surname_
        self.age = age_
