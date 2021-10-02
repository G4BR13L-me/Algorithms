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
    int C, N, T, D, out, count = 0;
    priority_queue<int, vector<int>, greater<int>> atendimento;
    cin >> C >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T >> D;
        if (atendimento.size() >= C)
        {
            out = atendimento.top();
            atendimento.pop();

            if (out > T + 20)
                count++;

            if (T > out)
                atendimento.push(T + D);
            else
                atendimento.push(D + out);
        }
        else
        {
            atendimento.push(T + D);
        }
    }
    cout << count << endl;

    return 0;
}