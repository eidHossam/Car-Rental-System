#pragma once
#include "Client_edits_request.h"

class Admin : public  Client_edits_request
{
private:
	int data_count = 5;
	data_manipulation mani;

public:
	
	 void admin_interface();
};

