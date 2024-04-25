#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ����ָ����Χ�ڵ������
int generateRand(int minVal, int maxVal) 
{
    return rand() % (maxVal - minVal + 1) + minVal;
}

// ������������ʽ
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

        // ����������
        if (hasBracket && generateRand(0, 1) == 1) 
            expression = "(" + expression + ")";
    }

    // ������Ϊ�������������ɻ������ʽ
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

    // �û�����
    cout << "�����������������";
    cin >> numOperator;
    cout << "�������������";
    cin >> maxVal;
    cout << "�Ƿ������ţ�1Ϊ�У�0Ϊ�ޣ���";
    cin >> hasBracket;
    cout << "�Ƿ���С����1Ϊ�У�0Ϊ�ޣ���";
    cin >> hasDecimal;
    cout << "���������������+,-,*,/����";
    cin >> operators;
    cout << "�����������ʽ����file, printer����";
    cin >> outputMethod;

    // ������������ʽ
    string expression = generateExpression(numOperator, maxVal, hasBracket, hasDecimal, operators);

    // �����������ʽ
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
