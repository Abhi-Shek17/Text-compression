#include <bits/stdc++.h>
using namespace std;
class btn
{
public:
    char a;
    int count;
    btn *left;
    btn *right;
    btn(char data, int c)
    {
        a = data;
        count = c;
        left = NULL;
        right = NULL;
    }
    btn(btn *l, btn *r)
    {
        a = (char)0;
        count = l->count + r->count;
        left = l;
        right = r;
    }
    ~btn()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
    }
};