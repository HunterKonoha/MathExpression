#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

/// <summary>
/// 数式処理クラス内で使う構文木の基底クラスです。
/// </summary>
namespace paf {
  namespace MathExpression {
    template<typename T>
    class ExpValue {
      public:
        using ArgumentType = const std::unordered_map<std::string, T>&;
        using VectorArgumentType = const std::unordered_map<std::string, std::vector<T>>&;
        using NodeType = std::shared_ptr<ExpValue<T>>;
        using TreeType = std::vector<NodeType>;

      private:
        TreeType node_; 

      protected:
        NodeType GetNode(std::size_t Index);
        std::size_t GetNodeSize();
        void SetNode(TreeType Node);

      public:
        ExpValue(TreeType Node);
        virtual ~ExpValue();
        virtual T ExpEval(ArgumentType Argument = {}, VectorArgumentType VecArgument = {}) = 0;
        virtual bool IsConstValue();
        virtual bool IsAllofConstValue();
        void OptimizeExpression();
        T operator()(ArgumentType Argument = {});
    };
  }
}