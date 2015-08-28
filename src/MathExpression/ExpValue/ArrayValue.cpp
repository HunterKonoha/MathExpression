#include "ArrayValue.h"
#include "ArrayEval.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ArrayValue<T>::ArrayValue(TreeType Exp, std::shared_ptr<ExpValue<T>> Func) :ExpValue<T>(Exp), func_(std::dynamic_pointer_cast<ArrayEval<T>>(Func)) {
  if (Func != nullptr&&std::dynamic_pointer_cast<ArrayEval<T>>(Func) == nullptr) {
    throw - 1;
  }
}
template<typename T>
paf::MathExpression::ArrayValue<T>::~ArrayValue() {


}
template<typename T>
std::shared_ptr<paf::MathExpression::ArrayEval<T>> paf::MathExpression::ArrayValue<T>::GetArrayFunc() {
  return this->func_;
}
template<typename T>
T paf::MathExpression::ArrayValue<T>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  throw - 1;
}
template<typename T>
bool paf::MathExpression::ArrayValue<T>::IsAllofConstValue() {
  if (!ExpValue<T>::IsAllofConstValue())return false;
  if (this->func_ != nullptr) {
    if (!this->func_->IsAllofConstValue())return false;
  }
  return true;
}
template paf::MathExpression::ArrayValue<int>;
template paf::MathExpression::ArrayValue<double>;
template paf::MathExpression::ArrayValue<boost::multiprecision::cpp_dec_float_100>;