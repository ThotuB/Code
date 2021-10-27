# Expression Element:
# - Operation
# - Number

class Operation:
    def __init__(self, left, right):
        self.left = left
        self.right = right

class Num:
    def __init__(self, value):
        self.value = value

    def eval(self):
        return self.value

    def __str__(self):
        return str(self.value)


class Add(Operation):
    def eval(self):
        return self.left.eval() + self.right.eval()

    def __str__(self):
        return f'({self.left} + {self.right})'
    

class Sub(Operation):
    def eval(self):
        return self.left.eval() - self.right.eval()

    def __str__(self):
        return f'({self.left} - {self.right})'


class Mul(Operation):
    def eval(self):
        return self.left.eval() * self.right.eval()

    def __str__(self):
        return f'({self.left} * {self.right})'


class Div(Operation):
    def eval(self):
        return self.left.eval() / self.right.eval()

    def __str__(self):
        return f'({self.left} / {self.right})'


class Exp(Operation):
    def eval(self):
        return self.left.eval() ** self.right.eval()

    def __str__(self):
        return f'({self.left} ^ {self.right})'
