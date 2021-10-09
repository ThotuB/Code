class Cls:
    def __init__(self):
        self.a = 1

    def plmfunc(self):
        return 'plm'

def plm(obj):
    return obj.a


obj = Cls()
print(plm(obj))