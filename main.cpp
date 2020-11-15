#include"main.tab.hh"
#include<iostream>
#include"common.h"
using std::cout;
using std::endl;
TreeNode *root=nullptr;
int main ()
{
    yyparse();
    if(root!=nullptr){
        root->genNodeId();
        root->printAST();
    }
}
int yyerror(char const* message)
{
  cout << message << endl;
  return -1;
}