#include "logic.h"
#include <sstream>
#include <cmath>

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

        double a; // §Ú§ã§á§à§Ý§î§Ù§å§Ö§Þ double, §é§ä§à§Ò§í §á§à§Õ§Õ§Ö§â§Ø§Ñ§ä§î §ß§Ö§è§Ö§Ý§à§é§Ú§ã§Ý§Ö§ß§ß§í§Ö §Ù§ß§Ñ§é§Ö§ß§Ú§ñ
        double b;
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
            else if (op == 'p') // §Õ§à§Ò§Ñ§Ó§Ý§ñ§Ö§Þ §á§à§Õ§Õ§Ö§â§Ø§Ü§å §é§Ú§ã§Ý§Ñ pi
            {
                output_ss << M_PI * a;
            }
            else if (op == 'e') // §Õ§à§Ò§Ñ§Ó§Ý§ñ§Ö§Þ §á§à§Õ§Õ§Ö§â§Ø§Ü§å §é§Ú§ã§Ý§Ñ e
            {
                output_ss << exp(a);
            }
        }
        return output_ss.str();
    }
}