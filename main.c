#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

void a_string(void *data) {
	if (NULL == data)
		printf("nil\n");
	else
		printf("%s ", (char *)data);
}

void f(void **data) {
	*data = NULL;
}

void a_int(void *data) {
	if (NULL == data)
		printf("nil\n");
	else
		printf("%d ", *(int *)data);
}

/* if a < b return <0 else if a > b return >0 else if equals return 0 */
int cmp_int(void *a, void *b) {
	return (*(int *)a) - (*(int *)b);
}

/* if a < b return <0 else if a > b return >0 else if equals return 0 (in lexical order)*/
int cmp_string(void *a, void *b) {
	return strcmp((const char *)a, (const char *)b);
}

int main() {

	LinkedList *list = NULL, *ret = NULL;
	int x = 4, y = 1;

	add_to_top(&list, "!", a_string, f);
	add_to_top(&list, "ever", a_string, f);
	add_to_top(&list, &x, a_int, f);
	add_to_top(&list, "you", a_string, f);
	add_to_top(&list, "love", a_string, f);
	add_to_top(&list, "I", a_string, f);

	print_linked_list(list);

	free_linked_list(&list);

	add_at_the_end(&list, "U", a_string, f);
	add_at_the_end(&list, "are", a_string, f);
	add_at_the_end(&list, "the", a_string, f);
	add_at_the_end(&list, "only", a_string, f);
	add_at_the_end(&list, &y, a_int, f);
	add_at_the_end(&list, &x, a_int, f);
	add_at_the_end(&list, "me", a_string, f);
	add_at_the_end(&list, "!", a_string, f);

	print_linked_list(list);

	free_linked_list(&list);

	add_to_top(&list, "I", a_string, f);
	add_after_first_occurrence(&list, "number", a_string, f, "I", cmp_string);
	add_before_first_occurrence(&list, "love", a_string, f, "number", cmp_string);
	add_after_first_occurrence(&list, &x, a_int, f, "number", cmp_int);
	add_before_first_occurrence(&list, "the", a_string, f, "number", cmp_string);
	add_before_first_occurrence(&list, "four", a_string, f, &x, cmp_string);

	print_linked_list(list);

	free_linked_list(&list);

	add_after_last_occurrence(&list, "This", a_string, f, NULL, cmp_string);
	add_after_last_occurrence(&list, "is", a_string, f, "This", cmp_string);
	add_after_last_occurrence(&list, "a", a_string, f, "is", cmp_string);
	add_after_last_occurrence(&list, "module", a_string, f, "a", cmp_string);
	add_after_last_occurrence(&list, "of", a_string, f, "module", cmp_string);
	add_after_last_occurrence(&list, "list", a_string, f, "of", cmp_string);
	add_after_last_occurrence(&list, "for", a_string, f, "list", cmp_string);
	add_after_last_occurrence(&list, "list", a_string, f, "for", cmp_string);
	add_after_last_occurrence(&list, "linked", a_string, f, "list", cmp_string);

	print_linked_list(list);

	ret = find_first_occurrence(list, "list", cmp_string);
	print_linked_list(ret);

	ret = find_last_occurrence(list, "list", cmp_string);
	print_linked_list(ret);

	printf("size of the last list : %d.\n", linked_list_size(list));

	free_linked_list(&list);

	return EXIT_SUCCESS;

}
