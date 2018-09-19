#include "node.h"
#include <string>

using std::string;

node::node(string line, node* next) {

	this->line = line;
	this->next = next;
}