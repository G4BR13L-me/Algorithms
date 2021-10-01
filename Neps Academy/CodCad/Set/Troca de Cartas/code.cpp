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
    int A, B, card;
    cin >> A >> B;
    set<int> setA, setB;
    for (int i = 0; i < A; i++)
    {
        cin >> card;
        setA.insert(card);
    }
    for (int i = 0; i < B; i++)
    {
        cin >> card;
        setB.insert(card);
    }

    int countA = 0, countB = 0;
    for (auto x : setA)
    {
        if (setB.find(x) == setB.end())
            countA++;
    }
    for (auto x : setB)
    {
        if (setA.find(x) == setA.end())
            countB++;
    }
    cout << (countA < countB ? countA : countB) << endl;
    return 0;
}