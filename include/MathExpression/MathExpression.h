#pragma once
#include "ExpValue\ExpValue.h"
#include "PreArgument.h"

namespace paf {
  namespace MathExpression {
    template<typename T = double>
    class MathExpression {
      private:
        std::shared_ptr<ExpValue<T>> root;
        std::vector<std::pair<std::string, std::vector<std::string>>> outsidefunc_;

      public:
        /// <summary>
        /// ��������͂��A�\���؂𐶐����܂��B
        /// </summary>
        /// <param name="Expression">����</param>
        /// <param name="Argument">�����Ŏg�p�ł���ϐ���֐��̐�p�N���X</param>
        MathExpression(const std::string& Expression, const PreArgument<T>& Argument = {});
        MathExpression();
        ~MathExpression();
        /// <summary>
        /// �\���؂�]�����A�l��Ԃ��܂��B�Ԃ��l���z�񂾂����ꍇ��O�𓊂��܂��B
        /// </summary>
        /// <param name="Argument">�ϐ����X�g</param>
        /// <param name="VecArgument">�z��ϐ����X�g</param>
        /// <returns>�l</returns>
        T operator()(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {});
        /// <summary>
        /// ��������͂��A�\���؂𐶐����܂��B
        /// </summary>
        /// <param name="Expression">����</param>
        /// <param name="Argument">�����Ŏg�p�ł���ϐ���֐��̐�p�N���X</param>
        void ConstructExpression(const std::string& Expression, const PreArgument<T>& Argument = {});
        /// <summary>
        /// �\���؂�]�����A�l��Ԃ��܂��B�Ԃ��l���z�񂾂����ꍇ��O�𓊂��܂��B
        /// </summary>
        /// <param name="Argument">�ϐ����X�g</param>
        /// <param name="VecArgument">�z��ϐ����X�g</param>
        /// <returns>�l</returns>
        T Calc(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {})const;
        /// <summary>
        /// �\���؂�]�����A�z��Ƃ��Ēl��Ԃ��܂��B�Ԃ��l���l�������ꍇ��O�𓊂��܂��B
        /// </summary>
        /// <param name="Argument">�ϐ��z��</param>
        /// <param name="VecArgument">�z��ϐ��z��</param>
        /// <returns>�z��</returns>
        std::vector<T> VecCalc(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {})const;
        /// <summary>
        /// �Ԃ��l���z�񂩂ǂ����m�F���܂��B
        /// </summary>
        /// <returns>true(�z��)/false(�l)</returns>
        bool IsArrayExpression();
    };
  }
}