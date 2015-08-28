#pragma once
#include "../../ExpValue.h"

namespace paf {
  namespace MathExpression {
    namespace ExpValueClass {
      namespace MathFunction {
        template<typename T>
        class Sin :public ExpValue<T> {
          public:
            Sin(TreeType Argument);
            ~Sin();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Cos :public ExpValue<T> {
          public:
            Cos(TreeType Argument);
            ~Cos();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Tan :public ExpValue<T> {
          public:
            Tan(TreeType Argument);
            ~Tan();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Radian :public ExpValue<T> {
          public:
            Radian(TreeType Argument);
            ~Radian();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };
        template<typename T>
        class Angle :public ExpValue<T> {
          public:
            Angle(TreeType Argument);
            ~Angle();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {});
        };

        template<typename T>
        class ArcSin :public ExpValue<T> {
          public:
            ArcSin(TreeType Argument);
            ~ArcSin();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class ArcCos :public ExpValue<T> {
          public:
            ArcCos(TreeType Argument);
            ~ArcCos();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class ArcTan :public ExpValue<T> {
          public:
            ArcTan(TreeType Argument);
            ~ArcTan();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Ln :public ExpValue<T> {
          public:
            Ln(TreeType Argument);
            ~Ln();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Log10 :public ExpValue<T> {
          public:
            Log10(TreeType Argument);
            ~Log10();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Log :public ExpValue<T> {
          public:
            Log(TreeType Argument);
            ~Log();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Exp :public ExpValue<T> {
          public:
            Exp(TreeType Argument);
            ~Exp();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };

        template<typename T>
        class Abs :public ExpValue<T> {
          public:
            Abs(TreeType Argument);
            ~Abs();
            T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {})override;
        };
      }
    }
  }
}