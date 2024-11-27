from exp import Add, Sub, Mul, Div, Num, Sym
import exp

if __name__ == "__main__":
    expression = Div(Num(1), Sym('x'))
    print(expression)
    print(expression.deriv('x'))

