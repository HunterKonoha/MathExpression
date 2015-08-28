#pragma once
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

namespace paf {
  namespace MathExpression {
    template<typename T>
    class MathExpression;

    template<typename T = double>
    class PreArgument {
      private:
        template<typename R>
        using StringUnorderedMap = std::unordered_map<std::string, R>;
        template<typename R>
        using StringVectorPair = std::vector<std::pair<std::string, R>>;
        using Function = std::vector<std::pair<std::string, std::pair<std::vector<std::string>, MathExpression<T>>>>;

      public:
        /// <summary>
        /// �ϐ��̌^
        /// </summary>
        using VariableTemplate = StringVectorPair<MathExpression<T>>;
        /// <summary>
        /// �֐��̌^
        /// </summary>
        using FunctionTemplate = Function;

      private:
        StringUnorderedMap<const MathExpression<T>&> variable_;
        StringUnorderedMap<std::pair<std::vector<std::string>, const MathExpression<T>&>> func_;


      public:
        PreArgument();
        /// <summary>
        /// 
        /// </summary>
        /// <param name="VariableList">�����Ŏg�p����ϐ��z��ւ̎Q��</param>
        PreArgument(const StringVectorPair<MathExpression<T>>& VariableList);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="FuncList">�����Ŏg�p����֐��z��ւ̎Q��</param>
        PreArgument(const Function& FuncList);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="VariableList">�����Ŏg�p����ϐ��z��ւ̎Q��</param>
        /// <param name="FuncList">�����Ŏg�p����֐��z��ւ̎Q��</param>
        PreArgument(const StringVectorPair<MathExpression<T>>& VariableList, const Function& FuncList);
        /// <summary>
        /// �����Ŏg����ϐ���ǉ����܂��B
        /// </summary>
        /// <param name="Name">�ǉ�����ϐ���</param>
        /// <param name="Variable">�ϐ��̐��������N���X�ւ̎Q��</param>
        void AddVariable(const std::string& Name, const MathExpression<T>& Variable);
        /// <summary>
        /// �����Ŏg����ϐ���ǉ����܂��B
        /// </summary>
        /// <param name="VariableList">�����Ŏg�p����ϐ��z��ւ̎Q��</param>
        void AddVariable(const StringVectorPair<MathExpression<T>>& VariableList);
        /// <summary>
        /// �����Ŏg�p�ł���֐���ǉ����܂��B
        /// </summary>
        /// <param name="Name">�֐���</param>
        /// <param name="ArgumentNameList">�������z��</param>
        /// <param name="Argument">�֐��{�̂ւ̎Q��</param>
        void AddFunction(const std::string& Name, const std::vector<std::string>& ArgumentNameList, const MathExpression<T>& Argument);
        /// <summary>
        /// �����Ŏg�p�ł���֐���ǉ����܂��B
        /// </summary>
        /// <param name="FuncList">�����Ŏg�p����֐��z��ւ̎Q��</param>
        void AddFunction(const Function& FuncList);
        /// <summary>
        /// �ϐ������݂��邩�m�F���܂��B
        /// </summary>
        /// <param name="Name">�ϐ���</param>
        /// <returns>true(���݂���)/false(���݂��Ȃ�)</returns>
        bool ExistVariable(const std::string& Name)const;
        /// <summary>
        /// �֐������݂��邩�m�F���܂��B
        /// </summary>
        /// <param name="Name">�֐���</param>
        /// <returns>true(���݂���)/false(���݂��Ȃ�)</returns>
        bool ExistFunction(const std::string& Name)const;
        /// <summary>
        /// �ϐ��𓾂܂��B
        /// </summary>
        /// <param name="Name">�ϐ���</param>
        /// <returns>�ϐ��ւ̎Q��</returns>
        const MathExpression<T>& GetVariable(const std::string& Name)const;
        /// <summary>
        /// �֐��𓾂܂��B
        /// </summary>
        /// <param name="Name">�֐���</param>
        /// <returns>�����Ɗ֐��{�̂ւ̎Q��</returns>
        const std::pair<std::vector<std::string>, const MathExpression<T>&>& GetFunction(const std::string& Name)const;
    };
  }
}