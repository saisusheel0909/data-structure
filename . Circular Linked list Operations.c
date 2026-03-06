#include <stdio.h>

NODE newnode = createNodeInCLL(x);
NODE temp = first;
int i;

if(pos == 1) {

    if(first == NULL) {
        newnode->next = newnode;
        return newnode;
    }

    while(temp->next != first)
        temp = temp->next;

    newnode->next = first;
    temp->next = newnode;
    first = newnode;

    return first;
}

for(i = 1; i < pos-1; i++) {
    temp = temp->next;

    if(temp == first) {
        printf("Position not found\n");
        return first;
    }
}

newnode->next = temp->next;
temp->next = newnode;

return first;

	
}

// Delete node at given position in CLL
NODE deleteAtPositionInCLL( NODE first, int pos ) {


NODE temp = first, prev;
int i;

if(pos == 1) {

    while(temp->next != first)
        temp = temp->next;

    NODE del = first;
    printf("Deleted element: %d\n", del->data);

    if(first->next == first)
        return NULL;

    first = first->next;
    temp->next = first;

    free(del);
    return first;
}

for(i = 1; i < pos; i++) {
    prev = temp;
    temp = temp->next;

    if(temp == first) {
        printf("Position not found\n");
        return first;
    }
}

prev->next = temp->next;
printf("Deleted element: %d\n", temp->data);
free(temp);

return first;


	
	
}

// Reverse CLL
NODE reverseCLL(NODE first ) {
	
//write your code here...


NODE prev = NULL, curr = first, next;

if(first == NULL)
    return NULL;

do {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
} while(curr != first);

first->next = prev;
first = prev;

return first;



}

// Concatenate two CLLs
NODE concatCLL( NODE first, NODE second) {




if(first == NULL) return second;
if(second == NULL) return first;

NODE temp1 = first;
NODE temp2 = second;

while(temp1->next != first)
    temp1 = temp1->next;

while(temp2->next != second)
    temp2 = temp2->next;

temp1->next = second;
temp2->next = first;

return first;




}

int main() {
    NODE first = NULL, second = NULL;
    int x, pos, op, n;

    while (1) {
        printf("1.Create 2.Insert 3.Delete 4.Display 5.Reverse 6.Concat 7.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                first = createCLL(n);
                break;
            case 2:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 5:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                    traverseListInCLL(first);   // <-- display reversed list
                }
                break;
            case 6:
                printf("Creating second CLL to concatenate...\n");
                printf("How many nodes in second CLL? ");
                scanf("%d", &n);
                second = createCLL(n);
                first = concatCLL(first, second);
                printf("Concatenated CLL:\n");
                traverseListInCLL(first);
                break;
            case 7:
                exit(0);
        }
    }
}
