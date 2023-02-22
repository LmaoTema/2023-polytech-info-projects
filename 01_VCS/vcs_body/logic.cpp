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

        double a; // �ڧ���ݧ�٧�֧� double, ����ҧ� ���էէ֧�اѧ�� �ߧ֧�֧ݧ��ڧ�ݧ֧ߧߧ�� �٧ߧѧ�֧ߧڧ�
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
            else if (op == 'p') // �է�ҧѧӧݧ�֧� ���էէ֧�اܧ� ��ڧ�ݧ� pi
            {
                output_ss << M_PI * a;
            }
            else if (op == 'e') // �է�ҧѧӧݧ�֧� ���էէ֧�اܧ� ��ڧ�ݧ� e
            {
                output_ss << exp(a);
            }
        }
        return output_ss.str();
    }
}