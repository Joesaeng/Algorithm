// BOJ 9935 :: ���ڿ� ����
#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
string str;
string bomb;
string ans;
int bombIdx;
int strSize;
int main()
{
    FASTIO;
    cin >> str >> bomb;
    for (int i = 0; i < str.size(); ++i)
    {
        ans += str[i];
        // �̹��� �߰��� ���ڰ� ���� ���ڿ��� ���ڸ��� ���ٸ�
        if (str[i] == bomb[bomb.size() - 1]) 
        {
            bool b = true;
            // ���ڿ����� �������� �̵��ϸ鼭 ���� ���ڿ��� �´��� Ȯ��
            for (int j = 0; j < bomb.size(); ++j)
            {
                if (ans.size() - 1 - j < 0) break;
                if (ans[ans.size() - 1 - j] != bomb[bomb.size() - 1 - j])
                {
                    b = false;
                    break;
                }
                bombIdx = ans.size() - 1 - j;
            }
            if (b) ans.erase(bombIdx, bomb.size());
        }
    }
    if (ans.size() == 0) cout << "FRULA";
    else cout << ans;
    return 0;
}