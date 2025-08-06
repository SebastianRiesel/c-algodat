#include "slinkedlist.h"
#include <stdlib.h>

#define INDEX_IN_BOUNDS(index, size) (index >= 0 && index < size)

struct s_ald_slinkedlist_element{
    ald_slinkedlist_element_t* next;
    void* data;
};

ald_slinkedlist_element_t* ald_slinkedlist_element_create(void* data){
    ald_slinkedlist_element_t* list = (ald_slinkedlist_element_t*) calloc(1, sizeof(ald_slinkedlist_element_t));
    list->data = data;
    return list;
}

void ald_slinkedlist_element_free(ald_slinkedlist_element_t* list){
    free(list);
}


void ald_slinkedlist_free(ald_slinkedlist_t* list){
    ald_slinkedlist_element_t* next = list;
    while(list != NULL){
        next = list->next;
        free(list);
        list = next;
    }

}



void ald_slinkedlist_free_next(ald_slinkedlist_t* list){
    ald_slinkedlist_free(list->next);
    list->next = NULL;
}


ald_slinkedlist_t* ald_slinkedlist_append(ald_slinkedlist_t* list, void* data){
    if(list == NULL){
        return ald_slinkedlist_element_create(data);
    }

    ald_slinkedlist_t* last = list;
    while(last->next != NULL){
        last = last->next;
    }

    last->next = ald_slinkedlist_element_create(data);
    return list;
}


ald_slinkedlist_t* ald_slinkedlist_prepend(ald_slinkedlist_t* list, void* data){
    ald_slinkedlist_element_t* new_first = ald_slinkedlist_element_create(data);
    new_first->next = list;
    return new_first;
}


ald_slinkedlist_t* ald_slinkedlist_insert_at(ald_slinkedlist_t* list, size_t index, void* data){
    if(index == 0){
        return ald_slinkedlist_prepend(list, data);
    }

    size_t current_index = 0;

    ald_slinkedlist_t* new_elem,* next;

    next = list;

    if(next == NULL){
        return ald_slinkedlist_element_create(data);
    }


    while(next->next!=NULL){
        current_index++;
        next = next->next;

        if(current_index+1 == index){
            break;
        }

    }
    ald_slinkedlist_insert_after(next, data);
    return list;
}


void ald_slinkedlist_insert_after(ald_slinkedlist_element_t* element, void* data){
    ald_slinkedlist_element_t* new_elem = ald_slinkedlist_element_create(data);
    new_elem->next = element->next;
    if(element != NULL){
        element->next = new_elem;
    }
}


ald_slinkedlist_t* ald_slinkedlist_concat(ald_slinkedlist_t* list1, ald_slinkedlist_t* list2){return NULL;}


ald_slinkedlist_t* ald_slinkedlist_insert_list(ald_slinkedlist_element_t* element, ald_slinkedlist_t* list2){return NULL;}


bool ald_slinkedlist_contains(ald_slinkedlist_t* list, void* data, ald_compare_function_t* cmp){return false;}


ssize_t ald_slinkedlist_index_of(ald_slinkedlist_t* list, void* data, ald_compare_function_t* cmp){return -1;}


ald_slinkedlist_t* ald_slinkedlist_search(ald_slinkedlist_t* list, void* data, ald_compare_function_t* cmp){return NULL;}

ald_slinkedlist_t* ald_slinkedlist_remove(ald_slinkedlist_t* list, void* data, ald_compare_function_t* cmp){return NULL;}


ald_slinkedlist_t* ald_slinkedlist_remove_element(ald_slinkedlist_t* list, ald_slinkedlist_element_t* element){return NULL;}

ald_slinkedlist_t* ald_slinkedlist_remove_at(ald_slinkedlist_t* list, size_t index){return NULL;}


size_t ald_slinkedlist_size(ald_slinkedlist_t* list){
    size_t size = 0;

    while(list!=NULL){
        size++;
        list = list->next;
    }
    return size;
}
