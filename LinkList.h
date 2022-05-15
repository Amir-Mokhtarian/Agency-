#ifndef LINKLIST_H
#define LINKLIST_H
#include "Trip.h"

class LinkList
{
public:

	Trip value;
	LinkList* next;

	LinkList(Trip& a)
	{
		value = a;
		next = nullptr;
	}
    LinkList();
    virtual ~LinkList();

protected:

private:
};

#endif // LINKLIST_H
