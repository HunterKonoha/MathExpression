#include "MathFunction.h"
#include "../../Functions.h"
#include <cmath>
#include <boost\multiprecision\cpp_dec_float.hpp>
#include <boost\math\constants\constants.hpp>

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Sin<T>::Sin(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Sin");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Sin<T>::~Sin() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Sin<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::sin(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Sin<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::sin(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Sin<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Sin<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Sin<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Cos<T>::Cos(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Cos");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Cos<T>::~Cos() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Cos<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::cos(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Cos<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::cos(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Cos<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Cos<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Cos<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Tan<T>::Tan(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Tan");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Tan<T>::~Tan() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Tan<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::tan(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Tan<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::tan(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Tan<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Tan<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Tan<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Radian<T>::Radian(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {


}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Radian");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Radian<T>::~Radian() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Radian<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument) / static_cast<T>(180.0)*boost::math::constants::pi<T>();
}
template paf::MathExpression::ExpValueClass::MathFunction::Radian<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Radian<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Radian<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Angle<T>::Angle(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Angle");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Angle<T>::~Angle() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Angle<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return this->GetNode(0)->ExpEval(Argument, VecArgument)*static_cast<T>(180.0) / boost::math::constants::pi<T>();
}
template paf::MathExpression::ExpValueClass::MathFunction::Angle<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Angle<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Angle<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcSin<T>::ArcSin(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Arcsin");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcSin<T>::~ArcSin() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::ArcSin<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::asin(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::ArcSin<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::asin(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::ArcSin<int>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcSin<double>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcSin<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcCos<T>::ArcCos(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Arccos");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcCos<T>::~ArcCos() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::ArcCos<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::acos(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::ArcCos<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::acos(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::ArcCos<int>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcCos<double>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcCos<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcTan<T>::ArcTan(TreeType Argument) try:ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "ArcTan");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::ArcTan<T>::~ArcTan() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::ArcTan<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::atan(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::ArcTan<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::atan(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::ArcTan<int>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcTan<double>;
template paf::MathExpression::ExpValueClass::MathFunction::ArcTan<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Ln<T>::Ln(TreeType Argument)try :ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Ln");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Ln<T>::~Ln() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Ln<T>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return std::log(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Ln<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::log(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Ln<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Ln<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Ln<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Log10<T>::Log10(TreeType Argument)try :ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Log10");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Log10<T>::~Log10() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Log10<T>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return std::log10(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Log10<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return boost::multiprecision::log10(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Log10<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Log10<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Log10<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Log<T>::Log(TreeType Argument)try :ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Log");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Log<T>::~Log() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Log<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::log(this->GetNode(1)->ExpEval(Argument, VecArgument)) / std::log(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Log<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return  (boost::multiprecision::log(this->GetNode(1)->ExpEval(Argument, VecArgument)) / boost::multiprecision::log(this->GetNode(0)->ExpEval(Argument, VecArgument)));
}
template paf::MathExpression::ExpValueClass::MathFunction::Log<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Log<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Log<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Exp<T>::Exp(TreeType Argument)try :ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Exp");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Exp<T>::~Exp() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Exp<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::exp(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Exp<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return  boost::multiprecision::exp(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Exp<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Exp<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Exp<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Abs<T>::Abs(TreeType Argument)try :ExpValue<T>(Functions::CheckArgumentSize<1>(Argument)) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Abs");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::MathFunction::Abs<T>::~Abs() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::MathFunction::Abs<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::abs(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::MathFunction::Abs<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return  boost::multiprecision::abs(this->GetNode(0)->ExpEval(Argument, VecArgument));
}
template paf::MathExpression::ExpValueClass::MathFunction::Abs<int>;
template paf::MathExpression::ExpValueClass::MathFunction::Abs<double>;
template paf::MathExpression::ExpValueClass::MathFunction::Abs<boost::multiprecision::cpp_dec_float_100>;