#include "ExtendFunction.h"
#include "../../\ArrayEval.h"
#include "../../Functions.h"
#include <boost\multiprecision\cpp_dec_float.hpp>
#include <boost\limits.hpp>

template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Sum<T, ArgumentSize>::Sum(TreeType Node, NodeType Func) try :ArrayValue<T>(Functions::CheckArgumentSize<ArgumentSize>(Node), Func) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Sum");
  throw;
}
template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Sum<T,ArgumentSize>::~Sum() {

}
template<typename T, int ArgumentSize>
T paf::MathExpression::ExpValueClass::ExtendFunction::Sum<T, ArgumentSize>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  T result(0);
  if (this->GetNodeSize() != 0) {
    for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
      result += this->GetNode(i)->ExpEval(Argument, VecArgument);
    }
  }
  else {
    auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
    for (auto val : vec) {
      result += val;
    }
  }
  return result;
}
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<int,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<int,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<double,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<double,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<boost::multiprecision::cpp_dec_float_100,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Sum<boost::multiprecision::cpp_dec_float_100,0>;

template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Average<T,ArgumentSize>::Average(TreeType Node,NodeType Func)try :ArrayValue<T>(Functions::CheckArgumentSize<ArgumentSize>(Node), Func) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Average");
  throw;
}
template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Average<T,ArgumentSize>::~Average() {

}
template<typename T, int ArgumentSize>
T paf::MathExpression::ExpValueClass::ExtendFunction::Average<T, ArgumentSize>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  T result(0);
  if (this->GetNodeSize() != 0) {
    int max = this->GetNodeSize();
    for (int i = 0; i < max; ++i) {
      result += this->GetNode(i)->ExpEval(Argument, VecArgument);
    }
    result /= max;
  }
  else {
    auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
    for (auto val : vec) {
      result += val;
    }
    result /= vec.size();
  }
  return result;
}
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<int,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<int,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<double,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<double,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<boost::multiprecision::cpp_dec_float_100,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Average<boost::multiprecision::cpp_dec_float_100,0>;

template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Min<T,ArgumentSize>::Min(TreeType Node,NodeType Func)try :ArrayValue<T>(Functions::CheckArgumentSize<ArgumentSize>(Node), Func) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Min");
  throw;
}
template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Min<T,ArgumentSize>::~Min() {

}
template<typename T, int ArgumentSize>
T paf::MathExpression::ExpValueClass::ExtendFunction::Min<T, ArgumentSize>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  T result(std::numeric_limits<T>::max());
  if (this->GetNodeSize() != 0) {
    for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
      if (result > this->GetNode(i)->ExpEval(Argument, VecArgument))result = this->GetNode(i)->ExpEval(Argument, VecArgument);
    }
  }
  else {
    auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
    for (auto val : vec) {
      if (result > val)result = val;
    }
  }
  return result;
}
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<int,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<int,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<double,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<double,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<boost::multiprecision::cpp_dec_float_100,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Min<boost::multiprecision::cpp_dec_float_100,0>;

template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Max<T,ArgumentSize>::Max(TreeType Node,NodeType Func)try :ArrayValue<T>(Functions::CheckArgumentSize<ArgumentSize>(Node), Func) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Max");
  throw;
}
template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Max<T,ArgumentSize>::~Max() {

}
template<typename T, int ArgumentSize>
T paf::MathExpression::ExpValueClass::ExtendFunction::Max<T, ArgumentSize>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  T result(0);
  if (this->GetNodeSize() != 0) {
    for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
      if (result < this->GetNode(i)->ExpEval(Argument, VecArgument))result = this->GetNode(i)->ExpEval(Argument, VecArgument);
    }
  }
  else {
    auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
    for (auto val : vec) {
      if (result < val)result = val;
    }
  }
  return result;
}
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<int,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<int,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<double,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<double,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<boost::multiprecision::cpp_dec_float_100,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Max<boost::multiprecision::cpp_dec_float_100,0>;

template<typename T>
paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<T>::RealRand(TreeType Node)try :ExpValue<T>(Functions::CheckArgumentSize<2>(Node)),gen_(std::random_device()()){

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Realrand");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<T>::~RealRand() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::uniform_real_distribution<>(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument))(this->gen_);
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return std::uniform_real_distribution<>(this->GetNode(0)->ExpEval(Argument, VecArgument).convert_to<double>(), this->GetNode(1)->ExpEval(Argument, VecArgument).convert_to<double>())(this->gen_);
}
template paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<int>;
template paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<double>;
template paf::MathExpression::ExpValueClass::ExtendFunction::RealRand<boost::multiprecision::cpp_dec_float_100>;

template<typename T>
paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<T>::IntRand(TreeType Node)try :ExpValue<T>(Functions::CheckArgumentSize<2>(Node)), gen_(std::random_device()()) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Intrand");
  throw;
}
template<typename T>
paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<T>::~IntRand() {

}
template<typename T>
T paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<T>::ExpEval(ArgumentType Argument,VectorArgumentType VecArgument) {
  return std::uniform_int_distribution<>(this->GetNode(0)->ExpEval(Argument, VecArgument), this->GetNode(1)->ExpEval(Argument, VecArgument))(this->gen_);
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<boost::multiprecision::cpp_dec_float_100>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  return std::uniform_int_distribution<>(this->GetNode(0)->ExpEval(Argument, VecArgument).convert_to<int>(), this->GetNode(1)->ExpEval(Argument, VecArgument).convert_to<int>())(this->gen_);
}
template paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<int>;
template paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<double>;
template paf::MathExpression::ExpValueClass::ExtendFunction::IntRand<boost::multiprecision::cpp_dec_float_100>;

template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Std<T,ArgumentSize>::Std(TreeType Node,NodeType Func)try :ArrayValue<T>(Functions::CheckArgumentSize<ArgumentSize>(Node), Func) {

}
catch (MathExpessionException& e) {
  e.ReplaceMessage("{Function}", "Std");
  throw;
}template<typename T, int ArgumentSize>
paf::MathExpression::ExpValueClass::ExtendFunction::Std<T,ArgumentSize>::~Std() {

}
template<typename T, int ArgumentSize>
T paf::MathExpression::ExpValueClass::ExtendFunction::Std<T, ArgumentSize>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  T result(0);
  T result2(0);
  if (this->GetNodeSize() != 0) {
    for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
      auto val = this->GetNode(i)->ExpEval(Argument, VecArgument);
      result += val*val;
      result2 += val;
    }
    result /= this->GetNodeSize();
    result2 /= this->GetNodeSize();
  }
  else {
    auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
    for (auto val : vec) {
      result += val*val;
      result2 += val;
    }
    result /= vec.size();
    result2 /= vec.size();
  }
  return std::sqrt(result - result2*result2);
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::ExtendFunction::Std<boost::multiprecision::cpp_dec_float_100, -1>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  boost::multiprecision::cpp_dec_float_100 result(0);
  boost::multiprecision::cpp_dec_float_100 result2(0);
  for (int i = 0, max = this->GetNodeSize(); i < max; ++i) {
    auto val = this->GetNode(i)->ExpEval(Argument, VecArgument);
    result += val*val;
    result2 += val;
  }
  result /= this->GetNodeSize();
  result2 /= this->GetNodeSize();
  return boost::multiprecision::sqrt(result - result2*result2);
}
template<>
boost::multiprecision::cpp_dec_float_100 paf::MathExpression::ExpValueClass::ExtendFunction::Std<boost::multiprecision::cpp_dec_float_100, 0>::ExpEval(ArgumentType Argument, VectorArgumentType VecArgument) {
  boost::multiprecision::cpp_dec_float_100 result(0);
  boost::multiprecision::cpp_dec_float_100 result2(0);
  auto vec = this->GetArrayFunc()->VecEval(Argument, VecArgument);
  for (auto val : vec) {
    result += val*val;
    result2 += val;
  }
  result /= vec.size();
  result2 /= vec.size();
  return boost::multiprecision::sqrt(result - result2*result2);
}
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<int,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<int,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<double,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<double,-1>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<boost::multiprecision::cpp_dec_float_100,0>;
template paf::MathExpression::ExpValueClass::ExtendFunction::Std<boost::multiprecision::cpp_dec_float_100,-1>;