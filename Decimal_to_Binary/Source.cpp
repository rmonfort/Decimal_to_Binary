#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stoi;
using std::vector;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		// Ignore empty lines
		if (line.empty())
		{
			continue;
		}

		// Convert number to decimal
		unsigned int number = stoi(line);
		vector<unsigned int> my_bits;
		while (number != 0)
		{
			unsigned int bit = number % 2;
			number /= 2;
			my_bits.push_back(bit);
		}
		for (auto i = my_bits.crbegin(); i < my_bits.crend(); i++)
		{
			cout << *i;
		}
		cout << endl;
	}

	return 0;
}