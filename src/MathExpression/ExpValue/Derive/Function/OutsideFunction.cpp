#include "OutsideFunction.h"
#include "../../../MathExpression.h"
#include "../../../MathExpressionException.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::OutsideFunction<T>::OutsideFunction(TreeType Argument,const std::string& FunctionName, const PreArgument<T>& PreArgument) :ExpValue<T>(Argument), func_(PreArgument.GetFunction(FunctionName)) {
  if (this->GetNodeSize() != this->func_.first.size())throw MathExpessionException("引数の数が一致しません。\n指定された引数の数は" + std::to_string(this->func_.first.size()) + "ですが、渡された数は" + std::to_string(this->GetNodeSize()) + "でした。\問題の関数は" + FunctionName + "です。");
}
template<typename T>
paf::MathExpression::ExpValueClass::OutsideFunction<T>::~OutsideFunction() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::OutsideFunction<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  std::unordered_map<std::string, T> arg;
  for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
    arg[this->func_.first[i]] = this->GetNode(i)->ExpEval(Argument, VecArgument);
  }
  return this->func_.second.Calc(arg, VecArgument);
}
template<typename T>
bool paf::MathExpression::ExpValueClass::OutsideFunction<T>::IsConstValue() {
  return false;
}
template paf::MathExpression::ExpValueClass::OutsideFunction<int>;
template paf::MathExpression::ExpValueClass::OutsideFunction<double>;
template paf::MathExpression::ExpValueClass::OutsideFunction<boost::multiprecision::cpp_dec_float_100>;