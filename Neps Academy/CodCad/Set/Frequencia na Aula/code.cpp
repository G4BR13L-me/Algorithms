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
    int N, student;
    set<int> s;
    cin >> N;
    while (N--)
    {
        cin >> student;
        s.insert(student);
    }
    cout << s.size() << endl;

    return 0;
}