#include "data_manipulation.h"

string data_manipulation::tempData[10];
fstream data_manipulation::new_file;

void data_manipulation::print_data(fstream& file,int data_count)
{
	string line;

	while (!file.eof())
	{
		line = breakLineToWords(file);

		if (line.empty())
			continue;

		output_words(data_count);

		cout << "\n\n";
	}
}

void data_manipulation::output_words(int data_count)
{
	for (int i = 0; i < data_count; i++)
		cout << "\t" << tempData[i] << "\t";
}

string data_manipulation::breakLineToWords(fstream& file)
{
	string line, word;

	getline(file, line);

	stringstream s(line);
	int i = 0;
	while (getline(s, word, ','))
	{
		tempData[i] = word;
		i++;
	}
	return line;
}

int data_manipulation::get_items_count(const char* file_name)
{
	int count = 0;
	ifstream read_count(file_name);
	while (!read_count.eof())
	{
		string n;
		getline(read_count, n);

		if (n.empty())
			continue;

		count++;
	}

	return count;
}

string data_manipulation::check_duplicate(const char* file_name, string check_name)
{
	fstream file(file_name, ios::in);

	if (!file)
		return check_name;

	while (!file.eof())
	{
		breakLineToWords(file);

		if (check_name == tempData[1])
		{
			cout << "\nUsername already used please enter another username: ";

			getline(cin, check_name);

			check_name = check_duplicate(file_name, check_name);

		}
	}
	file.close();
	return check_name;
}

void data_manipulation::delete_item(int item)
{
	item--;
}