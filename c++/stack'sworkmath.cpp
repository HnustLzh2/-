#include<iostream>
using namespace std;
char op[100010]; //stack of operators
long long nums[100010]; //stack of numbers
int t1 = -1,t2 = -1;
bool isdigit(char ch)
{
    return ch >= '0' && ch <= '9';
}
int compare(char a, char b)
{
    if((a == '+' || a == '-') && (b == '*' || b ==
    '/'))return -1;
    else if((b == '+' || b == '-') && (a == '*' || a ==
    '/'))return 1;
    return 0;
}
void calc(char ch)
{
    long long b = nums[t2--], a = nums[t2 --];
    if(ch == '+') nums[++t2] = a + b;
    else if(ch == '-')nums[++t2] = a - b;
    else if(ch == '*')nums[++t2] = a * b;
    else if(ch == '/')nums[++t2] = a / b;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        char x = s[i];
        if(isdigit(x)){
            long long num = x - '0';
            while(i < s.size() && isdigit(s[++i]))num = num * 10 + s[i] - '0';
            i--;
            nums[++ t2] = num;
        }
        else if(x == '(')op[++ t1] = x;
        else if(x == ')'){
            char ch = op[t1--];
            while(ch == '+' || ch == '*' || ch == '-' || ch == '/'){
                calc(ch);
                ch = op[t1--];
            }
        }
        else{
            char ch = op[t1];
            if(ch == '('){
                op[++ t1] = x;
                continue;
            }
            while(t1 != -1 && ch != '(' && compare(x,ch) != 1 )
            {
                t1--;
                calc(ch);
                ch = op[t1];
                if(ch == '('){
                    break;
                }
            }
            op[++ t1] = x;
        }
    }
    while(t1 != -1)
    {
        char ch = op[t1 --];
        calc(ch);
    }
    cout << nums[t2];
    return 0;
}
