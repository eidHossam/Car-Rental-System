#pragma once
#include "edit_data.h"

using namespace std;
class Client : protected edit_data
{
private:
	string name;
	string password;
	string phone_num;
	string address;
	string client_num;

	int client_data_count = 5;
public:
	int client_count = 0;
	const char* client_file = "Client.csv";

	Client() : name("User not found"), password("Unknown"), phone_num("0"), address("Unknown"), client_num("0")
	{	};
	void set_info(string cn, string nm, string pass, string pn, string add);

	string get_name() const
	{
		return name;
	}
	string get_client_num() const
	{
		return client_num;
	}

	void signup();
	void save_client_info();
	
	bool check_clients_info(string login_name, string login_password);

	void delete_client();

	void print_clients_list();
	bool edit_client(fstream& file);
};