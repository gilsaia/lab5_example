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

    void printNodeInfo();
    void printAST();
    void printNodeConnection();
    void genNodeId();

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