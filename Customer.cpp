#include "Customer.h"
edit_data edit2;
void Client::signup() 
{
	system("CLS");
	
	string n;
	client_count = get_items_count(client_file);

	cin.ignore(); //when we use getline after cin it ignores the first input because cin puts a new line after its done so this is to fix that problem

	cout << "\t\t\t\t Registration page.";


	cout << "\nEnter the name: ";
	getline(cin, n);

	name = check_duplicate(client_file,n);

	cout << "\nEnter the  password: ";
	getline(cin, password);

	cout << "\nEnter the phone number: ";
	getline(cin, phone_num);

	cout << "\nEnter the address: ";
	getline(cin, address);

	save_client_info();

	cout << "\nClient registered successfully, the clients ID is " << client_count  << endl;

	system("pause");
}

void Client::save_client_info()
{
	fstream myfile("Client.csv", ios::out | ios::app); //after taking the data from the user we write it in our file 

	myfile << client_count << "," << name << "," << password << "," << phone_num << "," << address << "\n";

	myfile.close();
}


bool Client::check_clients_info(string login_name, string login_password )
{
	fstream myfile("Client.csv", ios::in);
	
	while (!myfile.eof())
	{
		breakLineToWords(myfile);

		if (login_name == tempData[1] && login_password == tempData[2]) 
		{
			set_info(tempData[0], tempData[1], tempData[2], tempData[3], tempData[4]);
			return true;
		}
	}
	return false;
}


void Client::delete_client()
{
	client_count--;
}

void Client::set_info(string cn, string nm, string pass, string pn, string add)
{
	client_num = cn;
	name = nm;
	password = pass;
	phone_num = pn;
	address = add;
}

void Client::print_clients_list()
{
	cout << "\tID\t\tName\t\tPassword\tPhone_number\tAddress\n\n";

	fstream client_file("Client.csv", ios::in);
	
	if (!client_file)
		return;
	
	print_data(client_file, client_data_count);
}

bool Client::edit_client(fstream& file)
{
	client_count = get_items_count(client_file);
	cout << "\n1 - to change the name.\n2 - to change the password.\n3 - to change the phone number.\n4 - to change the address."
		<< "\n5 - to delete the client."
		<< "\n or press \"0\" to go back to the main menu."
		<< "\nPlease enter the required operation: ";
	
	return edit2.editing_data(file, client_data_count, client_file,client_count);
}

