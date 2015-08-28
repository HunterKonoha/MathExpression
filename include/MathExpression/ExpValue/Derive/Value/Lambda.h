#pragma once
#include "../../ExpValue.h"
#include <vector>
#include <string>

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      template<typename T>
      class Lambda :public ExpValue<T> {
        private:
          std::vector<std::string> argname_;

        public:
          Lambda(const std::vector<std::string>& ArgumentName, NodeType Exp);
          ~Lambda();
          T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
          const std::vector<std::string>& GetArgumentList();
      };
    }
  }
}