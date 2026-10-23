#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
char stk[MAX], top=-1;

void push(char ele, char stk[]){
    top++;
    stk[top]= ele;
}

char pop(char stk[]){
    char ele= stk[top];
    top--;
    return ele;
}

int Priority(char op){
    if(op=='/' || op == '*' || op=='%')
    return 1;
    else if(op=='+' || op=='-')
    return 0;
}

void InfixtoPostfix(char source[], char destination[]){
    int i=0, j=0;
    char  bin;
    strcpy(destination,"");
    while(source[i]!='\0'){
        if(source[i]=='('){
            push(source[i], stk);
            i++;
        }
        else if(source[i]==')'){
            while((top!=-1) && (stk[top]!= '(')){
                destination[j]= pop(stk);
                j++;
            }
            if(top==-1){
                printf("\nIncorrect Expression.");
                exit(1);
            }
            bin = pop(stk);
            i++;
        }
        else if(isalpha(source[i]) || isdigit(source[i])){
            destination[j] = source[i];
            i++;
            j++;
        }
        else if((source[i]=='/') || (source[i]=='%') || (source[i]=='*') || (source[i]=='+') || (source[i]=='-')){
            while((top!=-1) && (stk[top]!='(') && (Priority(stk[top]) >= Priority(source[i]))){
                destination[j]= pop(stk);
                j++;
            }
            push(source[i],stk);
            i++;
        }
        else{
            printf("\nIncorrect Expression!!");
            exit(1);
        }
    }
    while((top!=-1) && (stk[top]!='(')){
        destination[j]= pop(stk);
        j++;
    }
    destination[j]='\0';
}

void main(){
    char infix[50], postfix[50];
    printf("\nEnter the infix expression: ");
    gets(infix);
    strcpy(postfix,"");
    InfixtoPostfix(infix, postfix);
    printf("\n The equivalent postfix expression is : %s \n", postfix);
}


