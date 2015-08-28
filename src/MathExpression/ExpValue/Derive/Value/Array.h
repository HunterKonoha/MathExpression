#pragma once
#include "../../ArrayEval.h"
#include "../../../PreArgument.h"

namespace paf {
  namespace MathExpression {
    template<typename T>
    class MathExpression;

    namespace ExpValueClass {

      template<typename T>
      class Array :public ArrayEval<T> {
        private:
          std::string name_;
          const MathExpression<T>* argvalue_;

        public:
          Array(const std::string& Name, TreeType ValueList, const PreArgument<T>& Argument);
          ~Array();
          bool IsConstValue();
          std::vector<T> VecEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
          T GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index)override;
      };
    }
  }
}