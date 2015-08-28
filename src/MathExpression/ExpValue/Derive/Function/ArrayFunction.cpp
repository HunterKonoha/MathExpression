#include "ArrayFunction.h"
#include "../../Functions.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<int ArgumentSize,class T>
inline void CheckLambdaArgument(T Lambda) {
  if (Lambda->GetArgumentList().size() != ArgumentSize) {
    throw paf::MathExpression::MathExpessionException("ラムダ式の引数の数が一致しません。\n要求された数は2でしたが、渡された数は" + std::to_string(Lambda->GetArgumentList().size()) + "でした。\n問題の関数は{Function}です。");
  }
}

template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Select<T>::Select(TreeType Node, NodeType Func) :ArrayEval<T>({},Func) {
  try {
    Functions::CheckArgumentSize<1>(Node);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Select");
    throw;
  }
  this->lambda = std::dynamic_pointer_cast<ExpValueClass::Lambda<T>>(Node[0]);
  try {
    CheckLambdaArgument<2>(this->lambda);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Select");
    throw;
  }
}
template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Select<T>::~Select() {

}
template<typename T>
std::vector<T> paf::MathExpression::ExpValueClass::ArrayFunction::Select<T>::VecEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  std::unordered_map<std::string, T> arg(Argument);
  auto arglist = this->lambda->GetArgumentList();
  auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
  std::vector<T> result;
  for (int i = 0; i < vec.size(); ++i) {
    arg[arglist[0]] = vec[i];
    arg[arglist[1]] = static_cast<T>(i);
    if (std::abs(this->lambda->ExpEval(arg, VecArgument) - 1.0) < DBL_EPSILON) {
      result.push_back(vec[i]);
    }
  }
  return  result;
}
template<>
std::vector<boost::multiprecision::cpp_dec_float_100> paf::MathExpression::ExpValueClass::ArrayFunction::Select<boost::multiprecision::cpp_dec_float_100>::VecEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  std::unordered_map<std::string, boost::multiprecision::cpp_dec_float_100> arg(Argument);
  auto arglist = this->lambda->GetArgumentList();
  auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
  std::vector<boost::multiprecision::cpp_dec_float_100> result;
  for (int i = 0; i < vec.size(); ++i) {
    arg[arglist[0]] = vec[i];
    arg[arglist[1]] = i;
    if (boost::multiprecision::abs(this->lambda->ExpEval(arg, VecArgument) - 1.0) < DBL_EPSILON) {
      result.push_back(vec[i]);
    }
  }
  return  result;
}
template<typename T>
T paf::MathExpression::ExpValueClass::ArrayFunction::Select<T>::GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index) {
  std::unordered_map<std::string, T> arg(Argument);
  std::size_t count(0);
  auto arglist = this->lambda->GetArgumentList();
  auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
  for (int i = 0; i < vec.size(); ++i) {
    arg[arglist[0]] = vec[i];
    arg[arglist[1]] = static_cast<T>(i);
    if (std::abs(this->lambda->ExpEval(arg, VecArgument) - 1.0) < DBL_EPSILON) {
      if (count++ == Index)return vec[i];
    }
  }
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::ArrayFunction::Select<boost::multiprecision::cpp_dec_float_100>::GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index) {
  std::unordered_map<std::string, boost::multiprecision::cpp_dec_float_100> arg(Argument);
  std::size_t count(0);
  auto arglist = this->lambda->GetArgumentList();
  auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
  for (int i = 0; i < vec.size(); ++i) {
    arg[arglist[0]] = vec[i];
    arg[arglist[1]] = i;
    if (boost::multiprecision::abs(this->lambda->ExpEval(arg, VecArgument) - 1.0) < DBL_EPSILON) {
      if (count++ == Index)return vec[i];
    }
  }
}
template paf::MathExpression::ExpValueClass::ArrayFunction::Select<int>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Select<double>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Select<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<T>::Adapt(TreeType Node, NodeType Func) :ArrayEval<T>({}, Func) {
  try {
    Functions::CheckArgumentSize<1>(Node);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Adapt");
    throw;
  }
  this->lambda = std::dynamic_pointer_cast<ExpValueClass::Lambda<T>>(Node[0]);
  try {
    CheckLambdaArgument<2>(this->lambda);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Select");
    throw;
  }
}
template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<T>::~Adapt() {

}
template<typename T>
std::vector<T> paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<T>::VecEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  std::unordered_map<std::string, T> arg(Argument);
  std::vector<T> result(this->GetArrayFunc()->VecEval(Argument, VecArgument));
  std::size_t count(0);
  auto arglist = this->lambda->GetArgumentList();
  for (int i = 0; i < result.size(); ++i) {
    arg[arglist[0]] = result[i];
    arg[arglist[1]] = static_cast<T>(i);
    result[i] = this->lambda->ExpEval(arg, VecArgument);
  }
  return result;
}
template<typename T>
T paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<T>::GetVecValue(ArgumentType Argument, VectorArgumentType VecArgument, std::size_t Index) {
  std::unordered_map<std::string, T> arg(Argument);
  auto arglist = this->lambda->GetArgumentList();
  arg[arglist[0]] = this->GetArrayFunc()->GetVecValue(Argument, VecArgument, Index);
  arg[arglist[1]] = static_cast<T>(Index);
  return this->lambda->ExpEval(arg, VecArgument);
}
template paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<int>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<double>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Adapt<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Fold<T>::Fold(TreeType Node, NodeType Func) :ArrayValue<T>({}, Func) {
  try {
    Functions::CheckArgumentSize<1>(Node);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Fold");
    throw;
  }
  this->lambda = std::dynamic_pointer_cast<ExpValueClass::Lambda<T>>(Node[0]);
  try {
    CheckLambdaArgument<3>(this->lambda);
  }
  catch (MathExpessionException& e) {
    e.ReplaceMessage("{Function}", "Select");
    throw;
  }
}
template<typename T>
paf::MathExpression::ExpValueClass::ArrayFunction::Fold<T>::~Fold() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::ArrayFunction::Fold<T>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  auto vec = this->GetArrayFunc()->VecEval(Argument);
  auto arglist = this->lambda->GetArgumentList();
  std::unordered_map<std::string, T> arg(Argument);
  T result(0);
  for (int i = 0; i < vec.size(); ++i) {
    arg[arglist[0]] = result;
    arg[arglist[1]] = vec[i];
    arg[arglist[2]] = static_cast<T>(i);
    result = this->lambda->ExpEval(arg, VecArgument);
  }
  return result;
}
template paf::MathExpression::ExpValueClass::ArrayFunction::Fold<int>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Fold<double>;
template paf::MathExpression::ExpValueClass::ArrayFunction::Fold<boost::multiprecision::cpp_dec_float_100>;