# COMPILER-DESIGN-BASICS

COMPANY = CODTECH IT SOLUTIONS

NAME = SAYALI PADMANE

INTERN ID = CT04WR115

DOMAIN = C PROGRAMMING

DURATION = 4 WEEKS

MENTOR = NEELA SANTOSH

DESCRIPTION:
This C program is a simple lexical analyzer, which reads a source code file and breaks it down into meaningful elements called tokens. It identifies keywords, operators, and identifiers—the essential building blocks of a programming language. This process is the first step in a compiler’s job and is called lexical analysis.
When you run the program, it asks for the name of the file to analyze (e.g., input.c). It opens the file, reads it character by character, and tries to categorize each part of the code
There are three main parts the program looks for:
Keywords – These are reserved words in the C language like int, float, if, return, etc. The program checks words against a list of known keywords and prints them out when matched.
Operators – These are symbols like +, -, =, <, > that perform actions in code. Whenever the program reads one of these symbols, it identifies and prints it as an operator.
Identifiers – Anything that is not a keyword but made up of letters or numbers is assumed to be an identifier. These are usually variable names or function names (like a, b, main, etc.).
The logic works by collecting characters into a buffer. If it finds a space, newline, or any special character, it stops collecting and checks whether the word in the buffer is a keyword or an identifier. For operators, it checks and prints them immediately.

For example, in this line of code:
int a = 10;
int is recognized as a keyword
a is recognized as an identifier
= is an operator
10 is treated as an identifier (since the program doesn't currently distinguish numbers)
Although the program is basic, it's a great starting point for understanding how a real compiler reads source code. With a few improvements, it could be extended to:
Recognize numbers and constants separately
Handle multi-character operators (==, >=, etc.)
Detect comments and string literals
Support more keywords or languages
This small but functional lexical analyzer introduces students to the foundational concepts of compiler design. It’s also a great C programming exercise involving file I/O, string handling, and character analysis.

OUTPUT:
![Image](https://github.com/user-attachments/assets/a4ba59fc-37ff-43a2-944b-f5826736e3fa)
