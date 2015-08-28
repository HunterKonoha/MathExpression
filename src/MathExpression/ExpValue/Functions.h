#pragma once
#include <vector>
#include <string>
#include "../MathExpressionException.h"

namespace paf {
  namespace MathExpression {
    namespace Functions {
      template<typename T>
      T UnitConvert(const std::string& Value, const std::string& Real);
      template<typename T>
      T HexConvert(const std::string& Value, const std::string& Real);
      template<int ArgumentSize, class T>
      inline T CheckArgumentSize(const T& Argument) {
        if (ArgumentSize != -1 && Argument.size() != ArgumentSize) {
          throw MathExpessionException("関数の引数の数が一致しません。\n本来の引数の数は" + std::to_string(ArgumentSize) + "でしたが、渡された数は" + std::to_string(Argument.size()) + "でした。\n問題の関数は{Function}です。");
        }
        return Argument;
      }
    }
  }
}