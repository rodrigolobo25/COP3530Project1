#include <iostream>
#include <string>
#include "node.h"
class list
{
public:
	node* head = new node("", NULL);
	node* temp = head;
	node* last = head;
	
	void insertEnd(string text);

	void insert(int index, string text);

	void dlete(int index);

	void edit(int index, string text);

	void print();

	void search(string text);

	bool quit();
};

	