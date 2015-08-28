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
        /// 数式を解析し、構文木を生成します。
        /// </summary>
        /// <param name="Expression">数式</param>
        /// <param name="Argument">内部で使用できる変数や関数の専用クラス</param>
        MathExpression(const std::string& Expression, const PreArgument<T>& Argument = {});
        MathExpression();
        ~MathExpression();
        /// <summary>
        /// 構文木を評価し、値を返します。返す値が配列だった場合例外を投げます。
        /// </summary>
        /// <param name="Argument">変数リスト</param>
        /// <param name="VecArgument">配列変数リスト</param>
        /// <returns>値</returns>
        T operator()(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {});
        /// <summary>
        /// 数式を解析し、構文木を生成します。
        /// </summary>
        /// <param name="Expression">数式</param>
        /// <param name="Argument">内部で使用できる変数や関数の専用クラス</param>
        void ConstructExpression(const std::string& Expression, const PreArgument<T>& Argument = {});
        /// <summary>
        /// 構文木を評価し、値を返します。返す値が配列だった場合例外を投げます。
        /// </summary>
        /// <param name="Argument">変数リスト</param>
        /// <param name="VecArgument">配列変数リスト</param>
        /// <returns>値</returns>
        T Calc(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {})const;
        /// <summary>
        /// 構文木を評価し、配列として値を返します。返す値が値だった場合例外を投げます。
        /// </summary>
        /// <param name="Argument">変数配列</param>
        /// <param name="VecArgument">配列変数配列</param>
        /// <returns>配列</returns>
        std::vector<T> VecCalc(const std::unordered_map<std::string, T>& Argument = {}, const std::unordered_map<std::string, std::vector<T>>& VecArgument = {})const;
        /// <summary>
        /// 返す値が配列かどうか確認します。
        /// </summary>
        /// <returns>true(配列)/false(値)</returns>
        bool IsArrayExpression();
    };
  }
}