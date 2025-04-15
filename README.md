# Learn C Hard Way

## 📖 Usage
To set up the project from scratch (with MSYS2, CMake, and VSCode), follow the [USAGE.md](./USAGE.md) guide.

## History of C
Dennis M. Ritchie created C, a general-purpose, procedural, imperative computer programming language, at Bell Telephone Laboratories in 1972 in order to create the Unix operating system.  Along with Java, which is similarly popular and the most generally used programming language among contemporary software programmers, C is the most widely used computer language, consistently ranking at the top of the popularity scale.  A collection of C built-in functions, constants, and header files such as <stdio.h>, <stdlib.h>, <math.h>, and others make up the C Standard Library.  For C programmers, this library will serve as a reference guide.

[Data Taken from this Source](https://www.tutorialspoint.com/cprogramming/c_overview.htm) 

## Features of C langauge
- C was invented to write an operating system called UNIX.
- C is a successor of B language which was introduced around the early 1970s.
- The language was formalized in 1988 by the American National Standard Institute (ANSI).
- The UNIX OS was totally written in C.
- Today C is the most widely used and popular System Programming Language.
- Most of the state-of-the-art software have been implemented using C.
- Today's most popular Linux OS and RDBMS MySQL have been written in C.

## Why Use C Language?
C was initially used for system development work, particularly the programs that make-up the operating system. C was adopted as a system development language because it produces code that runs nearly as fast as the code written in assembly language.

Some examples of the use of C might be −
- Operating Systems
- Language Compilers
- Assemblers
- Text Editors
- Print Spoolers
- Network Drivers
- Modern Programs
- Databases
- Language Interpreters
- Utilities

## Advantages of C Language

- Efficiency and speed − C is known for being high−performing and efficient. It can let you work with memory at a low level, as well as allow direct access to hardware, making it ideal for applications requiring speed and economical resource use.
- Portable − C programs can be compiled and executed on different platforms with minimal or no modifications. This portability is due to the fact that the language has been standardized and compilers are available for use on various operating systems globally.
- Close to Hardware − C allows direct manipulation of hardware through the use of pointers and low−level operations. This makes it suitable for system programming and developing applications that require fine-grained control over hardware resources.
- Standard Libraries − For common tasks such as input/output operations, string manipulation, and mathematical computations, C comes with a large standard library which helps developers write code more efficiently by leveraging pre−built functions.
- Structured Programming − C helps to organize code into modular and easy−to−understand structures. With functions, loops, and conditionals, developers can produce clear code that is easy to maintain.
- Procedural Language − C follows a procedural paradigm that is often simpler and more straightforward for some types of programming tasks.
- Versatility − C language is a versatile programming language and it can be used for various types of software such as system applications, compilers, firmware, application software, etc.

## Drawbacks of C Language

- Manual Memory Management − C languages need manual memory management, where a developer has to take care of allocating and deallocating memory explicitly.
- No Object−Oriented Feature − Nowadays, most of the programming languages support the OOPs features. But C language does not support it.
- No Garbage Collection − C language does not support the concept of Garbage collection. A developer needs to allocate and deallocate memory manually and this can be error-prone and lead to memory leaks or inefficient memory usage.
- No Exception Handling − C language does not provide any library for handling exceptions. A developer needs to write code to handle all types of expectations

## Include Header Files
Include necessary header files that contain declarations of functions, constants, and macros that can be used in one or more source code files. Some popular header files are as −

- stdio.h − Provides input and output functions like printf and scanf.
```c
    #include <stdio.h>
```
- stdlib.h − Contains functions involving memory allocation, rand function, and other utility functions.
```c
    #include <stdlib.h>
```
- math.h − Includes mathematical functions like sqrt, sin, cos, etc.
```c
    #include <math.h>
```
- string.h − Includes functions for manipulating strings, such as strcpy, strlen, etc.
```c
    #include <string.h>
```
- ctype.h − Functions for testing and mapping characters, like isalpha, isdigit, etc.
```c
    #include <ctypes.h>
```
- stdbool.h − Defines the boolean data type and values true and false.
```c
    #include <stdbool.h>
```
- time.h − Contains functions for working with date and time.
```c
    #include <time.h>
```
- limits.h − Defines various implementation-specific limits on integer types.
```c
    #include <limits.h>
```
## History of C Versions After Traditional C

Dennis Ritchie along with Brian Kernighan published the first edition of their book "The C Programming Language". Popularly known as K&R (the initials of its authors), the book served for many years as an informal specification of the language. The version of C that it describes is commonly referred to as "K&R C". It is also referred to as C78.

Many of the features of C language introduced in K&R C are still the part of the language ratified as late as in 2018. In early versions of C, only functions that return types other than int must be declared if used before the function definition; functions used without prior declaration were presumed to return type int.

C compilers by AT&T and other vendors supported several features added to the K&R C language. Although C started gaining popularity, there was a lack of uniformity in implementation. Therefore, it was felt that the language specifications must be standardized.

- ANSI C
In the 1980s, the American National Standards Institute (ANSI) began working on a formal standard for the C language. This led to the development of ANSI C, which was standardized in 1989. ANSI C introduced several new features and clarified ambiguities present in earlier versions of the language.

- C89/C90
The ANSI C standard was adopted internationally and became known as C89 (or C90, depending on the year of ratification). It served as the basis for compilers and development tools for many years.

- C99
In 1999, the ISO/IEC approved an updated version of the C standard known as C99. The C standard was further revised in the late 1990s.

- C99 introduced new features, including inline functions, several new data types such as a complex type to represent complex numbers, and variable-length arrays etc. It also added support for C++ style one-line comments beginning with //.

- C11
C11, published in 2011, is another major revision of the C standard. The C11 standard adds new features to C and the library and introduced features such as multi-threading support, anonymous structures and unions, and improved Unicode support. It includes type generic macros, anonymous structures, improved Unicode support, atomic operations, multi-threading, and bounds-checked functions. It has an improved compatibility with C++.

- C17
The C17 standard has been published in June 2018. C17 is the current standard for the C programming language. No new features have been introduced with this standard revision. It only performs certain technical corrections, and clarifications to defects in C11.

- C18
The most recent version of the C standard, C18, was published in 2018. It includes minor revisions and bug fixes compared to C11.

- C23
C23 is the informal name for the next major C language standard revision, expected to be published in 2024. 14 new keywords are expected to be introduced in this revision.

## The C Compiler
The source code written in the source file is the human readable source for your program. It needs to be "compiled", into machine language so that your CPU can actually execute the program as per the instructions given.

There are many C compilers available. Following is a select list of C compilers that are widely used −

- GNU Compiler Collection (GCC) − GCC is a popular open-source C compiler. It is available for a wide range of platforms including Windows, macOS, and Linux. GCC is known for its wide range of features and support for a variety of C standards.

- Clang: Clang is an open-source C compiler that is part of the LLVM(Low Level Virtual Machine) project. It is available for a variety of platforms including Windows, macOS, and Linux. Clang is known for its speed and optimization capabilities.

- Microsoft Visual C++ − Microsoft Visual C++ is a proprietary C compiler that is developed by Microsoft. It is available for Windows only. Visual C++ is known for its integration with the Microsoft Visual Studio development environment.

- Turbo C − Turbo C is a discontinued C compiler that was developed by Borland. It was popular in the early 1990s, but it is no longer widely used.

## C Build Process

![Image ](images/C-buildProcess.jpg)

The C build process typically involves several phases, with different tools involved in each stage. Here's a detailed breakdown of the phases, the files generated at each stage, and the associated file extensions.

### 1.Preprocessing
The first phase in the build process is preprocessing. This involves expanding macros, including header files, and processing conditional compilation directives.

Tools: gcc -E or clang -E   
Input: .c files (C source files)    
Output: .i files (Preprocessed C files) 
#### Actions:
- Macros are expanded (e.g., #define).
- Header files are included (e.g., #include).
- Conditional compilation is handled (e.g., #ifdef).

#### Example:
```bash
    gcc -E main.c -o main.i
```
### 2.The next phase is compiling, which translates the preprocessed C code into assembly language.

Tools: gcc -S or clang -S   
Input: .i (Preprocessed C files)    
Output: .s files (Assembly files)   
#### Actions:
- The .i file (preprocessed code) is compiled into assembly language.
- At this point, the code is still platform-dependent (specific to architecture).

#### Example:
```bash
    ggcc -S main.i -o main.s
```
### 3.The assembly phase converts assembly language code into machine code.

Tools: gcc -c or clang -c      
Input: .s files (Assembly files)        
Output: .o files (Object files)  
#### Actions:
- The assembly code is turned into machine code, which is specific to the target architecture (CPU type).
- The .o file is still platform-dependent but contains the machine-level instructions (not yet linked into a full program).
#### Example:
```bash
    gcc -c main.s -o main.o
```
### 4.Linking
The final phase is linking, where object files and libraries are combined into an executable program or shared library.

Tools: gcc or clang  
Input: .o files (Object files)    
#### Output:
- Executable: Typically .out, .exe, or no extension depending on the platform.
- Shared libraries: .so (Linux), .dll (Windows), .dylib (macOS).

#### Actions:
- The object files are linked together to form an executable.
- Libraries (both static and dynamic) can be linked at this stage.
#### Example:
```bash
    gcc main.o -o main.out
```
```bash
    gcc -shared -o libexample.so example.o
```
### 5.Final Output (Executable or Library)
- Executable files: The final linked output is an executable file (.out, .exe, or no extension, depending on the platform).
- Library files: If you’re building a shared library, the final output is a shared library (.so, .dll, .dylib).

## Main Memory Segments in C
In C programming, when a program is compiled and run, its memory is divided into several well-defined segments, each serving a specific purpose.    
Here’s a breakdown of the main memory segments in C:
### 1. Text Segment
- Stores compiled machine code (executable instructions).
- Read-only to prevent modification (helps catch bugs and security issues).
- Shared among processes running the same program (in modern OS).
### 2. Data Segment
- Stores global and static variables that are initialized.
- Allocated at compile time and exists throughout the program's execution.
### 3. BSS Segment
- BSS = Block Started by Symbol
- Holds global and static variables that are uninitialized (or zero-initialized).
- Memory is allocated, but initialized to zero at runtime.
### 4. Heap Segment
- Used for dynamically allocated memory (malloc(), calloc(), etc.).
- Grows upward (toward higher addresses).
- Managed by the programmer — memory must be manually freed.
### 5. Stack Segment
- Stores local variables, function parameters, and return addresses.
- Grows downward (toward lower addresses).
- Automatically managed — memory is freed when functions return.

## Tokens in C
A token is referred to as the smallest unit in the source code of a computer language such as C. The term token is borrowed from the theory of linguistics. Just as a certain piece of text in a language (like English) comprises words (collection of alphabets), digits, and punctuation symbols. A compiler breaks a C program into tokens and then proceeds ahead to the next stages used in the compilation process.

The first stage in the compilation process is a tokenizer. The tokenizer divides the source code into individual tokens, identifying the token type, and passing tokens one at a time to the next stage of the compiler.

The parser is the next stage in the compilation. It is capable of understanding the language's grammar. identifies syntax errors and translates an error-free program into the machine language.

A C source code also comprises tokens of different types. The tokens in C are of the following types −
- Character set
    - Uppercase: A to Z
    - Lowercase: a to z
    - Digits: 0 to 9
    - Special characters: ! " # $ % & ' ( ) * + - . : , ; ` ~ = < > { } [ ] ^ _ \ /
- Keyword tokens    
    auto, double, int, struct, break, else, long, switch, case, enum, register, typedef, char, extern, return, union, continue, for, signed, void, do, if, static, while, default, goto, sizeof, volatile, const, float, short, unsigned
- Literal tokens
    - In computer programming terminology, the term literal refers to a textual representation of a value to be assigned to a variable, directly hard-coded in the source code.
    - for example \(int x = 10;\) 10 is an integer literal assigned to "x".
- Identifier tokens
    - In contrast to the keywords, the identifiers are the user-defined elements in a program. You need to define various program elements by giving them an appropriate name. For example, variable, constant, label, user-defined type, function, etc.
- Operator tokens
    - C is a computational language. Hence a C program consists of expressions that perform arithmetic and comparison operations. The special symbols from the character set of C are mostly defined as operators. For example, the well-known symbols, +, −, * and / are the arithmetic operators in C. Similarly, < and > are used as comparison operators.
- Special symbol tokens
    - Apart from the symbols defined as operators, the other symbols include punctuation symbols like commas, semicolons, and colons. In C, you find them used differently in different contexts.

## Keywords:
### Primary Types C Keywords:
| Keyword | Description |
|----------|----------|
|int	|Declares an integer variable|
|long	|Declares a long integer variable|
|short	|Declares a short integer variable|
|signed	|Declares a signed variable|
|double	|Declares a double-precision variable|
|char	|Declares a character variable|
|float	|Declares a floating-point variable|
|unsigned|	Declares an unsigned variable|
|void	|Specifies a void return type|

### User-defined Types C Keywords
| Keyword | Description |
|----------|----------|
|struct	|Declares a structure type|
|typedef	|Creates a new data type|
|union	|Declares a union type|
|enum	|Declares an enumeration type|

### Storage Types C Keywords
| Keyword | Description |
|----------|----------|
|auto	|Specifies automatic storage class|
|extern	|Declares a variable or function|
|static	|Specifies static storage class|
|register	|Specifies register storage class|

### Conditionals C Keywords
| Keyword | Description |
|----------|----------|
|goto	|Jumps to a labeled statement|
|if	|Starts an if statement|
|else	|Executes when the if condition is false|
|case	|Labels a statement within a switch|
|switch	|Starts a switch statement|
|default	|Specifies default statement in switch|

### Loops and Loop Control C Keywords
| Keyword | Description |
|----------|----------|
|For	|Starts a for-loop|
|do	|Starts a do-while loop|
|while	|starts a while loop|
|continue	|Skips an iteration of a loop|
|break	|Terminates a loop or switch statement|

### C99 version, five more keywords were added −
- _Bool
- _Complex
- _Imaginary
- inline

### C11, seven more keywords have been added
- _Alignas
- _Alignof
- _Atomic
- _Generic
- _Noreturn
- _Static_assert

### C23 introduce 14 more keywords −
- alignas
- alignof
- bool
- constexpr
- false
- nullptr
- static_assert
- thread_local
- true
- typeof
- typeof_unqual
- _Decimal128

## Format Specifiers:
| Format Specifier | Type |
|----------|----------|
|%c	|Character|
|%d|	Signed integer|
|%f|	Float values|
|%i|	Unsigned integer|
|%l or %ld or %li|	Long|
|%lf	|Double|
|%Lf	|Long double|
|%lu	|Unsigned int or unsigned long|
|%lli or %lld|	Long long|
|%llu	|Unsigned long long|

## Data Types
### Basic Data Types
| Type	|Storage size|Value range
|----------|----------|----------|
|char	|1 byte	|-128 to 127 or 0 to 255|
|unsigned char	|1 byte|	0 to 255|
|signed char	|1 byte|	-128 to 127|
|int	|2 or 4 bytes|	-32,768 to 32,767 or -2,147,483,648 to 2,147,483,647|
|unsigned int	|2 or 4 bytes|	0 to 65,535 or 0 to 4,294,967,295|
|short	|2 bytes|	-32,768 to 32,767|
|unsigned short	|2 bytes|	0 to 65,535|
|long	|8 bytes|	-9223372036854775808 to 9223372036854775807|
|unsigned long|	8 bytes|	0 to 18446744073709551615|

### Floating-Point Data Types
|Type	|Storage size	|Value range|	Precision|
|----------|----------|----------|----------|
|float	|4 byte	|1.2E-38 to 3.4E+38	|6 decimal places
|double	|8 byte	|2.3E-308 to 1.7E+308	|15 decimal places
|long double	|10 byte	|3.4E-4932 to 1.1E+4932	|19 decimal places

## Integer Promotions
The C compiler promotes certain data types to a higher rank for the sake of achieving consistency in the arithmetic operations of integers.

In addition to the standard int data type, the C language lets you work with its subtypes such as char, short int, long int, etc. Each of these data types occupy a different amount of memory space. For example, the size of a standard int is 4 bytes, whereas a char type is 2 bytes of length. When an arithmetic operation involves integer data types of unequal length, the compiler employs the policy of integer promotion.   

As a general principle, the integer types smaller than int are promoted when an operation is performed on them. If all values of the original type can be represented as an int, the value of the smaller type is converted to an int; otherwise, it is converted to an unsigned int.

One must understand the concept of integer promotion to write reliable C code, and avoid unexpected problems related to the size of data types and arithmetic operations on smaller integer types.

### Example:
```c
    char a = 251;
    unsigned char b = a;
```
In the above example, "a" and "b" are treated as integers during comparison. "a" is a signed char converted to int as -5, while "b" is an unsigned char converted to int as 251.

## Operators:
### Arithmetic Operators:
|Operator|	Description|	Example|
|----------|----------|----------|
|+|	Adds two operands.	|A + B = 30|
|−|	Subtracts second operand from the first.	|A − B = -10|
|*|	Multiplies both operands.	|A * B = 200|
|/|	Divides numerator by de-numerator.	|B / A = 2|
|%|	Modulus Operator and remainder of after an integer division.	|B % A = 0|
|++|	Increment operator increases the integer value by one.	|A++ |
|--|	Decrement operator decreases the integer value by one.	|A-- |

### Relational Operators:
|Operator|	Description	|Example|
|----------|----------|----------|
|==|	Checks if the values of two operands are equal or not. If yes, then the condition becomes true.	|(A == B) is not true.|
|!=|	Checks if the values of two operands are equal or not. If the values are not equal, then the condition becomes true.	|(A != B) is true.|
|>	|Checks if the value of left operand is greater than the value of right operand. If yes, then the condition becomes true.	|(A > B) is not true.|
|<|	Checks if the value of left operand is less than the value of right operand. If yes, then the condition becomes true.	|(A < B) is true.|
|>=|	Checks if the value of left operand is greater than or equal to the value of right operand. If yes, then the condition becomes true.	|(A >= B) is not true.|
|<=|	Checks if the value of left operand is less than or equal to the value of right operand. If yes, then the condition becomes true.	|(A <= B) is true.|

### Logical Operators
|Operator|	Description	|Example|
|----------|----------|----------|
|&&|	Called Logical AND operator. If both the operands are non-zero, then the condition becomes true.	|(A && B) is false.|
|\|\||	Called Logical OR Operator. If any of the two operands is non-zero, then the condition becomes true.	|(A \|\| B) is true.|
|!|	Called Logical NOT Operator. It is used to reverse the logical state of its operand. If a condition is true, then Logical NOT operator will make it false. |!(A && B) is true.|

### Bitwise Operators:
|Operator|	Description|	Example|
|----------|----------|----------|
|&|	Binary AND Operator copies a bit to the result if it exists in both operands.	|(A & B) = 12, i.e., 0000 1100|
|\||	Binary OR Operator copies a bit if it exists in either operand.	|(A \| B) = 61, i.e., 0011 1101|
|^|	Binary XOR Operator copies the bit if it is set in one operand but not both.	|(A ^ B) = 49, i.e., 0011 0001|
|~|	Binary One's Complement Operator is unary and has the effect of 'flipping' bits.	|(~A ) = ~(60), i.e,. -0111101|
|<<|	Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand.	|A << 2 = 240 i.e., 1111 0000|
|>>|	Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand.	|A >> 2 = 15 i.e., 0000 1111|

### Assignment Operators:
|Operator|	Description|	Example|
|----------|----------|----------|
|=|	Simple assignment operator. Assigns values from right side operands to left side operand	|C = A + B will assign the value of A + B to C|
|+=|	Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand.	|C += A is equivalent to C = C + A|
|-=|	Subtract AND assignment operator. It subtracts the right operand from the left operand and assigns the result to the left operand.	|C -= A is equivalent to C = C - A|
|*=|	Multiply AND assignment operator. It multiplies the right operand with the left operand and assigns the result to the left operand.	|C *= A is equivalent to C = C * A|
|/=|	Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand.	|C /= A is equivalent to C = C / A|
|%=|	Modulus AND assignment operator. It takes modulus using two operands and assigns the result to the left operand.	|C %= A is equivalent to C = C % A|
|<<=|	Left shift AND assignment operator.	|C <<= 2 is same as C = C << 2|
|>>=|	Right shift AND assignment operator.	|C >>= 2 is same as C = C >> 2|
|&=|	Bitwise AND assignment operator.	|C &= 2 is same as C = C & 2|
|^=|	Bitwise exclusive OR and assignment operator.	|C ^= 2 is same as C = C ^ 2|
|\|=|	Bitwise inclusive OR and assignment operator.	|C \|= 2 is same as C = C \| 2|

### Misc Operators &map; sizeof & ternary:
|Operator|	Description|	Example|
|----------|----------|----------|
|sizeof()|	Returns the size of a variable.	|sizeof(a), where a is integer, will return 4.|
|&|	Returns the address of a variable.	|&a; returns the actual address of the variable.|
|*|	Pointer to a variable.	|*a;|
|? :|	Conditional Expression.|If Condition is true ? then value X : otherwise value Y|

### Operators Precedence in C:
|Category|	Operator|	Associativity|
|----------|----------|----------|
|Postfix|	() [] -> . ++ - -	|Left to right|
|Unary|	+ - ! ~ ++ - - (type)* & sizeof	|Right to left|
|Multiplicative|	* / %	|Left to right|
|Additive|	+ -	|Left to right|
|Shift|	<< >>	|Left to right|
|Relational|	< <= > >=	|Left to right|
|Equality|	== !=	|Left to right|
|Bitwise AND|	&	|Left to right|
|Bitwise XOR|	^	|Left to right|
|Bitwise OR|	\|	|Left to right|
|Logical AND|	&&	|Left to right|
|Logical OR|	\|\|	|Left to right|
|Conditional|	?:	|Right to left|
|Assignment|	= += -= *= /= %=>>= <<= &= ^= \|=	|Right to left|
|Comma|	,	|Left to right|

## 🔗 Truth Tables
You can view all logic gate truth tables [here](truth-table.md).

## Variadic Functions:
A function that can take a variable number of arguments is called a variadic function. One fixed argument is required to define a variadic function. The most frequently used library functions in C, i.e., printf() and scanf() are in fact the best-known examples of variadic functions, as we can put a variable number of arguments after the format specifier string. 
You need to include the stdarg.h header file at the top of the code to handle the variable arguments.

|Methods|Description|
|----------|----------|
|va_start(va_list ap, arg)	|Arguments after the last fixed argument are stored in the va_list.|
|va_arg(va_list ap, type)	|Each time, the next argument in the variable list va_list and coverts it to the given type, till it reaches the end of list.|
|va_copy(va_list dest, va_list src)	|This creates a copy of the arguments in va_list|
|va_end(va_list ap)	|This ends the traversal of the variadic function arguments. As the end of va_list is reached, the list object is cleaned up.|

## Pointers:
A pointer is a variable that stores the memory address of another variable. 
Think of it like a signpost — it doesn’t hold the value itself, but tells you where the value lives in memory.  
### Why Use Pointers?
- To access and modify variables indirectly
- For dynamic memory (like arrays, buffers)
- To pass large data to functions efficiently
- To handle hardware registers in embedded systems
- For function pointers, callbacks, etc.
|Term|	Meaning|
|----------|----------|
|&a|	Address of variable a|
|int* ptr|	Declares a pointer to an int|
|*ptr|	Dereference: access value at address|

### Double Pointer:
A pointer to pointer which is also known as a double pointer in C is used to store the address of another pointer.  
A variable in C that stores the address of another variable is known as a pointer. A pointer variable can store the address of any type including the primary data types, arrays, struct types, etc. Likewise, a pointer can store the address of another pointer too, in which case it is called "pointer to pointer" (also called "double pointer").
```
pointer         pointer        variable
+---------+    +---------+    +---------+
|         |    |         |    |         |
| Address |--->| Address |--->|  Value  |
|         |    |         |    |         |
+---------+    +---------+    +---------+
```

### Chain of Pointers:
A chain of pointers in C is a series of pointers that point to each other. A pointer variable can store the address of another variable which can be of any type, including another pointer, in which case it is called a pointer to pointer.   
A chain of pointers is when there are multiple levels of pointers. Theoretically, there is no limit to how many levels the chaining can be done.
```
variable a     pointer ptr1   pointer ptr2  pointer ptr3
+---------+    +---------+    +---------+    +---------+
|         |    |         |    |         |    |         |
| 1000    |<---|   &a    |<---|  &ptr1  |<---|  &ptr2  |
|         |    |         |    |         |    |         |
+---------+    +---------+    +---------+    +---------+
```
### Dagling Pointer:
Dangling pointers in C is used to describe the behavior of a pointer when its target (the variable it is pointing to) has been deallocated or is no longer accessible. In other words, a dangling pointer in C is a pointer that doesn't point to a valid variable of the appropriate type.
- can cause due to non properly free dynamic memory allocation.
- can cause if function can return a pointer and its not static address.
- access out of scope address.
### Wild Pointer:
A wild pointer in C is a pointer that has not been initialized to point to a known, valid memory address. It may point anywhere, and using it can lead to crashes, undefined behavior, or data corruption.

### Near Pointer:
The "near" keyword in C is used to declare a pointer that can only access memory within the current data segment. A near pointer on a 16-bit machine is a pointer that can store only 16-bit addresses. 
A near pointer can only access data of a small size of about 64 kb in a given period, which is its main disadvantage. The size of a near pointer is 2 bytes.
```c
    char near *ptr;
```
### Far Pointer:
A far pointer is a 32-bit pointer that can access information that is outside the computer memory in a given segment. To use this pointer, one must allocate the "sector register" to store data addresses in the segment and also another sector register must be stored within the most recent sector.    
A far pointer stores both the offset and segment addresses to which the pointer is differencing. When the pointer is incremented or decremented, only the offset part is changing. The size of the far pointer is 4 bytes.
```c
    char far *s;
```

### Huge Pointer:
A huge pointer has the same size of 32-bit as that of a far pointer. A huge pointer can also access bits that are located outside the sector.

A far pointer is fixed and hence that part of the sector in which they are located cannot be modified in any way; however huge pointers can be modified.    
In a huge pointer, both the offset and segment address is changed. That is why we can jump from one segment to another using a huge pointer. As they compare the absolute addresses, you can perform the relational operation on it. The size of a huge pointer is 4 bytes.
```c
    int huge* ptr;
```

## Strcut Vs Unions:
|Feature|	struct|	union|
|----------|----------|----------|
|Memory	|Allocates separate memory for each member|	All members share the same memory|
|Size|	Sum of sizes of all members (plus padding)|	Size of the largest member|
|Access|	Can access all members at once|	Can access only one member at a time|
|Usage|	Used when you need all values together|	Used when you need only one value at a time|
|Example|	struct SensorData { int temp; int humidity; }|	union Value { int i; float f; char c; }|

### Struct use:
- Device register groupings (GPIO config, etc.)
- Grouping related data (like sensor readings)
- Easier to reason about multiple fields

### Union use:
- Memory optimization (e.g., packets, buffers)
- Type interpretation (e.g., raw data as float/int)
- Shared memory views in embedded

## Dynamic Memory allocation:
|Function|	Description|
|----------|----------|
|void *calloc(int num, int size);|	This function allocates an array of num elements each of which size in bytes will be size.|
|void free(void *address);|	This function releases a block of memory block specified by address.|
|void *malloc(size_t size);|	This function allocates an array of num bytes and leave them uninitialized.|
|void *realloc(void *address, int newsize);|	This function re-allocates memory extending it up to newsize.|

### Malloc:
This function is defined in the stdlib.h header file. It allocates a block memory of the required size and returns a void pointer.
- Purpose: Allocates a block of memory of a specified size.
- Initial Value: Memory is uninitialized (contains garbage values).
```c
    int *ptr;
    ptr = (int *) malloc (sizeof (int));
```
### Calloc:
The calloc() function (stands for contiguous allocation) allocates the requested memory and returns a pointer to it.
- Purpose: Allocates memory for an array of elements and initializes all bytes to 0.
```c
    int *ptr;
    ptr = (int *) calloc(n, sizeof(int));
```
Here, "n" is the number of elements to be allocated and "size" is the byte-size of each element.
### Realloc:
The realloc() (re-allocation) function in C is used to dynamically change the memory allocation of a previously allocated memory. You can increase or decrease the size of an allocated memory block by calling the realloc() function.
- Purpose: Changes the size of a previously allocated memory block.
```c
    void *realloc(*ptr, size);
```
### free:
The free() function in C is used to dynamically de-allocate the memory allocated using functions such as malloc() and calloc(), since it is not freed on their own.
```c
    void free(void *ptr);
```