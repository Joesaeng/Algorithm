// BOJ 7662 :: 이중 우선순위 큐
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int t, k, a;
char c;

template<typename T>
class DualQueue
{
public:
    void input(T n)
    {
        q.insert(n);
    }
    void pop(T n)
    {
        if (q.empty()) return;
        if (n == -1)
        {
            auto iter = q.begin();
            q.erase(iter);
        }
        else if (n == 1)
        {
            auto iter = q.end();
            --iter;
            q.erase(iter);
        }
        
    }
    bool empty()
    {
        return q.empty();
    }
    int MAX()
    {
        auto iter = q.end();
        --iter;
        return *iter;
    }
    int MIN()
    {
        auto iter = q.begin();
        return *iter;
    }

private:
    multiset<T> q;
};

int main()
{
    FASTIO;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> k;
        DualQueue<int> dq;
        for (int j = 0; j < k; ++j)
        {
            cin >> c;
            if (c == 'I')
            {
                cin >> a;
                dq.input(a);
            }
            else if (c == 'D')
            {
                cin >> a;
                dq.pop(a);
            }
        }
        if (dq.empty()) cout << "EMPTY" << '\n';
        else
        {
            cout << dq.MAX() << ' ' << dq.MIN() << '\n';
        }
    }
    return 0;
}