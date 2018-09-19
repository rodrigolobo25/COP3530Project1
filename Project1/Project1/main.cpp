#include "main.h"
#include "list.h"
#include <iostream>
#include <string>

using namespace std;

void main() {

	bool x = true;
	
	 

	while (x) {

		int index;
		string input;
		string text = "";
		getline(cin, input);

		const char *line = input.c_str();
		int linelength = strlen(line);

		list* thelist = new list();

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

			for (int i = start + 1; i < linelength - 1; i++)
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

			for (int i = start + 1; i < linelength - 1; i++)
				text = text + line[i];

			thelist->edit(index, text);

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
	
}

