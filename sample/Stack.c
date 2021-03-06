#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>

#include "Stack.h"

Stack_t *
CreateStack(kern_sample_t *in)
{
	size_t count = 0;
	char *ptr;
	Stack_t *retval = NULL;
	ssize_t indx;
	size_t base;

	if (in == NULL)
		return NULL;

	count = in->num_pcs;

	retval = malloc(sizeof(*retval) + sizeof(caddr_t) * count);
	retval->count = count;

	for (indx = 0;
	     indx < in->num_pcs;
	     indx++) {
		retval->stacks[indx] = (void*)in->pc[indx];
	}

//	fprintf(stderr, "found %zu items\n", indx);

done:
	return retval;
}

void
ReleaseStack(Stack_t *stack)
{
	if (stack) {
#if 0
		size_t indx;
		for (indx = 0;
		     indx < stack->count;
		     indx++) {
			free(stack->stacks[indx]);
		}
#endif
		free(stack);
	}
	return;
}
