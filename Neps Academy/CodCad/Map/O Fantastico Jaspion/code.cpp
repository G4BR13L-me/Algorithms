#include <bits/stdc++.h>
using namespace std;
#define optimize                 \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)
#define endl '\n'
#define ll long long

vector<string> split(string s)
{
    stringstream ss(s);
    string word;
    vector<string> ans;
    while (ss >> word)
    {
        ans.push_back(word);
    }
    return ans;
}

int main()
{
    optimize;
    int T, M, N;
    string jap, br;
    cin >> T;
    while (T--)
    {
        unordered_map<string, string> translate;
        cin >> M >> N;
        getline(cin, jap);
        while (M--)
        {
            getline(cin, jap);
            getline(cin, br);
            translate[jap] = br;
        }

        while (N--)
        {
            getline(cin, jap);
            vector<string> words = split(jap);
            for (auto word : words)
            {
                if (translate[word] == "")
                    cout << word << " ";
                else
                    cout << translate[word] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}