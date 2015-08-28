#include "ExpValue.h"
#include "Derive\Value\Value.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValue<T>::ExpValue(TreeType Node) :node_(Node) {
  node_.shrink_to_fit();
}
template<typename T>
paf::MathExpression::ExpValue<T>::~ExpValue() {
}
template<typename T>
T paf::MathExpression::ExpValue<T>::operator()(ArgumentType Argument) {
  return this->ExpEval(Argument);
}
template<typename T>
typename paf::MathExpression::ExpValue<T>::NodeType paf::MathExpression::ExpValue<T>::GetNode(std::size_t Index) {
  return this->node_[Index];
}
template<typename T>
std::size_t paf::MathExpression::ExpValue<T>::GetNodeSize() {
  return this->node_.size();
}
template<typename T>
void paf::MathExpression::ExpValue<T>::SetNode(TreeType Node) {
  this->node_ = Node;
}
template<typename T>
bool paf::MathExpression::ExpValue<T>::IsConstValue() {
  return true;
}
template<typename T>
void paf::MathExpression::ExpValue<T>::OptimizeExpression() {
  bool opti = true;
  for (auto& val : this->node_) {
    val->OptimizeExpression();
    if (val->IsAllofConstValue())val = NodeType(new ExpValueClass::Value<T>(val->ExpEval()));
  }
}
template<typename T>
bool paf::MathExpression::ExpValue<T>::IsAllofConstValue() {
  if (!this->IsConstValue())return false;
  for (auto& val : this->node_) {
    if (!val->IsAllofConstValue())return false;
  }
  return true;
}
template paf::MathExpression::ExpValue<int>;
template paf::MathExpression::ExpValue<double>;
template paf::MathExpression::ExpValue<boost::multiprecision::cpp_dec_float_100 >;