class Obj:
    def __init__(this, name, age):
        this.name = name
        this.age = age
    def __str__(this):
        return 'name: ' + this.name + ' age: ' + str(this.age)


obj = Obj('Tom', 18)
print(obj)