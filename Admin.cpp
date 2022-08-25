#include "Admin.h"
#include "Customer.h"
#include "Car.h"
#include "update_request_status.h"
Client curr_client1;
Car curr_car;
Client_edits_request r;
void Admin::admin_interface()
{
	int operation = 0;
	
	while (true)
	{
		system("CLS");
		cout << "\t\t\t\tLoged in as an admin.\n";

		cout << "\n\t\t\t\t1.Register a new client.\n"
			<< "\t\t\t\t2.Edit an existing client\n"
			<< "\t\t\t\t3.View a list of clients.\n"
			<< "\t\t\t\t4.Add a new car.\n"
			<< "\t\t\t\t5.Edit an existing car.\n"
			<< "\t\t\t\t6.View list of cars.\n"
			<< "\t\t\t\t7.Client's rental requests.\n"
			<< "\t\t\t\t\"0\" to log out\n"
			<< "\n\t\t\t\tPlease enter the number of the required operation: ";

		(cin >> operation);

		if (operation == 0)
			break;

		int x = 1;

		switch (operation)
		{
		case 1:
			while (x)
			{
				system("CLS");
				
				curr_client1.signup();

				cout << "\n\"1\" to register another client, \"0\" to go back to the main menu: ";
				cin >> x;
			}
			break;

		case 2:
			while (x)
			{
				system("CLS");
				
				curr_client1.print_clients_list();

				cin.ignore();

				editing_data_interface(curr_client1.client_file,operation);
				
				cout << "\nDo you want to continue editing?"
					<< "\n\"1\" to continue , \"0\" to exit: ";
				cin >> x;
			}
			break;

		case 3:
			while (x)
			{
				system("ClS");

				curr_client1.print_clients_list();

				cout << "\nTotal number of clients = " << mani.get_items_count(curr_client1.client_file) << endl;

				cout << "\n\"0\" to go back to the main menu: ";
				cin >> x;
			}
			break;
		
		case 4:
			while (x)
			{
				curr_car.adding_car();

				cout << "\nDo you want to add another car?"
					<< "\n\"1\" if yes , \"0\" to exit: ";
				cin >> x;
			}
			break;

		case 5:
			while (x)
			{
				system("CLS");
				
				curr_car.print_cars_list();
				
				cin.ignore();

				editing_data_interface(curr_car.cars_file,  operation);

				cout << "\nDo you want to continue editing?"
					<< "\n\"1\" to continue , \"0\" to exit: ";
				cin >> x;
			}
			break;

		case 6:
			while (x)
			{
				system("ClS");

				curr_car.print_cars_list();

				cout << "\nTotal number of cars = " << mani.get_items_count(curr_car.cars_file) << endl;

				cout << "\n\"0\" to go back to the main menu: ";
				cin >> x;
			}
			break;

		case 7:
			while (x)
			{
				system("CLS");

				update_request_status update;

				update.print_requests_list();

				cin.ignore();
				edit_data data;
				data.editing_data_interface(r.reservation_file, operation);

				cout << "\nDo you want to continue editing?"
					<< "\n\"1\" to continue , \"0\" to exit: ";
				cin >> x;
			}
			break;
		
		default:
			system("CLS");
			cout << "Please enter a valid input: \n";
				system("pause");
			break;
		}
	}
}








