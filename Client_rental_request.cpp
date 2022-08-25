#include "Client_rental_request.h"
#include "Customer.h"
Client curr_client;

void Client_rental_request::Client_interface(Client &Current_client)
{
	curr_client	= Current_client;
	client_id = Current_client.get_client_num();
	client_name = Current_client.get_name();
	while(true)
	{ 
		print_client_interface_layout();

		int operation ;
		cout << "\t\t\t\t1-Make a new rental request.\n"
			<< "\t\t\t\t2-Edit an existing rental request.\n"
			<< "\t\t\t\tOr enter\"0\" to log out.\n"
			<< "\n\n\t\t\t\tEnter the required operation: ";
		cin >> operation;

		try 
		{
			if (operation == 0)
				return;
			else if (operation > 2 || operation < 0)
				throw operation;
		}
		catch (int operation)
		{
			cout << "\nPlease enter a valid operation!.\n";
			system("pause");
			Client_interface(Current_client);
		}
	
		cin.ignore();

		switch (operation)
		{
		case 1:

			make_rental_request();

			break;

		case 2:
		
			request.edit_rental_request(client_id);
			break;

		default:
			cout << "\nEnter a valid operation.\n";
			system("pause");
			break;
		}
	}
}

void Client_rental_request::make_rental_request()
{
	print_client_interface_layout();


	chosen_car.print_cars_list();

	cout << "Enter the ID of the car you want."
		<< "\n\"100\" to log out: ";
	getline(cin, real_car_id);

	if (real_car_id == "100")
		return;

	bool available = car_exists(real_car_id);
	try
	{
		if (available)
			confirm_request();
		else
			throw available;
	}
	catch (bool available)
	{
		cout << "\nPlease Enter a valid car Id.\n";
		system("pause");
		make_rental_request();
	}
}

void Client_rental_request::print_client_interface_layout()
{
	system("CLS");
	cout << "\t\t\t\t CLIENT'S INTERFACE\n";
	cout << "Welcome " << client_name << ".\n\n\n";
}

bool Client_rental_request::car_exists(string real_id)
{
	fstream car_file("car.csv", ios::in);

	while (!car_file.eof())
	{
		breakLineToWords(car_file);

		if (real_id == tempData[0] && tempData[4] == "available")
		{
			chosen_car.set_info(tempData[1], tempData[2], tempData[3]);
			return true;
		}
	}
	return false;
}

void Client_rental_request::confirm_request()
{
	int confirm;
	system("CLS");
	cout << "\t\t\t\tRESERVATION CONFIRMATION PAGE.\n";

	cout << "\n\n\n\t\t\t\tThe information of the car you chose.\n"
		<< "\n\t\t\t\tYou chose a " << chosen_car.get_manu_year() << " " << chosen_car.get_model()
		<< "\n\n\t\t\t\tPrice per hour ($): " << chosen_car.get_price() << " dollars ($)\n"
		<< "\n\n\t\t\t\t (1) to continue (0) to exit:";
	cin >> confirm;
	
	if (confirm == 1)
	{
		cout << "\n\n\t\t\t\tEnter the start and end date of the reservation";
		input_data();
	}
	else if (confirm == 0)
		Client_interface(curr_client);
	else
	{
		cout << "\n\n\t\t\t\tEnter a valid operation!.";
		system("pause");
		confirm_request();
	}
}

void Client_rental_request::input_data()
{
	bool valid_input = get_rental_hours();
	try
	{
		if (!valid_input)
			throw !valid_input;
	}
	catch (bool valid_input)
	{
		cout << "\nPlease enter a valid date!.\n";
		system("pause");
		confirm_request();
	}
}

bool Client_rental_request::get_rental_hours()
{
	int sDay, sMonth, eDay, eMonth, sHour, eHour;

	cout << "\n\t\t\t\tstart day (1-31): ";
	cin >> sDay;
	if (sDay > 31 || sDay < 1)
		return false;

	cout << "\n\t\t\t\tstart month (0-11): ";
	cin >> sMonth;
	if (sMonth > 11 || sMonth < 0)
		return false;

	cout << "\n\t\t\t\tend day (1-31): ";
	cin >> eDay;
	if (eDay > 31 || eDay < 1)
		return false;


	cout << "\n\t\t\t\tend month (0-11): ";
	cin >> eMonth;
	if (eMonth > 11 || eMonth < 0)
		return false;

	cout << "\n\t\tAt what hour will you pick up the car (0-23) how many hours after midnight: ";
	cin >> sHour;
	if (sHour > 23 || sHour < 0)
		return false;

	cout << "\n\t\tAt what hour will you drop off the car (0-23) how many hours after midnight: ";
	cin >> eHour;
	if (eHour > 23 || eHour < 0)
		return false;


	struct tm start;
	struct tm end;

	start.tm_hour = sHour; start.tm_min = 0; start.tm_sec = 0;
	start.tm_mon = sMonth;  start.tm_mday = sDay; start.tm_year = 122;

	end.tm_hour = eHour; end.tm_min = 0; end.tm_sec = 0;
	end.tm_mon = eMonth;  end.tm_mday = eDay; end.tm_year = 122;

	double diff_in_hours = difftime(mktime(&end), mktime(&start)) / 3600;

	total_due = (diff_in_hours * stoi(tempData[3]));
	system("CLS");

	cout << "\n\t\t\t\tYour total due is " << total_due << "$"
		<< "\n\t\t\t\tto rent the " << chosen_car.get_manu_year() << " " << chosen_car.get_model()
		<< " for " << diff_in_hours << " hour/s.\n";
	system("pause");
	payment_method();
}

void Client_rental_request::payment_method()
{
	system("CLS");
	int operation ;
	cout << "\n\n\n\t\t\t\tHow do you want to pay?\n"
		<< "\t\t\t\t1-Cash.\n"
		<< "\t\t\t\t2-VISA.\n"
		<< "\t\t\t\tOr \"0\" to go back to the main menu\n";
	
	try 
	{
		cin >> operation;
		if (operation == 0)
			Client_interface(curr_client);
		else if (operation == 1)
		{
			cin.ignore();
			cout << "\n\n\t\t\t\tEnter your national ID number: ";
			getline(cin, payment_info);
		}
		else if (operation == 2)
		{
			cin.ignore();
			cout << "\n\n\t\t\t\tEnter your card number: ";
			getline(cin, payment_info);
		}
		else
			throw operation;
	}
	catch (int operation)
	{
		system("CLS");
		cout << "\n\n\n\t\t\t\tPlease enter a valid operation\n";
		system("pause");
		payment_method();
	}

	save_reservation_info();

	Client_interface(curr_client);
}

void Client_rental_request::save_reservation_info()
{
	fstream reservations_file("reservation.csv", ios::out | ios::app);
	requests_count = get_items_count(reservation_file);
		
	reservations_file <<requests_count << "," << client_id << "," << client_name << "," << real_car_id << "," << chosen_car.get_model()
		<< "," << total_due << "," << payment_info << "," << "waiting approval" << endl;
	
	reservations_file.close();

	system("cls");
	cout << "\n\n\n\t\t\t\tReservation was successful\n"
		<< "\n\t\t\t\tYou will be directed to the main menu!.\n";
	system("pause");
}

