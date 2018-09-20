#include <string>
#include <iostream>


using std::string;

class node
{
public:

	string line;
	node* next;

	node(string line, node* next);


};

class list
{
public:
	
	node* last = new node("", NULL);
	node* head = new node("", last);
	node* temp = head;

	void insertEnd(string text);

	void insert(int index, string text);

	void dlete(int index);

	void edit(int index, string text);

	void print();

	void search(string text);

	bool quit();
};