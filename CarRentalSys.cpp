#include "CarRentalSys.h"
#include "Admin.h"
#include "Client_rental_request.h"


void CarRentalSys::start_sys()
{
	system("CLS");
	cout << "\t\t\t\tWELCOME TO GHOST'S CAR RENTALS.\n";
	
	int operation = 0;
	cout << "\n\n\n\t\t\t\t1-Register a new account."
		 << "\n\n\t\t\t\t2-Login."
		 << "\n\n\t\t\t\t0-Exit.\n";
	cin >> operation;

	try
	{
		if (operation < 0 || operation > 2)
			throw operation;
	}
	catch (int operation)
	{
		cout << "\nEnter a valid operation!.\n";
		system("pause");
		start_sys();
	}
	
	while (operation)
	{
		if (operation == 1)
			curr_client.signup();
		else
			login();

		system("CLS");
		cout << "\n\n\n\n\n\t\tPlease enter \"1\" to register a new account , \"2\" to login or \"0\" to exit: ";
		cin >> operation;
	}

	system("CLS");
	cout << "\n\n\n\n\n\t\tThank you for using our store, hope to see you again soon.\n";
	return;
}

void CarRentalSys::login()
{
	Admin curr_admin;
	Client_rental_request request;
	
	cin.ignore();

	system("CLS");

	cout << "\t\t\t\tLogin page.\n";

	string client_or_admin = right_login_info();

	if (client_or_admin == "Admin")
	{
		curr_admin.admin_interface();
	}
	else if (client_or_admin == "Client")
	{
		request.Client_interface(curr_client);
	}
	else
	{
		cout << "Account not found.\n";
	}
}

string CarRentalSys::right_login_info()
{
	cout << "\n\n\n\t\t\t\tUsername: ";
	getline(cin, login_name);

	cout << "\t\t\t\tPassword: ";
	getline(cin, login_password);

	if (login_name == "Admin" && login_password == "Admin")
	{
		return "Admin";
	}
	else if(curr_client.check_clients_info(login_name,login_password))
	{
		return "Client";
	}
	else
		return "NOT FOUND";
}





