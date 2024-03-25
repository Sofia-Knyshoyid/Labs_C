#include <stdio.h>
#include <stdlib.h>

// typedef int Data;

typedef struct Data{
    int data_int;
    double data_double;
} Data;

typedef struct tagListElement {
    struct tagListElement *next;
    Data                   data;
} ListElement;

typedef struct tagList {
    ListElement *head;
    ListElement *tail;
    int size;
} List;

/* inicjalizacja listy */
void init(List*list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

/* Dodawanie danych do listy */
void push_front(List*list, Data data) {
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    element->next = list->head;

    element->data.data_int = data.data_int;
    // element->data = data;

    if(list->head != NULL) {
        list->head=element;
    } else {
        list->head = element;
        list->tail = element;
    }
    list->size++;
}

void push_back(List*list, Data data) {
    ListElement* element = (ListElement*)malloc(sizeof(ListElement));
    element->next = NULL;

    element->data.data_int = data.data_int;
    // element->data = data;

    if(list->tail != 0){
        // connect the last (for now) element to the new
        list->tail->next = element;
        // set the new as the last
        list->tail = element;
    } else {
        list->head = element;
        list->tail = element;
    }
    list->size++;
}

/* Usuwanie pierwszego elementu */
void delete_front(List *list){
    ListElement* toDelete;
    if(list->head == 0) return;
    toDelete = list->head;
    list->head = list->head->next;
    if(list->head == 0) list->tail = 0;
    free(toDelete);
    list->size--;
}

/* Zwalnianie całej listy */
void freeList(List *list) {
    while(list->head) {
        delete_front(list);
    }
}

/* Wypisanie zawartości listy */
void dumpList(const List *list) {
    ListElement *curr;
    for(curr=list->head; curr!=0; curr=curr->next){
        printf("%d ",curr->data.data_int);
    }
    printf("\n");
}

int main(void) {
    List list;
    init(&list);
    for(int i=0; i<10; i++) {
        Data data_1;
        data_1.data_int=i;
        push_front(&list,data_1);
        push_back(&list,data_1);
    } 
    dumpList(&list);
 
    for(int i=0; i<5; i++) {
        Data data_2;
        data_2.data_int=100+i;
        delete_front(&list);
        push_back(&list,data_2); 
    }
    dumpList(&list);
 
    freeList(&list);
    return 0;
}