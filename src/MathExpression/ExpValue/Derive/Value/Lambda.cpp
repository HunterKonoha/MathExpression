#include "Lambda.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::Lambda<T>::Lambda(const std::vector<std::string>& ArgumentName, NodeType Exp) :ExpValue<T>({ Exp }), argname_(ArgumentName) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Lambda<T>::~Lambda() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Lambda<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument);
}
template<typename T>
const std::vector<std::string>& paf::MathExpression::ExpValueClass::Lambda<T>::GetArgumentList() {
  return this->argname_;
}
template paf::MathExpression::ExpValueClass::Lambda<int>;
template paf::MathExpression::ExpValueClass::Lambda<double>;
template paf::MathExpression::ExpValueClass::Lambda<boost::multiprecision::cpp_dec_float_100>;