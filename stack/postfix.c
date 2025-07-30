#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 20

//https://github.com/Nivedck

int stack[MAX_SIZE];
int top=-1;

void push(int val){
    if(top==MAX_SIZE-1){
        printf("Stack Underflow");
        return;
    }
    top++;
    stack[top]=val;
}

int pop(){
    if(top==-1){
        printf("Stack Underflow");
        return -1;
    }
    top--;

    return stack[top+1];
}

int solve_postfix(char* expr){
    int i=0;

    while(expr[i]!= '\0'){
        
        char ch=expr[i];

        if(isdigit(ch)){
            push(ch - '0');
        }
        else{
            int b= pop();
            int a= pop();
            int result;

            switch(ch){
                case '+':
                    result = a+b;
                    break;
                case '-':
                    result = a-b;
                    break;
                case '*':
                    result = a*b;
                    break;
                case '/':
                    result = a/b;
                default:
                    printf("Invalid Operator %c !",ch);
                    return -1;
            }

            push(result);
        }
        
        i++;
    }

    return pop();
}

int main(){

    //Hardcoded values , change values  or implement reading functions if you have time :( 
    char expr[]="15+";
    int result=solve_postfix(expr);
    printf("Result : %d " ,result);
    
    return 0;
}
