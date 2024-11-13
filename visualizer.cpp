// visualizer.cpp
#include "visualizer.h"
#include <fstream>
#include <clang/Analysis/CFG.h>

void exportToDot(const clang::CFG* cfg, const std::string& filename) {
    std::ofstream file(filename);
    file << "digraph CFG {\n";
    for (const auto* block : *cfg) {
        for (auto succ : block->succs()) {
            if (succ) {
                file << "  " << block->getBlockID() << " -> " << succ->getBlockID() << ";\n";
            }
        }
    }
    file << "}\n";
}
