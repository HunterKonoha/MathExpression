#include "Variable.h"
#include "../../../MathExpression.h"
#include "../../../MathExpressionException.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::Variable<T>::Variable(const std::string& Value,const PreArgument<T>& Argument) :ExpValue<T>({}), name_(Value),argvalue_(Argument.ExistVariable(this->name_)?&Argument.GetVariable(this->name_):nullptr) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Variable<T>::~Variable() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Variable<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  auto variable = Argument.find(this->name_);
  if (variable != Argument.end()) {
    return variable->second;
  }
  else if (this->argvalue_ != nullptr) {
    return this->argvalue_->Calc(Argument,VecArgument);
  }
  else throw MathExpessionException("指定された変数が存在しません。\n指定された変数名は" + this->name_ + "です。");
}
template<typename T>
bool paf::MathExpression::ExpValueClass::Variable<T>::IsConstValue() {
  return false;
}
template paf::MathExpression::ExpValueClass::Variable<int>;
template paf::MathExpression::ExpValueClass::Variable<double>;
template paf::MathExpression::ExpValueClass::Variable<boost::multiprecision::cpp_dec_float_100>;