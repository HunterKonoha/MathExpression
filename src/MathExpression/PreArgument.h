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
        /// 変数の型
        /// </summary>
        using VariableTemplate = StringVectorPair<MathExpression<T>>;
        /// <summary>
        /// 関数の型
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
        /// <param name="VariableList">内部で使用する変数配列への参照</param>
        PreArgument(const StringVectorPair<MathExpression<T>>& VariableList);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="FuncList">内部で使用する関数配列への参照</param>
        PreArgument(const Function& FuncList);
        /// <summary>
        /// 
        /// </summary>
        /// <param name="VariableList">内部で使用する変数配列への参照</param>
        /// <param name="FuncList">内部で使用する関数配列への参照</param>
        PreArgument(const StringVectorPair<MathExpression<T>>& VariableList, const Function& FuncList);
        /// <summary>
        /// 内部で使える変数を追加します。
        /// </summary>
        /// <param name="Name">追加する変数名</param>
        /// <param name="Variable">変数の数式処理クラスへの参照</param>
        void AddVariable(const std::string& Name, const MathExpression<T>& Variable);
        /// <summary>
        /// 内部で使える変数を追加します。
        /// </summary>
        /// <param name="VariableList">内部で使用する変数配列への参照</param>
        void AddVariable(const StringVectorPair<MathExpression<T>>& VariableList);
        /// <summary>
        /// 内部で使用できる関数を追加します。
        /// </summary>
        /// <param name="Name">関数名</param>
        /// <param name="ArgumentNameList">引数名配列</param>
        /// <param name="Argument">関数本体への参照</param>
        void AddFunction(const std::string& Name, const std::vector<std::string>& ArgumentNameList, const MathExpression<T>& Argument);
        /// <summary>
        /// 内部で使用できる関数を追加します。
        /// </summary>
        /// <param name="FuncList">内部で使用する関数配列への参照</param>
        void AddFunction(const Function& FuncList);
        /// <summary>
        /// 変数が存在するか確認します。
        /// </summary>
        /// <param name="Name">変数名</param>
        /// <returns>true(存在する)/false(存在しない)</returns>
        bool ExistVariable(const std::string& Name)const;
        /// <summary>
        /// 関数が存在するか確認します。
        /// </summary>
        /// <param name="Name">関数名</param>
        /// <returns>true(存在する)/false(存在しない)</returns>
        bool ExistFunction(const std::string& Name)const;
        /// <summary>
        /// 変数を得ます。
        /// </summary>
        /// <param name="Name">変数名</param>
        /// <returns>変数への参照</returns>
        const MathExpression<T>& GetVariable(const std::string& Name)const;
        /// <summary>
        /// 関数を得ます。
        /// </summary>
        /// <param name="Name">関数名</param>
        /// <returns>引数と関数本体への参照</returns>
        const std::pair<std::vector<std::string>, const MathExpression<T>&>& GetFunction(const std::string& Name)const;
    };
  }
}