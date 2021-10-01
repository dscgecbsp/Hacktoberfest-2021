#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>

using namespace std;

struct date{  int d,m,y; };



void menu();

class account
{
   double bal,num;
   char name[50],add[100],pan[10],aadhaar[16], contact[10],toa;
   date dob;

public : void input()
	 {
	  cout<<"Enter the Account Number        : ";  cin>>num;
	  cout<<"Enter the Name                  : ";  gets(name);
	  cout<<"Enter the PAN Card Number       : ";  gets(pan);
	  cout<<"Enter the Aadhaar Number        : ";  gets(aadhaar);
	  cout<<"Enter the Date of Birth \n";
	  cout<<" Day   : "; cin>>dob.d;
	  cout<<" Month : ";cin>>dob.m;
	  cout<<" Year  : ";cin>>dob.y;
	  cout<<"Enter the Residencial Address   : ";  gets(add);
	  cout<<"Enter the Contact Number        : ";   gets(contact);
	  cout<<"Enter the Type of Account (C/S) : ";  cin>>toa;
	 }

	 void output()
	   {
	   cout<<num<<"\n"
	       <<name<<"\n"
	       <<aadhaar<<"\n"
	       <<pan<<"\n"<<add<<"\n"<<contact<<"\n"<<"\n";
	   }
	 void increase(double x)
	 {
	   bal=bal+x;
	 }
	void decrease(double x)
	 {
	   bal=bal-x;
	 }
	void interest(float r)
	{
	   bal=bal+((bal*r)/100);
	}



	char* getname()
	  {  return name;	}
	double getanum()
	  {  return num;        }
	char* getpan()
	  {  return pan;	}
	char* getaadhaar()
	  {  return aadhaar;    }
	double getbal()
	  {  return bal;	}
	char* getadd()
	  {  return add; 	}
	int getd()
	  {  return dob.d;      }
	int getm()
	  {   return dob.m;     }
	int gety()
	  {  return dob.y;      }
	char* getcontact()
	  {  return contact;    }
	char gettoa()
	  {  return toa;         }



	void setbal(double a)
	  {  bal=a;              }
	void setname(char z[])
	  {  strcpy(name,z);     }
	void setpan(char z[])
	  {  strcpy(pan,z);    	 }
	void setaadhaar(char z[])
	  {  strcpy(aadhaar,z);	 }
	void setadd(char z[])
	  {  strcpy(add,z);      }
	void setdate(date z)
	  {  dob.d=z.d;
	     dob.m=z.m;
	     dob.y=z.y;
	  }
	void setcontact(char z[])
	  {  strcpy(contact,z);  }

};


class data
{
  double number;
  date dt;
  double amount,total;
  public : void setnum(double x)
	    {
	     number=x;
	    }
	    void setdate(date z)
	    {
	     dt.d=z.d;
	     dt.m=z.m;
	     dt.y=z.y;
	    }
	    void setamount(double q)
	    {  amount=q;      }
	    void settotal(double w)
	    {  total=w;       }
	    int getd()
	    {  return dt.d;   }
	    int getm()
	    {  return dt.m;   }
	    int gety()
	    {  return dt.y;   }
	    double getnum()
	    {  return number; }
	    double getamount()
	    {  return amount; }
	    double gettotal()
	    {  return total; }



};


void create_account()
{
  account A;
  char f;
    ofstream ofs;
   ofs.open("records.dat",ios::binary|ios::app);
  do
  {
   clrscr();
   A.setbal(0);
   A.input();
   ofs.write((char*)&A,sizeof(A));

   cout<<"\n\nAccount successfully created !!!!!!";
   cout<<"\n\nWant to create more accounts ? ";
   cin>>f;
  }
  while((f=='y')||(f=='Y'));
  ofs.close();

 }

void deposit()
{
  account E;
  int f=1;
  double x,anum;
  date z;
  data Q;
  ofstream ofs1,ofs2;
  ifstream ifs;

  ofs1.open("temp.dat",ios::binary|ios::app);
  ofs2.open("transaction.dat",ios::binary|ios::app);
  ifs.open("records.dat",ios::binary);


  cout<<"Enter the Account Number ";
  cin>>anum;
  while(!ifs.eof())
  {
    ifs.read((char*)&E,sizeof(E));
    if(ifs.eof()) break;
    if(E.getanum()!=anum)
      {
	ofs1.write((char*)&E,sizeof(E));
      }
    else if(E.getanum()==anum)
      {
	clrscr();
	f=0;
	cout<<"Enter Amount ";
	cin>>x;
	E.increase(x);
	cout<<"Enter the Date of Transaction \n";
	cout<<" Day   : "; cin>>z.d;
	cout<<" Month : ";cin>>z.m;
	cout<<" Year  : ";cin>>z.y;
	Q.setnum(anum);
	Q.setdate(z);
	Q.setamount(x);
	Q.settotal(E.getbal());
	ofs1.write((char*)&E,sizeof(E));
	ofs2.write((char*)&Q,sizeof(Q));
	cout<<"Amount has been successfully deposited !!!!!!!\n\n";
	cout<<"Current Balance is : "<<E.getbal();
      }
  }
if(f!=0) cout<<"Invalid Account Number !!!!!";
ifs.close();
ofs2.close();
ofs1.close();
remove("records.dat");
rename("temp.dat","records.dat");
}



void withdraw()
{
  account E;
  data Q;
  double x,anum;
  int f;
  date z;

  ofstream ofs1,ofs2;
  ifstream ifs;

  ofs1.open("temp.dat",ios::binary|ios::app);
  ofs2.open("transaction.dat",ios::binary);
  ifs.open("records.dat",ios::binary);



  cout<<"Enter the Account Number ";
  cin>>anum;


  while(!ifs.eof())
  {
    ifs.read((char*)&E,sizeof(E));
    if(ifs.eof()) break;
    if(E.getanum()!=anum)
      {
	ofs1.write((char*)&E,sizeof(E));
      }
    else if(E.getanum()==anum)
      {
	clrscr();
	f=0;
	cout<<"Enter Amount ";
	cin>>x;
	if(x>E.getbal())
	 {  ofs1.write((char*)&E,sizeof(E));
	   cout<<"Insufficient Account Balance\n\n";
	 }

	else
	 {
	   E.decrease(x);
	   cout<<"Enter the Date of Transaction \n";
	   cout<<" Day   : "; cin>>z.d;
	   cout<<" Month : ";cin>>z.m;
	   cout<<" Year  : ";cin>>z.y;
	   Q.setnum(anum);
	   Q.setdate(z);
	   Q.setamount(x);
	   Q.settotal(E.getbal());
	   ofs1.write((char*)&E,sizeof(E));
	   ofs2.write((char*)&Q,sizeof(Q));
	   cout<<"Amount has been successfully withdrawn !!!!!!!\n\n";
	 }
	cout<<"Current Balance is : "<<E.getbal();

      }
  }
if(f!=0) cout<<"Invalid Account Number !!!!!";
ifs.close();
ofs1.close();
ofs2.close();
remove("records.dat");
rename("temp.dat","records.dat");
}

void daily_trans()
{
   int f=1,q=1;
   data E;
   account G;
   double anum;
   date sl;
   cout<<"Enter the Account Number : ";
   cin>>anum;
   ifstream ifs1,ifs2;
   ifs1.open("transactions.dat",ios::binary);
   ifs2.open("records.dat",ios::binary);
   while(!ifs2.eof())
   {
    ifs2.read((char*)&G,sizeof(G));
    if(ifs2.eof()) break;
    if(G.getanum()==anum)
      { f=0;
	cout<<"Enter the Date for which Transaction is to be checked \n";
	cout<<" Day   : "; cin>>sl.d;
	cout<<" Month : ";cin>>sl.m;
	cout<<" Year  : ";cin>>sl.y;
  //	clrscr();
	cout<<"\tDAILY TRANSACTIONS SLIP \n\n"
	    <<"Account Number        : "<<G.getanum()
	    <<"\nAccount Holder's Name : "<<G.getname()
	    <<"\n\n"
	    <<"================================================================"
	    <<"\n   Date\t\t Deposited or Withdrawn\t\t Balance\n"
	    <<"________________________________________________________________\n";
	while(!ifs1.eof())
	 {
	   ifs1.read((char*)&E,sizeof(E));
	   if(ifs1.eof()) break;
	   if((E.getnum()==anum)&&(E.getd()==sl.d)&&(E.getm()==sl.m)&&(E.gety()==sl.y))
	      { q=0;
		cout<<sl.d<<"/"<<sl.m<<"/"<<sl.y
		    <<"\t\t"<<E.getamount()
		    <<"\t\t\t"<<E.gettotal()<<"\n";
	      }
	  }
       if(q!=0){ clrscr(); cout<<"No Transactions Done on This Date "; }
     break;
     }

   }
if(f!=0){clrscr(); cout<<"Invalid Account Number !!!!!"; }
ifs2.close();
ifs1.close();
}


void interest()
{

  account A;
  float rc,rs;
  ifstream ifs;
  ofstream ofs;
  ifs.open("records.dat",ios::binary);
  ofs.open("temp.dat",ios::binary|ios::app);
  cout<<"Enter the rate of interest \n";
  cout<<"For savings account : "; cin>>rs;
  cout<<"For current account : "; cin>>rc;

  while(!ifs.eof())
  {
    ifs.read((char*)&A,sizeof(A));
    if(ifs.eof()) { break; }
    if((A.gettoa()=='c')||(A.gettoa()=='C'))
     { A.interest(rc); }
    else { A.interest(rs); }
    ofs.write((char*)&A,sizeof(A));
   }
   cout<<"\n\nInterest successfully added";
   ofs.close();
   ifs.close();
   remove("records.dat");
   rename("temp.dat","records.dat");
}

void close_account()
{
 account A;
 double anum;
 char ch;
 int f=0;

 do
 {
 clrscr();
 f=0;
 ifstream ifs;
 ofstream ofs;
 ifs.open("records.dat",ios::binary);
 ofs.open("temp.dat",ios::binary|ios::app);
 cout<<"Enter the account number you want to delete : ";
 cin>>anum;

 while(!ifs.eof())
 {
  ifs.read((char*)&A,sizeof(A));
   if(ifs.eof()) break;
   if(A.getanum()!=anum)
    {  ofs.write((char*)&A,sizeof(A));     }
   else if(A.getanum()==anum) f=1;
 }
if(f!=1)
{ cout<<"Invalid account number !!!!!";  }
else if(f==1)
{ cout<<"Account successfully deleted !!!!"; }
ofs.close();
ifs.close();
remove("records.dat");
rename("temp.dat","records.dat");

cout<<"\n\nDo you want to delete more accounts ? (Y/N) ";
cin>>ch;
}
while((ch=='y')||(ch=='Y'));

}


void search_account()
{

 char ch,comp[50];
 double anum;
 int f=0,x;
 account A;

 do
 {
  f=0;
  clrscr();
  ifstream ifs;
  ifs.open("records.dat",ios::binary);

  cout<<"On what basis you want to search ?\n"
      <<"1. Account Number\n"
      <<"2. Name\n"
      <<"3. Aadhaar Number\n"
      <<"4. PAN Card Number\n"
      <<"Enter your choice : ";
  cin>>x;
  if(x==1)
    {  cout<<"Enter the account number you want to search : ";
       cin>>anum;
       while(!ifs.eof())
	 {
	  ifs.read((char*)&A,sizeof(A));
	  if(ifs.eof()) break;
	  if(A.getanum()==anum)
	   {  clrscr();
	      f=1;
	      cout<<"\t\t\tACCOUNT DETAILS\n";
	      cout<<"\n\t\tAccount Number        : "<<A.getanum();
	      cout<<"\n\t\tName                  : "<<A.getname();
	      cout<<"\n\t\tResidencial Address   : "<<A.getadd();
	      cout<<"\n\t\tPAN Number            : "<<A.getpan();
	      cout<<"\n\t\tAadhaar Number        : "<<A.getaadhaar();
	      cout<<"\n\t\tDate of Birth         : "<<A.getd()<<" - "<<A.getm()<<" - "<<A.gety();
	      cout<<"\n\t\tContact Number        : "<<A.getcontact();
	   }
	 }
     if(f!=1)
       { cout<<"Invalid account number !!!!!";  }
    }
  if(x==2)
   {  cout<<"Enter the Account Holder's Name : ";
      gets(comp);
      while(!ifs.eof())
      {
	ifs.read((char*)&A,sizeof(A));
	if(ifs.eof()) break;
	if(strcmpi(A.getname(),comp)==0)
	{  clrscr();
	   f=1;
	   cout<<"\t\t\tACCOUNT DETAILS\n";
	   cout<<"\n\t\tAccount Number        : "<<A.getanum();
	   cout<<"\n\t\tName                  : "<<A.getname();
	   cout<<"\n\t\tResidencial Address   : "<<A.getadd();
	   cout<<"\n\t\tPAN Number            : "<<A.getpan();
	   cout<<"\n\t\tAadhaar Number        : "<<A.getaadhaar();
	   cout<<"\n\t\tDate of Birth         : "<<A.getd()<<" - "<<A.getm()<<" - "<<A.gety();
	   cout<<"\n\t\tContact Number        : "<<A.getcontact();
	}
      }
    if(f!=1)
      { cout<<"Invalid account number !!!!!";  }
   }
if(x==3)
 {    cout<<"Enter the Aadhaar Number : ";
      gets(comp);
      while(!ifs.eof())
      {
	ifs.read((char*)&A,sizeof(A));
	if(ifs.eof()) break;
	if(strcmpi(A.getaadhaar(),comp)==0)
	{  clrscr();
	   f=1;
	   cout<<"\t\t\tACCOUNT DETAILS\n";
	   cout<<"\n\t\tAccount Number        : "<<A.getanum();
	   cout<<"\n\t\tName                  : "<<A.getname();
	   cout<<"\n\t\tResidencial Address   : "<<A.getadd();
	   cout<<"\n\t\tPAN Number            : "<<A.getpan();
	   cout<<"\n\t\tAadhaar Number        : "<<A.getaadhaar();
	   cout<<"\n\t\tDate of Birth         : "<<A.getd()<<" - "<<A.getm()<<" - "<<A.gety();
	   cout<<"\n\t\tContact Number        : "<<A.getcontact();
	}
      }
if(f!=1)
{ cout<<"Invalid account number !!!!!";  }
}
  if(x==4)
{    cout<<"Enter the PAN Card Number : ";
     gets(comp);
     while(!ifs.eof())
      {
	ifs.read((char*)&A,sizeof(A));
	if(ifs.eof()) break;
	if(strcmpi(A.getpan(),comp)==0)
	{  clrscr();
	   f=1;
	   cout<<"\t\t\tACCOUNT DETAILS\n";
	   cout<<"\n\t\tAccount Number        : "<<A.getanum();
	   cout<<"\n\t\tName                  : "<<A.getname();
	   cout<<"\n\t\tResidencial Address   : "<<A.getadd();
	   cout<<"\n\t\tPAN Number            : "<<A.getpan();
	   cout<<"\n\t\tAadhaar Number        : "<<A.getaadhaar();
	   cout<<"\n\t\tDate of Birth         : "<<A.getd()<<" - "<<A.getm()<<" - "<<A.gety();
	   cout<<"\n\t\tContact Number        : "<<A.getcontact();
	}
      }
   if(f!=1)
    { cout<<"Invalid account number !!!!!";  }
   }

ifs.close();
cout<<"\n\nDo you want to search more accounts ? (Y/N) ";
cin>>ch;
}
while((ch=='y')||(ch=='Y'));


}

void check_bal()
{
 int ch,f=0;
 double anum;
 account A;

 clrscr();
 ifstream ifs;
 ifs.open("records.dat",ios::binary);

 cout<<"Enter the Account Number : ";
 cin>>anum;

 while(!ifs.eof())
 {
  ifs.read((char*)&A,sizeof(A));
  if(ifs.eof()) break;

  if(A.getanum()==anum)
    { f=1;
      cout<<"Current Balance is : "<<A.getbal();
      break;
    }
 }
if(f!=1)
{ cout<<"Invalid account number !!!!!";  }
ifs.close();
}


void update_account()
{
  account E;   char a[100],ch;   int f=1,x,v;   date z; double anum;
  do
  {
  ofstream ofs;
  ifstream ifs;

  ofs.open("temp.dat",ios::binary|ios::app);
  ifs.open("records.dat",ios::binary);
  cout<<"Enter the Account Number ";
  cin>>anum;
  while(!ifs.eof())
  {
    ifs.read((char*)&E,sizeof(E));
    if(ifs.eof()) break;
    if(E.getanum()!=anum)
      {
	ofs.write((char*)&E,sizeof(E));
      }
    else if(E.getanum()==anum)
      { clrscr();
	f=0;
	cout<<"Which detail you want to update ?\n";
	cout<<"1. Name\n"
	    <<"2. Address\n"
	    <<"3. Aadhaar\n"
	    <<"4. PAN No.\n"
	    <<"5. Contact No.\n"
	    <<"6. Date of Birth\n";
	cin>>x;
	switch(x)
	{
	case 1 : cout<<"Enter the New Name ";
		 gets(a);  E.setname(a);    break;
	case 2 : cout<<"Enter the New Address ";
		 gets(a);  E.setadd(a);     break;
	case 3 : cout<<"Enter the New Aadhaar Number ";
		 gets(a);  E.setaadhaar(a); break;
	case 4 : cout<<"Enter the New PAN Number ";
		 gets(a);  E.setpan(a);     break;
	case 5 : cout<<"Enter the New Contact Number ";
		 gets(a);  E.setcontact(a); break;
	case 6 : cout<<"Enter the New Date of Birth\n ";
		 cout<<"Date   : "; cin>>z.d;
		 cout<<"Month  : "; cin>>z.m;
		 cout<<"Year   : "; cin>>z.y;
		 E.setdate(z);  break;
	default : cout<<"Invalid Choice "; break;
	}
	ofs.write((char*)&E,sizeof(E));
	break;
      }
  }
if(f!=0) cout<<"Invalid Account Number !!!!!";
ifs.close();
ofs.close();
remove("records.dat");
rename("temp.dat","records.dat");

cout<<"\n\nDo you want to update details of more accounts ? (Y/N) ";
cin>>ch;
}
while((ch=='y')||(ch=='Y'));


}


void employee()
{
 int o;
 char ch;
 do
 { clrscr();
  cout<<"\t\tÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸    \n"
      <<"\t\t³                                          ³    \n"
      <<"\t\t³    What you want to do ?                 ³    \n"
      <<"\t\t³                                          ³    \n"
      <<"\t\t³    1. Create Account                     ³    \n"
      <<"\t\t³    2. Deposit Money                      ³    \n"
      <<"\t\t³    3. Withdraw Money                     ³    \n"
      <<"\t\t³    4. Get Daily Transactions Slip        ³    \n"
      <<"\t\t³    5. Check Balance                      ³    \n"
      <<"\t\t³    6. Update Interest in All Accounts    ³    \n"
      <<"\t\t³    7. Close An Account                   ³    \n"
      <<"\t\t³    8. Search an Account                  ³    \n"
      <<"\t\t³    9. Update Account Details             ³    \n"
      <<"\t\t³    0. Return to previous menu            ³    \n"
      <<"\t\t³                                          ³    \n"
      <<"\t\tÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾    \n\n"
      <<"Enter your choice : ";
 cin>>o;
    if(o==1)
       create_account();
    else if(o==2)
       deposit();
    else if(o==3)
       withdraw();
    else if(o==4)
       daily_trans();
    else if(o==5)
       check_bal();
    else if(o==6)
       interest();
    else if(o==7)
       close_account();
    else if(o==8)
       search_account();
    else if(o==9)
       update_account();

    else if(o==0)
	menu();
  else
    cout<<"Invalid entry !!!! ";
 cout<<"\n\nWant to perform more actions ? (Y/N) ";
 cin>>ch;
}
while((ch=='y')||(ch=='Y'));


}

void menu()
{

  int ch;   account E;
  char x;

  do
  {
  //clrscr();
  cout<<"\t  ÛÛÛÛÛÛÛÛ     ÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛ      ÛÛ   ÛÛ      ÛÛ \n"
      <<"\t  ÛÛ      ÛÛ   ÛÛ      ÛÛ   ÛÛ ÛÛ     ÛÛ   ÛÛ    ÛÛ   \n"
      <<"\t  ÛÛ      ÛÛ   ÛÛ      ÛÛ   ÛÛ  ÛÛ    ÛÛ   ÛÛ  ÛÛ     \n"
      <<"\t  ÛÛÛÛÛÛÛÛÛÛ   ÛÛÛÛÛÛÛÛÛÛ   ÛÛ   ÛÛ   ÛÛ   ÛÛÛÛ       \n"
      <<"\t  ÛÛ      ÛÛ   ÛÛ      ÛÛ   ÛÛ    ÛÛ  ÛÛ   ÛÛ  ÛÛ     \n"
      <<"\t  ÛÛ      ÛÛ   ÛÛ      ÛÛ   ÛÛ     ÛÛ ÛÛ   ÛÛ    ÛÛ   \n"
      <<"\t  ÛÛÛÛÛÛÛÛ     ÛÛ      ÛÛ   ÛÛ      ÛÛÛÛ   ÛÛ      ÛÛ \n";

   cout<<"\n\n\t\tÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»\n"
       <<"\t\tº                            º\n"
       <<"\t\tº      Welcome User !!!!!    º\n"
       <<"\t\tº   1. Perform Actions       º\n"
       <<"\t\tº   2. Total Record          º\n"
       <<"\t\tº   0. Exit                  º\n"
       <<"\t\tº                            º\n"
       <<"\t\tÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼\n\n"
       <<"Enter your choice : ";
   cin>>ch;
  switch(ch)
  {
  case 1 :   employee();break;
  case 2 :   ifstream ifs("records.dat",ios::binary);
	     while(!ifs.eof())
	       {
		 ifs.read((char*)&E,sizeof(E));
		 if(ifs.eof()) break;
		 else E.output();
	     }
	     ifs.close(); break;
 case 0 :   exit(0);
 default : cout<<"\nOoops !!!! Invalid entry....\n\n ";
 }
  cout<<"Do you want to return to main menu ? (Y/N) ";
  cin>>x;
}
  while((x=='y')||(x=='Y'));

}

void main()
{
  menu();

  cout<<"Press any key to exit....";

  getch();
}