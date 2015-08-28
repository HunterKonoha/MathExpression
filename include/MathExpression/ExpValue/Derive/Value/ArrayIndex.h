#pragma once
#include "../../ArrayValue.h"

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      template<typename T>
      class ArrayIndex :public ArrayValue<T> {
        private:
          int index_;

        public:
          ArrayIndex(NodeType Array, int Index);
          ~ArrayIndex();
          T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
      };
    }
  }
}