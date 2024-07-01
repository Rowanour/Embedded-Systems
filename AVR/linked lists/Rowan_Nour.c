#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum error {
    OK,
    NotOK
} Error_t;

typedef struct node {
    int Data;
    struct node* Link;
} Node_t;

Error_t Initialize_List(Node_t** headArg);
Error_t Add_ElementAtStart(Node_t** headArg, int data);
Error_t Add_ElementAtEnd(Node_t** headArg, int data);
Error_t Delete(Node_t** headArg, int data);
Error_t Print_List(Node_t* headArg);
void Quit(Node_t* headArg);

int valid() {
    int x;
    while (true) 
    {
        //I looked it up and found out that scanf gives 1 if an integer is passed to it
        if (scanf("%d", &x) != 1 || x > 2147483647) {
            printf("invalid input try again\n");
        //I also looked this up, the getchar() cleans the buffer so the output doesn't go into an infinite loop    
            while ((getchar()) != '\n');
        } else {
            return x;
        }
    }
}

int main() {
    Node_t* head = NULL;
    int y, data;

    Initialize_List(&head);

    while (1) {
        printf("1- add element at the start \n");
        printf("2- add element at the end \n");
        printf("3- delete element \n");
        printf("4- print \n");
        printf("5- quit\n");
        printf("enter a number ");
        y = valid();

        if (y == 1) {
            data = valid();
            Add_ElementAtStart(&head, data);
        } else if (y == 2) {
            data = valid();
            Add_ElementAtEnd(&head, data);
        } else if (y == 3) {
            data = valid();
            Delete(&head, data);
        } else if (y == 4) {
            Print_List(head);
        } else if (y == 5) {
            Quit(head);
            return 0;
        } else if (y > 2147483647) {
            printf("invalid output!\n");
        } else {
            printf("invalid output!\n");
        }
    }

    return 0;
}

Error_t Initialize_List(Node_t** headArg) {
    if (headArg == NULL) {
        return NotOK;
    } else {
        *headArg = NULL;
        return OK;
    }
}

Error_t Add_ElementAtStart(Node_t** headArg, int data) {
    if (headArg == NULL) {
        return NotOK;
    } else {
        if (data >= 2147483647) {
            printf("Invalid value!\n");
            return NotOK;
        } else {
        Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
        if (temp == NULL) {
            return NotOK;
        } else {
            temp->Data = data;
            temp->Link = *headArg;
            *headArg = temp;
            return OK;
        }
    }
}
}
Error_t Print_List(Node_t* headArg) {
    if (headArg == NULL) {
        printf("List is empty.\n");
        return NotOK;
    } else {
        while (headArg != NULL) {
            printf("%d ", headArg->Data);
            headArg = headArg->Link;
        }
        printf("\n");
        return OK;
    }
}

Error_t Add_ElementAtEnd(Node_t** headArg, int data) {
    if (headArg == NULL) {
        return NotOK;
    }

    else if (data > 2147483647) {
        printf("invalid value!\n");
        return NotOK;
    }

    Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
    if (temp == NULL) {
        return NotOK;
    }
    temp->Data = data;
    temp->Link = NULL;

    if (*headArg == NULL) {
        *headArg = temp;
    } else {
        Node_t* current = *headArg;
        while (current->Link != NULL) {
            current = current->Link;
        }
        current->Link = temp;
    }

    return OK;
}


Error_t Delete(Node_t** headArg, int data) {
    if (headArg == NULL || *headArg == NULL) {
        return NotOK;
    }

    Node_t* temp = *headArg;
    Node_t* prev = NULL;

    while (temp != NULL && temp->Data != data) {
        prev = temp;
        temp = temp->Link;
    }

    if (temp == NULL) {
        printf("element not found.\n");
        return NotOK;
    }

    if (prev != NULL) {
        prev->Link = temp->Link;
    } else {
        *headArg = temp->Link;
    }

    free(temp);
    return OK;
}




void Quit(Node_t* headArg) {
    Node_t* current = headArg;
    
    while (current != NULL) {
        Node_t* temp = current;
        current = current->Link;
        free(temp);
    }
}

