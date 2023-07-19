#include <bits/stdc++.h>
#include "btree.h"
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}
void ins(btn *n, map<char, string> &m, string s)
{
    if (n->left == NULL && n->right == NULL)
    {
        m[n->a] = s;
        return;
    }
    ins(n->left, m, s + '0');
    ins(n->right, m, s + '1');
}
string bwchar(string c)
{
    string ans = "";
    int size = c.size();
    while (size >= 8)
    {
        string es = c.substr(1, 7);
        c = c.substr(8);
        int an = 0;
        for (int i = 0; i < 7; i++)
        {
            an += (es[6 - i] - '0') * pow(2, i);
        }
        ans += (char)an;
        size = size - 8;
    }

    int an = 0;
    for (int i = 0; i < size; i++)
    {
        an += (c[i] - '0') * pow(2, 6 - i);
    }
    ans += (char)an;
    return ans;
}
int main()
{
    ifstream Myfile("test.txt");
    string temp;
    string final = "";
    while (getline(Myfile, temp))
    {
        final = final + (char)1 + temp;
    }
    map<char, int> m;
    for (int i = 0; i < final.size(); i++)
    {
        m[final[i]]++;
    }
    vector<pair<char, int>> freq;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        pair<char, int> a;
        a.first = it->first;
        a.second = it->second;
        freq.push_back(a);
    }
    sort(freq.begin(), freq.end(), cmp);
    int i = 0;
    int e = freq.size() - 2;
    int size = freq.size();
    int gap = INT_MIN;
    btn *tempnode = new btn(freq[e + 1].first, freq[e + 1].second);

    while (e >= 24)
    {
        btn *temp1 = new btn(freq[e].first, freq[e].second);
        btn *node = new btn(temp1, tempnode);
        tempnode = node;
        e--;
    }
    btn *tempnode2 = new btn(freq[e].first, freq[e].second);
    e--;
    while (e >= 12)
    {
        btn *temp1 = new btn(freq[e].first, freq[e].second);
        btn *node = new btn(temp1, tempnode2);
        tempnode2 = node;
        e--;
    }
    btn *head1 = new btn(tempnode, tempnode2);
    btn *head2 = new btn(freq[e].first, freq[e].second);
    e--;
    while (e >= 7)
    {
        btn *temp1 = new btn(freq[e].first, freq[e].second);
        btn *node = new btn(temp1, head2);
        head2 = node;
        e--;
    }
    btn *last1 = new btn(head1, head2);
    btn *last2 = new btn(freq[e].first, freq[e].second);
    e--;
    while (e >= 4)
    {
        btn *temp1 = new btn(freq[e].first, freq[e].second);
        btn *node = new btn(temp1, last2);
        last2 = node;
        e--;
    }
    btn *head = new btn(last2, last1);
    while (e >= 0)
    {
        btn *temp1 = new btn(freq[e].first, freq[e].second);
        btn *node = new btn(temp1, head);
        head = node;
        e--;
    }
    map<char, string> encode;
    string s = "";
    ins(head, encode, s);
    ofstream writefile("secret.txt");
    writefile << '{';
    for (auto it = encode.begin(); it != encode.end(); it++)
    {
        writefile << it->first << ':' << it->second << ',';
    }
    writefile << '}';
    string encoded = "";
    for (int i = 0; i < final.size(); i++){
        string code = encode[final[i]];
        for (int k = 0; k < code.size(); k++)
        {
            if (encoded.size() % 8 == 0)
            {
                encoded += '0';
            }
            encoded += code[k];
        }
    }
    string encodedtochar = bwchar(encoded);
    writefile << encodedtochar;
    Myfile.close();
    writefile.close();
}