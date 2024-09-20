#include "ssearch.h"

int linearStringSearch(std::string string, std::string target, int& compares)
{
	for (int i = 0; i <= string.size() - target.size(); ++i)
	{
		int j = 0;
		while (j < target.size() && string[i + j] == target[j])
		{
			compares++;
			++j;
		}

		if (j == target.size())
			return i;

		compares++;
	}

	return -1;
}

int BoerMooreSearch(std::string string, std::string target, int& compares)
{
	std::vector<int> shifts(1000, target.size());
	for (int i = 0; i < target.size() - 1; ++i)
		shifts[abs((int)target[i])] = target.size() - i - 1;

	int i = 0;
	while (i <= string.size() - target.size())
	{
		int j = target.size() - 1;
		while (j > -1 && string[i + j] == target[j])
		{
			compares++;
			--j;
		}
		
		if (j < 0)
			return i;
		
		compares++;
		i += shifts[abs((int)string[i + target.size() - 1])];
	}

	return -1;
}

int KMPSearch(std::string string, std::string target, int& compares)
{
	std::string s = target + '#' + string;
	std::vector<int> maxLen(s.size(), 0);
	int i = 0;
	while (i < s.size() - 1)
	{
		++i;
		int prevLen = maxLen[i - 1];
		while (prevLen > 0 && s[prevLen] != s[i])
			prevLen = maxLen[prevLen - 1];

		if (s[prevLen] == s[i])
			maxLen[i] = prevLen + 1;
		else
			maxLen[i] = 0;

		compares++;
		if (maxLen[i] == target.size())
		{
			compares -= target.size();
			return i - 2 * target.size();
		}
	}

	compares -= target.size();
	return -1;
}

int hs(std::string string)
{
	int sum = 0;
	for (int i = 0; i < string.size(); ++i)
		sum += (int)string[i];
	return sum;
}
int KRSearch(std::string string, std::string target, int& compares)
{
	int hsTarget = hs(target);
	std::string s;
	for (int i = 0; i < target.size(); ++i)
		s.push_back(string[i]);
	int h = hs(s);

	for (int i = 0; i <= string.size() - target.size(); ++i)
	{
		if (h == hsTarget)
		{
			int j = 0;
			while (j < target.size() && string[i + j] == target[j])
			{
				compares++;
				++j;
			}
			
			if (j == target.size())
				return i;

			compares++;
		}
		h -= (int)string[i];
		h += (int)string[i + target.size()];
	}

	return -1;
}