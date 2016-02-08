#ifndef HEADER_LINKED_LIST_H_
#define HEADER_LINKED_LIST_H_


struct _list {
	void *data; /* data of the cell */
	void (*print_data)(void *data); /* pointer to the function which displays the data of the structure */
	void (*free_data)(void **data); /* pointer to the function which frees the data of the structure */
	struct _list *next; /* pointer to the next cell of the structure */
};
/*
 * Recursive structure which has a data in each cell of the structure.
 * The first cell ( ie first data ) is directly accessible in a LinkedList.
 * To access the following cells, use the pointer 'next' that points to the next cell of the current LinkedList.
 */

typedef struct _list LinkedList;


/*
 * @Function free_linked_list
 * @Params
 * 		LinkedList **list
 * 		# pointer to a LinkedList #
 * @Return void
 * @Description
 * 		This function frees the memory space dedicated to the LinkedList in the parameters.
 * 		At the end of the function, the LinkedList points to the NULL pointer.
 * 		WARNING : the free_data function cannot be NULL (it is used to free the data from the structure).
 */
extern void free_linked_list(LinkedList **list);

/*
 * @Function print_linked_list
 * @Params
 * 		LinkedList *list
 * 		# LinkedList to print #
 * @Return void
 * @Description
 * 		This function displays all the LinkedList on the console.
 * 		WARNING : print_data cannot be NULL (it is used to print data from the LinkedList).
 */
extern void print_linked_list(LinkedList *list);

/*
 * @Function print_linked_list
 * @Params
 * 		LinkedList *list
 * 		# LinkedList to print #
 * 		char *separator
 * 		# string to separate the data #
 * 		# when print them on the console #
 * @Return void
 * @Description
 * 		This function displays all the LinkedList on the console.
 * 		Each data is separated by the string 'separator'.
 * 		If separator is NULL, the separator is a space.
 * 		WARNING : print_data cannot be NULL (it is used to print data from the LinkedList).
 */
extern void print_linked_list_with_separator(LinkedList *list, char *separator);

/*
 * @Function add_to_top
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * @Return int # error detection value #
 * @Description
 * 		This function add to the top of the LinkedList the data in parameters.
 * 		It returns 0 if there were an allocation problem.
 * 		Else it returns 1.
 */
extern int add_to_top(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data));

/*
 * @Function add_at_the_end
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * @Return int # error detection value #
 * @Description
 * 		This function add at the end of the LinkedList the data in parameters.
 * 		It returns 0 if there were an allocation problem.
 * 		Else it returns 1.
 */
extern int add_at_the_end(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data));

/*
 * @Function add_after_first_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * 		void *reference
 * 		# data reference to add data after it #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function to compare two same data #
 * @Return int # error detection value #
 * @Description
 * 		This function add after the first occurrence of reference in the LinkedList, the data in parameters.
 * 		WARNING: We suppose that cmp_data can compare all the data of the LinkedList.
 * 		It returns 0 if there were an allocation problem or reference not found.
 * 		Else it returns 1.
 */
extern int add_after_first_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function add_before_first_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * 		void *reference
 * 		# data reference to add data before it #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function to compare two same data #
 * @Return int # error detection value #
 * @Description
 * 		This function add before the first occurrence of reference in the LinkedList, the data in parameters.
 * 		WARNING: We suppose that cmp_data can compare all the data of the LinkedList.
 * 		It returns 0 if there were an allocation problem or reference not found.
 * 		Else it returns 1.
 */
extern int add_before_first_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function add_after_last_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * 		void *reference
 * 		# data reference to add data after it #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function to compare two same data #
 * @Return int # error detection value #
 * @Description
 * 		This function add after the last occurrence of reference in the LinkedList, the data in parameters.
 * 		WARNING: We suppose that cmp_data can compare all the data of the LinkedList.
 * 		It returns 0 if there were an allocation problem or reference not found.
 * 		Else it returns 1.
 */
extern int add_after_last_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function add_before_last_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *data
 * 		# generic data to add #
 * 		# correspond to the first field of a LinkedList #
 * 		void (*print_data)(void *data)
 * 		# pointer to the function which displays the data from the structure #
 * 		void (*free_data)(void **data)
 * 		# pointer to the function which frees the data from the structure #
 * 		void *reference
 * 		# data reference to add data before it #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function to compare two same data #
 * @Return int # error detection value #
 * @Description
 * 		This function add before the last occurrence of reference in the LinkedList, the data in parameters.
 * 		WARNING: We suppose that cmp_data can compare all the data of the LinkedList.
 * 		It returns 0 if there were an allocation problem or reference not found.
 * 		Else it returns 1.
 */
extern int add_before_last_occurrence(LinkedList **list, void *data, void (*print_data)(void *data), void (*free_data)(void **data), void *reference, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function add_list
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		const LinkedList *list_to_add
 * 		# LinkedList to add to list #
 * 		# this LinkedList will not be modified #
 * @Return void
 * @Description
 * 		This function add at the end of list the LinkedList list_to_add.
 * 		WARNING: This function just link list_to_add at the end of list,
 * 		so if you free(or modifies) list_to_add, list will be modified.
 * 		And if you free(or modifies) an element of list which is in list_to_add, list_to_add will be modified.
 */
extern void add_list(LinkedList **list, const LinkedList *list_to_add);

/*
 * @Function remove_first_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to remove of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return int # error detection return #
 * @Description
 * 		This function remove the first occurrence of target_data in list.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 * 		If target_data has not been found, it returns 0.
 * 		Else it returns 1.
 */
extern int remove_first_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function remove_last_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to remove of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return int # error detection return #
 * @Description
 * 		This function remove the last occurrence of target_data in list.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 * 		If target_data has not been found, it returns 0.
 * 		Else it returns 1.
 */
extern int remove_last_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function remove_all_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to remove of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return void
 * @Description
 * 		This function remove all occurrences of target_data in list.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 */
extern void remove_all_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function extract_first_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to extract of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return LinkedList * # pointer to the cell where there is target_data or NULL #
 * @Description
 * 		This function remove the first occurrence of target_data in list.
 * 		It returns a LinkedList corresponding to where the function found target_data in list.
 * 		If target_data is not present in list, it returns NULL.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 */
extern LinkedList * extract_first_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function extract_last_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to extract of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return LinkedList * # pointer to the cell where there is target_data or NULL #
 * @Description
 * 		This function remove the last occurrence of target_data in list.
 * 		It returns a LinkedList corresponding to where the function found target_data in list.
 * 		If target_data is not present in list, it returns NULL.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 */
extern LinkedList * extract_last_occurrence(LinkedList **list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function find_first_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to find of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return LinkedList * # pointer to the cell where there is target_data or NULL #
 * @Description
 * 		This function search the first occurrence of target_data in list.
 * 		It returns a LinkedList corresponding to where the function found target_data in list.
 * 		If target_data is not present in list, it returns NULL.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 */
extern LinkedList * find_first_occurrence(LinkedList *list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function find_last_occurrence
 * @Params
 * 		LinkedList **list
 * 		# LinkedList which will be modified #
 * 		void *target_data
 * 		# data to find of list #
 * 		int (*cmp_data)(void *data1, void *data2)
 * 		# pointer to a function that can compare the elements of list #
 * @Return LinkedList * # pointer to the cell where there is target_data or NULL #
 * @Description
 * 		This function search the last occurrence of target_data in list.
 * 		It returns a LinkedList corresponding to where the function found target_data in list.
 * 		If target_data is not present in list, it returns NULL.
 * 		WARNING: We suppose that cmp_data can compare all the elements of list.
 */
extern LinkedList * find_last_occurrence(LinkedList *list, void *target_data, int (*cmp_data)(void *data1, void *data2));

/*
 * @Function linked_list_size
 * @Params
 * 		LinkedList *list
 * 		# LinkedList to measured #
 * @Return unsigned int # number of elements in the LinkedList #
 * @Description
 * 		This function counts the elements in list.
 * 		It returns the number of elements in list.
 */
extern unsigned int linked_list_size(LinkedList *list);


#endif /* HEADER_LINKED_LIST_H_ */
