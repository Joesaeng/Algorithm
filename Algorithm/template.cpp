// TEMPLATE

#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 987654321
using namespace std;
using ll = long long;


// 큰 수 덧셈
string Sum(string left, string right)
{
	int sum = 0;
	string ret;

	while (!left.empty() || !right.empty() || sum)
	{
		if (!left.empty())
		{
			sum += left.back() - '0';
			left.pop_back();
		}
		if (!right.empty())
		{
			sum += right.back() - '0';
			right.pop_back();
		}
		ret.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

// 큰 수 뺄셈
string subtraction(string left, string right)
{
	bool b = false;
	ll res = 0, leftl = left.length(), rightl = right.length();
	string s;

	for (ll i = 0; i < leftl || i < rightl; ++i)
	{
		if (i < leftl)
		{
			res += left[leftl - i - 1] - '0';
			if (b) { res--; b = false; }
		}
		if (i < rightl)
			res -= right[rightl - i - 1] - '0';

		if (res < 0)
		{
			res = 10 - abs(res);
			b = true;
		}
		s += res + '0';
		res = 0;
	}
	if (s.back() == '0' && s.length() > 1) s.pop_back();
	reverse(s.begin(), s.end());

	return s;
}

// 큰 수 나눗셈(제수는 long long 이하)
string ll_div(string str, ll div)
{
	ll res = 0;
	string s;

	for (ll i = 0; i < str.length(); ++i)
	{
		res = (res * 10) + str[i] - '0';
		s += (res / div) + '0';
		res %= div;
	}
	int i = 0;
	for (; i < s.length(); ++i)
		if (s[i] != '0') break;
	s = s.substr(i, s.length());
	return s;
}

// 두 좌표(x,y) 사이의 길이
double length(double x, double y, double xx, double yy)
{
	double ret = sqrt((xx - x) * (xx - x) + (yy - y) * (yy - y));
	return ret;
}

// 헤론의 공식(세 변의 길이 a,b,c 가 있을 때 삼각형의 넓이를 구함)
double Heron(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	double ret = sqrt(s * (s - a) * (s - b) * (s - c));
	return ret;
}

// 신발끈 공식 : n개의 점으로 이루어진 다각형의 각 점들의 좌표가 시계or반시계 방향으로 주어졌을 때, 다각형의 넓이를 구하는 공식
double shoelace(int n, vector<pair<double, double>>& points)
{
	double ret;
	double fx = points[0].first;
	double fy = points[0].second;
	double aa = 0;
	double bb = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		double a = points[i].first * points[i + 1].second;
		double b = points[i].second * points[i + 1].first;
		aa += a;
		bb += b;
	}
	double a = points[n - 1].first * fy;
	double b = points[n - 1].second * fx;
	aa += a;
	bb += b;

	ret = abs(aa - bb) / 2;

	return ret;
}

// 이중 우선순위 큐
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

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.first < b.first;
}
int bigger(const int left, const int right)
{
	return left > right ? left : right;
}

int main()
{
    FASTIO;

    return 0;
}

// 다익스트라 알고리즘
int func(int start, int dest)
{
	int pos = start;
	vector<int> dist = vector<int>(n + 1, INF);
	priority_queue<pair<int, int>> q;
	dist[pos] = 0;
	q.push(pair{ 0,pos });

	while (!q.empty())
	{
		int cost = -q.top().first;
		pos = q.top().second;
		q.pop();

		if (pos == dest) return cost;

		for (int i = 0; i < road[pos].size(); ++i)
		{
			int next = road[pos][i].second;
			int nCost = road[pos][i].first;
			if (dist[next] > cost + nCost)
			{
				dist[next] = cost + nCost;
				q.push(pair{ -dist[next], next });
			}
		}
	}
	return -1;
}