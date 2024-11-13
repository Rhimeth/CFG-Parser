#ifndef VISUALIZER_H
#define VISUALIZER_H
#include <clang/Analysis/CFG.h>
void exportToDot(const clang::CFG* cfg, const std::string& filename);
#endif