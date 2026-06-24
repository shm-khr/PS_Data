#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <algorithm>

using ii = std::pair<int, int>;
std::vector<int> vi;
std::vector<int> table;

void manacher()
{
	int r = 0;
	int p = 0;

	for (int i = 1; i < vi.size(); i++)
	{
		if (i <= r)
			table[i] = std::min(table[2 * p - i], r - i);
		else
			table[i] = 0;

		while (i - table[i] - 1 > 0 && i + table[i] + 1 < vi.size() &&
			vi[i - table[i] - 1] == vi[i + table[i] + 1])
			table[i]++;

		if (r < i + table[i])
		{
			r = i + table[i];
			p = i;
		}
	}
}

int main()
{
	std::string a;
	std::cin >> a;

	int pos[26][26] = { 0, };

	for (int i = 0; i < a.size(); i++)
	{
		if (i > 0)
		{
			pos[a[i] - 'a'][a[i - 1] - 'a']++;
		}

		vi.push_back(-1);
		vi.push_back(a[i] - 'a');

		table.push_back(0);
		table.push_back(0);
	}

	manacher();

	long long int l = a.size();

	long long int total = l * (l - 1) / 2 + 1;

	for (int i = 0; i < l - 1; i++)
	{
		if (i > 0)
			pos[a[i] - 'a'][a[i - 1] - 'a']--;

		for (int j = 0; j < 26; j++)
		{
			if (j == a[i + 1] - 'a')
				continue;

			total -= pos[a[i] - 'a'][j];
		}
	}

	for (int i = 2; i < table.size() - 1; i ++)
	{
		if (i % 2 == 0)
		{
			total -= (table[i] + 1) / 2;
		}
		else
		{
			total -= table[i] / 2;
		}
	}

	printf("%lld", total);

	return 0;
}