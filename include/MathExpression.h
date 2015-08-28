#pragma once
#ifdef _MSC_VER
# if (_MSC_VER<1900)
#  define PATH "vc++12.0\\"
# else
#  define PATH "vc++14.0\\"
# endif
# ifndef _DEBUG
#   pragma comment(lib,PATH"MathExpression.lib")
# else
#   pragma comment(lib,PATH"MathExpression_d.lib")
# endif
#endif

#include "MathExpression\MathExpression.h"
#include "MathExpression\MathExpressionException.h"
#include "MathExpression\PreArgument.h"