#pragma once
#include "ExpValue.h"

namespace paf {
  namespace MathExpression {
    template<typename T>
    class ArrayEval;

    template<typename T>
    class ArrayValue :public ExpValue<T> {
      public:
        using ArrayFunc = std::shared_ptr<ArrayEval<T>>;

      private:
        ArrayFunc func_;

      protected:


      public:
        ArrayValue(TreeType Exp, NodeType Func);
        virtual ~ArrayValue();
        virtual T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        bool IsAllofConstValue();
        ArrayFunc GetArrayFunc();
    };
  }
}