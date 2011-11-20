#ifndef __GF_ARRAY__
#define __GF_ARRAY__

#define MAX_ITEMS 200
#include <stdio.h>

class GFArray {
private:
	void *objs[MAX_ITEMS];
	int num_items;
protected:
public:
	GFArray() {
		num_items=0;
		for (int i=0; i<MAX_ITEMS; i++) 
			objs[i] = NULL;
	}
	~GFArray() {}
	inline int Length() { return num_items; }
	inline void Push(void *data) { addData(data); }
	inline void addData(void *data) { 
		if (num_items>=MAX_ITEMS) return;
		objs[num_items++]=data;
	}
	inline void setData(int id, void *data) { 
		if (id>=MAX_ITEMS) return;
		objs[id]=data;
	}
	inline void *Get(int id) { 
		return getData(id);
	}
	inline void *getData(int id) { 
		if (id>=num_items) return NULL;
		return objs[id];
	}
	inline void deleteData(int id) {
		if (id>=num_items) return;		
		objs[id] = objs[num_items-1];
		objs[--num_items] = NULL;
	}
};

/*
class LinkedList {
	LinkedListItem *firstitem;
	LinkedList() {
		firstitem = null;
	}
	~LinkedList() {}

};

class LinkedListItem {
private:
	void *obj;
	LinkedListItem *nextitem;
public:
	LinkedListItem() {
		nextitem=null;
		obj=null;
	}
	~LinkedListItem() {}
	inline void setData(void *obj) { this->obj = obj; }
	inline void *getData() { return obj; }
	inline void setNext(LinkedListItem *next) { this->nextitem = next; }
	inline LinkedListItem *getNext() { return nextitem; }
};
*/

#endif //__GF_ARRAY__
