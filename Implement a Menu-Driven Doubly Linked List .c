#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


struct Node* head = NULL;


void display() {
if (head == NULL) {
    printf("List is empty\n");
    return;
}

struct Node* temp = head;

while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}

printf("\n");

   
}


void insert(int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = num;
newNode->next = NULL;
newNode->prev = NULL;

if (head == NULL) {
    head = newNode;
}
else {
    struct Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

printf("Inserted successfully\n");
    
}


void deleteNumber(int num) {
    if (head == NULL) {
    printf("List is empty\n");
    return;
}

struct Node* temp = head;

while (temp != NULL && temp->data != num)
    temp = temp->next;

if (temp == NULL) {
    printf("Number %d not found\n", num);
    return;
}

if (temp->prev == NULL)
    head = temp->next;
else
    temp->prev->next = temp->next;

if (temp->next != NULL)
    temp->next->prev = temp->prev;

free(temp);

printf("List after deletion: ");
display();
    
    
}


void reverseList() {
if (head == NULL) {
    printf("List is empty\n");
    return;
}

struct Node *temp = NULL;
struct Node *current = head;

while (current != NULL) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
}

if (temp != NULL)
    head = temp->prev;

display();

}


void concatenate() {
int n, val;
scanf("%d", &n);

if (n == 0) {
    printf("Second list is empty\n");
    return;
}

struct Node* temp = head;

if (temp != NULL)
    while (temp->next != NULL)
        temp = temp->next;

for (int i = 0; i < n; i++) {
    scanf("%d", &val);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
        temp = head;
    } else {
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }
}

display();
	
}

int main() {
    int choice, num;

    while (1) {
        printf("Enter operation\n1: Insert\n2: Delete\n3: Display\n4: Reverse\n5: Concatenate\n6: Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &num);
                insert(num);
                break;

            case 2:
                scanf("%d", &num);
                deleteNumber(num);
                break;

            case 3:
                display();
                break;

            case 4:
                reverseList();
                break;

            case 5:
                concatenate();
                break;

            case 6:
                printf("Exit\n");
