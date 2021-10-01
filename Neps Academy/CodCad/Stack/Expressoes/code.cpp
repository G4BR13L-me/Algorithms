#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

int main()
{
    optimize;
    int T;
    string s;
    cin >> T;
    while (T--)
    {
        stack<char> match;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (match.empty())
            {
                match.push(s[i]);
            }
            else
            {
                if (match.top() == '{' && s[i] == '}')
                {
                    match.pop();
                }
                else if (match.top() == '[' && s[i] == ']')
                {
                    match.pop();
                }
                else if (match.top() == '(' && s[i] == ')')
                {
                    match.pop();
                }
                else
                {
                    match.push(s[i]);
                }
            }
        }
        if (match.empty())
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}