#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

struct link_list {
	struct link_list *prev;
	struct link_list *next;
};

#endif /* __LINK_LIST_H__ */
