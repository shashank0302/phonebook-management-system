#include<bits/stdc++.h>
#include<fstream>
#include "Contact.h"
#include "ContactDB.h"
using namespace std;

ContactDB b;

void Contact::AddRecord()
{
    ofstream fout;
    fout.open("PhonBook.txt",ios::out|ios::binary|ios::app);
    b.storeData();
    fout.write((char*)&b,sizeof(b));
    fout.close();
    cout<<"\nRecord Saved to File......\n";
}



void Contact::DisplayRecords()
{
    ifstream fin;
    fin.open("PhonBook.txt",ios::out|ios::binary|ios::app);
    while(fin.read((char*)&b,sizeof(b)))
    {
        b.showData();
    }
    fin.close();
    cout<<"\nReading of Data File Completed......\n";
}

void Contact::SearchBySrNo()
{
    ifstream fin;
    int n, flag=0;
    fin.open("PhonBook.txt",ios::out|ios::binary|ios::app);
    cout<<"Enter Serial Number of Record To Display: ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getSrNo())
        {
            b.showData();
            flag++;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}

void Contact::deleteRecord()
{
    ifstream fin;
    ofstream fout;
    int flag=0;
    string n;
	fin.open("PhonBook.txt",ios::out|ios::binary|ios::app);
    fout.open("temp.txt",ios::out|ios::binary);
    cout<<"Enter name of Record To Delete : ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getName())
        {
            cout<<"\nThe Following record is deleted....\n";
            b.showData();
            flag++;
        }
        else
        {
            fout.write((char*)&b,sizeof(b));
        }
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
    remove("PhonBook.txt");
    rename("temp.txt","PhonBook.txt");
}

void Contact::modifyRecord()
{
    fstream fio;
    int n, flag=0,pos;
    fio.open("PhonBook.txt",ios::out|ios::binary|ios::in);

    cout<<"Enter Serial Number of Record To Modify : ";
    cin>>n;

    while(fio.read((char*)&b,sizeof(b)))
    {
        pos=fio.tellg();
        if(n==b.getSrNo())
        {
            cout<<"\nThe Following record will be modified....\n";
            b.showData();
            flag++;
            cout<<"\nRe-Enter the New Details.....\n";
            b.storeData();
            fio.seekg(pos-sizeof(b));
            fio.write((char*)&b,sizeof(b));
            cout<<"\n....Data Modified Successfully....\n";
        }
    }
    fio.close();
    if(flag==0)
        cout<<"\nThe Record of Serial Number "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
}

void Contact::SearchByName(){
	ifstream fin;
    int  flag=0;
    string n;
    fin.open("PhonBook.txt",ios::out|ios::binary|ios::app);
    cout<<"Enter the name of Record To Display: ";
    cin>>n;

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(n==b.getName())
        {
            b.showData();
            flag++;
            cout<<"\n\n.....Record Found and Displayed......\n";
        }
    }
    fin.close();
    if(flag==0)
        cout<<"\nThe Record of the name "<<n<<" is not in file....\n";
    cout<<"\nReading of Data File Completed......\n";
	
}

bool Contact::findcontact(string name){
	ifstream fin;
    fin.open("PhonBook.txt",ios::out|ios::binary|ios::app);

    while(fin.read((char*)&b,sizeof(b)))
    {
        if(name==b.getName())
        {
			return true;
			break;
        }
    }
    return false;	
}
