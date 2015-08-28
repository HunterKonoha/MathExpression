#include "ArrayEval.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ArrayEval<T>::ArrayEval(TreeType Node, NodeType Func) :ArrayValue<T>(Node, Func) {

}
template<typename T>
paf::MathExpression::ArrayEval<T>::~ArrayEval() {

}
template paf::MathExpression::ArrayEval<int>;
template paf::MathExpression::ArrayEval<double>;
template paf::MathExpression::ArrayEval<boost::multiprecision::cpp_dec_float_100>;