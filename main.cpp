#include<bits/stdc++.h>
#include<windows.h>
#include<fstream>
#include "ContactDB.h"
#include "Contact.h"
using namespace std;


void start();
void menu();


Contact newcontact;

int main(int argc, char** argv) {
	 start();
	 menu();
	return 0;
}


void menu()
{
	int play;
    int ch;
    	char name[25];
    do
    {
    
        cout<<"............................................\n";
        cout<<"           PHONE BOOK MANAGEMENT\n";
        cout<<"............................................\n\n";
        cout<<"::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout<<"0. Exit\n";
        cout<<"1. Save New Phone Record\n";
        cout<<"2. Display All Saved Records\n";
        cout<<"3. Search Specific Record(through serial number)\n";
        cout<<"4. Search Specific Record(through name)\n";
        cout<<"5. Delete Specific Record\n";
        cout<<"6. Modify Existing Record\n";
        cout<<"Enter Your Choice : ";
        cin>>ch;

        switch(ch)
        {
        	case 0: exit(1); break;
            case 1: cout<<"enter the contact name you wish to enter : ";
					cin>>name;
					for (int i=0; i<strlen(name); i++)
        				name[i]=tolower(name[i]);
					if(newcontact.findcontact(name)){
						cout<<"record found with similar name cannot complete action!"<<endl;
					}else{
						newcontact.AddRecord();
					}
					break;
            case 2: newcontact.DisplayRecords(); 
					break;
            case 3: newcontact.SearchBySrNo();
					break;
			case 4:
					newcontact.SearchByName();
					break;
            case 5: newcontact.deleteRecord(); 
					break;
            case 6: newcontact.modifyRecord();
					break;
			default:
					cout<<"invalid command"<<endl;
					break;
        }
        cout<<"exit->press '0'"<<endl<<"continue->press'1'"<<endl;
        cin>>play;
        system("CLS");
    }while(play);
    cout<<"Shutting down!";
}


void start(){
	system("Color 0B");
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t---------------------------------\n";
	cout<<"\t\t\t\t\t\t---------------------------------\n";
	cout<<"\t\t\t\t\t\t      PHONEBOOK APPLICATION"<<endl;
	cout<<"\t\t\t\t\t\t---------------------------------\n";
	cout<<"\t\t\t\t\t\t---------------------------------\n";
	cout<<"\t\t\t\t\tLoading ";
	char x=219;
	for(int i=0;i<35;i++){
		cout<<x;
		if(i<10)
			Sleep(200);
		if(i>=10 &&i<20)
			Sleep(100);
		if(i>=10)
			Sleep(25);
	}
	system("CLS");
}






















//
//void AddNumber(){
//	newcontact.AddNumber();
//}
//void DisplayRecords(){
//	newcontact.DisplayRecords();
//}
//void SearchBySrNo(){
//	newcontact.SearchBySrNo();
//}
//void deleteRecord(){
//	newcontact.deleteRecord();
//}
//void modifyRecord(){
//	newcontact.modifyRecord();
//}
