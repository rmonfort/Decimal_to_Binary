#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::stoi;
using std::vector;
using std::find_if;

// Checks if number is a digit and positive
bool is_positive_number(const std::string& s)
{
	return find_if(s.begin(), s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

// Convert decimal number to binary and outputs the result
void convert_decimal_to_binary(unsigned int number)
{
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

		// Check if positive
		if (is_positive_number(line))
		{
			// Convert string to integer
			unsigned int number = stoi(line);

			// If number is zero output 0 and continue the loop
			if (number == 0)
			{
				cout << "0" << endl;
				continue;
			}

			// Converts the number to binary and outputs the results
			convert_decimal_to_binary(number);
		}
	}

	return 0;
}