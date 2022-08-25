#include "edit_data.h"
#include "Car.h"
#include "Customer.h"
#include "update_request_status.h"


void edit_data::editing_data_interface(const char* file_name, int swtch_case)
{
	fstream file(file_name, ios::in);
	new_file.open("temp.csv", ios::out | ios::app);

	bool back_to_main_menu = false;
	bool item_found = false;
	string id;

	cout << "\nID of the item to edit.\n"
		<< "or press \"100\" to go back to the main menu: ";
	getline(cin, id);

	if (id == "100")
	{
		file.close();
		new_file.close();
		remove("temp.csv");
		return;
	}

	string current_line;
	while (!file.eof())
	{
		current_line = breakLineToWords(file);
		if (id == tempData[0] && swtch_case == 2)
		{
			Client curr_client;
			back_to_main_menu = curr_client.edit_client(file);
			item_found = true;
			if (back_to_main_menu)
			{
				new_file << current_line << endl;
				saveRestOfDataAfterEditing(file);
			}
			break;
		}
		else if (id == tempData[0] && swtch_case == 5)
		{
			Car curr_car;
			back_to_main_menu = curr_car.edit_car(file);
			item_found = true;
			if (back_to_main_menu)
			{
				new_file << current_line << endl;
				saveRestOfDataAfterEditing(file);
			}
			break;
		}
		else if (id == tempData[0] && swtch_case == 7)
		{
			update_request_status update;
			back_to_main_menu = update.edit_request(file);
			item_found = true;
			if (back_to_main_menu)
			{
				new_file << current_line << endl;
				saveRestOfDataAfterEditing(file);
			}
			break;
		}
		else
		{
			new_file << current_line << endl;
		}
	}

	if (!item_found)
	{
		cout << "\nItem not found!.\n";
		system("pause");
	}
	file.close();
	new_file.close();

	remove(file_name);
	rename("temp.csv", file_name);
}

bool edit_data::editing_data(fstream& file,int data_count, const char* file_name, int items_count)
{
	int operation;
	cin >> operation;
	if (operation == 0)
	{
		return true;
	}
	else if (operation > 0 && operation < data_count)
	{
		input_new_value( operation, data_count);
		saveRestOfDataAfterEditing(file);
	}
	else if (operation == data_count)
	{
		delete_item(items_count);
		reorder(file,items_count, data_count);
		cout << "\nThis client has been deleted successfully.\n";
	}
	else
	{
		cout << "\nPlease enter a valid operation number.\n";
		editing_data(file, data_count, file_name, items_count);
	}
	return false;
}

void edit_data::input_new_value(int operation, int data_count)
{
	cin.ignore();

	string new_value;

	cout << "Enter the new value: ";
	getline(cin, new_value);


	tempData[operation] = new_value;

	for (int i = 0; i < data_count; i++)
	{
		new_file << tempData[i] << ",";
	}

	new_file << "\n";
}

void edit_data::reorder(fstream& file, int items_count, int numOfData)
{
	new_file.close();
	new_file.open("temp.csv", ios::out | ios::app);

	string swap;
	string id = tempData[0];
	for (int num = stoi(id); num < (items_count - 1); )
	{
		breakLineToWords(file);

		tempData[0] = id;

		for (int i = 0; i < numOfData; i++)
		{
			new_file << tempData[i] << ",";
		}
		new_file << "\n";
		num++;
		id = to_string(num);
	}
	new_file.close();
}

void edit_data::saveRestOfDataAfterEditing(fstream& file)
{	
	string swap;
	while (!file.eof())
	{
		getline(file, swap);
		if (swap.empty())
			continue;

		new_file << swap << endl;
	}
	new_file.close();
}
