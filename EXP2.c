#include<stdio.h>
int q[50],i,n,choice,f=-1,r=-1,ele;

void dqueue(){
    if(f==-1){
        printf("\nQueue Underflow!!!(No active alerts)");
    }
    else{
        ele= q[f];
        printf("\nTemperature deleted: %d", ele);
        if(f==r){
            f=-1;
            r=-1;
        }
        else{
            f++;
        }
    }
}

void enqueue(){
    if (r>=n-1){
        printf("\nQueue Overflow!!!");
    }
    else{
        printf("\nEnter the temperature to be inserted: ");
        scanf("%d",&ele);
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
            while (f != -1) {
                dqueue();
            }
            printf("\nAll active alerts cleared successfully.\n");
            return;
        }
        r++;
        q[r]=ele;
        if(f==-1){
            f++;
        }
    }
}

void display(){
    if(f==-1){
        printf("\nQueue Underflow!!!(No active alerts)");
    }
    else{
        printf("\nACTIVE ALERTS QUEUE:");
        for(i=f; i<=r; i++){
            printf("\n %d", q[i]);
        }
    }
}

void main(){
    printf("\nEnter the size of Queue: ");
    scanf("%d", &n);
    do
    {
        printf("\n---- HEATWAVE MONITOR MENU ----\n 1.Insert Temperature \n 2.Delete temperature \n 3.Display All Alerts \n 4.EXIT");
        printf("\nChoose operation to perform: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1 :
            enqueue();
            break;
        case 2:
            dqueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nExited Successfully!!!\n");
            break;    
        default:
            printf("\nInvalid Input!\nEnter betweem 1 to 4\n");
            break;
        }
    } while (choice != 4);
    
}