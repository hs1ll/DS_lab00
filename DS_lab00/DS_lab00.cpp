#include <iostream>
#include <Windows.h>
#include <fstream>
#include "ssearch.h"
#include "turtle.h"

void combSort(std::vector<int>& arr, int& swaps);

void oddEvenSort(std::vector<int>& arr, int& swaps);

int main()
{
#pragma region TASK 01
	/*setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);

	std::ifstream fin;

	fin.open("../res/mu.txt");
	std::string str = "";
	std::vector<std::string> lines;
	while (!fin.eof())
	{
		if (std::getline(fin, str))
			lines.push_back(str);
	}
	fin.close();
	SetConsoleCP(866);

	int linearCompares = 0, boerCompares = 0, KMPCompares = 0, KRCompares = 0;
	const std::string target = "Муму";
	for (std::string s : lines)
	{
		linearStringSearch(s, target, linearCompares);
		BoerMooreSearch(s, target, boerCompares);
		KMPSearch(s, target, KMPCompares);
		KRSearch(s, target, KRCompares);
	}
	std::cout << "Search fucntion\t\tCompares number\n";
	std::cout << "Linear\t\t\t" << linearCompares << "\n";
	std::cout << "BoerMoore\t\t" << boerCompares << "\n";
	std::cout << "KMP\t\t\t" << KMPCompares << "\n";
	std::cout << "KR\t\t\t" << KRCompares << "\n";*/
#pragma endregion

#pragma region TASK 02
	std::vector<int> combArr = { 4, 2, 5, 1, 3, 6, 0, 8, 9, 7, 14, 12, 15, 11, 13, 16, 10, 18, 19, 17 };
	std::vector<int> oddEvenArr = { 4, 2, 5, 1, 3, 6, 0, 8, 9, 7, 14, 12, 15, 11, 13, 16, 10, 18, 19, 17 };
	std::cout << "Original array: ";
	for (int i : combArr)
		std::cout << i << " ";
	int combSwaps = 0, oddEvenSwaps = 0;
	combSort(combArr, combSwaps);
	oddEvenSort(oddEvenArr, oddEvenSwaps);
	std::cout << "\nComb Sort: " << combSwaps;
	std::cout << "\nOdd-Even Sort: " << oddEvenSwaps;
#pragma endregion

#pragma region TASK 03
	/*std::vector<std::vector<std::string>> field;
	std::vector<std::vector<int>> solution = turtleMaze("../res/maze.txt", field);
	printTurlteMazeSolution(field, solution);*/
#pragma endregion

#pragma region TASK 04
	/*std::vector<int> nums = { 10, 1, 1, 2, 3, 2, 1, 0, 5, -1, -10 };
	std::vector<std::vector<int>> seqs(nums.size());
	for (int i = 0; i < nums.size(); ++i)
		seqs[i].push_back(nums[i]);

	for (int j = 1; j < nums.size(); ++j)
	{
		for (int i = 0; i < j; ++i)
		{
			if (nums[j] < nums[i])
			{
				if (seqs[i].size() + 1 > seqs[j].size())
				{
					seqs[j] = seqs[i];
					seqs[j].push_back(nums[j]);
				}
			}
		}
	}

	int mxIndex = 0;
	for (int i = 1; i < seqs.size(); ++i)
	{
		if (seqs[mxIndex].size() < seqs[i].size())
			mxIndex = i;
	}

	std::cout << "Original numbers: ";
	for (int i : nums)
		std::cout << i << " ";
	std::cout << "\nLongest decreasing subsequence: ";
	for (int i : seqs[mxIndex])
		std::cout << i << " ";
	std::cout << "\n";*/
#pragma endregion
}

void combSort(std::vector<int>& arr, int& swaps)
{
	double factor = 1.3;
	int step = arr.size() - 1;

	while (step >= 1)
	{
		for (int i = 0; i + step < arr.size(); i++)
		{
			if (arr[i] > arr[i + step])
			{
				std::swap(arr[i], arr[i + step]);
				++swaps;
			}
		}
		step /= factor;
	}
}

void oddEvenSort(std::vector<int>& arr, int& swaps)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 2; j < arr.size(); j += 2)
			{
				if (arr[j] < arr[j - 1])
				{
					std::swap(arr[j], arr[j - 1]);
					++swaps;
				}
			}
		}
		else
		{
			for (int j = 1; j < arr.size(); j += 2)
			{
				if (arr[j] < arr[j - 1])
				{
					std::swap(arr[j], arr[j - 1]);
					++swaps;
				}
			}
		}
	}
}