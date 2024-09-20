#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <set>
#include <regex>
#include <sstream>

std::vector<std::vector<int>> turtleMaze(std::string const& path, std::vector<std::vector<std::string>>& field);
void turtleGetDataFromFile(std::string const& path, int& n, int& m, int& startRow, int& startCol, int& finishRow, int& finishCol, std::vector<std::vector<std::string>>& field);
void turtleMazeSolution(int currentMove, int currentRow, int currentCol,
	std::vector<std::vector<int>> const& moves, std::vector<std::vector<std::string>>& field, 
	std::vector<std::vector<int>>& placements, std::vector<std::vector<int>>& solution, int horizontalCount, int& mxHorizontal);
bool turtleMazeValidation(int const& currentRow, int const& currentCol, std::vector<std::vector<std::string>> const& field);

void turtleMazeExample(std::string const& path);

void printTurlteMazeSolution(std::vector<std::vector<std::string>>& field, std::vector<std::vector<int>> const& solution);