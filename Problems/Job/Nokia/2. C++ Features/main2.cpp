class Fraction {
public:
    constexpr Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}

    // operatos
    constexpr Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    constexpr Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    constexpr bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

private:
    int numerator;
    int denominator;
};

