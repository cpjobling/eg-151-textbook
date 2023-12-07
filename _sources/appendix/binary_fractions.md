<!-- #region -->
(appendixa:binary_fractions)=
# Appendix A.3: Binary Fractions

## Floating Point Numbers

With decimal numbers a decimal point is used to separate the whole and fractional parts of a number. Recalling from {ref}`week02` that we represent numbers using a weighted [positional notation](https://en.wikipedia.org/wiki/Positional_notation)  in which digit's value is relative to its position. ({numref}`fig:pos_ntn`) illustrates the idea

```{figure} pictures/positional_notation.png
:name: fig:pos_ntn
:align: center
:width: 50%
:alt: Positional notation

Positional notation
```

We use exponentiation of negative powers of the base to represent the fractional part of a number:


$$14.12_{10} = \left(1\times 10^1\right) + \left(4\times 10^0\right) + \left(1\times 10^{-1}\right) + \left(2\times 10^{-2}\right)$$ 
<!-- #endregion -->

The idea extends to binary, octal and hexadecimal numbers:

\begin{align*}
0000.101_2 &= \left(1\times 2^{-1}\right) + \left(0\times 2^{-2}\right) + \left(1\times 2^{-3}\right) \\
&= \frac{1}{2} + 0\times \frac{1}{4} + \frac{1}{8}\\ 
&= 0.5 + 0 + 0.125 = 0.625_{10}
\end{align*}

The representation of octal and hexadecimal numbers is left as an exercise.


## Decimal Floating-Point Number Conversion

To convert a decimal fraction (base 10) to a new base (n) the fractional
part is repeatedly multiplied by n.

- The whole number part of the product gives the value at the current
power.

- The decimal part of the product is multiplied by n and repeated until
the fractional part of the product is zero

- Read the result from **top to bottom**


## Limitations

Convert $0.675_{10}$ to binary

0.675 × 2 = 1.35 1

0.35 × 2 = 0.7 0

0.7 × 2 = 1.4 1

0.4 × 2 = 0.8 0

0.8 × 2 = 1.6 1

0.6 × 2 = 1.2 1

0.2 × 2 = 0.4 0

0.4 × 2 = 0.8 0

0.8 × 2 = 1.6 1


## Reality

Modern computers use a special data format called **floating point** which can be used to approximate decimal numbers to a reasonable precision over a large range. However, floating point numbers need more storage (typically 32 or 64 bits per number) and special hardware to make computation with these values efficient. For microcontrollers, particularly with limited memory and 8-bit data storage, we rarely use floating point arithmetic and rely instead of integer representations.

```python

```
