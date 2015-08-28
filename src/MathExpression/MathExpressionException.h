#pragma once
#include <stdexcept>
#include <string>

namespace paf {
  namespace MathExpression {
    class MathExpessionException :public std::exception {
      private:
      std::string msg_;

      public:
      MathExpessionException();
      /// <summary>
      /// エラーメッセージで初期化します。
      /// </summary>
      /// <param name="Message">エラーメッセージ</param>
      MathExpessionException(const std::string& Message);
      ~MathExpessionException() throw();
      /// <summary>
      /// エラーの原因を返します。
      /// </summary>
      /// <returns>エラーの原因</returns>
      const char* what() const throw() override;
      /// <summary>
      /// エラーメッセージを追加します。
      /// </summary>
      /// <param name="Message">エラーメッセージ</param>
      /// <returns>自分自身</returns>
      MathExpessionException& operator<<(const std::string& Message);
      /// <summary>
      /// エラーメッセージの一部を置き換えます。
      /// </summary>
      /// <param name="Target">置き換えられるエラーメッセージ</param>
      /// <param name="Message">置き換えるエラーメッセージ</param>
      void ReplaceMessage(const std::string& Target, const std::string& Message);
    };
  }
}