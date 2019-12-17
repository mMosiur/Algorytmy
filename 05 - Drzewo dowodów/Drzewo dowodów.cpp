#include <iostream>

typedef unsigned short ushort;
typedef unsigned int uint;

struct TreeNode {

	const uint category; // Index of this category
	TreeNode* left_child = nullptr; // First subcategory if this category
	TreeNode* right_sibling = nullptr; // Next category of the same depth as this one

	// Constructor, sets the category of the node
	TreeNode(uint t_category) : category(t_category) {}

	// Destructor, deletes the child node and next node on the same depth
	~TreeNode() {
		if (left_child) delete left_child;
		if (right_sibling) delete right_sibling;
	}

	// Returns the child of a given category
	// If the category does not exist, it creates one and returns it
	TreeNode* child_with_category(uint t_category) {
		if (left_child == nullptr) return left_child = new TreeNode(t_category);
		if (left_child->category == t_category) return left_child;
		TreeNode* pos = left_child;
		while (pos->right_sibling != nullptr) {
			pos = pos->right_sibling;
			if (pos->category == t_category) return pos;
		}
		return pos->right_sibling = new TreeNode(t_category);
	}
};

class Tree {

	TreeNode* const root; // Const pointer to the root of the tree

	// Adds all the necesary nodes and create a path of given length
	void add_entry(ushort entry_length) {
		TreeNode* pos = root;
		uint cat;
		while (entry_length-- != 0) {
			std::cin >> cat;
			pos = pos->child_with_category(cat);
		}
	}

	// Displays the node in preorder order: given node -> it's child -> it's sibling
	void display(TreeNode* subtree_root) {
		std::cout << subtree_root->category << " ";
		if (subtree_root->left_child) display(subtree_root->left_child);
		if (subtree_root->right_sibling) display(subtree_root->right_sibling);
	}

public:

	// Constructor, specifies how many entries the tree gets as input and sets the root to 0
	Tree(ushort nof_entries) : root(new TreeNode(0)) {
		ushort x;
		while (nof_entries-- != 0) {
			std::cin >> x;
			add_entry(x);
		}
	}

	// Destructor, deletes the root
	~Tree() {
		delete root;
	}

	// Displays the tree without displaying the root
	void display() {
		if (root->left_child) display(root->left_child);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);

	ushort n; // The number of entries
	std::cin >> n;

	Tree tree(n); // Create the tree of a given number of entries

	tree.display(); // Display the created tree

	return 0;
}