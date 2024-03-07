#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    double data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, double num) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }
    s->data[++s->top] = num;
}

double pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return s->data[s->top--];
}

double peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return s->data[s->top];
}

double operate(char op, double a, double b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                printf("Division by zero.\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Invalid operator.\n");
            exit(1);
    }
}

int main() {
    Stack s;
    initialize(&s);
    char str[100];
    printf("Enter a postfix expression: ");
    scanf("%s", str);
    int i, len = strlen(str);
    double a, b, res;
    for (i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            push(&s, str[i] - '0');
        } else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            a = pop(&s);
            b = pop(&s);
            res = operate(str[i], b, a);
            push(&s, res);
        }
    }
    printf("Result: %.2f\n", peek(&s));
    return 0;
}
