﻿// Snow.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdlib>
#include <iomanip>

constexpr auto PI = 3.1415926;

int menu_select() {
    int select;
    std::cout << "-------Welcome to Snow Calculator-------" << std::endl;
    std::cout << "               1. sin x                 " << std::endl;
    std::cout << "               2. cos x                 " << std::endl;
    std::cout << "               3. tan x                 " << std::endl;
    std::cout << "               4. cot x                 " << std::endl;
    std::cout << "               5. Clean screen          " << std::endl;
    std::cout << "               0. to quit               " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cin >> select;
    return select;
}

double inputtrans(void) {
    double x;

    std::cout << "Please input x: " << std::endl;
    std::cin >> x;
    while (x >= 360.0)
    {
        x -= 360.0;
    }
    return (x * PI / 180.0);
}

double factorial(double n) {
    if (n <= 1) {
        return n;
    }
    else {
        return n * factorial(n - 1);
    }
}

//下面为求绝对值函数
double myabs(double num1)
{
    return((num1 > 0) ? num1 : -num1);
}

//下面为求sin(x)的值
double snowsin(double num2)
{
    int i = 1, negation = 1;//取反
    double sum;
    double index = num2;//指数
    double Factorial = 1;//阶乘
    double TaylorExpansion = num2;//泰勒展开式求和
    do
    {
        Factorial = Factorial * ((__int64)i + 1) * ((__int64)i + 2);//求阶乘
        index *= num2 * num2;//求num2的次方
        negation = -negation;//每次循环取反
        sum = index / Factorial * negation;
        TaylorExpansion += sum;
        i += 2;
    } while (myabs(sum) > 1e-15);
    return(TaylorExpansion);
}

double snowcos(double x) {
    x = (PI / 2) - x;
    return sin(x);
}

double snowtan(double x) {
    return (snowsin(x) / snowcos(x));
}

double snowcot(double x) {
    return (1 / snowtan(x));
}

int main()
{
    double result = 0.0;
    double x = 0.0;
    int menu = menu_select();
    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            x = inputtrans();
            result = snowsin(x);
            std::cout << std::fixed << std::setprecision(5) << "Result =  " << result << std::endl;
            break;
        case 2:
            x = inputtrans();
            result = snowcos(x);
            std::cout << std::fixed << std::setprecision(5) << "Result =  " << result << std::endl;
            break;
        case 3:
            x = inputtrans();
            result = snowtan(x);
            std::cout << std::fixed << std::setprecision(5) << "Result =  " << result << std::endl;
            break;
        case 4:
            x = inputtrans();
            result = snowcot(x);
            std::cout << std::fixed << std::setprecision(5) << "Result =  " << result << std::endl;
            break;
        case 5:
            system("cls");
            break;
        case 0:
            break;
        default:
            std::cout << "Wrong input, please input again!" << std::endl;
            break;
        }
        if (menu == 0) {
            break;
        }
        menu = menu_select();
    }
    
    std::cout << "Thank you for using!\nPress any key to exit.\n";
    system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
