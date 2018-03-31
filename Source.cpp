#include "Header.h"

std::ostream &operator<<(std::ostream &os, const Name_pairs &np)
{
	for (int i = 0; i < np.retname().size(); ++i)
	{
		os << '(' << np.retname()[i] << ',' << np.retage()[i] << ')' << std::endl;
	}
	return os;
}

void print(Name_pairs& np)
{
	std::cout << np;
}

void Name_pairs::sort()
{
	std::vector<std::string>temp_name = name;
	std::vector<double>temp_age = age;

	std::sort(name.begin(),name.end());
	
	for (int i = 0; i<name.size(); ++i)
	{
		for (int j = 0; j < temp_name.size(); ++j)
		{
			if (name[i] == temp_name[j])
			{
				age[i] = temp_age[j];
			}
		}	
	}
}

bool operator==(const Name_pairs &nn, const Name_pairs &na)
{
	return nn.retname() == na.retname()
		&& nn.retage() == na.retage();
}

bool operator!=(const Name_pairs &nn, const Name_pairs &na)
{
	return !(nn == na);
}

void Name_pairs::read_names()
{
	std::string a;
	while (std::cin >> a && a != ";")
	{
		name.push_back(a);
	}
}

void Name_pairs::read_ages()
{
	double b;
	for (int i = 0; i < name.size(); ++i)
	{
		std::cin >> b;
		age.push_back(b);
	}
}

int main()
{
	
	Name_pairs test;
	std::cout << "Input Names for storage(end input with ';') :\n";
	test.read_names();
	std::cout << "Input corresponding ages :\n";
	test.read_ages();
	std::cout << "(Name, age) pair : \n";
	print(test);
	std::cout << std::endl << std::endl;
	std::cout << "Alphabetically sorted: \n";
	test.sort();
	print(test);
	std::cout << "\n\n";

	Name_pairs test2;
	std::cout << "Input Names for storage(end input with ';') :\n";
	test2.read_names();
	std::cout << "Input corresponding ages :\n";
	test2.read_ages();
	std::cout << "(Name, age) pair : \n";
	print(test2);
	std::cout << std::endl << std::endl;

	std::cout << "Similarity check:\n";
	if (test == test2)std::cout << "identical\n";
	else std::cout << "unidentical\n";

	system("pause");

}


