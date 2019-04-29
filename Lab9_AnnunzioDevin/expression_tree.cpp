#include "expression_tree.h"
#include <cassert>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

expression_tree::expression_tree (const std::string& op,
				  const expression_tree& left,
				  const expression_tree& right)
{
  assert ((op == "+") || (op == "*"));
  node = new binary_tree_node<std::string> (op, left.node,
					    right.node);
}

bool all_digits (const string& s)
// return whether all characters is s are digits
{
  size_t i = 0;
  while (i < s.length() && isdigit (s[i]))
    i++;
  return i == s.length();
}

expression_tree::expression_tree (const std::string& value)
{
  	
  node = new binary_tree_node<std::string>(value);
}

int toInt(string s){
// to be implemented
    int num;
    istringstream (s) >> num;
    return num;
}

int expression_tree::evaluate(const binary_tree_node<std::string>* head) const
{
    //to be implemented
    if(head-> left() == NULL)
    {
        return toInt(head->data());
    }

    int left = evaluate((head->left()));
    int right = evaluate(head-> right());

    if(head-> data() == "+")
        return left + right;
    else
        return left * right;
}
