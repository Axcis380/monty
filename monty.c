#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

Stack stack;

// Initialize the stack
void initStack() {
    stack.top = -1;
}

// Push an element onto the stack
void push(int value) {
    if (stack.top < STACK_SIZE - 1) {
        stack.top++;
        stack.stack[stack.top] = value;
    } else {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

// Pop an element from the stack (not needed for pall)
int pop() {
    if (stack.top >= 0) {
        return stack.stack[stack.top--];
    } else {
        fprintf(stderr, "Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
}

// Print all values on the stack
void pall() {
    int i;
    for (i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.stack[i]);
    }
}

int main() {
    initStack();

    // Read and execute instructions from a file (or any other source)
    FILE* file = fopen("bytecodes/00.m", "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open bytecode file\n");
        return EXIT_FAILURE;
    }

    char opcode[10]; // Assuming opcode names are less than 10 characters
    int arg;

    while (fscanf(file, "%s %d", opcode, &arg) != EOF) {
        if (strcmp(opcode, "push") == 0) {
            push(arg);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "Error: Unknown opcode %s\n", opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
