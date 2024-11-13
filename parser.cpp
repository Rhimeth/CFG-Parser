// parser.cpp
#include "parser.h"
#include <clang/AST/AST.h>
#include <clang/AST/ASTConsumer.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <llvm/Support/raw_ostream.h>

class FunctionExtractor : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
    virtual void run(const clang::ast_matchers::MatchFinder::MatchResult& Result) override {
        if (const clang::FunctionDecl* funcDecl = Result.Nodes.getNodeAs<clang::FunctionDecl>("functionDecl")) {
            llvm::outs() << "Function: " << funcDecl->getNameInfo().getName().getAsString() << "\n";
            for (auto param : funcDecl->parameters()) {
                llvm::outs() << "  Param: " << param->getNameAsString() << "\n";
            }
        }
    }
};

void parseFunctions(clang::ASTContext& Context); {
    clang::ast_matchers::MatchFinder Finder;
    FunctionExtractor Extractor;
    Finder.addMatcher(clang::ast_matchers::functionDecl().bind("functionDecl"), &Extractor);
    Finder.matchAST(Context);
}
