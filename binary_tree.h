#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <fstream>
#include <string>

class binary_tree {
public:
	class node;
	binary_tree();
	void addRoot(const std::string &data);
	void addLeft(node *nd, const std::string &data);
	void addRight(node *nd, const std::string &data);

	node *getRoot();

	std::string get(node *node);
	bool isEmpty();

	void print(std::ostream &os=std::cout); 
	static binary_tree read(const char *filename);
	void write(const char *filename);
	void question(char& again);
private:
	void question(node* nd, int depth, char & again);
	void print(std::ostream &os, node *nd, int indent);
	static node *read(std::ifstream &ifs);
	void write(std::ofstream &ofs, node *nd, int depth);
	node *root;
};

struct binary_tree::node {
	node(const std::string &data);
	std::string data;
	node *left, *right;
};

std::string name_to_filename(std::string name);

#endif
