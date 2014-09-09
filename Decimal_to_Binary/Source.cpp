#include <iostream>
#include <string>
#include <fstream>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::bitset;
using std::stoi;

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
		// Convert decimal number to binary
		bitset<16> binary(stoi(line));
		
		// Remove leading zeroes 
		string result = binary.to_string();
		result.erase(0, result.find_first_not_of('0'));
		cout << result << endl;
	}

	return 0;
}