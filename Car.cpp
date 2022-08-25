#include "Car.h"
#include "edit_data.h"
edit_data edit1;

void Car::set_info(string mdl, string manu_year, string p)
{
	model = mdl;
	manufacturingYear = manu_year;
	price = p;
	availability = "Available";
}

void Car::adding_car()
{
	system("CLS");

	string m;
	cars_count = get_items_count(cars_file);

	cin.ignore(); //when we use getline after cin it ignores the first input because cin puts a new line after its done so this is to fix that problem

	cout << "\t\t\t\t Car registration.";

	cout << "\nEnter the model: ";
	getline(cin, m);
	model = check_duplicate(cars_file, m);

	cout << "Enter the  manufactring year: ";
	getline(cin, manufacturingYear);


	cout << "Enter the price per hour: ";
	getline(cin, price);

	availability = "available";

	save_car_info();

	cout << "car added successfully, the car's ID is " << cars_count  << endl;

}

void Car::save_car_info()
{
	fstream myfile("car.csv", ios::out | ios::app); //after taking the data from the user we write it in our file 

	myfile << cars_count << "," << model << "," << manufacturingYear << "," << price << "," << availability << "\n";

	myfile.close();
}


void Car::print_cars_list()
{
	fstream car_file("car.csv", ios::in);

	if (!car_file)
		return;

	cout << "\tID\t\tModel\t\tmanu_year\tPPH($)\t\tAvailability\n\n";

	print_data(car_file, numOfCarData);
	cout << "\n";
}

void Car::delete_car()
{
	cars_count--;
}

bool Car::edit_car(fstream &file)
{
	cars_count = get_items_count(cars_file);
	cout << "\n1.Change the model.\n"
		<< "2.Change the manufactring year.\n"
		<< "3.Change the price.\n"
		<< "4.Change availability.\n"
		<< "5.Delete the car.\n"
		<< "\"0\" to go back to the main menu.\n"
		<< "Please enter the number of the required operation: ";

	return edit1.editing_data(file,numOfCarData,cars_file,cars_count);
}
