#include <iostream>
#include <stack>
#include <map>
#include <string>

struct node{
    char exp;
    node *left;
    node *right;
    node()
    {
        exp = '=';
        left = right = nullptr;
    }
    node(char ex)
    {
        exp = ex;
        left = right = nullptr;
    }
    node(char ex, node *l, node *r)
    {
        exp = ex;
        left = l;
        right = r;
    }
};

bool judge(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '=')
        return true;
    else
        return false;
}

int operate(int a, char c, int b)
{
    int ans;
    if (c == '+')
        ans = a + b;
    else if (c == '-')
        ans = a - b;
    else if (c == '*')
        ans = a * b;
    else
        ans = a / b;
    return ans;
}


char compare(char c1, char c2)
{
    int int_c1, int_c2;
    std::map<char, int> optr;
    optr['+'] = 1;
    optr['-'] = 2;
    optr['*'] = 3;
    optr['/'] = 4;
    optr['('] = 5;
    optr[')'] = 6;
    optr['='] = 7;
    int_c1 = optr[c1];
    int_c2 = optr[c2];

    if (int_c1 == 1 || int_c1 == 2)
    {
        if (int_c2 >= 3 && int_c2 <= 5)
            return '<';
        else
            return '>';
    }

    if (int_c1 == 3 || int_c1 == 4)
    {
        if (int_c2 == 5)
            return '<';
        else
            return '>';
    }

    if (int_c1 == 5)
    {
        if (int_c2 == 6)
            return '=';
        else if (int_c2 == 7)
            return '#';
        else
            return '<';
    }

    if (int_c1 == 6)
    {
        if (int_c2 == 5)
            return '#';
        else
            return '>';
    }

    if (int_c1 == 7)
    {
        if (int_c2 == 7)
            return '=';
        else if (int_c2 == 6)
            return '#';
        else
            return '<';
    }
}

void init_tree(std::string s, node* &T)
{
    std::stack<node*> EXPT;
    std::stack<char> OPTR;
    OPTR.push('=');
    int i = 0;
    while (i < s.size() && (s[i] != '=' || OPTR.top() != '='))
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            T = new node(s[i]);
            EXPT.push(T);
            i++;
        }
        else if (judge(s[i]))
        {
            switch (compare(OPTR.top(), s[i]))
            {
                case '<':
                {
                    OPTR.push(s[i]);
                    i++;
                    break;
                }
                case '>':
                {
                    char opt = OPTR.top();
                    OPTR.pop();
                    node* b = EXPT.top();
                    EXPT.pop();
                    node* a = EXPT.top();
                    EXPT.pop();
                    T = new node(opt, a, b);
                    EXPT.push(T);
                    break;
                }
                case '=':
                {
                    OPTR.pop();
                    i++;
                    break;
                }
            }
        }
    }
}

int calculate(node* T)
{
    int lexp = 0, rexp = 0;
    if (T->left == nullptr && T->right == nullptr)
        return T->exp - '0';
    else
    {
        lexp = calculate(T->left);
        rexp = calculate(T->right);
        return operate(lexp, T->exp, rexp);
    }
}

int main()
{
    std::string s;
    while(true)
    {
        std::cin >> s;
        if(s == "=")
            break;
        node *root;
        init_tree(s, root);
        std::cout << calculate(root) << std::endl;
    }
    return 0;
}
