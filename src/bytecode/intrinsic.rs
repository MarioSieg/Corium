/// Contains all intrinsic procedure ids.
/// G = Generic
/// M = Math
#[repr(i32)]
#[derive(Copy, Clone, Eq, PartialEq, Debug)]
pub enum IntId {
    /// Prints one character to stdout
    PutChar,

    /// Flushes the virtual stdout to the system's stdout.
    Flush,

    /// Returns the largest integer less than or equal to a number.
    Floor,

    /// Returns the smallest integer greater than or equal to a number.
    Ceil,

    /// Returns the nearest integer to a number. Round half-way cases away from 0.0.
    Round,

    /// Returns the integer part of a number.
    Trunc,

    /// Returns the fractional part of a number.
    Fract,

    /// Computes the absolute value of self. Returns NAN if the number is NAN.
    Abs,

    /// Returns a number that represents the sign of self.
    Signum,

    /// Returns a number composed of the magnitude of self and the sign of sign.
    /// Equal to self if the sign of self and sign are the same, otherwise equal to -self. If self is a NAN, then a NAN with the sign of sign is returned.
    Copysign,

    /// Calculates Euclidean division, the matching method for rem_euclid.
    /// This computes the integer n such that self = n * rhs + self.rem_euclid(rhs).
    /// In other words, the result is self / rhs rounded to the integer n such that self >= n * rhs.
    DivEuclid,

    ///Calculates the least nonnegative remainder of self (mod rhs).
    /// In particular, the return value r satisfies 0.0 <= r < rhs.abs() in most cases.
    /// However, due to a floating point round-off error it can result in r == rhs.abs(),
    /// violating the mathematical definition, if self is much smaller than rhs.abs() in magnitude and self < 0.0.
    /// This result is not an element of the function's codomain,
    /// but it is the closest floating point number in the real numbers and thus fulfills
    /// the property self == self.div_euclid(rhs) * rhs + self.rem_euclid(rhs) approximatively.
    RemEuclid,

    /// Raises a number to a floating point power.
    PowF,

    /// Returns the square root of a number.
    /// Returns NaN if self is a negative number.
    Sqrt,

    /// Returns e^(self), (the exponential function).
    Exp,

    /// Returns 2^(self).
    Exp2,

    /// Returns the natural logarithm of the number.
    Ln,

    /// Returns the logarithm of the number with respect to an arbitrary base.
    /// The result may not be correctly rounded owing to implementation details;
    /// self.log2() can produce more accurate results for base 2, and self.log10()
    /// can produce more accurate results for base 10.
    Log,

    /// Returns the base 2 logarithm of the number.
    Log2,

    /// Returns the base 10 logarithm of the number.
    Log10,

    /// Returns the cubic root of a number.
    Cbrt,

    /// Calculates the length of the hypotenuse of a right-angle triangle given legs of length x and y.
    Hypot,

    /// Computes the sine of a number (in radians).
    Sin,

    /// Computes the cosine of a number (in radians).
    Cos,

    /// Computes the tangent of a number (in radians).
    Tan,

    /// Computes the arcsine of a number.
    /// Return value is in radians in the range [-pi/2, pi/2] or NaN
    /// if the number is outside the range [-1, 1].
    Asin,

    /// Computes the arccosine of a number.
    /// Return value is in radians in the range [0, pi] or NaN
    /// if the number is outside the range [-1, 1].
    Acos,

    /// Computes the arctangent of a number. Return value is in radians in the range [-pi/2, pi/2];
    Atan,

    /// Computes the four quadrant arctangent of self (y) and other (x) in radians.
    /// x = 0, y = 0: 0
    /// x >= 0: arctan(y/x) -> [-pi/2, pi/2]
    /// y >= 0: arctan(y/x) + pi -> (pi/2, pi]
    /// y < 0: arctan(y/x) - pi -> (-pi, -pi/2)
    Atan2,

    /// Returns e^(self) - 1 in a way that is accurate even if the number is close to zero.
    ExpM1,

    /// Returns ln(1+n) (natural logarithm) more accurately than if the operations were performed separately.
    Ln1P,

    /// Hyperbolic sine function.
    SinH,

    /// Hyperbolic cosine function.
    CosH,

    /// Hyperbolic tangent function.
    TanH,

    /// Inverse hyperbolic sine function.
    AsinH,

    /// Inverse hyperbolic cosine function.
    AcosH,

    /// Inverse hyperbolic tangent function.
    AtanH,

    /// Returns true if this value is NaN.
    IsNan,

    /// Returns true if this value is positive infinity or negative infinity, and false otherwise.
    IsInfinite,

    /// Returns true if this number is neither infinite nor NaN.
    IsFinite,

    /// Returns true if the number is neither zero, infinite, subnormal, or NaN.
    IsNormal,

    /// Returns true if self has a positive sign, including +0.0,
    /// NaNs with positive sign bit and positive infinity.
    IsSignalPositive,

    /// Returns true if self has a negative sign, including -0.0,
    /// NaNs with negative sign bit and negative infinity.
    IsSignalNegative,

    /// Takes the reciprocal (inverse) of a number, 1/x.
    Recip,

    /// Converts radians to degrees.
    ToDegrees,

    /// Converts degrees to radians.
    ToRadians,

    /// Returns the maximum of the two numbers.
    /// If one of the arguments is NaN, then the other argument is returned.
    Max,

    /// Returns the minimum of the two numbers.
    /// If one of the arguments is NaN, then the other argument is returned.
    Min,

    Count,
}
