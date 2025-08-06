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

ald_slinkedlist_element_t* ald_slinkedlist_get_element(ald_slinkedlist_t* list, size_t index){
    if(list == NULL){
        return NULL;
    }


    ald_slinkedlist_element_t* current = list;
    size_t current_index = 0;

    while(current != NULL){

        if(current_index == index){
            return current;
        }
        current = current->next;
        current_index++;
    }
    return list;
}


void* ald_slinkedlist_get(ald_slinkedlist_t* list, size_t index){
    ald_slinkedlist_element_t* element = ald_slinkedlist_get_element(list, index);
    if(element != NULL){
        return element->data;
    }

    return NULL;
}


int ald_slinkedlist_set(ald_slinkedlist_t* list, size_t index, void* data){
    ald_slinkedlist_element_t* element = ald_slinkedlist_get_element(list, index);
    if(element != NULL){
        element->data = data;
        return 0;
    }

    return -1;
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


ald_slinkedlist_t* ald_slinkedlist_concat(ald_slinkedlist_t* list1, ald_slinkedlist_t* list2){

    if(list1 == NULL){
        return list2;
    }
    if(list2 == NULL){
        return list1;
    }

    // go to the end of the first list
    ald_slinkedlist_t* current_element = list1;
    while(current_element->next!=NULL){
        current_element = current_element->next;
    }

    current_element->next = list2;

    return list1;
}


void ald_slinkedlist_insert_list(ald_slinkedlist_element_t* element, ald_slinkedlist_t* list2){
    if(element==NULL){
        return;
    }

    if(list2 == NULL){
        return;
    }

    ald_slinkedlist_element_t* last_element_list2 = list2;

    while(last_element_list2->next != NULL){
        last_element_list2 = last_element_list2->next;
    }

    last_element_list2->next = element->next;

    element->next = list2;

}

bool ald_slinkedlist_contains(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp){
    return ald_slinkedlist_index_of(list, data, cmp) != -1;
}

ssize_t ald_slinkedlist_index_of(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp){
    if(list == NULL){
        return -1;
    }

    ald_slinkedlist_element_t* current = list;
    ssize_t idx = 0;
    while(current->next != NULL){

        if(cmp(data, current->data) == 0){
            return idx;
        }

        current = current->next;
        ++idx;
    }
    return -1;
}

ald_slinkedlist_t* ald_slinkedlist_search(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp){
    if(list == NULL){
        return NULL;
    }

    ald_slinkedlist_element_t* current = list;
    while(current->next != NULL){

        if(cmp(data, current->data) == 0){
            return current;
        }

        current = current->next;
    }
    return NULL;
}

ald_slinkedlist_t* ald_slinkedlist_remove(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp){
    if(list == NULL){
        return NULL;
    }

    if(cmp(data, list->data) == 0){
        ald_slinkedlist_t* next = list->next;
        ald_slinkedlist_element_free(list);
        return next;
    }

    ald_slinkedlist_element_t* current = list->next;
    ald_slinkedlist_element_t* previous = list;

    while(current != NULL){

        if(cmp(data, current->data) == 0){
            previous->next = current->next;
            ald_slinkedlist_element_free(current);
            return list;
        }
        previous = current;
        current = current->next;
    }
    return list;
}

ald_slinkedlist_t* ald_slinkedlist_remove_element(ald_slinkedlist_t* list, ald_slinkedlist_element_t* element){
    if(list == NULL){
        return NULL;
    }

    if(list == element){
        ald_slinkedlist_t* next = list->next;
        ald_slinkedlist_element_free(list);
        return next;
    }

    ald_slinkedlist_element_t* current = list->next;
    ald_slinkedlist_element_t* previous = list;

    while(current != NULL){

        if(current == element){
            previous->next = current->next;
            ald_slinkedlist_element_free(current);
            return list;
        }
        previous = current;
        current = current->next;
    }
    return list;
}

ald_slinkedlist_t* ald_slinkedlist_remove_at(ald_slinkedlist_t* list, size_t index){
    if(list == NULL){
        return NULL;
    }

    if(index == 0){
        ald_slinkedlist_t* next = list->next;
        ald_slinkedlist_element_free(list);
        return next;
    }

    ald_slinkedlist_element_t* current = list->next;
    ald_slinkedlist_element_t* previous = list;
    size_t current_index = 1;

    while(current != NULL){

        if(current_index == index){
            previous->next = current->next;
            ald_slinkedlist_element_free(current);
            return list;
        }
        previous = current;
        current = current->next;
        current_index++;
    }
    return list;
}


size_t ald_slinkedlist_size(ald_slinkedlist_t* list){
    size_t size = 0;

    while(list!=NULL){
        size++;
        list = list->next;
    }
    return size;
}
