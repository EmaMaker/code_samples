import os
from Employee import Employee


lEmployees = []

def addEmployee():
    global lEmployees

    sName = input("Employee name")
    sSurname = input("Employee surname")
    sAge = input("Employee age")
    sSalary = input("Employee's salary")

    lEmployees.append(Employee(sName, sSurname, sAge, sSalary))
    getInput()

def listEmployeesList():
    global lEmployees

    print("\nName\t\tSurname\t\tAge\t\tSalary")
    for e in lEmployees:
        #print(str(employee))
        print(str(e.name) + "\t\t\t" +str(e.surname)+ "\t\t\t" + str(e.age)+ "\t\t" + str(e.salary))

    getInput()


def saveToList():
    s = input("Name of file to save list on (no .txt ext.): ")
    s1 = s + ".txt"
    if not(os.path.exists(s1)):
        f = open(s1, "w")
        for e in lEmployees:
            f.write(str(e.name) + "|" + str(e.surname) + "|" + str(e.age) + "|" + str(e.salary)+"\n")
        f.close()

        print("Saved list to " + s1)
        getInput()
    else:
        print("File already exists")
        saveToList()

def loadFromList():
    lEmployees[:] = []
    s = input("Name of file to load list from (no .txt ext.): ")
    s1 = s + ".txt"

    if os.path.exists(s1):
        f = open(s1, "r")
        for line in f.readlines():
            infos = line.split("|")
            lEmployees.append(Employee(infos[0], infos[1], infos[2], (infos[3].replace("\n", ""))))
        f.close()
    getInput()

def getInput():
    i = input("[a] To add an employee\n"
              "[l] To list all employees\n"
              "[s] To save the current list on a file\n"
              "[f] To load a list of employees from a file (Overwrites the current list)\n"
              "[e] To exit\n\n")

    i.lower()

    if i == "l":
        listEmployeesList()
    elif i == "a":
        addEmployee()
    elif i == "s":
        saveToList()
    elif i == "f":
        loadFromList()
    elif i == "e":
        print("Goodbye")
        exit(0)
    else:
        print("Invalid input")
        getInput()


getInput()


