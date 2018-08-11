// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef JITTERY_SYMBOL_H
#define JITTERY_SYMBOL_H

#include <string>

namespace jit
{
    template<typename T>
    class Symbol
    {
    public:
        explicit Symbol(const std::string &name, T value) {
            this->name += name;
            this->value = value;
        }

        const std::string &GetName() const {
            return name;
        }

        T GetValue() {
            return value;
        }

        void SetValue(T value) {
            this->value = value;
        }

        bool IsImmutable() const {
            return immutable;
        }

        void MarkAsImmutable() {
            immutable = true;
        }

    private:
        bool immutable = false;
        std::string name;
        T value;
    };
}

#endif //JITTERY_SYMBOL_H