#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


/*
 * @Function alloc_linked_list
 * @Params
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 *		struct _list *next
 *		# pointer to a LinkedList #
 *		# correspond to the second field of a LinkedList #
 * @Return LinkedList * # return a pointer to a new cell allocated with malloc(3) #
 * @Description
 * 		This function create a LinkedList allocated with malloc(3).
 * 		In this structure, data is put in the 'data' field,
 * 		and the 'next' field points on next.
 * 		If the LinkedList is correctly done, the function returns it.
 * 		Else the function returns the NULL pointer.
 */
static LinkedList * alloc_linked_list(void *data, void (*print_data)(void *data), void (*free_data)(void **data), struct _list *next) {

	LinkedList *list = NULL;

	list = (LinkedList *)malloc(sizeof(LinkedList));
	if (NULL == list) {
		fprintf(stderr, "error: allocation fail.\n");
		return NULL;
	}

	list->data = data;
	list->print_data = print_data;
	list->free_data = free_data;
	list->next = next;

	return list;

}

/*
 * This function frees the memory space dedicated to the LinkedList in the parameters.
 * At the end of the function, the LinkedList points to the NULL pointer.
 * This function does it recursively.
 * WARNING : the free_data function cannot be NULL.
 */
void free_linked_list(LinkedList **list) {

	if (NULL == (*list))
		return;

	free_linked_list(&((*list)->next));
	(*list)->free_data(&((*list)->data));
	free(*list);
	*list = NULL;

}

/*
 * This function displays all the LinkedList on the console.
 * This function does it recursively.
 * WARNING : the print_data function cannot be NULL.
 */
void print_linked_list(LinkedList *list) {

	if (NULL == list) {
		printf("\n");
		return;
	}

	list->print_data(list->data);
	print_linked_list(list->next);

}

/*
 * This function displays all the LinkedList on the console.
 * Each data is separated by the string 'separator'.
 * If 'separator' is NULL, the separator is a space.
 * This function does it recursively.
 * WARNING : the print_data function cannot be NULL.
 */
void print_linked_list_with_separator(LinkedList *list, char *separator) {

	if (NULL == list) {
		printf("\n");
		return;
	}

	list->print_data(list->data);
	if (NULL == separator)
		printf(" ");
	else if (list->next != NULL)
		printf("%s", separator);

	print_linked_list_with_separator(list->next, separator);

}

/*
 * This function add to the top of the LinkedList the data in parameters with malloc(3).
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_to_top(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data)) {

	*list = alloc_linked_list(data, print_data, free_data, *list);

	return ((*list) != NULL);

}

/*
 * This function add at the end of the LinkedList the data in parameters with malloc(3).
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_at_the_end(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data)) {

	LinkedList *tmp = *list;

	if (NULL == (*list)) {
		*list = alloc_linked_list(data, print_data, free_data, *list);
		if (NULL == (*list))
			return 0;
	} else {
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = alloc_linked_list(data, print_data, free_data, NULL);
		if (NULL == tmp->next)
			return 0;
	}

	return 1;

}

/*
 * This function add after the first occurrence of reference in the LinkedList, the data in parameters with malloc(3).
 * WARNING: We suppose that cmp_data can compare all the data in the LinkedList.
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_after_first_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list;

	if (NULL == (*list) && reference != NULL) {
		fprintf(stderr, "WARNING: You want to add after an element that not exist.\n");
		return 0;
	} else if (NULL == (*list) && NULL == reference) {
		*list = alloc_linked_list(data, print_data, free_data, NULL);
		return ((*list) != NULL);
	} else {
		if (NULL == reference)
			return add_at_the_end(list, data, print_data, free_data);
		while (tmp != NULL && cmp_data(reference, tmp->data) != 0)
			tmp = tmp->next;
		if (NULL == tmp) {
			fprintf(stderr, "WARNING: You want to add after an element that not exist.\n");
			return 0;
		}
		tmp->next = alloc_linked_list(data, print_data, free_data, tmp->next);
		return (tmp->next != NULL);
	}

}

/*
 * This function add before the first occurrence of reference in the LinkedList, the data in parameters with malloc(3).
 * WARNING: We suppose that cmp_data can compare all the data in the LinkedList.
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_before_first_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list;

	if (NULL == (*list) && reference != NULL) {
		fprintf(stderr, "WARNING: You want to add before an element that not exist.\n");
		return 0;
	} else if (NULL == (*list) && NULL == reference) {
		*list = alloc_linked_list(data, print_data, free_data, NULL);
		return ((*list) != NULL);
	} else {
		if (NULL == reference)
			return add_at_the_end(list, data, print_data, free_data);
		if (cmp_data(reference, (*list)->data) == 0)
			return add_to_top(list, data, print_data, free_data);
		while (tmp->next != NULL && cmp_data(reference, tmp->next->data) != 0)
			tmp = tmp->next;
		if (NULL == tmp->next) {
			fprintf(stderr, "WARNING: You want to add before an element that not exist.\n");
			return 0;
		}
		tmp->next = alloc_linked_list(data, print_data, free_data, tmp->next);
		return (tmp->next != NULL);
	}

}

/*
 * This function add after the last occurrence of reference in the LinkedList, the data in parameters with malloc(3).
 * WARNING: We suppose that cmp_data can compare all the data in the LinkedList.
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_after_last_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *last = NULL;

	if (NULL == (*list) && reference != NULL) {
		fprintf(stderr, "WARNING: You want to add after an element that not exist.\n");
		return 0;
	} else if (NULL == (*list) && NULL == reference) {
		*list = alloc_linked_list(data, print_data, free_data, NULL);
		return ((*list) != NULL);
	} else {
		if (NULL == reference)
			return add_at_the_end(list, data, print_data, free_data);
		while (tmp != NULL) {
			if (cmp_data(reference, tmp->data) == 0)
				last = tmp;
			tmp = tmp->next;
		}

		if (NULL == last) {
			fprintf(stderr, "WARNING: You want to add after an element that not exist.\n");
			return 0;
		}
		last->next = alloc_linked_list(data, print_data, free_data, last->next);
		return (last->next != NULL);
	}

}

/*
 * This function add before the last occurrence of reference in the LinkedList, the data in parameters with malloc(3).
 * WARNING: We suppose that cmp_data can compare all the data in the LinkedList.
 * It returns 0 if there were an allocation problem.
 * Else it returns 1.
 */
int add_before_last_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *last = NULL;

	if (NULL == (*list) && reference != NULL) {
		fprintf(stderr, "WARNING: You want to add before an element that not exist.\n");
		return 0;
	} else if (NULL == (*list) && NULL == reference) {
		*list = alloc_linked_list(data, print_data, free_data, NULL);
		return ((*list) != NULL);
	} else {
		if (NULL == reference)
			return add_at_the_end(list, data, print_data, free_data);
		if (cmp_data(reference, (*list)->data) == 0)
			last = tmp;
		while (tmp->next != NULL) {
			if (cmp_data(reference, tmp->next->data) == 0) {
				last = tmp;
			}
			tmp = tmp->next;
		}

		if (NULL == last) {
			fprintf(stderr, "WARNING: You want to add before an element that not exist.\n");
			return 0;
		}
		last->next = alloc_linked_list(data, print_data, free_data, last->next);
		return (last->next != NULL);
	}

}

/*
 * This function add at the end of list the LinkedList list_to_add.
 * WARNING : This function just link list_to_add at the end of list,
 * so if you free(or modifies) an element common of the two list,
 * the other list will be modified too.
 */
void add_list(LinkedList **list, const LinkedList *list_to_add) {

	LinkedList *tmp = *list;

	if (NULL == list_to_add)
		return;

	if (NULL == (*list)) {
		*list = (LinkedList *)list_to_add;
		return;
	}

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = (LinkedList *)list_to_add;

}

/*
 * This function remove the first occurrence of target_data in list.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 * If target_data has not been found, it returns 0.
 * Else it returns 1.
 */
int remove_first_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *save;

	if (NULL == (*list))
		return 0;

	while (tmp->next != NULL && cmp_data(tmp->next->data, target_data) != 0)
		tmp = tmp->next;

	if (NULL == tmp->next) {
		if (cmp_data(tmp->data, target_data) == 0) {
			free_linked_list(list);
			return 1;
		}
		return 0;
	}

	save = tmp->next;
	tmp->next = tmp->next->next;
	free(save);
	save = NULL;

	return 1;

}

/*
 * This function remove the first occurrence of target_data in list.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 * If target_data has not been found, it returns 0.
 * Else it returns 1.
 */
int remove_last_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *save, *last = NULL;

	if (NULL == (*list))
		return 0;

	if (NULL == tmp->next) {
		if (cmp_data(tmp->data, target_data) == 0) {
			free_linked_list(list);
			return 1;
		}
		return 0;
	}

	while (tmp->next != NULL) {
		if (cmp_data(tmp->next->data, target_data) == 0)
			last = tmp;
		tmp = tmp->next;
	}

	if (NULL == last)
		return 0;

	save = last->next;
	last->next = last->next->next;
	free(save);
	save = NULL;

	return 1;

}


void remove_all_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	while (remove_first_occurrence(list, target_data, cmp_data) != 0);

}

/*
 * This function extract the first occurrence of target_data in list.
 * It returns a LinkedList corresponding to where the function found target_data in list.
 * If target_data is not present in list, it returns NULL.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 */
LinkedList * extract_first_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *save;

	if (NULL == (*list))
		return NULL;

	while (tmp->next != NULL && cmp_data(tmp->next->data, target_data) != 0)
		tmp = tmp->next;

	if (NULL == tmp->next) {
		if (cmp_data(tmp->data, target_data) == 0) {
			save = *list;
			*list = NULL;
			return save;
		}
		return NULL;
	}

	save = tmp->next;
	tmp->next = tmp->next->next;

	return save;

}

/*
 * This function extract the last occurrence of target_data in list.
 * It returns a LinkedList corresponding to where the function found target_data in list.
 * If target_data is not present in list, it returns NULL.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 */
LinkedList * extract_last_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *tmp = *list, *save, *last = NULL;

	if (NULL == (*list))
		return NULL;

	if (NULL == tmp->next) {
		if (cmp_data(tmp->data, target_data) == 0) {
			save = *list;
			*list = NULL;
			return save;
		}
		return NULL;
	}

	while (tmp->next != NULL) {
		if (cmp_data(tmp->next->data, target_data) == 0)
			last = tmp;
		tmp = tmp->next;
	}

	if (NULL == last)
		return 0;

	save = last->next;
	last->next = last->next->next;

	return save;

}

/*
 * This function search the first occurrence of target_data in list.
 * It returns a LinkedList corresponding to where the function found target_data in list.
 * If target_data is not present in list, it returns NULL.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 */
LinkedList * find_first_occurrence(LinkedList *list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	while (list != NULL && cmp_data(list->data, target_data) != 0)
		list = list->next;

	return list;

}

/*
 * This function search the last occurrence of target_data in list.
 * It returns a LinkedList corresponding to where the function found target_data in list.
 * If target_data is not present in list, it returns NULL.
 * WARNING: We suppose that cmp_data can compare all the elements of list.
 */
LinkedList * find_last_occurrence(LinkedList *list, void *target_data, int (*cmp_data)(void *data1, void *data2)) {

	LinkedList *last = NULL;

	while (list != NULL) {
		if (cmp_data(list->data, target_data) == 0)
			last = list;
		list = list->next;
	}

	return last;

}

/*
 * This function counts the elements in list.
 * It returns the number of elements in list.
 */
unsigned int linked_list_size(LinkedList *list) {

	unsigned int count = 0;

	while (list != NULL) {
		count += 1;
		list = list->next;
	}

	return count;

}
