#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char c) {
  return (c == '+') || (c == '-');
}

bool isOpenParen(char c) {
  return c == '(';
}

bool isClosingParen(char c) {
  return c == ')';
}
// (,),+,-,0,1,...,9
string parse(string s) {
  stack<char> stack;
  string postfix = "";
  
  for (char c : s) {
    if (isOperator(c) || isOpenParen(c)) {
      stack.push(c);
    } else if (isClosingParen(c)) {
      while (!stack.empty() 
        && !isOpenParen(stack.top())) {
        postfix += stack.top();
        stack.pop();
      }
      stack.pop();
    } else {
      postfix += c;
    }
  }

  while (!stack.empty()) {
    postfix += stack.top();
    stack.pop();
  }

  return postfix;
}


int main() {
  // (2-2)+1
  // stack (   postfix 
  // stack (   postfix 2
  // stack (-  postfix 2
  // stack (-  postfix 22
  // stack     postfix 22-
  // stack +   postfix 22-
  // stack +   postfix 22-1
  // stack     postfix 22-1+

  // String building
  // string s = "";
  // s += "hello ";
  // s += "world";

  // cout << s << endl;

  // working witha stack
  // stack<char> stack;

  // stack.push('+')
  // char c = stack.top();
  // stack.pop()
  
  cout << parse("(2-2)+1");
}