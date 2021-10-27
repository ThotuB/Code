class Object:
    def __init__(self, value):
        self.value = value

    def __class__(self) -> 'Object':
        return Object(self.__class__)

    #region ARITHMETIC
    # add: self + other
    def __add__(self, other: 'Object') -> 'Object':
        return Object(self.value + other.value)
    
    # sub: self - other
    def __sub__(self, other: 'Object') -> 'Object':
        return Object(self.value - other.value)
    
    # mul: self * other
    def __mul__(self, other: 'Object') -> 'Object':
        return Object(self.value * other.value)
    
    # truediv: self / other
    def __truediv__(self, other: 'Object') -> 'Object':
        return Object(self.value / other.value)
    
    # floordiv: self // other
    def __floordiv__(self, other: 'Object') -> 'Object':
        return Object(self.value // other.value)

    # mod: self % other
    def __mod__(self, other: 'Object') -> 'Object':
        return Object(self.value % other.value)

    # pow: self ** other
    def __pow__(self, other: 'Object') -> 'Object':
        return Object(self.value ** other.value)
    #endregion

    #region COMPARISON
    # eq: self == other
    def __eq__(self, other: 'Object') -> bool:
        return self.value == other.value
    
    # ne: self != other
    def __ne__(self, other: 'Object') -> bool:
        return self.value != other.value
    
    # lt: self < other
    def __lt__(self, other: 'Object') -> bool:
        return self.value < other.value
    
    # le: self <= other
    def __le__(self, other: 'Object') -> bool:
        return self.value <= other.value

    # gt: self > other
    def __gt__(self, other: 'Object') -> bool:
        return self.value > other.value
    
    # ge: self >= other
    def __ge__(self, other: 'Object') -> bool:
        return self.value >= other.value
    #endregion
    
    #region LOGICAL
    # and: self and other
    def __and__(self, other: 'Object') -> bool:
        return self.value and other.value
    
    # or: self or other
    def __or__(self, other: 'Object') -> bool:
        return self.value or other.value

    # not: not self
    def __not__(self) -> bool:
        return not self.value
    #endregion

    #region BITWISE
    # and: self & other
    def __and__(self, other: 'Object') -> 'Object':
        return Object(self.value & other.value)
    
    # or: self | other
    def __or__(self, other: 'Object') -> 'Object':
        return Object(self.value | other.value)
    
    # xor: self ^ other
    def __xor__(self, other: 'Object') -> 'Object':
        return Object(self.value ^ other.value)
    
    # invert: ~self
    def __invert__(self) -> 'Object':
        return Object(~self.value)

    # lshift: self << other
    def __lshift__(self, other: 'Object') -> 'Object':
        return Object(self.value << other.value)

    # rshift: self >> other
    def __rshift__(self, other: 'Object') -> 'Object':
        return Object(self.value >> other.value)
    # endregion

    #region ASSIGNMENT
    # iadd: self += other
    def __iadd__(self, other: 'Object') -> 'Object':
        self.value += other.value
        return self
    
    # isub: self -= other
    def __isub__(self, other: 'Object') -> 'Object':
        self.value -= other.value
        return self

    # imul: self *= other
    def __imul__(self, other: 'Object') -> 'Object':
        self.value *= other.value
        return self
    
    # itruediv: self /= other
    def __itruediv__(self, other: 'Object') -> 'Object':
        self.value /= other.value
        return self
    
    # ifloordiv: self //= other
    def __ifloordiv__(self, other: 'Object') -> 'Object':
        self.value //= other.value
        return self
    
    # imod: self %= other
    def __imod__(self, other: 'Object') -> 'Object':
        self.value %= other.value
        return self
    
    # ipow: self **= other
    def __ipow__(self, other: 'Object') -> 'Object':
        self.value **= other.value
        return self
    
    # iand: self &= other
    def __iand__(self, other: 'Object') -> 'Object':
        self.value &= other.value
        return self
    
    # ior: self |= other
    def __ior__(self, other: 'Object') -> 'Object':
        self.value |= other.value
        return self
    
    # ilshift: self <<= other
    def __ilshift__(self, other: 'Object') -> 'Object':
        self.value <<= other.value
        return self
    
    # irshift: self >>= other
    def __irshift__(self, other: 'Object') -> 'Object':
        self.value >>= other.value
        return self
    #endregion

    #region IDENTITY
    # is: self is other
    def __is__(self, other: 'Object') -> bool:
        return self is other
    
    # is not: self is not other
    def __is_not__(self, other: 'Object') -> bool:
        return self is not other
    #endregion

    #region MEMBERSHIP
    # in: self in other
    def __in__(self, other: 'Object') -> bool:
        return self.value in other.value
    
    # not in: self not in other
    def __not_in__(self, other: 'Object') -> bool:
        return self.value not in other.value
    #endregion

    #region UNARY
    # pos: +self
    def __pos__(self) -> 'Object':
        return Object(+self.value)

    # neg: -self
    def __neg__(self) -> 'Object':
        return Object(-self.value)
    #endregion

    #region STRING
    # repr: repr(self)
    def __repr__(self) -> str:
        return repr(self.value)

    def __str__(self) -> str:
        return str(self.value)
    #endregion


obj = Object(5)
print(obj.__class__)