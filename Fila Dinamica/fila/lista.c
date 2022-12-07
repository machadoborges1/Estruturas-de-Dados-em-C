#include <stdlib.h>

struct element {
    int value;
    struct no *next;
};

typedef struct element Element;

typedef struct list {
    Element *begin, *end;
    int size;
} List;

List *
create() {
    List *list;
    list = (List*)malloc(sizeof(List));

    if(list == NULL) return NULL;

    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
    return list;
}

void 
delete(List * list) {
    if(list != NULL) {
        Node *element;
        while((*list) != NULL) {
            element = *list;
            *list = (*list)->beguin;
            free(element);
        }
    }
}

void 
insertBegin(List * list, int value) {
    Node *element;
    element = (Node*)malloc(sizeof(Node));

    element->value = value;

    if(list->begin == NULL) {
        list->begin = element;
        list->end = element;
        element->next = NULL;
    } else {
        element->next = list->begin;
        list->end = element;
    }

    list->size++;
}

void
insertEnd(List * list, int value) {
    Node *element;
    element = (Node*)malloc(sizeof(Node));

    element->value;

    if(list->begin == NULL) {
        list->begin = element;
        list->end = element;    
    } else {
        list->end->next = element;
        list->end = element;
    }
    
    list->size++;
}


