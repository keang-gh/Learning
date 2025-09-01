/*******************************************************
 描述：中缀表达式转后缀表达式（逆波兰表达式）   待完善
 思路：
      1.建一个符号栈
      2.遍历字符
      2.遇到数字直接输出
      3.遇到（，直接入栈
      4.遇到），不入了，相当于要开始计算了，出栈直到（
      5.任何其他符号的优先级比（高
 作者：周康
 时间：2023.8.9
*******************************************************/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 比较符号优先级的
bool Priority(char ch, char topch)
{
	if ((ch == '*' || ch == '/') && (topch == '+' || topch == '-'))
		return true;
	if (topch == '(' && ch != ')')
		return true;
	return false;
}

// 中缀表达式 => 后缀表达式
string MiddleToEndExpr(string expr)
{
	string result;
	stack<char> s;

	for (char ch : expr)
	{
		if (ch >= '0' && ch <= '9')
		{
			result.push_back(ch);
		}
		else
		{
			for (;;)          
			{
				// 处理符号了
				if (s.empty() || ch == '(')
				{
					s.push(ch);
					break;
				}

				// 比较当前符号ch和栈顶符号top的优先级
				char topch = s.top();
				// Priority:true ch > topch   false ch <= topch
				if (Priority(ch, topch))
				{
					s.push(ch);
					break;
				}
				else
				{
					s.pop();
					if (topch == '(') // 如果遇见)，一直出栈，直到(
						break;
					result.push_back(topch);
				}
			}
		}
	}

	// 如果符号栈还存留符号，直接输出到后缀表达式里面     + /
	while (!s.empty())
	{
		result.push_back(s.top());
		s.pop();
	}

	return result;
}

int main()
{
	cout << MiddleToEndExpr("(1+2)*(3+4)") << endl;
	cout << MiddleToEndExpr("2+(4+6)/2+6/3") << endl;
	cout << MiddleToEndExpr("2+6/(4-2)+(4+6)/2") << endl;
}