#include "update_request_status.h"
#include "Customer.h"
#include "Client_edits_request.h"
#include "edit_data.h"
#include "data_manipulation.h"
Client c;
Client_edits_request request;

void update_request_status::print_requests_list()
{
	cout << "\n\nrequest_num\t\tClient's_id\tClient's_name\tCar_id\t\tCar_model\tTotal_due\tPay_method\tStatus\n";

	fstream file("reservation.csv", ios::in);

	if (!file)
		return;

	string line;
	data_manipulation data;

	while (!file.eof())
	{
		line = data.breakLineToWords(file);

		if (line.empty())
			continue;

		data.output_words(8);

		cout << "\n\n";
	}
	file.close();
}

bool update_request_status::edit_request(fstream &file)
{
	edit_data data;
	try
	{
		cout << "\n(1) to update request status (0) to delete."
			 << "\n or 2 to go back to main menu: ";
		cin >> operation;
		if (operation == 2)
			return true;
		else if (operation == 1)
		{
			edit_data edit;
			data.input_new_value(7,request.numOfData);
			data.saveRestOfDataAfterEditing(file);
		}
		else if (operation == 0)
		{
			request.delete_request(file);
		}
		else if (operation < 0 || operation > 1)
			throw operation;
	}
	catch (int operation)
	{
		cout << "\nEnter a valid operation!.\n";
		system("pause");
		edit_request(file);
	}
	return false;
}