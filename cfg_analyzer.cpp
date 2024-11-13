#include "cfg_analyzer.h"
#include "parser.h"
#include "graph_generator.h"
#include "visualizer.h"
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/raw_ostream.h>

int main(int argc, const char** argv) {
    if (argc < 2) {
        llvm::errs() << "Usage: cfg_analyzer <filename>\n";
        return 1;
    }

    // Setup and run the Clang tooling to parse and analyze the code
    clang::tooling::runToolOnCodeWithArgs(new MyFrontendAction, argv[1], clang::tooling::ArgumentsAdjuster::getClangSyntaxOnlyAdjuster());
    return 0;
}
