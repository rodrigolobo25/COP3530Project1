#include "main.h"
#include <iostream>
#include <string>

using namespace std;
using std::string;

node::node(string line, node* next) {

	this->line = line;
	this->next = next;
}
void list::insertEnd(string text) {
	node* p = new node(text, NULL);
	if (head->next == NULL)
		head->next = p;
	else
		last->next->next = p;
	last->next = p;
}

void list::insert(int index, string text){
	temp = head->next;
	if (index == 1) {
		node* p = new node(text, head);
		head = p;
		return;
	}
	while (index != 2) {
		if (temp->next == NULL) {
			return;
		}
		temp = temp->next;
		index--;
	}
	node* p = new node(text, temp->next);
	temp->next = p;
}

void list::dlete(int index){
	temp = head->next;
	int num = 2;
	if (index == 1){
		if (head->next == NULL) {
			return;
		}
		head->next = head->next->next;
		delete(temp);
		return;
	}
	while (num < index) {
		if (temp == NULL) {
			return;
		}
		temp = temp->next;
		num++;
	}

	if (temp == NULL || temp->next == NULL) {
		return;
	}

	node* p = temp->next;
	temp->next = p->next;
	delete(p);

}

void list::edit(int index, string text) {
	temp = head->next;
	int num = 1;
	if (index == 1) {
		node* p = new node(text, temp->next);
		delete(temp);
		head = p;
		return;
	}

	while (num+1 < index) {
		if (temp == NULL) {
			return;
		}
		temp = temp->next;
		num++;
	}

	if (temp == NULL) {
		return;
	}
	node* p = new node(text, temp->next->next);
	delete(temp->next);
	temp->next = p;
}


void list::print() {
	temp = head->next;
	int index = 1;
	while (temp != NULL)
	{
		cout<<index << " " << temp->line<<endl;
		temp = temp->next;
		index++;
	}
}

void list::search(string text) {
	
	temp = head->next;
	const char *search = text.c_str();
	int searchlength = strlen(search);
	int index = 1;
	bool exist = false;

	while (temp != NULL) {

		const char *line = temp->line.c_str();
		int lineLength = strlen(line);
		bool x = false;

		for (int i = 0; i < lineLength; i++) 
			if (line[i] == search[0] && i+searchlength <= lineLength && x == false)
				for (int j = 1; j < searchlength; j++) {

					if (line[i + j] == search[j]) {
						x = true;
					}
					else {
						x = false;
						break;
					}
						
				}
		if (x){
			cout << index << " " << temp->line << endl;
			exist = true;
		}
		

		index++;

		temp = temp->next;

	}
	if (!exist)
		cout << "not found" << endl;
}

bool list::quit() {
	return false;
}



int main() {

	bool x = true;
	list* thelist = new list();

	while (x) {

		int index;
		string input;
		string text = "";
		getline(cin, input);

		const char *line = input.c_str();
		int linelength = strlen(line);
		

		if (line[0] == 'i' && line[1] == 'n' && line[2] == 's' && line[3] == 'e' && line[4] == 'r' && line[5] == 't' && line[6] == 'E' && line[7] == 'n' && line[8] == 'd') {

			for (int i = 11; i < linelength - 1; i++) 
				text = text + line[i];

			thelist->insertEnd(text);

			
		}
		else if (line[0] == 'i' && line[1] == 'n' && line[2] == 's' && line[3] == 'e' && line[4] == 'r' && line[5] == 't'){

			int start = 7;
			string indexstr = "";

			while (isdigit(line[start])) {

				indexstr = indexstr + line[start];
				start++;
			}

			index = atoi(indexstr.c_str());                  //convert a string to an int

			for (int i = start + 2; i < linelength - 1; i++)
				text = text + line[i];

			thelist->insert(index, text);

		}
		else if (line[0] == 'd' && line[1] == 'e' && line[2] == 'l' && line[3] == 'e' && line[4] == 't' && line[5] == 'e') {

			int start = 7;
			string indexstr = "";

			while (isdigit(line[start])) {

				indexstr = indexstr + line[start];
				start++;
			}

			index = atoi(indexstr.c_str());                  //convert a string to an int

			thelist->dlete(index);

		}
		else if (line[0] == 'e' && line[1] == 'd' && line[2] == 'i' && line[3] == 't') {

			int start = 5;
			string indexstr = "";

			while (isdigit(line[start])) {

				indexstr = indexstr + line[start];
				start++;
			}

			index = atoi(indexstr.c_str());                  //convert a string to an int

			for (int i = start + 2; i < linelength - 1; i++)
				text = text + line[i];

			thelist->edit(index, text);

		}
		else if (line[0] == 'p' && line[1] == 'r' && line[2] == 'i' && line[3] == 'n' && line[4] == 't') {

			thelist->print();
		}
		else if (line[0] == 's' && line[1] == 'e' && line[2] == 'a' && line[3] == 'r' && line[4] == 'c' && line[5] == 'h') {

			for (int i = 8; i < linelength - 1; i++)
				text = text + line[i];

			thelist->search(text);

		}
		else if (line[0] == 'q' && line[1] == 'u' && line[2] == 'i' && line[3] == 't') {

			x = thelist->quit();

		}
	}
	return 0;
	
}

