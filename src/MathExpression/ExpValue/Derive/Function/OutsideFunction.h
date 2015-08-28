#pragma once
#include "../../ExpValue.h"
#include "../../../PreArgument.h"

namespace paf {
  namespace MathExpression {
    template<typename T>
    class MathExpression;

    namespace ExpValueClass {
      template<typename T>
      class OutsideFunction :public ExpValue<T> {
        private:
          const std::pair<std::vector<std::string>, const MathExpression<T>&> func_;

        public:
          OutsideFunction(TreeType Argument, const std::string& FunctionName, const PreArgument<T>& PreArgument);
          ~OutsideFunction();
          bool IsConstValue();
          T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
      };
    }
  }
}