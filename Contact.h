#include<bits/stdc++.h>
#ifndef CONTACT_H
#define CONTACT_H
using namespace std;

class Contact
{
	public:
	void AddRecord();    		//Function to add new record in a Binary File.
	void DisplayRecords();    //Function to read data file & display on screen.
	void SearchBySrNo();    //Function to search and display record by sr no.
	void deleteRecord();    //Function to delete a specific record from file.
	void modifyRecord();  	//function to modify a specific record from file.
	bool findcontact(string name);
	void SearchByName();
};

#endif
