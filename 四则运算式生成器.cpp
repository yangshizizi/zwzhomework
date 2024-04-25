#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// 生成指定范围内的随机数
int generateRand(int minVal, int maxVal) 
{
    return rand() % (maxVal - minVal + 1) + minVal;
}

// 生成四则运算式
string generateExpression(int numOperator, int maxVal, bool hasBracket, bool hasDecimal, string operators) 
{
    string expression;
    int result = 0;
    bool hasNegativeResult = false;

    for (int i = 0; i < numOperator; ++i) 
    {
        int num = generateRand(0, maxVal);
        char op = operators[generateRand(0, operators.size() - 1)];

        if (i > 0) 
        {
            expression += " " + string(1, op) + " ";
        }
        expression += to_string(num);

        if (op == '+')
            result += num;
        else if (op == '-')
            result -= num;
        else if (op == '*')
            result *= num;
        else if (num != 0)
            result /= num;

        if (result < 0)
            hasNegativeResult = true;

        // 随机添加括号
        if (hasBracket && generateRand(0, 1) == 1) 
            expression = "(" + expression + ")";
    }

    // 如果结果为负数，重新生成混合运算式
    if (hasNegativeResult)
        return generateExpression(numOperator, maxVal, hasBracket, hasDecimal, operators);

    return expression;
}

int main() 
{
    srand((unsigned)time(nullptr));

    int numOperator, maxVal;
    bool hasBracket, hasDecimal;
    string operators, outputMethod;

    // 用户输入
    cout << "请输入运算符数量：";
    cin >> numOperator;
    cout << "请输入最大数：";
    cin >> maxVal;
    cout << "是否有括号（1为有，0为无）：";
    cin >> hasBracket;
    cout << "是否有小数（1为有，0为无）：";
    cin >> hasDecimal;
    cout << "请输入运算符（如+,-,*,/）：";
    cin >> operators;
    cout << "请输入输出方式（如file, printer）：";
    cin >> outputMethod;

    // 生成四则运算式
    string expression = generateExpression(numOperator, maxVal, hasBracket, hasDecimal, operators);

    // 输出四则运算式
    if (outputMethod == "file") 
    {
        ofstream outFile("output.txt");
        outFile << expression;
        outFile.close();
    } 
    else if (outputMethod == "printer") 
    {
        
    } 
    else 
    {
        cout << expression << endl;
    }

    return 0;
}
