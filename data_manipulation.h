#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <cstdio>
#include <ctime>

using namespace std;

class data_manipulation 
{
public:
	static string tempData[10];
	static fstream new_file;

	void print_data(fstream& file, int data_count);
	void output_words(int data_count);


	string breakLineToWords(fstream& file);
	int get_items_count(const char* file_name);
	string check_duplicate(const char* file_name, string check_name);
	
	void delete_item(int item);
};

