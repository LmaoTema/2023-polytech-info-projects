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

        double a;
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
            else if (op == 's') // добавляем поддержку функции синуса
            {
                output_ss << "sin(" << a << ")=" << sin(a * M_PI / 180.0);
            }
            else if (op == 'c') // добавляем поддержку функции косинуса
            {
                output_ss << "cos(" << a << ")=" << cos(a * M_PI / 180.0);
            }
            else if (op == 't') // добавляем поддержку функции тангенса
            {
                if (cos(a * M_PI / 180.0) == 0) // Проверяем, что знаменатель не равен нулю
            {
                output_ss << "Error: tan(" << a << ") is undefined";
            }
            else
            {
                output_ss << "tan(" << a << ")=" << tan(a * M_PI / 180.0)
            }
        }
        return output_ss.str();
    }
}