#include <stdio.h>
#include "char_stack.h"
#include "double_stack.h"

int main() {
    c_Stack *ops = c_stack_create();
    d_Stack *vals = d_stack_create();

    while (1) {
        int c;
        // Ignore white space.
        while ((c = getchar()) == ' ');
        if (c == EOF) break;

        // Read char, push if operator.
        if (c == '(' || c == '\n') {
            continue;
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            c_stack_push(ops, c);
        } else if (c == ')') {
            // Pop, evaluate and push result.
            char op = c_stack_pop(ops);
            double r = d_stack_pop(vals);
            double l = d_stack_pop(vals);
            switch(op) {
                case '+': d_stack_push(vals, l + r); break;
                case '-': d_stack_push(vals, l - r); break;
                case '*': d_stack_push(vals, l * r); break;
                case '/': d_stack_push(vals, l / r); break;
            }
        } else {
            // Char is not operator or parenthesis: push double value.
            ungetc(c, stdin);
            double d;
            scanf("%lf", &d);
            d_stack_push(vals, d);
        }
    }

    printf("Result: %.2lf\n", d_stack_pop(vals));

    c_stack_destroy(ops);
    d_stack_destroy(vals);
}
