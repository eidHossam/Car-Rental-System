#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class update_request_status
{
private:
	int operation;



public:
	const char* reser_file = "reservation.csv";

	bool edit_request(fstream& file);

	void print_requests_list();
};

