#include "Value.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::Value<T>::Value(T Value) :ExpValue<T>({}), value_(Value) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Value<T>::~Value(){

}
template<typename T>
T paf::MathExpression::ExpValueClass::Value<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->value_;
}
template paf::MathExpression::ExpValueClass::Value<int>;
template paf::MathExpression::ExpValueClass::Value<double>;
template paf::MathExpression::ExpValueClass::Value<boost::multiprecision::cpp_dec_float_100>;