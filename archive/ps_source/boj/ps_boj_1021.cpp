#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int N, M;
deque <int> _deq;
queue<int> seq;

void cmd_left(deque<int>& deq)
{
	int temp = deq.front();
	deq.pop_front();
	deq.push_back(temp);
}

void cmd_right(deque<int>& deq)
{
	int temp = deq.back();
	deq.pop_back();
	deq.push_front(temp);
}

void run()
{
	int cnt = 0;
	deque<int> deq;

	while (1)
	{
		if (seq.empty())
		{
			cout << cnt;
			break;
		}
		int SEQ = seq.front();
		int t_cnt[2] = { 0,0 };

		for (int i = 0; i < 2; i++)
		{
			deq = _deq;
			while (1)
			{
				if (deq.front() == SEQ)
				{
					break;
				}
				else
				{
					if (i == 0)
					{
						cmd_left(deq);
						t_cnt[i]++;
					}
					else
					{
						cmd_right(deq);
						t_cnt[i]++;
					}
				}
			}
		}

		if (t_cnt[0] <= t_cnt[1])
		{
			cnt += t_cnt[0];
		}
		else
		{
			cnt += t_cnt[1];
		}

		seq.pop();
		deq.pop_front();
		_deq = deq;
	}
}

void init()
{
	//freopen("Text.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		_deq.push_back(i);
	}
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		seq.push(n);
	}

}

int main()
{
	init();
	run();
	return 0;
}
