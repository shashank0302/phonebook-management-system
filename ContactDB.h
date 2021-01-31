#ifndef CONTACTDB_H
#define CONTACTDB_H
#include<string>
using namespace std;

class ContactDB
{
	private:
		
		int srno;
		char name[25];
		char phoneNum[15];
	public:
		ContactDB();
		void storeData();
		void showData();
		int getSrNo();
		string getName();
		string getPhoneNum();
};

#endif
