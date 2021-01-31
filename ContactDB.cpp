#include<bits/stdc++.h>
#include<fstream>
#include "ContactDB.h"
using namespace std;
	
	
	ContactDB::ContactDB(){
		this->srno=0;
	}



void ContactDB::storeData(){
	    cout<<"\n...............CREATE NEW PHONE RECORD...............\n";
	    this->srno+=1;
	   	cin.ignore();
        cout<<"Enter Name   : "; cin.getline(name,25);
        cout<<"Enter phoneNumber : "; cin.getline(phoneNum,15);
	
}

void ContactDB::showData(){
	    cout<<"\n...............PHONE BOOK RECORD...............\n";
        cout<<"Sr. No.    : "<<srno<<endl;
        cout<<"Name       : "<<name<<endl;
        cout<<"Mobile No. : "<<phoneNum<<endl;
}

int ContactDB::getSrNo(){
	return srno;
}

string ContactDB::getName(){
	return name;
}
string ContactDB::getPhoneNum(){
	return phoneNum;
}
