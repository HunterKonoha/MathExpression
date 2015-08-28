#include "MathExpressionException.h"
#include <boost\algorithm\string\replace.hpp>

paf::MathExpression::MathExpessionException::MathExpessionException() :std::exception(), msg_("") {

}
paf::MathExpression::MathExpessionException::MathExpessionException(const std::string& Message) : std::exception(), msg_(Message) {

}
paf::MathExpression::MathExpessionException::~MathExpessionException() throw() {

}
const char* paf::MathExpression::MathExpessionException::what() const throw() {
  return this->msg_.c_str();
}
paf::MathExpression::MathExpessionException& paf::MathExpression::MathExpessionException::operator<<(const std::string& Message) {
  this->msg_ += Message;
  return *this;
}
void paf::MathExpression::MathExpessionException::ReplaceMessage(const std::string& Target, const std::string& Message) {
  boost::algorithm::replace_all(this->msg_, Target, Message);
}