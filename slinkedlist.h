#ifndef _SLINKEDLIST_H__
#define _SLINKEDLIST_H__

#include<stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include "compare.h"

/*
 * An element of a singly linked list element.
 */
typedef struct s_ald_slinkedlist_element ald_slinkedlist_element_t;


/*
 * A linked list.
 * Is defined as element itsself.
 */
typedef ald_slinkedlist_element_t ald_slinkedlist_t;

/*
 * Creates a ald_slinkedlist_t on the the heap and returns the pointer.
 */
ald_slinkedlist_element_t* ald_slinkedlist_element_create(void* data);

/*
 * Frees a ald_slinkedlist_element_t on the the heap.
 */
void ald_slinkedlist_element_free(ald_slinkedlist_element_t* list);

/*
 * Frees an entire linked list on the heap. All elements behind and including this element are freed.
 * Warning: If you free a list which is beginging in the middle of another list, element before the first freed element will have a dangling pointer.
 */
void ald_slinkedlist_free(ald_slinkedlist_t* list);


/*
 * Returns the ald_slinkedlist_element_t* at the given index. Returns NULL if index is out of bounds.
 */
ald_slinkedlist_element_t* ald_slinkedlist_get_element(ald_slinkedlist_t* list, size_t index);

/*
 * Returns the data pointer at the given index. Returns NULL if index is out of bounds.
 */
void* ald_slinkedlist_get(ald_slinkedlist_t* list, size_t index);

/*
 * Sets the data at the given index. Returns 0 if setting was succesful, returns not 0 otherwise.
 */
int ald_slinkedlist_set(ald_slinkedlist_t* list, size_t index, void* data);



/*
 * Frees an entire linked list on the heap, beginning with the next element, not this one.
 * Sets the next pointer of this element to NULL.
 * Can be used to cut a list and remove all elements to the right.
 */
void ald_slinkedlist_free_next(ald_slinkedlist_t* list);

/*
 * Append a new element with the given data to the end of the list.
 * Returns pointer to start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_append(ald_slinkedlist_t* list, void* data);


/*
 * Prepends a new element with the given data to the before the given list (only works when list is start of the list.
 * Returns pointer to start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_prepend(ald_slinkedlist_t* list, void* data);

/*
 * Inserts new element with given data at the given index in the list.
 * Inserts at the start when index is 0, inserts at end if index is to large for the list.
 * Returns pointer to start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_insert_at(ald_slinkedlist_t* list, size_t index, void* data);

/*
 * Inserts new element with given data after the given element in the list.
 */
void ald_slinkedlist_insert_after(ald_slinkedlist_element_t* element, void* data);

/*
 * Appends the second list to the end of the first.
 */
ald_slinkedlist_t* ald_slinkedlist_concat(ald_slinkedlist_t* list1, ald_slinkedlist_t* list2);

/*
 * Inserts the list into the another after the given element.
 */
void ald_slinkedlist_insert_list(ald_slinkedlist_element_t* element, ald_slinkedlist_t* list2);

/*
 * Returns true if the list contains the specified data, comparing with the given compare function.
 */
bool ald_slinkedlist_contains(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp);

/*
 * Returns the index of the given data, compared with the given compare function as size_t, if the list contains it. Otherwise, returns -1;
 */
ssize_t ald_slinkedlist_index_of(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp);

/*
 * Returns the pointer to first element in the list with the given data, if the list contains it. Compares elements with the given compare function.
 */
ald_slinkedlist_t* ald_slinkedlist_search(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp);

/*
 * Removes the first element with the given data out of the list, if it exists. Returns the new pointer to start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_remove(ald_slinkedlist_t* list, void* data, ald_compare_function_t cmp);

/*
 * Removes the element from the list, if it exists. Returns the new pointer to start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_remove_element(ald_slinkedlist_t* list, ald_slinkedlist_element_t* element);

/*
 * Removes the element at the given index, if it is in bounds. Returns the new pointer to the start of the list.
 */
ald_slinkedlist_t* ald_slinkedlist_remove_at(ald_slinkedlist_t* list, size_t index);


size_t ald_slinkedlist_size(ald_slinkedlist_t* list);


#endif  // _SLINKEDLIST_H__
