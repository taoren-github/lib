#ifndef __LIB_STACK_H__
#define __LIB_STACK_H__

typedef struct {
	int size;
	int capacity;
	void *data;
} stack_t;

int stack_init(stack_t *s);
void stack_destroy(stack_t *s);

#endif /* __LIB_STACK_H__ */
