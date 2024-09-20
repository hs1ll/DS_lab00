#pragma once
#include <string>
#include <vector>
#include <cmath>

int linearStringSearch(std::string string, std::string target, int& compares);

int BoerMooreSearch(std::string string, std::string target, int& compares);

int KMPSearch(std::string string, std::string target, int& compares);

int hs(std::string string);
int KRSearch(std::string string, std::string target, int& compares);