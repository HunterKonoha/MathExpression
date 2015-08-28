#include "Array.h"
#include "../../../MathExpression.h"
#include "../../../MathExpressionException.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::Array<T>::Array(const std::string& Name, TreeType ValueList, const PreArgument<T>& Argument) :ArrayEval<T>(ValueList, nullptr), name_(Name), argvalue_(Argument.ExistVariable(this->name_) ? &Argument.GetVariable(this->name_) : nullptr) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Array<T>::~Array() {

}
template<typename T>
std::vector<T> paf::MathExpression::ExpValueClass::Array<T>::VecEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  if (this->name_ != "") {
    auto value = VecArgument.find(this->name_);
    if (value == VecArgument.end()) {
      if (this->argvalue_ != nullptr) {
        return this->argvalue_->VecCalc(Argument, VecArgument);
      }
      else throw MathExpessionException("指定された配列変数が存在しません。\n指定された変数名は" + this->name_ + "です");
    }
    return value->second;
  }
  else {
    std::vector<T> value;
    value.reserve(this->GetNodeSize());
    for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
      value.push_back(this->GetNode(i)->ExpEval(Argument, VecArgument));
    }
    return value;
  }
}
template<typename T>
T paf::MathExpression::ExpValueClass::Array<T>::GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index) {
  if (this->name_ != "") {
    auto value = VecArgument.find(this->name_);
    if (value == VecArgument.end()) {
      if (this->argvalue_ != nullptr) {
        return this->argvalue_->VecCalc(Argument,VecArgument)[Index];
      }
      else throw MathExpessionException("指定された配列変数が存在しません。\n指定された変数名は" + this->name_ + "です");
    }
    return value->second[Index];
  }
  else {
    return this->GetNode(Index)->ExpEval(Argument, VecArgument);
  }
}
template<typename T>
bool paf::MathExpression::ExpValueClass::Array<T>::IsConstValue() {
  return false;
}
template paf::MathExpression::ExpValueClass::Array<int>;
template paf::MathExpression::ExpValueClass::Array<double>;
template paf::MathExpression::ExpValueClass::Array<boost::multiprecision::cpp_dec_float_100>;