// BOJ 11286 :: Àý´ñ°ª Èü
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, x;
struct cmp
{
    bool operator()(int a, int b)
    {
        if (abs(a) > abs(b))
            return true;
        else if (abs(a) == abs(b))
            if (a > b)
                return true;
            else
                return false;
        return false;
    }
};
int main()
{
    FASTIO;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
                cout << "0" << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(x);
    }
    return 0;
}