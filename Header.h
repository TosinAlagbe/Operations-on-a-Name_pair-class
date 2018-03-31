#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

class Name_pairs
{
	std::vector<std::string>name;
	std::vector<double>age;

public:

	std::vector<std::string> retname() const { return name; }
	std::vector<double> retage() const { return age; }

	void read_names();
	void read_ages();
	void sort();
};

void print(Name_pairs& np);
bool operator==(const Name_pairs &nn, const Name_pairs &na);     
bool operator!=(const Name_pairs &nn, const Name_pairs &na);
