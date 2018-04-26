#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

struct list_linker {
	struct list_linker *prev;
	struct list_linker *next;
};

static inline void
list_linker_init(struct list_linker *node)
{
	node->prev = node->next = node;
}

static inline void
__list_insert(struct list_linker *node,
              struct list_linker *prev,
              struct list_linker *next)
{
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
}

static inline void
list_insert_before(struct list_linker *node, struct list_linker *ref)
{
	__list_insert(node, ref->prev, ref);
}

static inline void
list_insert_after(struct list_linker *node, struct list_linker *ref)
{
	__list_insert(node, ref, ref->next);
}

static inline void
list_insert_head(struct list_linker *head, struct list_linker *node)
{
	list_insert_after(node, head);
}

static inline void
list_insert_tail(struct list_linker *head, struct list_linker *node)
{
	list_insert_before(node, head);
}

static inline void
list_delete(struct list_linker *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

#endif /* __LINK_LIST_H__ */
