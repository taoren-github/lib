#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

struct link_list {
	struct link_list *prev;
	struct link_list *next;
};

static inline void
link_list_init(struct link_list *node)
{
	node->prev = node->next = node;
}

static inline void
__list_insert(struct link_list *node,
              struct link_list *prev,
              struct link_list *next)
{
	node->prev = prev;
	node->next = next;
	prev->next = node;
	next->prev = node;
}

static inline void
list_insert_before(struct link_list *node, struct link_list *ref)
{
	__list_insert(node, ref->prev, ref);
}

static inline void
list_insert_after(struct link_list *node, struct link_list *ref)
{
	__list_insert(node, ref, ref->next);
}

static inline void
list_insert_head(struct link_list *head, struct link_list *node)
{
	list_insert_after(node, head);
}

static inline void
list_insert_tail(struct link_list *head, struct link_list *node)
{
	list_insert_before(node, head);
}

static inline void
list_delete(struct link_list *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

#endif /* __LINK_LIST_H__ */
