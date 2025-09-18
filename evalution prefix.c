

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
typedef struct {
    int data[MAX];
    int top;
} Stack;
void push(Stack *stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
    return stack->data[stack->top--];
}
int evaluatePrefix(char* expr) {
    Stack stack;
    stack.top = -1;

    int length = strlen(expr);
    for (int i = length - 1; i >= 0; i--) {
        if (isspace(expr[i])) continue;

        if (isdigit(expr[i])) {
            push(&stack, expr[i] - '0');
        } else {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);

            switch (expr[i]) {
                case '+': push(&stack, operand1 + operand2); break;
                case '-': push(&stack, operand1 - operand2); break;
                case '*': push(&stack, operand1 * operand2); break;
                case '/': push(&stack, operand1 / operand2); break;
            }
        }
    }

    return pop(&stack);
}

int main() {
    char expr[] = "-+7*45+20";
    printf("Result: %d\n", evaluatePrefix(expr));
    return 0;
}

