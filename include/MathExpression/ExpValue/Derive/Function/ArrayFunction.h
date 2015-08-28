#pragma once
#include "..\..\ArrayEval.h"
#include "..\Value\Lambda.h"

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      namespace ArrayFunction {
        template<typename T>
        class Select :public ArrayEval<T> {
          private:
            std::shared_ptr<ExpValueClass::Lambda<T>> lambda;

          public:
            Select(TreeType Node, NodeType Func);
            ~Select();
            std::vector<T> VecEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
            T GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index)override;
        };

        template<typename T>
        class Adapt :public ArrayEval<T> {
          private:
            std::shared_ptr<ExpValueClass::Lambda<T>> lambda;

          public:
            Adapt(TreeType Node, NodeType Func);
            ~Adapt();
            std::vector<T> VecEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
            T GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index)override;
        };

        template<typename T>
        class Fold :public ArrayValue<T> {
          private:
            std::shared_ptr<ExpValueClass::Lambda<T>> lambda;

          public:
            Fold(TreeType Node, NodeType Func);
            ~Fold();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };
      }
    }
  }
}