# Parametric Expression Element:
# - Operation
# - Number
# - Symbol

class Num:
    def __init__(self, val):
        self.val = val

    def eval(self, **_):
        return self.val

    def deriv(self, _):
        return Num(0)

    def __str__(self):
        return str(self.val)


class Sym:
    def __init__(self, sym):
        self.sym = sym

    def eval(self, **params):
        return params[self.sym]

    def deriv(self, sym):
        if self.sym == sym:
            return Num(1)
        else:
            return Num(0)

    def __str__(self):
        return self.sym


class Operation:
    def __init__(self, left, right):
        self.left = left
        self.right = right


class Add(Operation):
    def eval(self, **params):
        return self.left.eval(**params) + self.right.eval(**params)

    def deriv(self, sym):
        return Add(self.left.deriv(sym), self.right.deriv(sym))

    def __str__(self):
        return f'({self.left} + {self.right})'
    

class Sub(Operation):
    def eval(self, **params):
        return self.left.eval(**params) - self.right.eval(**params)

    def deriv(self, sym):
        return Sub(self.left.deriv(sym), self.right.deriv(sym))

    def __str__(self):
        return f'({self.left} - {self.right})'


class Mul(Operation):
    def eval(self, **params):
        return self.left.eval(**params) * self.right.eval(**params)

    def deriv(self, sym):
        return Add(Mul(self.left.deriv(sym), self.right), Mul(self.left, self.right.deriv(sym)))

    def __str__(self):
        return f'({self.left} * {self.right})'


class Div(Operation):
    def eval(self, **params):
        return self.left.eval(**params) / self.right.eval(**params)
    
    def deriv(self, sym):
        return Div(Sub(Mul(self.left.deriv(sym), self.right), Mul(self.left, self.right.deriv(sym))), Pow(self.right, 2))

    def __str__(self):
        return f'({self.left} / {self.right})'


class Pow(Operation):
    def eval(self, **params):
        return self.left.eval(**params) ** self.right.eval(**params)

    def deriv(self, sym):
        return Mul(Pow(self.left, Add(self.right, Num(1))), Mul(self.right, self.left.deriv(sym)))

    def __str__(self):
        return f'({self.left} ^ {self.right})'


def parse(expression: str):
    pass
