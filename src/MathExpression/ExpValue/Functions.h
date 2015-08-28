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
          throw MathExpessionException("�֐��̈����̐�����v���܂���B\n�{���̈����̐���" + std::to_string(ArgumentSize) + "�ł������A�n���ꂽ����" + std::to_string(Argument.size()) + "�ł����B\n���̊֐���{Function}�ł��B");
        }
        return Argument;
      }
    }
  }
}