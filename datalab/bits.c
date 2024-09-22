/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

//P1
/* 
 * tmax - return a the biggest positive number that an integer can represent
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int tmax(void) {
  return ~(1<<31);
}

//p2
/* 
 * bitNor - ~(x|y) using only ~ and & 
 *   Example: bitNor(4, 5) = -6, bitNor(-1,-2) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitNor(int x, int y) {
	return (~x)&(~y);
}

//P3
/*
 * getByte - return the nth byte of x
 *   You can assume 0 <= y <= 3
 *   Example: getByte(0x01020304, 2) = 0x2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x,int n) {
  return (x>>(n<<3))&0xff;
  //return 2;
}

//P4
/* 
 * roundUp - round up x to the nearest multiple of 256
 *   Example: roundUp(0x117f) = 0x1200
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int roundUp(int x) {
      return (x+(0xff)) & ~0xff;
    //return 3;
}

//p5
/*
 * absVal - return the absolute value of x
 *   Examples: absVal(-10) = 10
 *			   absVal(5) = 5
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int absVal(int x){
    return (x^(x>>31))+((x>>31)&1);
    //return 3;
}

//p6
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 4
 */
int isLessOrEqual(int x, int y) {
  return 4;
}

//p7
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  int A_shift = (x>>n);
  int check = x & (1<<31);
  check=check>>n<<1;
  x=A_shift & (~check);
  return x;
  //return 4;
}

//P8
/*
 * swapOddandEven - swap the odd bits and even bits in x
 *   Examples: swapOddandEven(0xAA) = 0x55
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapOddandEven(int x) {
  
  int mask1 = 0x55;
  int mask2 = 0xAA;
  mask1 = mask1|mask1<<8;
  mask1 = mask1|mask1<<16;
  mask2 = mask2|mask2<<8;
  mask2 = mask2|mask2<<16; 
  return ((x&mask1)<<1)|((x&mask2)>>1);
  
  //return 4;
}

//P9
/*
 * secondLowBit - return a mask that marks the position of the second least significant 1 bit.
 *   Examples: secondLowBit(0x00000110) = 0x00000100
 *			       secondLowBit(0xFEDC1a80) = 0x00000200
 *             secondLowBit(0)  = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowBit(int x) {
  int nagetive_one=~0;
	int a=x&(x+nagetive_one);
  int b=a&(a+nagetive_one);
  return a+(~b)+1;
  //return 4;
}

//P10
/* 
 * rotateNbits - rotate x to left by n bits\
 *   you can assume n >= 0
 *   Examples: rotateNbits(0x12345678, 8) = 0x34567812
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 5
 */
int rotateNBits(int x, int n) {
  
  n = n&(0x1f);
  return (x << n) | (x >> (33 + ~n));  //33 + ~n equals to "32 - n"
  
  //return 5;
}

//P11
/* 
 * fractions - return floor(x*7/16), for 0 <= x <= (1 << 28), x is an integer 
 *   Example: fractions(20) = 8
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 5
 */
int fractions(int x) {
  return ((x<<2) + (x<<1) + x)>>4;
}


//P12
/* 
 * overflowCalc - given binary representations of three 32-bit positive numbers and add them together, 
 *      return the binary representation of the part where bits are higher than 32.
 *   Examples: overflowCalc(0xffffffff,0xffffffff,0xffffffff) = 2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7 
 */
int overflowCalc(int x, int y, int z) {
  int a=(0xff<<8)+0xff;
  int high_x=(x>>16)&a;
  int high_y=(y>>16)&a;
  int high_z=(z>>16)&a;
  int low_x=x&a;
  int low_y=y&a;
  int low_z=z&a;
  int num1=low_x+low_y+low_z;
  int carry=num1>>16;
  int high=high_x+high_y+high_z+carry;
  int overflow=high>>16;
  return overflow;
  //return 7;
}

//P13
/* 
 * mul7 - return x*3, and if x*3 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul7(1) = 0x7, mul7(0x7ffffff0) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 36
 *   Rating: 8
 */
int mul3(int x) {
  int mul2 = (x<<1);
  int mul3 = mul2 +x;
  int overflow = ((x^mul3)|(x^mul2))>>31;
  int INT_MAX = 0x7f<<24|0xff<<16|0xff<<8|0xff;
  return (mul3 & ~overflow) | (((x>>31)^INT_MAX) & overflow);
}

//P14
/* 
 * float_abs - Return bit-level equivalent of expression |f| (absolute value of f) for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 20
 *   Rating: 3
 */
unsigned float_abs(unsigned uf) {
  int a=0xff<<23;
  int exp=(uf&a)>>23;
  int b=(0xff<<15)+(0xff<<7)+7;
  int f=uf&b;
  if(exp==0xff&&f!=0)
    return uf;
  else
    return uf&(~(1<<31));
  //return 3;
}

//p15
/* 
 * float_half - Return bit-level equivalent of expression f/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 32
 *   Rating: 4
 */
unsigned float_half(unsigned f) {
    int sign = f & 0x80000000; 
    int exponent = (f & 0x7F800000) >> 23; 
    int fraction = f & 0x007FFFFF; 

    if (exponent == 0) {
        fraction = (fraction>>1) + (((fraction&2)>>1)&fraction&1);
    } else if (exponent == 255) {
        return f;
    } else {
        exponent--;
        if (exponent == 0) {
          fraction = 0x800000|fraction;
          fraction = (fraction>>1) + (((fraction&2)>>1)&fraction&1);
        }
    }
    return sign | (exponent << 23) | fraction;
}

//P16
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 7
 */
unsigned float_i2f(int x) {
  int sign=x&0x80000000;
  int digit=x&0x7fffffff;
  int val;
  int exp=0;
  int temp_val;
  int lower_part;
  int comparison;
  int carry;
  int fraction;
  if(x==0x80000000)
    return 0xcf000000;
  if(x==0)
    return 0;

  if(sign==0x80000000)
    val=((~digit)&0x7fffffff)+1;
  else
    val=digit;
  
  temp_val=val;
  while(temp_val!=0){
    temp_val=temp_val>>1;
    exp++;
    if(temp_val==0) exp--;
  }

  if(exp>23){
    lower_part=val&(~(0xfffffffe<<(exp-24)));
    lower_part=lower_part<<1;
    comparison=(1<<(exp-23))+!(val&(1<<(exp-23)));
    carry = lower_part >= comparison;
    val=(val>>(exp-23))+carry;
    if(val>=0x1000000){
      exp+=1;
    }
  }
  else
    val=val<<(23-exp);

  fraction=val&0x7fffff;
  exp+=127;
  exp=(exp<<23);
  return sign|exp|fraction;
  //return 7;
}


//challange

//P17
/*
 * oddParity - return the odd parity bit of x, that is, 
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples:oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 2
 */
int oddParity(int x) {
  int a=(x>>24)&0xff;
  int b=(x>>16)&0xff;
  int c=(x>>8)&0xff;
  int d=x&0xff;

  int e=(a^b);
  int f=(c^d);

  int g=(e^f);

  a=g&0xf;
  b=(g>>4)&0xf;
  a=(a^b);

  c=a&0x3;
  d=(a>>2)&0x3;
  c=(c^d);
  
  a=c&1;
  b=(c>>1)&1;
  f=(a^b);
  return !f;
}

//p18
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 2
 */
int bitCount(int x) {
  return 4;
}