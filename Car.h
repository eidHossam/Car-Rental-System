#pragma once
#include <iostream>
#include "data_manipulation.h"

using namespace std;

class Car : public data_manipulation
{
private:
	string model;
	string availability;
	string manufacturingYear;
	string price;

	int numOfCarData = 5;

public:
	int cars_count = 0;
	const char* cars_file = "car.csv";

	Car() {};
	void set_info(string mdl, string manu_year, string p);

	void adding_car();
	void save_car_info();

	void delete_car();

	bool edit_car(fstream& file);
	
	void print_cars_list();

	string get_model()
	{
		return model;
	}
	string get_manu_year()
	{
		return manufacturingYear;
	}
	string get_price()
	{
		return price;
	}
};

