#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include "ExpressionTree.h"


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::ExpressionTree(const string& infix)
  : tree(nullptr)
{
  cout << "Converting from infix   '" << infix << "' to postfix notation\n";
  string postfix = convertInfixToPostfix(infix);
  cout << "Converting from postfix '" << postfix << "' to expression tree\n";
  buildTreeFromPostfix(postfix);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
ExpressionTree::~ExpressionTree()
{
  clear(tree);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
bool ExpressionTree::isOperator(const string& s) const
{
  return s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")";
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int ExpressionTree::opPrecedence(const string& op1, const string& op2) const
{
  int op1Int = (op1 == "/" || op1 == "*") ? 1 : 0;
  int op2Int = (op2 == "/" || op2 == "*") ? 1 : 0;

  return op1Int - op2Int;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Be thankful that I didn't ask for this method in the assignment!
string ExpressionTree::convertInfixToPostfix(const string& infix) const
{
  stack<string> stack;
  vector<string> result;

  istringstream in(infix);
  for(string s; in >> s; )
  {
    if(!isOperator(s))
      result.push_back(s);
    else if(stack.empty() || stack.top() == "(")
      stack.push(s);
    else if(s == "(")
      stack.push(s);
    else if(s == ")")
    {
      while(stack.top() != "(")
      {
        result.push_back(stack.top());
        stack.pop();
      }
      stack.pop();
    }
    else  // look at precedence of operators
    {
      int precedence = opPrecedence(s, stack.top());
      if(precedence > 0)
        stack.push(s);
      else
      {
        result.push_back(stack.top());
        stack.pop();
        stack.push(s);
      }
    }
  }
  while(!stack.empty())
  {
    result.push_back(stack.top());
    stack.pop();
  }

  // Generate postfix form
  string postfix;
  for(const auto& s: result)
    postfix += s + " ";

  return postfix;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Create an expression tree from a postfix expression
// pre-condition:   a valid postfix expression (each part separated by space)
// post-condition:  'tree' points to a valid expression tree
void ExpressionTree::buildTreeFromPostfix(const string& postfix)
{
  /* Algorithm
      create a stack containing ExprNode pointers
      for each string 's' in the postfix expression
        create a new ExprNode containing 's'
        if 's' is an operand
          push the new node to the stack
        else if 's' is an operator
          pop two values from stack, make them children of the new node,
          and and push the node to the stack
        end if
      end for

      at the end, the stack contains one item; the expression tree
   */

  // FIXME - add your implementation of the algorithm here
  //         at the end, instance variable 'tree' must point to the
  //         expression tree you've created
  stack<ExprNode*> thing; //initialize stack pointer
  istringstream stri(postfix);
  string str;
  for( ;getline(stri, str, ' '); ){ //while reading from postfix
    ExprNode* newNode = new ExprNode(str);
    if(!isOperator(str)){
      thing.push(newNode);  //push to stack
    }
    else if(isOperator(str)){
      newNode->left=thing.top();  //read value on top
      thing.pop();  //pop from stack

      newNode->right=thing.top();
      thing.pop();
      tree = newNode; //set newNode as root
      thing.push(newNode);  //push newNode to stack
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Traverse the expression tree and generate the result
// pre-condition:   an expression tree already exists
//                  (ie, buildTreeFromPostfix() has already been called)
// post-condition:  the expression tree is traversed, and the final
//                  output calculated (the tree is not modified)
double ExpressionTree::evaluate(const ExprNode* root) const
{
  /* Algorithm
      if root is nullptr then return 0.0
      else perform a postorder traversal on the root

      if data at root is an operator
        let right operand be the evaluation of the left child of root
        let left operand be the evaluation of the right child of root
        return the result of combining the left and right children using that operator
      else
        return the data at root converted to a double (hint: use stod)
      end if
   */

  // FIXME - add your implementation of the algorithm here
  //         at the end, the final return value is the overall result
  if(root==nullptr){
    return 0;
  }
  else{
    if(isOperator(root->data)){
      double Left=evaluate(root->left); //RECURSIVE evaluate on left root
      double Right=evaluate(root->right); //RECURSIVE evaluate on right root
      if(root->data=="+"){
        return Left+Right;  //adds left and right
      }
      else if(root->data=="-"){
        return Right-Left;  //subs right and left
      }
      else if(root->data=="*"){
        return Left*Right; //multiplies left and right
      }
      else
        return Right/Left;  //divides right and left
    }
    else{
      return stod(root->data); //converts value to double
    }
  }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// Utility function to clear memory
void ExpressionTree::clear(ExprNode* root)
{
  // FIXME - add your implementation of the algorithm here
  //         what type of traversal would be needed to delete nodes??
    if(root->left!=nullptr){
      clear(root->left);  //clears left if not deleted
    }
    if(  root->right!=nullptr){
      clear(root->right); //clears right if not deleted
    }

      root=nullptr;
      delete root;  //deletes current node

}


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main(int ac, char* av[])
{
  ExpressionTree expr1("2 / ( 3 + 7 )");
  cout << "Final evaluation: " << expr1.evaluate() << endl;

  cout << endl;

  ExpressionTree expr2("2 / ( 3 - 7 ) * 5");
  cout << "Final evaluation: " << expr2.evaluate() << endl;
}
