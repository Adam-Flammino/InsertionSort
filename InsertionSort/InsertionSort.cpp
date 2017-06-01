// InsertionSort.cpp 
// Adam Flammino 5/28 SDEV-345
// Insertion sort on a linked list

#include "stdafx.h"
#include <iostream>

class LinkedList {
	struct ListNode {
		double value;
		ListNode *next;
	public:
		ListNode(double x, ListNode *nextp = NULL) {
			value = x;
			next = nextp;
		}
	};
	ListNode *head;
public:
	// Constructor
	LinkedList() {
		head = NULL;
	}
	// Add to end of list
	void add(double x) {
		if (head == NULL) {
			head = new ListNode(x);
		}
		else {
			ListNode *last = head;
			while (last->next != NULL) {
				last = last->next;
			}
			last->next = new ListNode(x);
		}
	};

	// Sorts using insertion sort
	void insertionSort() {
		ListNode *nodePtr = head, *sort;
		double temp;
		while (nodePtr) {
			for (sort = nodePtr->next; sort; sort = sort->next) {
				if (nodePtr->value > sort->value) {
					temp = nodePtr->value;
					nodePtr->value = sort->value;
					sort->value = temp;
				}
			}
			nodePtr = nodePtr->next;
		}
	}

	// Prints list
	void print() {
		ListNode *nodePtr = head;
		while (nodePtr) {
			std::cout << nodePtr->value << std::endl;
			nodePtr = nodePtr->next;
		}
	}
};

int main()
{
	LinkedList linkedlist;
	linkedlist.add(23);
	linkedlist.add(54);
	linkedlist.add(2);
	linkedlist.add(8);
	linkedlist.add(3.2);
	linkedlist.add(14);
	linkedlist.add(43);
	linkedlist.add(0);
	linkedlist.add(9);
	linkedlist.add(2);
	linkedlist.insertionSort();
	linkedlist.print();
    return 0;
}
