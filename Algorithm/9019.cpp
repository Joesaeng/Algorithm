// BOJ 9019 :: DSLR
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, A, B;
pair<int, char> parent[10000];
int D(int a)
{
    return (a * 2) % 10000;
}
int S(int a)
{
    if (a == 0) return 9999;
    else return a - 1;
}
int L(int a)
{
    int ret = (a % 1000) * 10 + a / 1000;
    return ret;
}
int R(int a)
{
    int ret = (a % 10) * 1000 + a / 10;
    return ret;
}
void func()
{
    queue<int> q;
    vector<bool> discov(10000, false);
    string str;
    int pos = A;
    q.push(pos);
    parent[pos] = pair{ pos,'0' };
    discov[pos] = true;
    while (!q.empty())
    {
        int qsize = q.size();
        for (int i = 0; i < qsize; ++i)
        {
            pos = q.front();
            q.pop();
            if (pos == B)
            {
                while (!q.empty()) q.pop();
                break;
            }
            int d = D(pos);
            int s = S(pos);
            int l = L(pos);
            int r = R(pos);
            if (d == B){parent[d] = pair{ pos,'D' };while (!q.empty()) q.pop();break;}
            if (s == B){parent[s] = pair{ pos,'S' };while (!q.empty()) q.pop();break;}
            if (l == B){parent[l] = pair{ pos,'L' };while (!q.empty()) q.pop();break;}
            if (r == B){parent[r] = pair{ pos,'R' };while (!q.empty()) q.pop();break;}
            if (discov[d] == false)
            {
                q.push(d);
                parent[d] = pair{ pos,'D' };
                discov[d] = true;
            }
            if (discov[s] == false)
            {
                q.push(s);
                parent[s] = pair{ pos,'S' };
                discov[s] = true;
            }
            if (discov[l] == false)
            {
                q.push(l);
                parent[l] = pair{ pos,'L' };
                discov[l] = true;
            }
            if (discov[r] == false)
            {
                q.push(r);
                parent[r] = pair{ pos,'R' };
                discov[r] = true;
            }
        }

    }
    pos = B;
    while (parent[pos].first != pos)
    {
        if (parent[pos].first == pos)
            break;
        str += parent[pos].second;
        pos = parent[pos].first;
    }
    reverse(str.begin(), str.end());
    for (auto a : str)
        cout << a;
    cout << '\n';
}

int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> A >> B;
        func();
    }
    return 0;
}