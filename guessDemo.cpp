#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

#include "binary_tree.h"

using namespace std;

int main(){
	char contin, again = 'y';
	string filename;
	string name;
	binary_tree t1;

	cout << "Are you a continuing player? y or n" << endl;
	cin >> contin;


	while(contin != 'y' && contin != 'n'){
		cout << "Invalid entry. Please enter either a lowercase y, or lowercase n." << endl;
		cout << "Are you a continuing player?" << endl;
		cin >> contin;
	}

	if(contin == 'y'){
		cout << "Enter your name in the format provided, all lowercase. lastname_firstname " << endl;
		cin >> name;
		filename = name_to_filename(name);
		t1 = t1.read(filename.c_str());
}

	if(contin == 'n'){
		cout << "Welcome to guess the animal. The first step of teaching computers how to kill you." << endl;
		cout<< "Please enter your name in the format provided, all lowercase. lastname_firstname " << endl;
		cin >> name;
		filename = name_to_filename(name);
		t1.addRoot("Elephant");
}


	while (again == 'y'){
		again = 'n';
		t1.question(again);
		t1.write(filename.c_str());
	}	
	
	t1.print(cout);

	return 0;
}
