#include <stdio.h>
#define MAX 20
int deque[MAX];
int left = -1, right = -1;

void input_deque();
void output_deque();
void insert_left();
void insert_right();
void delete_left();
void delete_right();
void display();

void main(){
	int choice;
    do{
	printf("\n ----- MAIN MENU -----");
	printf("\n 1.Input restricted deque \n 2.Output restricted deque \n 3.Exit ");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		    input_deque();
		    break;
		case 2:
		    output_deque();
		    break;
        case 3:
            printf("\nExited Successfully!!!\n");
            break;
        default:
            printf("\nInvalid Input!!!");
            break;
		}
    }while(choice!=3);    
}

void input_deque(){
	int choice;
	do{
	printf("\n ****  INPUT RESTRICTED DEQUE **** ");
	printf("\n 1.Insert at right \n 2.Delete from left \n 3.Delete from right \n 4.Display \n 5.Quit");
	printf("\n Enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		    insert_right();
		    break;
		case 2:
		    delete_left();
		    break;
		case 3:
		    delete_right();
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
	}while(choice!=5);
}

void output_deque(){
	int choice;
	do{
	printf("\n **** OUTPUT RESTRICTED DEQUE **** ");
	printf("\n 1.Insert at right \n 2.Insert at left \n 3.Delete from left \n 4.Display \n 5.Quit");
	printf("\n Enter your choice : ");
	scanf("%d",&choice);
	switch(choice){
	    case 1:
	        insert_right();
	        break;
	    case 2:
	        insert_left();
	        break;
	    case 3:
	        delete_left();
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
	}while(choice!=5);
}
	
void insert_right(){
	int ele;
	printf("\n Enter the element to be added:");
	scanf("%d", &ele);
	if((left == 0 && right == MAX-1) || (left == right+1)){
	    printf("\n OVERFLOW \n");
	}
    else{
	    if (left == -1){
	        left = 0;
	        right = 0;
	    }
	    else{
	        if(right == MAX-1) 
	        right = 0;
	        else
	        right++;
	    }
	    deque[right] = ele ;
    }
}

void insert_left(){
	int ele;
	printf("\n Enter the element to be added:");
	scanf("%d", &ele);
	if((left == 0 && right == MAX-1) || (left == right+1)){
	    printf("\n Overflow \n");
	}
    else{
	    if (left == -1){
	        left = 0;
	        right = 0;
	    }
	    else{
	        if(left == 0)
	        left=MAX-1;
	        else
	        left--;
	    }
	    deque[left] = ele;
    }
}

void delete_left(){
	if (left == -1){
	    printf("\n UNDERFLOW \n");
	}
	else{
        printf("\n The deleted element is : %d", deque[left]);
	    if(left == right){
	        left = -1;
	        right = -1;
	    }
	    else{
	        if(left == MAX-1)
	        left = 0;
	        else
	        left++;
	    }
    }
}

void delete_right(){
	if (left == -1)
	{
	    printf("\n UNDERFLOW \n");
	}
	else{
        printf("\n The element deleted is : %d", deque[right]);
	    if(left == right){
	        left = -1;
	        right = -1;
	    }
	    else{
	        if(right == 0)
	        right=MAX-1;
	        else
	        right--;
	    }
    }
}

void display(){
    int front = left, rear = right;
	if(front == -1){
	    printf("\n QUEUE IS EMPTY \n");
	}
	else{
        printf("\n The elements of the queue are : ");
	    if(front <= rear ){
	        while(front <= rear){
	            printf("%d\t",deque[front]);
	            front++;
	        }
	    }

	    else{
	        while(front <= MAX-1){
	            printf("%d\t", deque[front]);
	            front++;
	        }
	        front = 0;
	        while(front <= rear){
	            printf("%d\t",deque[front]);
	            front++;
	        }
	    }
	    printf("\n");
    }
}