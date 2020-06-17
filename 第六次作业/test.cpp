#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;
class procal
{
public: 
	string exp; 
	int i;
	stack<string> val, label;
	void getis()
	{
		i = 0;
		label.push("0"); val.push("null");
		cout << "please input equation:" << endl;
		cin >> exp; exp.push_back('$');
	}
	void lex()
	{
		string s;
		while (!label.empty() && !val.empty())
		{
			//符号 
			if (exp[i] == '+' || exp[i] == '*' || exp[i] == '(' || exp[i] == ')' || exp[i] == '$'|| 
				exp[i] == '-' || exp[i] == '/')
			{
				s.push_back(exp[i]);
				match(s, s);
				s.clear();
				continue;
			}
			if (exp[i] >= '0' && exp[i] <= '9')
			{
				s.push_back(exp[i]); i++;
				while (exp[i] >= '0' && exp[i] <= '9')
				{
					s.push_back(exp[i]); i++;
				} i--;
				match(s, "id");
				s.clear();
				continue;
			}
			else
			{
				cout << "input error！" << endl;
				exit(0);
			}
		}
	}
	int string_to_num(string s)
	{
		int sum = 0, i = 0, j;
		while (i < s.size())
		{
			j = s[i] - '0';
			sum = sum * 10 + j; i++;
		}
		return sum;
	}
	string num_to_string(int a)
	{
		char temp; 
		string s;
		while (a)
		{
			temp = a % 10 + '0';
			s.push_back(temp);
			a = a / 10;
		}
		return reverse(s);
	}
	
	//倒置string 
	string reverse(string s)
	{
		string s1;
		while (s.size() > 0)
		{
			s1.push_back(s[s.size() - 1]);
			s.erase(s.size() - 1);
		}
		return s1;
	}
	void match(string user, string pro)
	{
		string s_top = label.top(); 
		string s1;
		
		//移进表 
		if ((s_top == "0" || s_top == "4" || s_top == "6" || s_top == "7"|| s_top == "8"|| s_top == "9") && pro == "id")
		{
			label.push("id"); 
			val.push(user); 
			label.push("5"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if ((s_top == "0" || s_top == "4" || s_top == "6" || s_top == "7"|| s_top == "8"|| s_top == "9") & pro == "(")
		{
			label.push("("); 
			label.push("4"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if ((s_top == "1" || s_top == "a") && pro == "+")
		{
			label.push("+"); 
			label.push("6"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if ((s_top == "1" || s_top == "a") && pro == "-")
		{
			label.push("-"); 
			label.push("7"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if ((s_top == "2" || s_top == "b" || s_top == "c") && pro == "*")
		{
			label.push("*"); 
			label.push("8"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if ((s_top == "2" || s_top == "b" || s_top == "c") && pro == "/")
		{
			label.push("/"); 
			label.push("9"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		if (s_top == "a" && pro == ")")
		{
			label.push(")"); 
			label.push("f"); 
			val.push("null"); 
			val.push("null"); 
			i++; 
			return;
		}
		
		
		//归约表 
		if (s_top == "2" && (pro == "+" || pro == "-" || pro == ")" || pro == "$"))
		{
			label.pop(); label.pop(); s1 = label.top(); label.push("E"); gototable(s1, "E");
			cout << "E->T归约" << endl; return;
		}
		if (s_top == "3" && (pro == "+" || pro == "-" || pro == "*" || pro == "/" || pro == ")" || pro == "$"))
		{
			label.pop(); label.pop(); s1 = label.top(); label.push("T"); gototable(s1, "T");
			cout << "T->F归约" << endl; return;
		}
		if (s_top == "5" && (pro == "+" || pro == "-" || pro == "*" || pro == "/" || pro == ")" || pro == "$"))
		{
			label.pop(); label.pop(); s1 = label.top(); label.push("F"); gototable(s1, "F");
			cout << "F->id归约" << endl; return;
		}
		//+
		if (s_top == "b" && (pro == "+" || pro == "-" || pro == ")" || pro == "$"))
		{	int a, b; bool flag = false;
			for (int i = 0; i < 6; i++)
			{
				label.pop(); val.pop();
				if (val.top() != "null" && !flag)
				{
					a = string_to_num(val.top()); flag = true;
				}
				if (val.top() != "null" && flag)
				{
					b = string_to_num(val.top());
				}
			} string s2 = num_to_string(a + b);
			s1 = label.top(); label.push("E"); val.push(s2); gototable(s1, "E"); val.push("null");
			cout << "E->E+T归约" << endl; return;
		}
		
		//-
		if (s_top == "c" && (pro == "+" || pro == "-" || pro == ")" || pro == "$"))
		{	int a, b; bool flag = false;
			for (int i = 0; i < 6; i++)
			{
				label.pop(); val.pop();
				if (val.top() != "null" && !flag)
				{
					a = string_to_num(val.top()); flag = true;
				}
				if (val.top() != "null" && flag)
				{
					b = string_to_num(val.top());
				}
			} string s2 = num_to_string(b-a);
			s1 = label.top(); label.push("E"); val.push(s2); gototable(s1, "E"); val.push("null");
			cout << "E->E-T归约" << endl; return;
		}
		
		//*
		if (s_top == "d" && (pro == "+" || pro == "-" || pro == "*" || pro == "/" || pro == ")" || pro == "$"))
		{	int a, b; bool flag = false;
			for (int i = 0; i < 6; i++)
			{
				label.pop(); val.pop();
				if (val.top() != "null" && !flag)
				{
					a = string_to_num(val.top()); flag = true;
				}
				if (val.top() != "null" && flag)
				{
					b = string_to_num(val.top());
				}
			} string s2 = num_to_string(a * b);
			s1 = label.top(); label.push("T"); val.push(s2); gototable(s1, "T"); val.push("null");
			cout << "T->T*F归约" << endl; return;
		}
		
		// /
		if (s_top == "e" && (pro == "+" || pro == "-" || pro == "*" || pro == "/" || pro == ")" || pro == "$"))
		{	int a, b; bool flag = false;
			for (int i = 0; i < 6; i++)
			{
				label.pop(); val.pop();
				if (val.top() != "null" && !flag)
				{
					a = string_to_num(val.top()); flag = true;
				}
				if (val.top() != "null" && flag)
				{
					b = string_to_num(val.top());
				}
			} string s2 = num_to_string((int)(b/a));
			s1 = label.top(); label.push("T"); val.push(s2); gototable(s1, "T"); val.push("null");
			cout << "T->T/F归约" << endl; return;
		}
		
		//(
		if (s_top == "f" && (pro == "+" || pro == "-" || pro == "*" || pro == "/" || pro == ")" || pro == "$"))
		{	string a;
			for (int i = 0; i < 6; i++)
			{
				string b = val.top(); label.pop(); val.pop();
				if (b != "null")
				{
					a = b;
				}
			}
			s1 = label.top(); label.push("F"); val.push(a); gototable(s1, "F"); val.push("null");
			cout << "F->(E)归约" << endl; return;
		}
		if (s_top == "1" && pro == "$")
		{
			val.pop();
			cout << val.top() << endl;
			cout << "accept" << endl; exit(0);
		}
		else
		{
			cout << "input error!" << endl;
			exit(0);
		}
	}
	
	//goto表 
	void gototable(string s1, string s2)
	{
		if (s1 == "0" && s2 == "E")
		{
			label.push("1");
		}
		if ((s1 == "0" || s1 == "4") && s2 == "T")
		{
			label.push("2");
		}
		if ((s1 == "0" || s1 == "4" || s1 == "6" || s1 == "7") && s2 == "F")
		{
			label.push("3");
		}
		if (s1 == "4" && s2 == "E")
		{
			label.push("a");
		}
		if (s1 == "6" && s2 == "T")
		{
			label.push("b");
		}
		if (s1 == "7" && s2 == "T")
		{
			label.push("c");
		}
		if (s1 == "8" && s2 == "F")
		{
			label.push("d");
		}
		if (s1 == "9" && s2 == "F")
		{
			label.push("e");
		}
	}
};
int main()
{
	procal p;
	p.getis();
	p.lex();
	return 0;
}

