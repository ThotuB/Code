class Constant:
    def __init__(self, value):
        self.value = value

    def func(self, x):
        return self.value

    @property
    def der(self):
        return Constant(0)

    def __str__(self):
        return f'y = {self.value}'

class Linear:
    def __init__(self, slope, intercept):
        self.slope = slope
        self.intercept = intercept

    def func(self, x):
        return self.slope * x + self.intercept

    @property
    def der(self):
        return Constant(self.slope)

    def __str__(self):
        return f"y = {self.slope}x + {self.intercept}"


class Func:
    pass