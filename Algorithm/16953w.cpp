// BOJ 16953 :: A -> B
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;
ll a;
ll b;
set<int> vis; // 트리를 이용한 방문 체크
int func()
{
    // A에서 B로 가는 여러가지 경로가 있을 수 있으니
    // 최단경로를 찾기 위해서 BFS탐색을 한다.
    queue<pair<int,int>> q;
    ll n = a;
    ll cnt = 1; // 최솟값 1
    vis.insert(n);
    q.push({ n,cnt }); // 현재값 n과 연산 회수 cnt
    while (!q.empty())
    {
        n = q.front().first;
        cnt = q.front().second;
        q.pop();
        if (n == b) return cnt;
        ll next = (n * 10) + 1; // 1을 수의 가장 오른쪽에 추가
        // 가능한 연산 두가지가 이전의 수보다 커지는 연산이기 때문에
        // 목표값 b를 넘어선다면 더이상 탐색하지 않는다.
        if (next <= b && vis.find(next) == vis.end())
        {
            vis.insert(n);
            q.push({ next,cnt + 1 });
        }
        next = n * 2;
        if (next <= b && vis.find(next) == vis.end())
        {
            vis.insert(n);
            q.push({ next,cnt + 1 });
        }
    }
    return -1;
}
int main()
{
    FASTIO;
    cin >> a >> b;
    cout << func();
    return 0;
}