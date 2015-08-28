#include "Operator.h"
#include <cmath>
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Add<T>::Add(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode, RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Add<T>::~Add() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Add<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) + this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Add<int>;
template paf::MathExpression::ExpValueClass::Operator::Add<double>;
template paf::MathExpression::ExpValueClass::Operator::Add<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Sub<T>::Sub(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode, RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Sub<T>::~Sub() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Sub<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) - this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Sub<int>;
template paf::MathExpression::ExpValueClass::Operator::Sub<double>;
template paf::MathExpression::ExpValueClass::Operator::Sub<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Mul<T>::Mul(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode, RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Mul<T>::~Mul() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Mul<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument)*this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Mul<int>;
template paf::MathExpression::ExpValueClass::Operator::Mul<double>;
template paf::MathExpression::ExpValueClass::Operator::Mul<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Div<T>::Div(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode, RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Div<T>::~Div() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Div<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) / this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Div<int>;
template paf::MathExpression::ExpValueClass::Operator::Div<double>;
template paf::MathExpression::ExpValueClass::Operator::Div<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Pow<T>::Pow(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode, RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Pow<T>::~Pow() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Pow<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::pow(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::Operator::Pow<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return boost::multiprecision::pow(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::Operator::Pow<int>;
template paf::MathExpression::ExpValueClass::Operator::Pow<double>;
template paf::MathExpression::ExpValueClass::Operator::Pow<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Surplus<T>::Surplus(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Surplus<T>::~Surplus() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Surplus<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) % this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template<>
double paf::MathExpression::ExpValueClass::Operator::Surplus<double>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::fmod(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::Operator::Surplus<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return boost::multiprecision::fmod(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::Operator::Surplus<int>;
template paf::MathExpression::ExpValueClass::Operator::Surplus<double>;
template paf::MathExpression::ExpValueClass::Operator::Surplus<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Equal<T>::Equal(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Equal<T>::~Equal() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Equal<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::abs(this->GetNode(0)->ExpEval(Argument, VecArgument) - this->GetNode(1)->ExpEval(Argument, VecArgument)) < DBL_EPSILON;
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::Operator::Equal<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return boost::multiprecision::abs(this->GetNode(0)->ExpEval(Argument, VecArgument) - this->GetNode(1)->ExpEval(Argument, VecArgument)) < DBL_EPSILON;
}
template paf::MathExpression::ExpValueClass::Operator::Equal<int>;
template paf::MathExpression::ExpValueClass::Operator::Equal<double>;
template paf::MathExpression::ExpValueClass::Operator::Equal<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::NotEqual<T>::NotEqual(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::NotEqual<T>::~NotEqual() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::NotEqual<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::abs(this->GetNode(0)->ExpEval(Argument, VecArgument) - this->GetNode(1)->ExpEval(Argument, VecArgument)) >= DBL_EPSILON;
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::Operator::NotEqual<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return boost::multiprecision::abs(this->GetNode(0)->ExpEval(Argument, VecArgument) - this->GetNode(1)->ExpEval(Argument, VecArgument)) >= DBL_EPSILON;
}
template paf::MathExpression::ExpValueClass::Operator::NotEqual<int>;
template paf::MathExpression::ExpValueClass::Operator::NotEqual<double>;
template paf::MathExpression::ExpValueClass::Operator::NotEqual<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Less<T>::Less(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Less<T>::~Less() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Less<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) < this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Less<int>;
template paf::MathExpression::ExpValueClass::Operator::Less<double>;
template paf::MathExpression::ExpValueClass::Operator::Less<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::LessEqual<T>::LessEqual(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::LessEqual<T>::~LessEqual() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::LessEqual<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) <= this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::LessEqual<int>;
template paf::MathExpression::ExpValueClass::Operator::LessEqual<double>;
template paf::MathExpression::ExpValueClass::Operator::LessEqual<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::Greater<T>::Greater(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::Greater<T>::~Greater() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::Greater<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) > this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::Greater<int>;
template paf::MathExpression::ExpValueClass::Operator::Greater<double>;
template paf::MathExpression::ExpValueClass::Operator::Greater<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::Operator::GreaterEqual<T>::GreaterEqual(NodeType LeftNode, NodeType RightNode) :ExpValue<T>({ LeftNode,RightNode }) {

}
template<typename T>
paf::MathExpression::ExpValueClass::Operator::GreaterEqual<T>::~GreaterEqual() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::Operator::GreaterEqual<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) >= this->GetNode(1)->ExpEval(Argument, VecArgument);
}
template paf::MathExpression::ExpValueClass::Operator::GreaterEqual<int>;
template paf::MathExpression::ExpValueClass::Operator::GreaterEqual<double>;
template paf::MathExpression::ExpValueClass::Operator::GreaterEqual<boost::multiprecision::cpp_dec_float_100>;