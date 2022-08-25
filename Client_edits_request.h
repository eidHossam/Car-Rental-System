#pragma once
#include "edit_data.h"
#include <cstdio>

using namespace std;

class Client_edits_request : public edit_data
{
private:
	string id;
	void choose_request_to_edit();

	void print_client_reservations();

public:
	const char* reservation_file = "reservation.csv";
	int requests_count = 0;
	int numOfData = 8;

	bool delete_request(fstream& file);
	void edit_rental_request(string client_id);
};

