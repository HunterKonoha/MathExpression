#include "ExpFunctionCreater.h"
#include "ExpValue\Derive\Function\MathFunction.h"
#include "ExpValue\Derive\Function\ExtendFunction.h"
#include "ExpValue\Derive\Function\OutsideFunction.h"
#include "ExpValue\Derive\Function\ArrayFunction.h"
#include "MathExpressionException.h"
#include "PreArgument.h"
#include <boost\multiprecision\cpp_dec_float.hpp>

template<typename T>
paf::MathExpression::ExpFunctionCreater<T>::ExpFunctionCreater() {
  this->AddNormalFunction<ExpValueClass::MathFunction::Radian<T>>("Radian");
  this->AddNormalFunction<ExpValueClass::MathFunction::Angle<T>>("Angle");
  this->AddNormalFunction<ExpValueClass::MathFunction::Sin<T>>("Sin");
  this->AddNormalFunction<ExpValueClass::MathFunction::Cos<T>>("Cos");
  this->AddNormalFunction<ExpValueClass::MathFunction::Tan<T>>("Tan");
  this->AddNormalFunction<ExpValueClass::MathFunction::ArcSin<T>>("Arcsin");
  this->AddNormalFunction<ExpValueClass::MathFunction::ArcCos<T>>("Arccos");
  this->AddNormalFunction<ExpValueClass::MathFunction::ArcTan<T>>("Arctan");
  this->AddNormalFunction<ExpValueClass::MathFunction::Ln<T>>("Ln");
  this->AddNormalFunction<ExpValueClass::MathFunction::Log10<T>>("Log10");
  this->AddNormalFunction<ExpValueClass::MathFunction::Log<T>>("Log");
  this->AddNormalFunction<ExpValueClass::MathFunction::Exp<T>>("Exp");
  this->AddNormalFunction<ExpValueClass::MathFunction::Abs<T>>("Abs");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::Std<T>>("Std");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::Sum<T>>("Sum");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::Average<T>>("Average");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::Max<T>>("Max");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::Min<T>>("Min");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::RealRand<T>>("Realrand");
  this->AddNormalFunction<ExpValueClass::ExtendFunction::IntRand<T>>("Intrand");
  this->AddArrayFunction<ExpValueClass::ExtendFunction::Sum<T, 0>>("Sum");
  this->AddArrayFunction<ExpValueClass::ExtendFunction::Average<T, 0>>("Average");
  this->AddArrayFunction<ExpValueClass::ExtendFunction::Max<T, 0>>("Max");
  this->AddArrayFunction<ExpValueClass::ExtendFunction::Min<T, 0>>("Min");
  this->AddArrayFunction<ExpValueClass::ExtendFunction::Std<T, 0>>("Std");
  this->AddArrayFunction<ExpValueClass::ArrayFunction::Select<T>>("Select");
  this->AddArrayFunction<ExpValueClass::ArrayFunction::Adapt<T>>("Adapt");
  this->AddArrayFunction<ExpValueClass::ArrayFunction::Fold<T>>("Fold");
}
template<typename T>
paf::MathExpression::ExpFunctionCreater<T>::~ExpFunctionCreater() {
}
template<typename T>
std::shared_ptr<paf::MathExpression::ExpValue<T>> paf::MathExpression::ExpFunctionCreater<T>::GetNormalFunction(const std::string& FuncName, std::vector<std::shared_ptr<ExpValue<T>>> Argument, const PreArgument<T>& PreArgument)const {
  auto it = this->normalfunc_.find(FuncName);
  if (it != this->normalfunc_.end()) {
    try {
      return it->second(Argument, PreArgument);
    }
    catch (MathExpessionException& e) {
      e.ReplaceMessage("{Function}", FuncName);
      throw e;
    }
  }
  else if (PreArgument.ExistFunction(FuncName)) {
    return std::shared_ptr<ExpValue<T>>(new ExpValueClass::OutsideFunction<T>(Argument, FuncName, PreArgument));
  }
  else throw MathExpessionException("指定された関数は存在しません。\n問題の関数名は" + FuncName + "です。");
}
template<typename T>
std::shared_ptr<paf::MathExpression::ExpValue<T>> paf::MathExpression::ExpFunctionCreater<T>::GetArrayFunction(const std::string& FuncName, std::shared_ptr<ExpValue<T>> Argument, std::shared_ptr<ExpValue<T>> Value)const {
  auto it = this->arrayfunc_.find(FuncName);
  if (it != this->arrayfunc_.end()) {
    if (Argument)return it->second({ Argument }, Value);
    else return it->second({}, Value);
  }
  else throw MathExpessionException("指定された関数は存在しません。\n問題の関数名は" + FuncName + "です。");
}
template<typename T>
template<class R>
void paf::MathExpression::ExpFunctionCreater<T>::AddNormalFunction(const std::string& Name) {
  this->normalfunc_[Name] = [](std::vector<std::shared_ptr<ExpValue<T>>> Arg, const PreArgument<T>& Argument) {return std::shared_ptr<ExpValue<T>>(new R(Arg)); };
}
template<typename T>
template<class R>
void paf::MathExpression::ExpFunctionCreater<T>::AddArrayFunction(const std::string& Name) {
  this->arrayfunc_[Name] = [](std::vector<std::shared_ptr<ExpValue<T>>> Arg, std::shared_ptr<ExpValue<T>> Value) {return std::shared_ptr<ExpValue<T>>(new R(Arg, Value)); };
}
template paf::MathExpression::ExpFunctionCreater<int>;
template paf::MathExpression::ExpFunctionCreater<double>;
template paf::MathExpression::ExpFunctionCreater<boost::multiprecision::cpp_dec_float_100>;