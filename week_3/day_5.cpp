#include <iostream>
#include <algorithm>

int N, M;
long long max;
long long lines[100001];

void input()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		std::cin >> lines[i];
		if (max < lines[i])
			max = lines[i];
	}
}

void solution()
{
	long long start, mid, end, count;
	long long result;

	start =  1;
	end = max * M;
	result = max * M;
	while (start <= end)
	{
		count = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
			count += mid / lines[i];

		if (count >= M)
		{
			end = mid - 1;
			if (result > mid)
				result = mid;
		}
		else
			start = mid + 1;
	}
	std::cout << result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	input();
	solution();
	return 0;
}
