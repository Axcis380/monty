#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int stack_size = 0;

/* Fnction to puh element onto stak */
void push(int value) {
    if (stack_size < STACK_SIZE) {
        stack[stack_size++] = value;
    } else {
        fprintf(stderr, "Error: Stack overflow\n");
        exit(EXIT_FAILURE);
    }
}

void pall() {
    for (int i = stack_size - 1; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char line[100];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        char *token = strtok(line, " \t\n");

        if (token == NULL) {
            continue;
        }

        if (strcmp(token, "push") == 0) {
            /* Parse n push  intgr onto stak */
            token = strtok(NULL, " \t\n");
            if (token == NULL) {
                fprintf(stderr, "Error: L%d: usage: push integer\n", line_number);
                return EXIT_FAILURE;
            }
            int value = atoi(token);
            push(value);
        } else if (strcmp(token, "pall") == 0) {
            /* Print elements on stack */
            pall();
        } else {
            fprintf(stderr, "Error: L%d: Unknown opcode: %s\n", line_number, token);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
