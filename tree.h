#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

enum NodeType{
    NODE_CONST,
    NODE_BOOL,
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,
    NODE_STMT,
    NODE_PROG,
    NODE_OP
};

enum StmtType{
    STMT_IF,
    STMT_WHILE,
    STMT_DECL,
    STMT_ASSIGN,
    STMT_PRINTF,
    STMT_SCANF
};

enum OpType{
    OP_EQUAL,
    OP_NOT,
    OP_ADD,
};

enum VarType{
    VAR_INTEGER,
    VAR_VOID
};

struct TreeNode {
    int nodeID;
    NodeType nodeType;

    TreeNode *child = nullptr;
    TreeNode *sibling = nullptr;

    void addChild(TreeNode *);
    void addSibling(TreeNode *);

    void genNodeId();//从根节点开始逐个赋Id 实现方式同学们可以自行修改

    void printAST();//打印语法树结点
    /***
     * 以下的几个函数皆为在printAST过程中辅助输出使用
     * 同学们可以根据需要自己使用其他方法
    ***/
    void printNodeInfo();
    void printNodeConnection();
    string nodeTypeInfo();

    int int_val;
    bool bool_val;
    StmtType stmtType;
    OpType opType;
    VarType varType;
    string var_name;

    TreeNode(NodeType type);
};
#endif