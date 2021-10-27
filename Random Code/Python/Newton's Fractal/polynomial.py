class Poly:
    def __init__(self, lst: list[complex], mode: str='coef'):
        if mode == 'coef':
            self.coeffs = lst
            self.order = len(lst)
        elif 'root':
            res = Poly([1])

            for root in lst:
                res *= Poly([-root, 1])
            
            self.coeffs = res.coeffs
            self.order = res.order


    def __call__(self, x: float):
        result = 0
        for i in range(self.order):
            result += self.coeffs[i] * x ** i
        return result

    #* OPERATIONS
    def _operation_helper(self, other: 'Poly', operation: callable):
        (min_order, min_poly, max_poly) = (self.order, self, other) if self.order < other.order else (other.order, other, self)

        coeffs = [operation(min_poly.coeffs[i], max_poly.coeffs[i]) for i in range(min_order)] + max_poly.coeffs[min_order:]

        return Poly(coeffs)

    def __add__(self, other: 'Poly'):
        return self._operation_helper(other, lambda a, b: a + b)

    def __sub__(self, other: 'Poly'):
        return self._operation_helper(other, lambda a, b: a - b)

    def __mul__(self, other: 'Poly'):
        result = [0] * (self.order + other.order - 1)

        for i in range(self.order):
            for j in range(other.order):
                result[i + j] += self.coeffs[i] * other.coeffs[j]

        return Poly(result)

    def __imul__(self, other: 'Poly'):
        return self.__mul__(other)

    #* DERIVATIVE
    def derivative(self):
        return Poly([self.coeffs[i] * i for i in range(1, self.order)])

    def __rshift__(self, other: int):
        res = self
        for _ in range(other):
            res = res.derivative()
        return res

    def __str__(self):
        result = ""
        for i in range(self.order):
            result += str(self.coeffs[i])

            if i == 1:
                result += "z"
            elif i > 1:
                result += "z^" + str(i)

            if i != self.order - 1:
                result += " + "
        return result
