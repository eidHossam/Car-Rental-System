#include "Client_edits_request.h"
edit_data edit;

void Client_edits_request::edit_rental_request(string client_id)
{
	id = client_id;
	system("CLS");

	print_client_reservations();

	choose_request_to_edit();
}

void Client_edits_request::print_client_reservations()
{
	fstream reservations_file("reservation.csv", ios::in);

	cout << "\n\nrequest_num\t\tClient's_id\tClient's_name\tCar_id\t\tCar_model\tTotal_due\tPay_method\tStatus\n";

	if (!reservations_file)
	{
		cout << "\n\n\t\t\t\tYou don't have any reservations at this moment!.\n";
		system("pause");
		reservations_file.close();
		return;
	}

	string request;
	while (!reservations_file.eof())
	{	
		request = breakLineToWords(reservations_file);

		if (request.empty())
			continue;

		if (id == tempData[1])
		{
			output_words(numOfData);
			cout << "\n";
		}
	}
	reservations_file.close();
}

void Client_edits_request::choose_request_to_edit()
{
		fstream file("reservation.csv", ios::in);
		new_file.open("temp.csv", ios::out | ios::app);

		if (!file)
			return;

		bool back_to_main_menu = false;
		bool item_found = false;
		string reservation_id;

		cout << "\nID of the item to edit.\n"
			<< "or press \"100\" to go back to the main menu: ";
		getline(cin, reservation_id);

		if (reservation_id == "100")
		{
			return;
		}

		string current_line;

		while (!file.eof()) //eof() function returns true when there is no more data to read
		{
			current_line = breakLineToWords(file);
			if (reservation_id == tempData[0] && id == tempData[1])
			{
				back_to_main_menu = delete_request(file);
				item_found = true;
				if (back_to_main_menu)
				{
					new_file << current_line << endl;
					edit.saveRestOfDataAfterEditing(file);
				}
				break;
			}
			else
				new_file << current_line << endl;
		}
		
		if (!item_found)
		{
			cout << "\nItem not found!.\n";
			system("pause");
		}
		
		file.close();
		new_file.close();

		remove("reservation.csv");
	    rename("temp.csv", "reservation.csv");
}

bool Client_edits_request::delete_request(fstream& file)
{
	system("CLS");
	requests_count = get_items_count(reservation_file);
	
	int confirm;
	cout << "\n\n\n\t\t\t\t(1) to delete (0) to go back to main menu: ";
	cin >> confirm;
	
	if (confirm == 1)
	{
		cout << "\n\t\t\t\tRequest has been deleted successfully!.\n";
		edit.reorder(file,requests_count,numOfData);
		requests_count--;
			system("pause");
			return false;
	}
	else if (confirm == 0)
		return true;
	else
	{
		system("CLS");
		cout << "\n\n\n\t\t\t\tEnter a valid operation!.\n";
		system("pause");
		delete_request(file);
	}
}


