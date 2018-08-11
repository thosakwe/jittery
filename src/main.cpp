// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <antlr4-runtime.h>
#include "frontend/frontend.h"
#include "jitter/jitter.h"

int main(int argc, const char **argv) {
    if (argc < 2) {
        std::cerr << "fatal error: no input file" << std::endl;
        return 1;
    } else {
        std::ifstream ifs(argv[1]);

        if (!ifs) {
            std::cerr << "fatal error: cannot read file " << argv[1] << std::endl;
            return 1;
        }

        antlr4::ANTLRInputStream inputStream(ifs);
        frontend::JitteryLexer lexer(&inputStream);
        antlr4::CommonTokenStream tokens(&lexer);
        frontend::JitteryParser parser(&tokens);

        auto *compilationUnit = parser.compilationUnit();

        if (compilationUnit == nullptr || parser.getNumberOfSyntaxErrors() > 0) {
            std::cerr << "fatal error: encountered errors while reading file  " << argv[1] << std::endl;
            return 1;
        }

        jit::Interpreter interpreter;
        const char *errorMessage = nullptr;

        if (!interpreter.LoadCompilationUnit(compilationUnit, &errorMessage)) {
            std::cerr << "fatal error: " << errorMessage << std::endl;
            return 1;
        }

        interpreter.Run(&errorMessage);
        return 0;
    }
}