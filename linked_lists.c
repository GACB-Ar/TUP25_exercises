#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function prototypes
struct Node;
void insert_at_beggining(struct Node** head, int value);
void show_list(struct Node* node);
void insert_at_end(struct Node** head, int value);
void delete(struct Node** head, int value);
bool search(struct Node* head, int value);

int main()
{
    struct Node* test_list = NULL;

    insert_at_beggining(&test_list, 30);
    insert_at_beggining(&test_list, 20);
    insert_at_end(&test_list, 10);
    show_list(test_list);

    bool search_value = search(test_list, 20);
    printf("%d\n", search_value);

    if(search_value){
        printf("The value is in the list\n");
    }else{
        printf("The value is not in the list");
    }

    delete(&test_list, 10);
    show_list(test_list);

    return 0;
}

//structure implementation
struct Node
{
    int data;
    struct Node* next;
};

// Function implementations
void insert_at_beggining(struct Node** head, int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node ->data = value;
    new_node ->next = *head;
    *head = new_node;
}

void insert_at_end(struct Node** head, int value){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node -> data = value;
    new_node -> next = NULL;

    if(*head == NULL){
        *head = new_node;
    }

    struct Node* current = *head;
    while (current -> next != NULL){
        current = current->next;
    }
    current -> next = new_node;
}

bool search(struct Node* head, int value){
    int counter = 0;
    while (head != NULL){
        if(head->data == value){
            counter++;
        }
        head = head->next;

    }

    if(counter >0){
        return true;
    }else{
        return false;
    }
}

void delete(struct Node** head, int value){
    struct Node* current = *head;
    struct Node* previous = NULL;

    while(current != NULL && current->data != value){
        previous = current;
        current = current->next;
    }

    if (current == NULL){
        printf("Valor no encontrado\n");
    }

    if (previous == NULL){
        *head = current->next;
    }else{
        previous->next = current->next;
    }

    free(current);
}

void show_list(struct Node* node){
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}