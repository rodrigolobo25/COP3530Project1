#include "list.h"
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

void list::insertEnd(string text) {
	node* p = new node(text, NULL);
	last->next = p;
	last = p;
}

void list::insert(int index, string text){
	temp = head;
	if (index == 1) {
		node* p = new node(text, head);
		head = p;
		return;
	}
	while (index != 2) {
		temp = temp->next;
		index--;
	}
	node* p = new node(text, temp->next);
	temp->next = p;
}

void list::dlete(int index){
	temp = head;
	int num = 2;
	if (index == 1){
		head = head->next;
		delete(temp);
		return;
	}
	while (num != index) {
		temp = temp->next;
		num++;
	}
	node* p = temp->next;
	temp->next = p->next;
	delete(p);

}

void list::edit(int index, string text) {
	temp = head;
	int num = 2;
	if (index == 1) {
		node* p = new node(text, temp->next);
		delete(temp);
		head = p;
		return;
	}
	while (num != index + 1) {
		temp = temp->next;
		num++;
	}
	node* p = new node(text, temp->next->next);
	delete(temp->next);
	temp->next = p;
}

void list::print() {
	temp = head;
	int index = 1;
	while (temp->next != NULL)
	{
		cout<<index + " " + temp->line<<endl;
		temp = temp->next;
		index++;
	}
	cout << index + " " + temp->line << endl;
}

void list::search(string text) {
	

}