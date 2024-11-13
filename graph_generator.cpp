// graph_generator.cpp
#include "graph_generator.h"
#include <clang/Analysis/CFG.h>
#include <llvm/Support/raw_ostream.h>

void generateCFG(const clang::FunctionDecl* function) {
    const clang::CFG* cfg = clang::CFG::buildCFG(function, function->getBody(), function->getASTContext(), clang::CFG::BuildOptions());
    if (!cfg) return;

    for (const auto* block : *cfg) {
        llvm::outs() << "Block: " << block->getBlockID() << "\n";
        for (auto& element : *block) {
            if (const clang::CFGStmt* stmt = element.getAs<clang::CFGStmt>()) {
                stmt->getStmt()->dump();
            }
        }
    }
}
