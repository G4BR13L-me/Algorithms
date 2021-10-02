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
    int N, D, fatia;
    cin >> N >> D;
    vector<int> fatias;
    for (int i = 0; i < N; i++)
    {
        cin >> fatia;
        fatias.push_back(fatia);
    }

    int right = 0, sum = 0, len = 0, count = 0;
    for (int i = 0; i < N; i++)
    {
        while (sum < D && len < i + N)
        {
            if (right == N)
                right = 0;
            sum += fatias[right++];
            len++;
        }
        if (sum == D)
            count++;
        sum -= fatias[i];
    }
    cout << count << endl;

    return 0;
}