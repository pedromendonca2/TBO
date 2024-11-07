#include "pilha.h"

void printInt(void* element){
    printf(" %d", *(int*)element);
}

void printChar(void* element){
    printf(" %c", *(char*)element);
}

void makeOperation(tStack* s1, tStack* s2){
    char* operatorPtr = (char*)pop(s2);
    char operator = *operatorPtr;
    free(operatorPtr);

    int* n1Ptr = (int*)pop(s1);
    int* n2Ptr = (int*)pop(s1);
    int n1 = *n1Ptr;
    int n2 = *n2Ptr;
    free(n1Ptr);
    free(n2Ptr);

    int result;

    switch(operator){
        case '+':
        result = n2 + n1;
        break;
        case '-':
        result = n2 - n1;
        break;
        case '/':
        result = n2 / n1;
        break;
        case '*':
        result = n2 * n1;
        break;
        default:
        printf("Esse sinal não existe\n");
        break;
    }

    printf(" Result: %d\n", result);

    int* op = malloc(sizeof(int));
    *op = result;
    push(s1, op);
}

int main(){

    int i=0;
    char c, expression[50];

    while ((c = getchar()) != '\n' && c != EOF) {
        expression[i++] = c;
    }

    expression[i] = '\0';
    i = 0;

    tStack* stack_1 = malloc(sizeof(tStack));
    tStack* stack_2 = malloc(sizeof(tStack));

    initStack(stack_1);
    initStack(stack_2);

    while(expression[i] != '\0'){ 
        if(expression[i] == ')'){
            makeOperation(stack_1, stack_2);
        } else if(expression[i] >= '0' && expression[i] <= '9'){
            int* num = malloc(sizeof(int));
            *num = expression[i] - '0';  // Converte caractere numérico para inteiro
            push(stack_1, num);
            display(stack_1, printInt);
        } else if(expression[i] == '(' || expression[i] == ' '){
            i++;
            continue;
        } else{
            char* op = malloc(sizeof(char));
            *op = expression[i];
            push(stack_2, op);
        }

        i++;
    }

    printf("FINAL:\n");
    display(stack_1, printInt);

    liberaArray(stack_1);
    liberaArray(stack_2);

    return 0;
}