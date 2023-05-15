#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int value;
    struct _node* next;
} node;                       // Node is a structure that our list will be built out of

typedef node* list;           // List is a pointer towards the beggining Node


node* insert_a (int n, node* list) { // Insert an element to the start of the list

    node* temp = malloc (sizeof(node));
    temp -> value = n;
    temp -> next = list;

    return temp;
}

node* insert_z (int n, node* list){  // Insert an element to the end of the list [Recursively]

    node* temp = list;

    if (temp == NULL){
        node* new = malloc (sizeof(node));
        new->value=n;
        new->next=NULL;
        return new;
    }
    else{
        temp->next=insert_z(n, temp->next);
        return temp;
    }
}


        
    

void print_itr (node* list){ // Print out a list  iteratively

    node* temp = list; // we need to assign a pointer towards a new node as we DO NOT want to modify the original list that we sent into this function

    while (temp != NULL){
        printf("%d ",temp -> value);
        temp = temp->next; // the loop keeps printing the next element until it hits the end of the list (NULL value)

    }
    printf("\n");
    
}

void print_rec (node* list){ // Print out a list recursively

    if (list == NULL){
        printf("\n");
    }
    else{
        printf("%d ", list->value);
        print_rec(list->next);
    }
}



int main (){

    list l = NULL;

    l = insert_a (2, l);
    print_itr(l);
    l = insert_a (5, l);
    print_itr(l);
    l = insert_a (4, l);
    print_itr(l);

    l = insert_z (4, l);
    print_rec(l);

    l = insert_z (8, l);
    print_rec(l);

}