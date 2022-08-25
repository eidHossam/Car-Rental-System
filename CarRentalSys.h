#pragma once
#include "Customer.h"

class CarRentalSys 
{
private:
	Client curr_client;
	string login_name, login_password;
	
	 
	void login();	 
	string right_login_info();

public:

	 void start_sys();	
};

