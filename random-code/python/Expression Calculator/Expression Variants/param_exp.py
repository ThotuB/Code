# Parametric Expression Element:
# - Operation
# - Number
# - Symbol

class Operation:
    def __init__(self, left, right):
        self.left = left
        self.right = right


class Num:
    def __init__(self, val):
        self.val = val

    def eval(self, x):
        return self.val

    def __str__(self):
        return str(self.val)


class Sym:
    def __init__(self, sym):
        self.sym = sym

    def eval(self, x):
        return x

    def __str__(self):
        return self.sym


class Add(Operation):
    def eval(self, x):
        return self.left.eval(x) + self.right.eval(x)

    def __str__(self):
        return f'({self.left} + {self.right})'
    

class Sub(Operation):
    def eval(self, x):
        return self.left.eval(x) - self.right.eval(x)

    def __str__(self):
        return f'({self.left} - {self.right})'


class Mul(Operation):
    def eval(self, x):
        return self.left.eval(x) * self.right.eval(x)

    def __str__(self):
        return f'({self.left} * {self.right})'


class Div(Operation):
    def eval(self, x):
        return self.left.eval(x) / self.right.eval(x)

    def __str__(self):
        return f'({self.left} / {self.right})'


class Exp(Operation):
    def eval(self, x):
        return self.left.eval(x) ** self.right.eval(x)

    def __str__(self):
        return f'({self.left} ^ {self.right})'
