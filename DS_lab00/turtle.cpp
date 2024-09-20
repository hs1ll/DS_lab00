#include "turtle.h"

std::vector<std::vector<int>> turtleMaze(std::string const& path, std::vector<std::vector<std::string>>& field)
{
	int n, m, startRow = -1, startCol = -1, finishRow = -1, finishCol = -1;
	turtleGetDataFromFile(path, n, m, startRow, startCol, finishRow, finishCol, field);

	std::vector<std::vector<int>> solution(n * m + 1, { -1, -1 });
	std::vector<std::vector<int>> placements;
	std::vector<std::vector<int>> moves = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1} };

	int mxHorizontal = 0;
	turtleMazeSolution(1, startRow, startCol, moves, field, placements, solution, 0, mxHorizontal);

	return solution;
}
void turtleGetDataFromFile(std::string const& path, int& n, int& m, int& startRow, int& startCol, int& finishRow, int& finishCol, std::vector<std::vector<std::string>>& field)
{
	std::set<std::string> chars = { "#", "F", "0", "S" };

	std::ifstream fin(path);
	if (fin.fail())
		throw std::exception("No such directory.\n");

	std::string line;
	std::getline(fin, line);
	std::regex r("\\d+ \\d+");
	if (!std::regex_match(line, r))
		throw std::exception("Invalid file data.\n");

	r = " ";
	std::smatch match;
	std::regex_search(line, match, r);
	n = std::stoi(match.prefix()), m = std::stoi(match.suffix());
	if (n <= 0 || m <= 0)
		throw std::exception("Invalid file data.\n");

	field.push_back(std::vector<std::string>(m + 2, "#"));
	int i = 0;
	while (std::getline(fin, line))
	{
		std::vector<std::string> row;
		row.push_back("#");

		std::stringstream s(line);
		std::string cell;
		int j = 0;
		while (s >> cell)
		{
			if (!chars.contains(cell))
				throw std::exception("Invalid file data.\n");

			if (cell == "S" && startRow == -1 && startCol == -1)
			{
				startRow = i + 1;
				startCol = j + 1;
			}
			else if (cell == "F" && finishRow == -1 && finishCol == -1)
			{
				finishRow = i + 1;
				finishCol = j + 1;
			}
			else if ((cell == "S" && startRow != -1 && startCol != -1) || (cell == "F" && finishRow != -1 && finishCol != -1))
				throw std::exception("Invalid file data.\n");
			row.push_back(cell);
			++j;
		}
		row.push_back("#");

		if (row.size() != m + 2)
			throw std::exception("Invalid file data.\n");

		field.push_back(row);
		++i;
	}
	field.push_back(std::vector<std::string>(m + 2, "#"));

	if (field.size() != n + 2)
		throw std::exception("Invalid file data.\n");

	fin.close();
}

void turtleMazeSolution(int currentMove, int currentRow, int currentCol,
	std::vector<std::vector<int>> const& moves, std::vector<std::vector<std::string>>& field,
	std::vector<std::vector<int>>& placements, std::vector<std::vector<int>>& solution, int horizontalCount, int& mxHorizontal)
{
	placements.push_back({ currentRow, currentCol });

	if (field[currentRow][currentCol] == "F")
	{
		if (placements.size() < solution.size())
		{
			solution = placements;
			mxHorizontal = horizontalCount;
		}
		else if (placements.size() == solution.size() && horizontalCount > mxHorizontal)
		{
			solution = placements;
			mxHorizontal = horizontalCount;
		}
	}
	else
	{
		field[currentRow][currentCol] = std::to_string(currentMove);
		for (int i = 0; i < moves.size(); ++i)
		{
			if (turtleMazeValidation(currentRow + moves[i][0], currentCol + moves[i][1], field))
			{
				if (moves[i][0] != 0 && moves[i][1] == 0)
					horizontalCount++;
				turtleMazeSolution(currentMove + 1, currentRow + moves[i][0], currentCol + moves[i][1], moves, field, placements, solution, horizontalCount, mxHorizontal);
			}
		}
		field[currentRow][currentCol] = std::to_string(0);
	}

	placements.pop_back();
}
bool turtleMazeValidation(int const& currentRow, int const& currentCol, std::vector<std::vector<std::string>> const& field)
{
	return (field[currentRow][currentCol] == "0" || field[currentRow][currentCol] == "F");
}

void turtleMazeExample(std::string const& path)
{
	std::vector<std::vector<std::string>> field;
	std::vector<std::vector<int>> solution = turtleMaze(path, field);
	printTurlteMazeSolution(field, solution);
}

void printTurlteMazeSolution(std::vector<std::vector<std::string>>& field, std::vector<std::vector<int>> const& solution)
{
	if (solution.size() == (field.size() - 2) * (field[0].size() - 2) + 1)
	{
		std::cout << "No solution.\n";
		return;
	}

	for (int i = 0; i < solution.size(); ++i)
		field[solution[i][0]][solution[i][1]] = std::to_string(i + 1);

	for (int i = 0; i < field.size(); ++i)
	{
		for (int j = 0; j < field[i].size(); ++j)
			std::cout << field[i][j] << "\t";
		std::cout << "\n\n";
	}
}