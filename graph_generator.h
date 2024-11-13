#ifndef GRAPH_GENERATOR_H
#define GRAPH_GENERATOR_H
#include <clang/AST/Decl.h>
void generateCFG(const clang::FunctionDecl* function);
#endif
