#pragma once
#include "ArrayValue.h"

namespace paf {
  namespace MathExpression {
    template<typename T>
    class ArrayEval :public ArrayValue<T> {
      private:

      public:
        ArrayEval(TreeType Node, NodeType Func);
        virtual  ~ArrayEval();
        virtual std::vector<T> VecEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {}) = 0;
        virtual T GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index) = 0;
    };
  }
}