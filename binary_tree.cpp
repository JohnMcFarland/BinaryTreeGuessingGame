#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "binary_tree.h"

using namespace std;

binary_tree::binary_tree() : root(0) {}

void binary_tree::addRoot(const string &data) {root = new node(data);}

void binary_tree::addLeft(node *nd, const string &data) {
    if (nd == 0) throw "Attempt addLeft on null";
    if (nd->left != 0) throw "Attempt addLeft on nd with existing left child";
    nd->left = new node(data);
}

void binary_tree::addRight(node *nd, const string &data) {
    if (nd == 0) throw "Attempt addRight on null";
    if (nd->right != 0) throw "Attempt addRight on nd with existing right child";
    nd->right = new node(data);
}

typename binary_tree::node *binary_tree::getRoot() {return root;}

bool binary_tree::isEmpty() {return root == 0;}

void binary_tree::print(std::ostream &os)  {print(os, root, 0);}

void binary_tree::print(std::ostream &os, node *nd, int indent) {
    if (nd == 0) return;
    os << string(indent*3, ' ') << nd->data << endl;
    print(os, nd->left, indent+1);
    print(os, nd->right, indent+1);
}

binary_tree binary_tree::read(const char *filename) {
    binary_tree tree;
    std::ifstream ifs(filename);

    if (!ifs) {
        std::cerr << "*** Warning " << filename << " not found -- starting with new tree" << std::endl;
        return tree;
    }
    tree.root = read(ifs);
    return tree;
    
}

typename binary_tree::node *binary_tree::read(std::ifstream &ifs) {
    string line;
    if (getline(ifs, line))
        if (line == "")
            return 0;
        else {
            int pos = line.find_first_not_of(' ');
            if (pos != string::npos)
                line = line.substr(pos);
            node *nd = new node(line);
            nd->left = read(ifs);
            nd->right = read(ifs);
            return nd;
        }
}

void binary_tree::write(const char *filename) {
    ofstream ofs(filename);

    if (!ofs) {
    		ostringstream oss;
		oss << filename  << " could not be opened for output";
		throw oss.str();
        return;
    }

    write(ofs, root, 0);
    ofs.close();
}

void binary_tree::write(ofstream &ofs, node *nd, int depth) {
    if (nd == 0) {
        ofs << "" << endl;
        return;
    }
    for (int i = 0; i < depth; i++)
        ofs << ' ';
    ofs << nd->data << endl;
    write(ofs, nd->left, depth+1);
    write(ofs, nd->right, depth+1);
}

binary_tree::node::node(const string &data) : data(data), left(0), right(0) {}


string name_to_filename(string name){
	string file;
	ostringstream oss;
	oss << name << ".txt";
	file = oss.str();
	return file;
}


void binary_tree::question(char& again){
	question(root, 0, again);
}

void binary_tree::question(node* nd, int depth, char & again){
	char x;
	if (nd->left == 0 && nd->right == 0){
		cout << "Is your animal a/an " << nd->data << ". y or n"<< endl;
		cin >> x;
		cin.ignore();
		if( x == 'y'){
			cout << "Your animal is a/an "<< nd->data << "!" << endl;
			cout << "Would you like to play again? y or n " << endl;
			cin >> again;
						
			return;
		}else{
			string newQuestion, animal;
			cout << "What yes or no question would have helped?" << endl; 
			getline(cin, newQuestion);
			cout<<"Question asked: " << newQuestion << endl;
			cout << "What was your animal?" << endl;//!!
			getline(cin, animal);
			cout<<"Animal added: " << animal << endl;//!!
			addRight(nd, nd->data);
			addLeft(nd, animal);
			nd->data = newQuestion;
			cout << "Keep playing? y or n" << endl;
			cin >> again;
			return;
		}
	}else{
		cout << nd->data << endl;
		cin >> x;
		if( x == 'y'){
			question(nd->left,depth+1,again);
		}else{
			question(nd->right, depth+1, again); 
		}
	}
}	


