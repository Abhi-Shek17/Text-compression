#include <bits/stdc++.h>
using namespace std;
string charbw(string &s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        string temp = "";
        int c = (int)s[i];
        for (int j = 6; j >= 0; j--)
        {
            if (c >= pow(2, j))
            {
                c = c - pow(2, j);
                temp += '1';
            }
            else
            {
                temp += '0';
            }
        }
        ans += '0' + temp;
    }
    return ans;
}
int main()
{
    ifstream read("secret.txt");
    string secret = "";
    string useme;
    while (getline(read, secret))
    {
        secret += useme;
    }

    map<string, char> m;
    int i = 1;
    while (secret[i] != '}')
    {
        char a = secret[i];
        string code = "";
        i++;
        i++;
        while (secret[i] != ',')
        {
            code += secret[i];
            i++;
        }
        m[code] = a;
        i++;
    }
    i++;
    secret = secret.substr(i);
    string decodetob = charbw(secret);
    string output = "";
    for (int j = 0; j < decodetob.size(); j++)
    {
        string tempchar = "";
        char a;
        while (!m.count(tempchar))
        {
            if (j % 8 == 0)
                j++;
            if (j >= decodetob.size())
            {
                break;
            }
            tempchar += decodetob[j];
            j++;
        }
        j--;
        a = m[tempchar];
        output += a;
    }
    cout << output;
    read.close();
    ofstream writeans("output.txt");
    
}
