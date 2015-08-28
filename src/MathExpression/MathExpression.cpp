#include "MathExpression.h"
#include "ExpFunctionCreater.h"
#include "ExpValue\ExpValue.h"
#include "ExpValue\ArrayEval.h"
#include "ExpValue\Functions.h"
#include "ExpValue\Derive\Value\Array.h"
#include "ExpValue\Derive\Value\ArrayIndex.h"
#include "ExpValue\Derive\Value\Value.h"
#include "ExpValue\Derive\Value\Variable.h"
#include "ExpValue\Derive\Value\Lambda.h"
#include "ExpValue\Derive\Operator.h"
#include <boost\spirit\include\qi.hpp>
#include <boost\spirit\include\phoenix.hpp>
#include <boost\spirit\include\classic_position_iterator.hpp>
#include <boost\multiprecision\cpp_dec_float.hpp>



template<typename CalcType>
struct calc
  : boost::spirit::qi::grammar<std::string::const_iterator, std::shared_ptr<paf::MathExpression::ExpValue<CalcType>>(), boost::spirit::ascii::space_type> {
  private:
    using ReturnValue = std::shared_ptr<paf::MathExpression::ExpValue<CalcType>>;

  private:
    boost::spirit::qi::rule<std::string::const_iterator, ReturnValue(), boost::spirit::ascii::space_type> compare,expr, term, pow, fctr, value, mathfunction,array,arrayval,lambda;
    boost::spirit::qi::rule<std::string::const_iterator, std::string(), boost::spirit::ascii::space_type> variable;
    boost::spirit::qi::rule<std::string::const_iterator, std::vector<ReturnValue>(), boost::spirit::ascii::space_type> funcargument;
    boost::spirit::qi::rule<std::string::const_iterator, std::vector<std::string>(), boost::spirit::ascii::space_type> argnamelist;
    const paf::MathExpression::PreArgument<CalcType>& variablelist;
    paf::MathExpression::ExpFunctionCreater<CalcType> creater;

  public:
    calc(const paf::MathExpression::PreArgument<CalcType>& Argument) : calc::base_type(compare), variablelist(Argument) {
      namespace spirit = boost::spirit;
      namespace qi = boost::spirit::qi;
      namespace phoenix = boost::phoenix;
      namespace MathExpression = paf::MathExpression;
      namespace ExpValueClass = paf::MathExpression::ExpValueClass;
      namespace Operator = paf::MathExpression::ExpValueClass::Operator;
      namespace Functions = paf::MathExpression::Functions;

      compare = expr[qi::_val = spirit::_1] > *(("==" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Equal<CalcType>>(qi::_val, spirit::_1))]
        | ("!=" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::NotEqual<CalcType>>(qi::_val, spirit::_1))]
        | ("<" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Less<CalcType>>(qi::_val, spirit::_1))]
        | (">" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Greater<CalcType>>(qi::_val, spirit::_1))]
        | ("<=" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::LessEqual<CalcType>>(qi::_val, spirit::_1))]
        | (">=" >> expr)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::GreaterEqual<CalcType>>(qi::_val, spirit::_1))]);
      expr = term[qi::_val = spirit::_1] > *(('+' >> term[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Add<CalcType>>(qi::_val, spirit::_1))])
        | ('-' >> term[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Sub<CalcType>>(qi::_val, spirit::_1))]));
      term = pow[qi::_val = spirit::_1] > *(('*' >> pow[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Mul<CalcType>>(qi::_val, spirit::_1))])
        | ('/' >> pow[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Div<CalcType>>(qi::_val, spirit::_1))])
        | ('%' >> pow[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Surplus<CalcType>>(qi::_val, spirit::_1))]));
      pow = fctr[qi::_val = spirit::_1] > *('^' >> fctr[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<Operator::Pow<CalcType>>(qi::_val, spirit::_1))]);
      fctr = value[qi::_val = spirit::_1];
      value = (qi::as_string[((qi::lit("0b") | qi::lit("0B")) >> +(qi::char_("01")))] >> qi::as_string[-('.' >> +(qi::char_("01")))])[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Value<CalcType>>(phoenix::bind(&Functions::UnitConvert<CalcType>, spirit::_1, spirit::_2)))]
        | (qi::as_string[((qi::lit("0x") | qi::lit("0X")) >> +(qi::char_("0-9a-fA-F")))] >> qi::as_string[-('.' >> +(qi::char_("0-9a-fA-F")))])[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Value<CalcType>>(phoenix::bind(&Functions::HexConvert<CalcType>, spirit::_1, spirit::_2)))]
        | spirit::double_[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Value<CalcType>>(spirit::_1))]
        | spirit::int_[qi::_val = phoenix::construct < ReturnValue>(phoenix::new_<ExpValueClass::Value<CalcType>>(spirit::_1))]
        | mathfunction[qi::_val = spirit::_1]
        | array[qi::_val = spirit::_1]
        | arrayval[qi::_val = spirit::_1]
        | variable[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Variable<CalcType>>(spirit::_1, this->variablelist))]
        | '(' >> expr[qi::_val = spirit::_1] >> ')';
      variable = (qi::char_("a-zA-Z_") > *(qi::char_("a-zA-Z0-9_")));
      funcargument = -(expr[phoenix::push_back(qi::_val, spirit::_1)] >> *(',' >> expr[phoenix::push_back(qi::_val, spirit::_1)]));
      mathfunction = (variable >> '(' >> funcargument >> ')')[qi::_val = phoenix::bind(&MathExpression::ExpFunctionCreater<CalcType>::GetNormalFunction, this->creater, spirit::_1, spirit::_2, variablelist)];
      array = (variable[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Array<CalcType>>(spirit::_1, MathExpression::ExpValue<CalcType>::TreeType{}, variablelist))] | arrayval[qi::_val = spirit::_1])
        >> (+(('.' >> variable >> '(' >> lambda >> ')')[qi::_val = phoenix::bind(&MathExpression::ExpFunctionCreater<CalcType>::GetArrayFunction, this->creater, spirit::_1, spirit::_2, qi::_val)]
          | ('[' >> spirit::int_ >> ']')[qi::_val = phoenix::construct <ReturnValue>(phoenix::new_<ExpValueClass::ArrayIndex<CalcType>>(qi::_val, spirit::_1))]));
      arrayval = ('[' >> funcargument >> ']')[qi::_val = phoenix::construct <ReturnValue>(phoenix::new_<ExpValueClass::Array<CalcType>>("", spirit::_1, variablelist))];
      argnamelist = variable[phoenix::push_back(qi::_val, spirit::_1)] >> *(',' >> variable[phoenix::push_back(qi::_val, spirit::_1)]);
      lambda = -(('(' >> argnamelist >> ")->" >> compare)[qi::_val = phoenix::construct<ReturnValue>(phoenix::new_<ExpValueClass::Lambda<CalcType>>(spirit::_1, spirit::_2))]);
    }
};

template<typename T>
paf::MathExpression::MathExpression<T>::MathExpression() {

}
template<typename T>
paf::MathExpression::MathExpression<T>::MathExpression(const std::string& Expression, const PreArgument<T>& Argument) {
  this->ConstructExpression(Expression, Argument);
}
template<typename T>
paf::MathExpression::MathExpression<T>::~MathExpression() {

}
template<typename T>
T paf::MathExpression::MathExpression<T>::operator()(const std::unordered_map<std::string, T>& Argument, const std::unordered_map<std::string, std::vector<T>>& VecArgument) {
  return this->Calc(Argument, VecArgument);
}
template<typename T>
void paf::MathExpression::MathExpression<T>::ConstructExpression(const std::string& Expression, const PreArgument<T>& Argument) {
  calc<T> calc(Argument);
  auto begin = Expression.begin();
  bool result(true);
  if (this->root)this->root.reset();
  try {
    result = boost::spirit::qi::phrase_parse(begin, Expression.end(), calc, boost::spirit::ascii::space, this->root);
  }
  catch (MathExpessionException& e) {
    throw e;
  }
  if (!(result&&begin == Expression.end())) {
    throw MathExpessionException("正しい数式が渡されなかったので、解析が完了できませんでした。\n解析できたのは" + std::string(Expression.begin(), begin) + "まででした。");
  }
  this->root->OptimizeExpression();
  if (this->root->IsAllofConstValue())this->root = std::shared_ptr<ExpValue<T>>(new ExpValueClass::Value<T>(this->root->ExpEval()));
}
template<typename T>
T paf::MathExpression::MathExpression<T>::Calc(const std::unordered_map<std::string, T>& Argument, const std::unordered_map<std::string, std::vector<T>>& VecArgument)const {
  return this->root->ExpEval(Argument, VecArgument);
}
template<typename T>
std::vector<T> paf::MathExpression::MathExpression<T>::VecCalc(const std::unordered_map<std::string, T>& Argument, const std::unordered_map<std::string, std::vector<T>>& VecArgument)const {
  if (std::dynamic_pointer_cast<ArrayEval<T>>(this->root) == nullptr) {
    throw MathExpessionException("この数式は配列を返しません。");
  }
  else return std::dynamic_pointer_cast<ArrayEval<T>>(this->root)->VecEval(Argument, VecArgument);
}
template<typename T>
bool paf::MathExpression::MathExpression<T>::IsArrayExpression() {
  return std::dynamic_pointer_cast<ArrayEval<T>>(this->root) != nullptr;
}
template paf::MathExpression::MathExpression<int>;
template paf::MathExpression::MathExpression<double>;
template paf::MathExpression::MathExpression<boost::multiprecision::cpp_dec_float_100>;