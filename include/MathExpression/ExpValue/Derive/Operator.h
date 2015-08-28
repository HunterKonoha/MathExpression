#pragma once
#include "../ExpValue.h"

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      namespace Operator {
        template<typename T>
        class Add :public ExpValue<T> {
          public:
            Add(NodeType LeftNode, NodeType RightNode);
            ~Add();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Sub :public ExpValue<T> {
          public:
            Sub(NodeType LeftNode, NodeType RightNode);
            ~Sub();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Mul :public ExpValue<T> {
          public:
            Mul(NodeType LeftNode, NodeType RightNode);
            ~Mul();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Div :public ExpValue<T> {
          public:
            Div(NodeType LeftNode, NodeType RightNode);
            ~Div();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgumentv = {})override;
        };

        template<typename T>
        class Pow :public ExpValue<T> {
          public:
            Pow(NodeType LeftNode, NodeType RightNode);
            ~Pow();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Surplus :public ExpValue<T> {
          public:
            Surplus(NodeType LeftNode, NodeType RightNode);
            ~Surplus();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Equal :public ExpValue<T> {
          public:
            Equal(NodeType LeftNode, NodeType RightNode);
            ~Equal();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class NotEqual :public ExpValue<T> {
          public:
            NotEqual(NodeType LeftNode, NodeType RightNode);
            ~NotEqual();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Less :public ExpValue<T> {
          public:
            Less(NodeType LeftNode, NodeType RightNode);
            ~Less();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class LessEqual :public ExpValue<T> {
          public:
            LessEqual(NodeType LeftNode, NodeType RightNode);
            ~LessEqual();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Greater :public ExpValue<T> {
          public:
            Greater(NodeType LeftNode, NodeType RightNode);
            ~Greater();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class GreaterEqual :public ExpValue<T> {
          public:
            GreaterEqual(NodeType LeftNode, NodeType RightNode);
            ~GreaterEqual();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };
      }
    }
  }
}