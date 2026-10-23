#include <stdio.h>
#include <stdlib.h>

struct Node {
    int temperature;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtStart(int temp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->temperature = temp;
    newNode->next = head;
    head = newNode;

    printf("Inserted temperature: %dC\n", temp);

    if (temp >= 45.0){
        printf(" ALERT: Severe Heatwave Warning! Temperature %dC is dangerously high.\n", temp);
    }    
    else if (temp >= 40.0){
        printf(" WARNING: Heatwave conditions detected (%dC).\n", temp);
    }
}

void deleteAtStart() {
    if (head == NULL) {
        printf("List is empty. No temperature reading to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("Deleted temperature reading: %dC\n", temp->temperature);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("No temperature observations recorded.\n");
        return;
    }
    struct Node *current = head;
    int count = 1;
    printf("\n--- Temperature Observations (most recent first) ---\n");
    while (current != NULL) {
        printf("%d. %dC", count, current->temperature);
        if (current->temperature >= 45.0)
            printf(" [SEVERE HEATWAVE]");
        else if (current->temperature >= 40.0)
            printf(" [HEATWAVE WARNING]");
        printf("\n");
        current = current->next;
        count++;
    }
    printf("-----------------------------------------------------\n");
}

void freeList() {
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;
    int temp;

    do {
        printf("\n===== Heatwave Monitoring & Early Warning System =====\n");
        printf("1. Insert new temperature reading (at start)\n");
        printf("2. Delete temperature reading (at start)\n");
        printf("3. Display all temperature observations\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature reading (C): ");
                scanf("%d", &temp);
                insertAtStart(temp);
                break;
            case 2:
                deleteAtStart();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExited Successfully!!!\n");
                freeList();
                break;
            default:
                printf("\nInvalid Input!\nEnter betweem 1 to 4\n");
                break;
        }
    }while(choice!=4);
    return 0;
}