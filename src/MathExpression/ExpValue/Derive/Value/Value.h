#pragma once
#include "../../ExpValue.h"

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      template<typename T>
      class Value :public ExpValue<T> {
        private:
          T value_;

        public:
          Value(T Value);
          ~Value();
          T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
      };
    }
  }
}