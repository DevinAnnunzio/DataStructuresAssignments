#include "bintree.h"
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout
#include <queue>


using namespace std;
using namespace main_savitch_10;

template <typename T>
void display_complete_tree(const binary_tree_node <T> *t) {
    if (t == NULL)
        return;

    queue<const binary_tree_node<T> *> q;

    q.push(t);

    while (q.empty() != true) {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;

        while (nodeCount > 0) {
            const binary_tree_node<T> *node = q.front();
            q.pop();

            if (!node) {
                cout << "null" << " ";
            } else {
                cout << node->data() << " ";
                if(node->left() != NULL)
                    q.push(node->left());
                if(node->right() != NULL)
                    q.push(node->right());
            }

            nodeCount--;
        }
        cout << endl;
    }
}
template <typename T>
binary_tree_node<T> *newNode(int data) {
    binary_tree_node<T> *temp = new binary_tree_node<T>();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main() {
    binary_tree_node <std::string> *root = new binary_tree_node<std::string>("M");
    binary_tree_node <std::string> *first = new binary_tree_node<std::string>("H");
    binary_tree_node <std::string> *second = new binary_tree_node<std::string>("T");
    binary_tree_node <std::string> *third = new binary_tree_node<std::string>("E",new binary_tree_node<std::string>("A"));
    binary_tree_node <std::string> *fourth = new binary_tree_node<std::string>("P",NULL,new binary_tree_node<std::string>("Q"));
    binary_tree_node <std::string> *fifth = new binary_tree_node<std::string>("W");
    first->set_left(third);
    second->set_left(fourth);
    second->set_right(fifth);
    root->set_left(first);
    root->set_right(second);
    display_complete_tree(root);
    return 0;}