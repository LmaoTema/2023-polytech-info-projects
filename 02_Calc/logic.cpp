#include "logic.h"
#include <sstream>

namespace calc
{
    std::string Logic::process_math()
    {
        if (expression.empty())
        {
            return "";
        }

        std::istringstream input_ss(expression);
        std::stringstream output_ss;

        int a;
        int b;
        char op;
        input_ss >> a >> op >> b;

        if (op == '+')
        {
            output_ss << a << op << b << "=" << a + b;
        }
        else
        {
            output_ss << a << op << b << "=";
            if (op == '-')
            {
                output_ss << a - b;
            }
            else if (op == '*')
            {
                output_ss << a * b;
            }
            else if (op == '/')
            {
                if (b == 0)
                {
                    output_ss << "Error: division by zero";
                }
                else
                {
                    output_ss << a / b;
                }
            }
        }
        return output_ss.str();
    }
}
