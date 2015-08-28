#pragma once
#include "../../ExpValue.h"
#include "../../../PreArgument.h"
#include <string>

namespace paf {
  namespace MathExpression {
    template<typename T>
    class MathExpression;

    namespace ExpValueClass {
      template<typename T>
      class Variable :public ExpValue<T> {
        private:
          std::string name_;
          const MathExpression<T>* argvalue_;

        public:
          Variable(const std::string& Value, const PreArgument<T>& Argument);
          ~Variable();
          bool IsConstValue();
          T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
      };
    }
  }
}