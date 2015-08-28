#pragma once
#include "ExpValue\ExpValue.h"
#include "ExpValue\ArrayValue.h"
#include "PreArgument.h"
#include <unordered_map>
#include <functional>
#include <string>

namespace paf {
  namespace MathExpression {
    template<typename T>
    class MathExpression;

    template<typename T>
    class ExpFunctionCreater {
      private:
        std::unordered_map<std::string, std::function<std::shared_ptr<ExpValue<T>>(std::vector<std::shared_ptr<ExpValue<T>>>, const PreArgument<T>&)>> normalfunc_;
        std::unordered_map<std::string, std::function<std::shared_ptr<ExpValue<T>>(std::vector<std::shared_ptr<ExpValue<T>>>, std::shared_ptr<ExpValue<T>>)>> arrayfunc_;

      public:
        ExpFunctionCreater();
        ~ExpFunctionCreater();
        std::shared_ptr<ExpValue<T>> GetNormalFunction(const std::string& FuncName, std::vector<std::shared_ptr<ExpValue<T>>> Argument, const PreArgument<T>& PreArgument)const;
        std::shared_ptr<ExpValue<T>> GetArrayFunction(const std::string& FuncName, std::shared_ptr<ExpValue<T>> Argument, std::shared_ptr<ExpValue<T>> Value)const;

      private:
        template<class R>
        void AddNormalFunction(const std::string& Name);
        template<class R>
        void AddArrayFunction(const std::string& Name);
    };
  }
}