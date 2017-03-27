#include <cstdio>

template<typename T>
class tqueue {
	struct node {
		T val;
		node* next;
	};
private:
	node* a, *b;
public:
	tqueue(void):a(NULL), b(NULL){}
	~tqueue() {
		this->clear();
	}
public:
	void push(const T& v) {
		node* n = new node();
		n->next = NULL;
		n->val  = v;
		if(a != NULL) {
			b->next = n;
			b = n;
		} else
			a = b = n;
	}

	void  pop(void){
		node* t = a;
		if(t != NULL){
			a = a->next;
			delete t;
		}
		if(a == NULL)
			b = NULL;
	}

	void clear(void){
		while(!empty())
			pop();
	}

	T& front(void) { return a->val; }
	T& front(void) const { return a->val; }

	bool empty(void) const {
		return (a == NULL);
	}
};