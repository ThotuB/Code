class Polynomial:
    def __init__(self, coefficients: list[int]):
        self.coeffs = coefficients
        self.order = len(coefficients)

    def operation_helper(self, other: 'Polynomial', operation: callable):
        (min_order, min_poly) = (self.order, self) if self.order < other.order else (other.order, other)
        max_poly = self if self.order > other.order else other

        coeffs = [operation(min_poly.coeffs[i], max_poly.coeffs[i]) for i in range(min_order)] + max_poly.coeffs[min_order:]

        return Polynomial(coeffs)

    def __add__(self, other: 'Polynomial'):
        return self.operation_helper(other, lambda a, b: a + b)

    def __sub__(self, other: 'Polynomial'):
        return self.operation_helper(other, lambda a, b: a - b)

    def __mul__(self, other: 'Polynomial'):
        result = [0] * (self.order + other.order - 1)

        for i in range(self.order):
            for j in range(other.order):
                result[i + j] += self.coeffs[i] * other.coeffs[j]

        return Polynomial(result)

    def __str__(self):
        result = ""
        for i in range(self.order):
            result += str(self.coeffs[i])

            if i == 1:
                result += "x"
            elif i > 1:
                result += "x^" + str(i)

            if i != self.order - 1:
                result += " + "
        return result


poly1 = Polynomial([1, 2])
poly2 = Polynomial([1, 2, 3])
print(poly1 * poly2)
