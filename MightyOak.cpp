#include <iostream>
#include <string>
using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) {
        this->name = name;
    }

    string get_name() const {
        return this->name;
    }
};

class Node {
private:
    Squirrel* squirrel;
    Node* left_child;
    Node* right_child;
public:
    Node(Squirrel* squirrel) : squirrel(squirrel), left_child(nullptr), right_child(nullptr) {}
    void set_left(Node* left) {
        left_child = left;
    }
    void set_right(Node* right) {
        right_child = right;
    }
    Node* left() const {
        return left_child;
    }
    Node* right() const {
        return right_child;
    }
    Squirrel* get_squirrel() const {
        return squirrel;
    }
};

void traverse_tree(Node* root) {
    if (root == nullptr) return;
    cout << root->get_squirrel()->get_name() << endl;
    traverse_tree(root->left());
    traverse_tree(root->right());
}

int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");
    Node* node_one = new Node(&cheeks);
    Node* node_two = new Node(&squeaks);
    Node* node_three = new Node(&fluffybutt);
    node_one->set_left(node_two);
    node_one->set_right(node_three);
    Node* retrieved_node_one = node_one->left();
    Node* retrieved_node_two = node_one->right();
    cout << "Left child of node_one: " << retrieved_node_one->get_squirrel()->get_name() << endl;
    cout << "Right child of node_one: " << retrieved_node_two->get_squirrel()->get_name() << endl;
    cout << "Tree traversal:" << endl;
    traverse_tree(node_one);
    delete node_one;
    delete node_two;
    delete node_three;
    return 0;
}
