#include <stdio.h>
int stk[10],i,top=-1,ele,n,choice;

void pop(){
    if(top<0){
        printf("\nStack Underflow(No active alerts)\n");
    }
    else{
        ele=stk[top];
        top--;
        printf("\nPopped Alert Element: %d\n",ele);
    }
}

void push(){
    if(top>=n-1){
        printf("\nStack Overflow\n");
    }
    else{
        printf("\nEnter the temperature to be pushed: ");
        scanf("%d", &ele);
        if (ele >= 45) {
            printf(">>> ALERT: Red Alert! Extreme Heatwave <<<\n");
        }
        else if (ele >= 43) {
            printf(">>> ALERT: Orange Alert! Severe Heatwave <<<\n");
        }
        else if (ele >= 40) {
            printf(">>> ALERT: Yellow Alert! Heatwave Warning <<<\n");
        }
        else {
            printf("\nTemperature is normal (< 40 deg). Clearing all active alerts...\n");
            while (top >= 0) {
                pop();
            }
            return;
        }
        top++;
        stk[top]= ele;
    }
}

void peek(){
    if(top<0){
        printf("\nStack is Empty (No active alerts)\n");
    }
    else{
        ele= stk[top];
        printf("\nTop Alert Element: %d\n",ele);
    }
}
void display(){
    if(top<0){
        printf("\nStack is Empty (No active alerts)\n");
    }
    else{
        printf("\nACTIVE ALERTS STACK:");
        for(i=top;i>=0;i--){
            printf("\n %d", stk[i]);
        }
    }
}

void main(){
    printf("\nEnter the size of stack:");
    scanf("%d", &n);
    do
    {
        printf("\n---- HEATWAVE MONITOR MENU ----\n 1.Push Temperature \n 2.Pop Alert \n 3.Peek Latest Alert \n 4.Display All Alerts \n 5.EXIT");
        printf("\nChoose operation to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 :
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\nExited Successfully!!!\n");
            break;
        default:
            printf("\nInvalid Input!\nEnter betweem 1 to 5\n");
            break;
        }
    } while (choice !=5);
    
}




