#pragma once

#include <cstddef>

template< typename T >
class List {
private:
	struct Node;
public:
	class Iterator {
	public:
		Iterator(Node* node) : m_node(node) { }

		bool operator == ( const Iterator& other ) const {
			if( this == &other ) return true;
			return m_node == other.m_node;
		}

		bool operator != ( const Iterator& other ) const {
			return !operator == ( other );
		}


		T operator*() const {
			if (m_node) return m_node->m_t;
			return T();
		}

		void operator++() {
			if (m_node) m_node = m_node->m_next;
		}
private:
    Node* m_node;
};
public:
	List() : m_head( NULL ) { };
	~List() { while( m_head ) remove(); };

	void append(const T& t);
	void remove();
	
	T head() const { return m_head->m_t; };
	Iterator begin() const { return Iterator(m_head); };
	Iterator end() const { return Iterator(NULL); };
	size_t size() const;
private:
	struct Node {
		Node() : m_next(NULL) { }
		Node(const T& t) : m_t(t), m_next(NULL) { }
		T m_t;
		Node* m_next;
	};

	Node* m_head;
};

template< typename T >
void List< T >::append(const T &t) {
	if( Node* node = new Node(t) ) {
		node->m_next = m_head;
		m_head = node;
	}
}

template< typename T >
void List< T >::remove() {
	if( m_head ) {
		Node* newHead = m_head->m_next;
		delete m_head;
		m_head = newHead;
	}
}

template< typename T >
size_t List< T >::size() const {
	size_t s = 0;
	for( Iterator it = begin(); it != end(); ++it ) ++s;

	return s;
}