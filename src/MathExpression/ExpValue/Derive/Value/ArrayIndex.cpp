#include "ArrayIndex.h"
#include "../../ArrayEval.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::ArrayIndex<T>::ArrayIndex(NodeType Array,int Index) :ArrayValue<T>({}, Array), index_(Index) {

}
template<typename T>
paf::MathExpression::ExpValueClass::ArrayIndex<T>::~ArrayIndex() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::ArrayIndex<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetArrayFunc()->GetVecValue(Argument, VecArgument, this->index_);
}
template paf::MathExpression::ExpValueClass::ArrayIndex<int>;
template paf::MathExpression::ExpValueClass::ArrayIndex<double>;
template paf::MathExpression::ExpValueClass::ArrayIndex<boost::multiprecision::cpp_dec_float_100>;