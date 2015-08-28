#pragma once
#include "../../ArrayValue.h"
#include "../../ExpValue.h"
#include <vector>
#include <string>
#include <random>

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      namespace ExtendFunction {
        template<typename T, int ArgumentSize = -1>
        class Sum :public ArrayValue<T> {
          public:
            Sum(TreeType Node, NodeType Func = nullptr);
            ~Sum();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T, int ArgumentSize = -1>
        class Average :public ArrayValue<T> {
          public:
            Average(TreeType Node, NodeType Func = nullptr);
            ~Average();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T, int ArgumentSize = -1>
        class Min :public ArrayValue<T> {
          public:
            Min(TreeType Node, NodeType Func = nullptr);
            ~Min();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T, int ArgumentSize = -1>
        class Max :public ArrayValue<T> {
          public:
            Max(TreeType Node, NodeType Func = nullptr);
            ~Max();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class RealRand :public ExpValue<T> {
          private:
          std::mt19937 gen_;

          public:
            RealRand(TreeType Node);
            ~RealRand();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class IntRand :public ExpValue<T> {
          private:
          std::mt19937 gen_;

          public:
            IntRand(TreeType Node);
            ~IntRand();
            T ExpEval(ArgumentType Argumrnt = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T, int ArgumentSize = -1>
        class Std :public ArrayValue<T> {
          public:
            Std(TreeType Node, NodeType Func = nullptr);
            ~Std();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };
      }
    }
  }
}