#pragma once
#include "data_manipulation.h"
class edit_data : public data_manipulation
{
public:

	void editing_data_interface(const char* file_name, int swtch_case);

	void input_new_value( int operation, int count);
	
	void reorder(fstream& file, int items_count, int numOfData);
	
	void saveRestOfDataAfterEditing(fstream& file);
	
	bool editing_data(fstream& file, int data_count, const char* file_name, int items_count);
};

