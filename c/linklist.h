#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

struct link_list {
	struct link_list *prev;
	struct link_list *next;
};

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
list_add_before(struct link_list *node, struct link_list *ref)
{
	__list_insert(node, ref->prev, ref);
}

static inline void
list_add_after(struct link_list *node, struct link_list *ref)
{
	__list_insert(node, ref, ref->next);
}

#endif /* __LINK_LIST_H__ */
