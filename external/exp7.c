#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int top=-1;
int stack[100];

int isEmpty(){
    return top==-1;
}

int is_operator(char c){
    return(c=='-'||c=='+'|| c=='/' || c=='*' || c=='^');
}

char push(char c){
    stack[++top]=c;
}

char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int precedence(char op){
    switch (op) {
        case '^' : return 3 ; 
        case '*' : case '/': return 2;
        case '+' : case '-': return 1;
        default: return 0;
    }
}

void infix_postfix(char infix[], char postfix[]){
    int i,k=0;
    char c;

    for(i=0;infix[i]!='\0';i++){
        c=infix[i];

        if(isalnum(c)){
            postfix[k++]=c;
        }
        else if(c=='('){
            push(c);
        }
        else if(c==')'){
            while(!isEmpty() && peek()!='('){
                postfix[k++]=pop();
            }
            pop();
        }else if (is_operator(c)) {
            while(!isEmpty() && precedence(peek())>=precedence(c)){
                postfix[k++]=pop();
            }
            push(c);
        }
    }

        while(!isEmpty()){
            postfix[k++]=pop();

        }
        postfix[k]='\0';
}

int main() {
    char infix[20], postfix[20];
    printf("Enter infix expression (single-digit operands): ");
    scanf("%s", infix);

    infix_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

}