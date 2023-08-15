(appendixa:ascii)=
# Appendix A.3: ASCII

ASCII. (American Standard Code for Information Interchange) is an
encoding format for text developed in the early 1960's.

The original ASCII format was based on the English alphabet and
encodes 128 specified characters into seven-bit binary numbers.

Ninety-five of the encoded characters are printable, including the
digits 0 to 9, lowercase letters a to z, uppercase letters A to Z,
space, and punctuation symbols.

The remaining 32 non-printing control codes for based around the
standards original implementation with Teletype machines -- most of
these are now obsolete but some are still used including carriage
return (`\r` in C), line feed (`\n` in C), tab (`\t` in C).

- As microprocessors evolved to 8-bit and higher the ASCII standard has
also evolved to use the eighth bit allowing a further 127 characters
(extended ASCII).[^note2]

```{list-table} ANSI ASCII Table
:header-rows: 1
:name: ascii_table
* - Dec
  - Hex
  - Symbol
  - Dec
  - Hex
  - Symbol
  - Dec
  - Hex
  - Symbol
  - Dec
  - Hex
  - Symbol
* - 0
  - `0x00`
  - Null character[^note3]
   - 32 
  - `0x20`
  - Space 
  - 64 
  - `0x40`
  - @
  - 96
  - `0x60`
  - `
* - 1 
  - `0x01`
  - Start of heading
  - 33 
  - `0x21`
  - ! 
  - 65 
  - `0x41`
  - A
  - 97
  - `0x61`
  - a
* - 2 
  - `0x02`
  - Start of text
  - 34 
  - `0x22`
  - "
  - 66 
  - `0x42`
  - B
  - 98
  - `0x62`
  - b
* - 3 
  - `0x03`
  - End of text
  - 35 
  - `0x23`
  - \# 
  - 67 
  - `0x43`
  - C
  - 99
  - `0x63`
  - c
* - 4 
  - `0x04`
  - End of Transmission
  - 36 
  - `0x24`
  - $ 
  - 67 
  - `0x44`
  - D
  - 100
  - `0x64`
  - d
* - 5 
  - `0x05`
  - Enquiry
  - 37 
  - `0x25`
  - \% 
  - 64 
  - `0x45`
  - E
  - 101
  - `0x65`
  - e
* - 6 
  - `0x06`
  - Acknowledgement
  - 38 
  - `0x26`
  - & 
  - 64 
  - `0x46`
  - F
  - 102
  - `0x66`
  - f
* - 7 
  - `0x07`
  - Bell
  - 39 
  - `0x27`
  - ' 
  - 64 
  - `0x47`
  - G
  - 103
  - `0x67`
  - g
* - 8 
  - `0x08`
  - Backspace
  - 40 
  - `0x08`
  - (
  - 64 
  - `0x48`
  - H
  - 104
  - `0x68`
  - h
* - 9 
  - `0x09`
  - Horizontal tab
  - 41 
  - `0x29`
  - ) 
  - 64 
  - `0x49`
  - I
  - 105
  - `0x69`
  - i
* - 10 
  - `0x0A`
  - Line feed
  - 42 
  - `0x2A`
  - * 
  - 64 
  - `0x4A`
  - J
  - 106
  - `0x6A`
  - j
* - 11 
  - `0x0B`
  - Vertical tab
  - 43 
  - `0x2B`
  - \+ 
  - 64 
  - `0x4B`
  - K
  - 107
  - `0x6B`
  - k
* - 12 
  - `0x0C`
  - Form feed
  - 44 
  - `0x2C`
  - ,
  - 64 
  - `0x4C`
  - L
  - 108
  - `0x6C`
  - l
* - 13 
  - `0x0D`
  - Carriage return
  - 45 
  - `0x2D`
  - \- 
  - 64 
  - `0x4D`
  - M
  - 109
  - `0x6D`
  - m
* - 14 
  - `0x0E`
  - Shift out
  - 46 
  - `0x2E`
  - . 
  - 64 
  - `0x4E`
  - N
  - 110
  - `0x6E`
  - n
* - 15 
  - `0x0F`
  - Shift in
  - 47
  - `0x2F`
  - / 
  - 64 
  - `0x4F`
  - O
  - 111
  - `0x6F`
  - o
* - 16 
  - `0x10`
  - Data link escape
  - 48 
  - `0x30`
  - 0 
  - 65 
  - `0x50`
  - P
  - 112
  - `0x70`
  - p
* - 17 
  - `0x11`
  - Device control 1
  - 49 
  - `0x31`
  -  1
  - 64 
  - `0x51`
  - Q
  - 113
  - `0x71`
  - q
* - 18 
  - `0x02`
  - Device control 2
  - 50 
  - `0x32`
  - 2 
  - 64 
  - `0x52`
  - R
  - 114
  - `0x72`
  - r
* - 19 
  - `0x13`
  - Device control 3
  - 51 
  - `0x33`
  - 3 
  - 64 
  - `0x53`
  - S
  - 115
  - `0x73`
  - s
* - 20 
  - `0x14`
  - Device control 4
  - 52 
  - `0x34`
  - 4 
  - 64 
  - `0x54`
  - T
  - 116
  - `0x74`
  - t
* - 21 
  - `0x15`
  - Negative acknowledgement
  - 53 
  - `0x35`
  - 5 
  - 64 
  - `0x55`
  - U
  - 117
  - `0x75`
  - u
* - 22 
  - `0x16`
  - Synchronous idle
  - 54 
  - `0x36`
  - 6 
  - 64 
  - `0x56`
  - V
  - 118
  - `0x76`
  - v
* - 23 
  - `0x17`
  - End of transmission block
  - 55 
  - `0x37`
  - 7 
  - 64 
  - `0x57`
  - W
  - 119
  - `0x77`
  - w
* - 24 
  - `0x18`
  - Cancel
  - 56 
  - `0x38`
  - 8 
  - 64 
  - `0x58`
  - X
  - 120
  - `0x78`
  - x
* - 25 
  - `0x19`
  - End of medium
  - 57 
  - `0x39`
  - 9 
  - 64 
  - `0x59`
  - Y
  - 121
  - `0x79`
  - y
* - 26 
  - `0x1A`
  - Substitute
  - 58 
  - `0x3A`
  - : 
  - 64 
  - `0x5A`
  - Z
  - 122
  - `0x7A`
  - z
* - 27 
  - `0x1B`
  - Escape
  - 59 
  - `0x3B`
  - ; 
  - 64 
  - `0x5B`
  - [
  - 123
  - `0x7B`
  - {
* - 28 
  - `0x1C`
  - File separator
  - 60 
  - `0x3C`
  - < 
  - 64 
  - `0x5C`
  - \
  - 124
  - `0x7C`
  - |
* - 29 
  - `0x1D`
  - Group separator
  - 61 
  - `0x3D`
  - = 
  - 64 
  - `0x4D`
  - ]
  - 125
  - `0x7D`
  - }
* - 30 
  - `0x1E`
  - Record separator
  - 62 
  - `0x3E`
  - \> 
  - 64 
  - `0x5E`
  - ^
  - 126
  - `0x7E`
  - ~
* - 31 
  - `0x1F`
  - Unit separator
  - 63 
  - `0x3F`
  - ?
  - 95 
  - `0x5F`
  - _
  - 127
  - `0x7F`
  - Delete
```

A very useful and useful reference is available as [ascii-code.com](https://ascii-code.com). See also [ASCII Code Chart](https://www.ascii-code.com/ASCII/codechart).


## Example

Encode the string "Welcome to Swansea University" in ASCII and give the binary codes that would be used to store this string in computer memory.


### Solution

Look up the characters and write down the equivalent hexadecimal code. Note, null (`\0`) is used to terminate the string

`'W'` = $87_{10}$ = `0x57` = $01010111_2$

`'e'` = $101_{10}$ = `0x65` = $01100101_2$

`'l'` = $108_{10}$ = `0x6C` = $01101011_2$

`'c'` = $99_{10}$ = `0x63` = $01100011_2$

`'o'` = $111_{10}$ = `0x6F` = $01101111_2$

`'m'` = $109_{10}$ = `0x6D` = $01101101_2$

`'e'` = $108_{10}$ = `0x6C` = $01101011_2$

`' '` = $108_{10}$ = `0x6C` = $01101011_2$

`'t'` = $108_{10}$ = `0x6C` = $01101011_2$

`'o'` = $108_{10}$ = `0x6C` = $01101011_2$

`' '` = $32_{10}$ = `0x20` = $00100000_2$

`'S'` = $83_{10}$ = `0x53` = $01010011_2$ 

`'w'` = $119_{10}$ = `0x77` = $01110111_2$

`'a'` = $97_{10}$ = `0x61` = $01100001_2$

`'n'` = $110_{10}$ = `0x6E` = $01101110_2$

`'s'` = $115_{10}$ = `0x73` = $01110011_2$

`'e'` = $108_{10}$ = `0x6C` = $01101011_2$

`'a'` = $97_{10}$ = `0x61` = $01100001_2$

`\0` = `0x000` = $00000000_2$

The final result (in hexadecimal) is

```
57
65
6C
63
6F
6D
65
32
74
6E
32
53
77
61
6E
73
65
61
00
```

[^note2]: As ASCII was only designed to represent English, extended ASCII was developed been used to extend the coding so that displays could print accented European characters, some Greek symbols used in mathematics, and some symbols that could be used to draw boxes on a simple display screen. In order to support the rest of the human languages and alphabets, and for other purposes such as Emojis, ASCII has been extended to a standard called UTF. This uses more bytes to represent each character and therefore greatly extends the types of texts that can be stored and manipulated inside a computer.

[^note3]: the null character (`\0` in C) is used in C to mark the end of a string.
