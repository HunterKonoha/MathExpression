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
      /// �G���[���b�Z�[�W�ŏ��������܂��B
      /// </summary>
      /// <param name="Message">�G���[���b�Z�[�W</param>
      MathExpessionException(const std::string& Message);
      ~MathExpessionException() throw();
      /// <summary>
      /// �G���[�̌�����Ԃ��܂��B
      /// </summary>
      /// <returns>�G���[�̌���</returns>
      const char* what() const throw() override;
      /// <summary>
      /// �G���[���b�Z�[�W��ǉ����܂��B
      /// </summary>
      /// <param name="Message">�G���[���b�Z�[�W</param>
      /// <returns>�������g</returns>
      MathExpessionException& operator<<(const std::string& Message);
      /// <summary>
      /// �G���[���b�Z�[�W�̈ꕔ��u�������܂��B
      /// </summary>
      /// <param name="Target">�u����������G���[���b�Z�[�W</param>
      /// <param name="Message">�u��������G���[���b�Z�[�W</param>
      void ReplaceMessage(const std::string& Target, const std::string& Message);
    };
  }
}