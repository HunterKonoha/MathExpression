#include "PreArgument.h"
#include "MathExpression.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::PreArgument<T>::PreArgument() {

}
template<typename T>
paf::MathExpression::PreArgument<T>::PreArgument(const StringVectorPair<MathExpression<T>>& VariableList) {
  this->AddVariable(VariableList);
}
template<typename T>
paf::MathExpression::PreArgument<T>::PreArgument(const Function& FuncList) {
  this->AddFunction(FuncList);
}
template<typename T>
paf::MathExpression::PreArgument<T>::PreArgument(const StringVectorPair<MathExpression<T>>& VariableList, const Function& FuncList) {
  this->AddVariable(VariableList);
  this->AddFunction(FuncList);
}
template<typename T>
void paf::MathExpression::PreArgument<T>::AddVariable(const std::string& Name, const MathExpression<T>& Variable) {
  this->variable_.insert({ Name, Variable });
}
template<typename T>
void paf::MathExpression::PreArgument<T>::AddVariable(const StringVectorPair<MathExpression<T>>& VariableList) {
  for (auto& val : VariableList) {
    this->variable_.insert(val);
  }
}
template<typename T>
void paf::MathExpression::PreArgument<T>::AddFunction(const std::string& Name, const std::vector<std::string>& ArgumentNameList, const MathExpression<T>& Argument) {
  this->func_.insert({ Name,{ArgumentNameList,Argument} });
}
template<typename T>
void paf::MathExpression::PreArgument<T>::AddFunction(const Function& FuncList) {
  for (auto& val : FuncList) {
    this->func_.insert({ val.first, val.second });
  }
}
template<typename T>
bool paf::MathExpression::PreArgument<T>::ExistVariable(const std::string& Name)const {
  return this->variable_.find(Name) != this->variable_.end();
}
template<typename T>
bool paf::MathExpression::PreArgument<T>::ExistFunction(const std::string& Name)const {
  return this->func_.find(Name) != this->func_.end();
}
template<typename T>
const paf::MathExpression::MathExpression<T>& paf::MathExpression::PreArgument<T>::GetVariable(const std::string& Name)const {
  return this->variable_.at(Name);
}
template<typename T>
const std::pair<std::vector<std::string>, const paf::MathExpression::MathExpression<T>&>& paf::MathExpression::PreArgument<T>::GetFunction(const std::string& Name)const {
  return this->func_.at(Name);
}
template paf::MathExpression::PreArgument<int>;
template paf::MathExpression::PreArgument<double>;
template paf::MathExpression::PreArgument<boost::multiprecision::cpp_dec_float_100>;