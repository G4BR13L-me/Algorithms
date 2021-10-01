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
    int N, D;
    while ((cin >> N >> D) && (N + D))
    {
        vector<char> s;
        string number;
        int finalSize = N - D;
        cin >> number;
        for (int i = 0; i < number.size(); i++)
        {
            while (!s.empty() && s.back() < number[i] && D)
            {
                s.pop_back();
                D--;
            }
            if (s.size() < finalSize)
                s.push_back(number[i]);
        }

        for (auto a : s)
        {
            cout << a;
        }
        cout << endl;
    }

    return 0;
}