#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 100
#define MAX_KEYWORDS 10
#define MAX_OPERATORS 10

// List of keywords
const char *keywords[MAX_KEYWORDS] = {
    "int", "float", "if", "else", "for", "while", "return", "break", "continue", "void"
};

// List of operators
const char *operators[MAX_OPERATORS] = {
    "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="
};

// Function to check if a token is a keyword
int isKeyword(const char *token) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1; // Found as a keyword
        }
    }
    return 0; // Not a keyword
}

// Function to check if a token is an operator
int isOperator(const char *token) {
    for (int i = 0; i < MAX_OPERATORS; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return 1; // Found as an operator
        }
    }
    return 0; // Not an operator
}

// Function to perform lexical analysis
void lexicalAnalysis(FILE *file) {
    char token[MAX_TOKEN_LENGTH];
    int index = 0;
    char ch;

    printf("Lexical Analysis Results:\n");
    printf("-------------------------\n");
    while ((ch = fgetc(file)) != EOF) {
        // Ignore whitespace
        if (isspace(ch)) {
            // If we reached the end of a token, process it
            if (index > 0) {
                token[index] = '\0'; // Terminate the string
                if (isKeyword(token)) {
                    printf("Keyword: %s\n", token);
                } else if (isOperator(token)) {
                    printf("Operator: %s\n", token);
                } else {
                    printf("Identifier: %s\n", token);
                }
                index = 0; // Reset index for next token
            }
            continue;
        }

        // Handle multi-character operators
        if (ch == '=' || ch == '!' || ch == '<' || ch == '>') {
            if ((ch_next = fgetc(file)) != EOF) {
                if (ch_next == '=') {
                    token[index++] = ch; // Add the first character
                    token[index++] = ch_next; // Add the second character
                } else {
                    ungetc(ch_next, file); // Return the character
                    token[index++] = ch; // Add the single character
                }
            }
        } else if (strchr("+-*/", ch)) { // Single character operators
            token[index++] = ch; 
        } else if (isalnum(ch) || ch == '_') { // Identifiers
            token[index++] = ch; 
        }
    }

    // Don't forget to add the last token if it exists
    if (index > 0) {
        token[index] = '\0';
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isOperator(token)) {
            printf("Operator: %s\n", token);
        } else {
            printf("Identifier: %s\n", token);
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the name of the input file (with .c extension): ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 1;
    }

    lexicalAnalysis(file);

    fclose(file);
    return 0;
}
