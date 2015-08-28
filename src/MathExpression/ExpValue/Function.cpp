#include "Functions.h"
#include <ctype.h>
#include <boost\lexical_cast.hpp>
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
T paf::MathExpression::Functions::UnitConvert(const std::string& Value, const std::string& Real) {
  T result(0);
  int i = 0;
  for (auto it = Value.rbegin(), end = Value.rend(); it != end; ++it) {
    result += boost::lexical_cast<T>(*it)*std::pow(2, i++);
  }
  i = 0;
  for (auto it = Real.begin(), end = Real.end(); it != end; ++it) {
    result += boost::lexical_cast<T>(*it)*std::pow(0.5, ++i);
  }
  return result;
}
template int paf::MathExpression::Functions::UnitConvert<int>(const std::string& Value, const std::string& Real);
template double paf::MathExpression::Functions::UnitConvert<double>(const std::string& Value, const std::string& Real);
template boost::multiprecision::cpp_dec_float_100 paf::MathExpression::Functions::UnitConvert<boost::multiprecision::cpp_dec_float_100>(const std::string& Value, const std::string& Real);

template<typename T>
T paf::MathExpression::Functions::HexConvert(const std::string& Value, const std::string& Real) {
  T result(0);
  std::locale loc;
  int i = 0;
  for (auto it = Value.rbegin(), end = Value.rend(); it != end; ++it) {
    if (std::isdigit(*it, loc))result += boost::lexical_cast<T>(*it)*std::pow(16, i++);
    else if (std::islower(*it, loc))result += (*it - 0x57)*std::pow(16, i++);
    else result += (*it - 0x37)*std::pow(16, i++);
  }
  i = 0;
  for (auto it = Real.begin(), end = Real.end(); it != end; ++it) {
    if (std::isdigit(*it, loc))result += boost::lexical_cast<T>(*it)*std::pow(1.0 / 16.0, ++i);
    else if (std::islower(*it, loc))result += (*it - 0x57)*std::pow(1.0 / 16.0, ++i);
    else result += (*it - 0x37)*std::pow(1.0 / 16.0, ++i);
  }
  return result;
}
template int paf::MathExpression::Functions::HexConvert<int>(const std::string& Value, const std::string& Real);
template double paf::MathExpression::Functions::HexConvert<double>(const std::string& Value, const std::string& Real);
template boost::multiprecision::cpp_dec_float_100 paf::MathExpression::Functions::HexConvert<boost::multiprecision::cpp_dec_float_100>(const std::string& Value, const std::string& Real);