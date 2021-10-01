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
    int T;
    string s;
    stack<char> match;
    cin >> T;
    getline(cin, s);
    while (T--)
    {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != '{' && s[i] != '}')
                continue;

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
                else
                {
                    match.push(s[i]);
                }
            }
        }
    }
    if (match.empty())
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}