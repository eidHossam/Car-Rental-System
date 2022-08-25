#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <ctime>
#include "Car.h"
#include "Client_edits_request.h"
#include "Customer.h"

using namespace std;

class Client_rental_request : private Client_edits_request
{
private:
	string client_name;
	string client_id;
	double total_due = 0.0;
	string payment_info;

	Car chosen_car;
	string real_car_id;
	Client_edits_request request;


	void make_rental_request();

	void print_client_interface_layout();

	bool car_exists(string real_id);

	void confirm_request();

	void input_data();

	bool get_rental_hours();

	void payment_method();

	void save_reservation_info();


public:
	
	void Client_interface(Client& Current_client);

};

