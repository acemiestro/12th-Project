#include<fstream.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

//*****************************
// Structure For Getting Date
//*****************************

struct mydate
{
	int dd,mm,yy;
};

//***************************************
// Class for accessing employee details
//***************************************

class employee
{
	private:
		int emp_id;
		char name[20];
		char sex;
		char phoneno[11];
	public:
		void getdata_emp(int );
		void showdata_emp(int );
		int get_empid();
		void getnewdata_emp();
};

//**********************************
// Class for accessing item details
//**********************************

class itemss
{
	private:
		int item_id;
		char name[20];
		float price;
	public:
		void getdata_item(int );
		void showdata_item(int);
		void showdata_item1(int );
		int get_itemid();
		float get_price();
		char *get_name();
		void getnewdata_item();
};

//**********************************
// Class for accessing user details
//**********************************

class user
{
	private:
		char usid[20];
		char pass[20];
	public:
		void getdata_user();
		void showdata_user(int );
		char *get_id();
		char *get_ps();
};

//**************************************
// Class for accessing customer details
//**************************************

class customer
{
	private:
		int cust_id;
		char name[20];
		char address[20];
		char phone[12];
		int oid;
	public:
		void getdata_cust(int a,char b[],char c[],char d[],int e);
		void showdata_cust(int);
		int get_custid();
		char *get_name();
		int get_oid();
};

//***********************************
// Class for accessing order details
//***********************************

class order
{
	private:
		int orno;
		mydate ordate;
		int itemid[5];
		int qty[5];
		float amt[5];
		float total;
		int size;
		time_t tme;
	public:
		int *getitemid();
		int *getqty();
		float *getamt();
		int getsize();
		float gettotal();
		time_t gettt()
		{
			return tme;
		}
		mydate getdt()
		{
			return ordate;
		}
		void getdata_order(int a,mydate b,int c[],int d[],float e[],float f,int n);
		void showdata_order(int);
		int get_orderid();
};

//*************************************
// Class for accessing billing details
//*************************************

class bill
{
	private:
		int billno;
		mydate dt;
		char status;
		float amt;
	public:
		void getdata_bill(int a,mydate b,char c,float d);
		void showdata_bill(int);
		int get_billno();
};

//*******************************
// Functions of class "employee"
//*******************************

void employee::getdata_emp(int e)
{
	emp_id=e;
	cout<<"\n Emp id "<<e;
	cout<<"\n Enter name ";
	gets(name);
	cout<<"\n Enter sex ";
	cin>>sex;
	cout<<"\n Enter phone no ";
	cin>>phoneno;
}
void employee::showdata_emp(int j)
{
	gotoxy(2,j);
	cout<<emp_id;
	gotoxy(17,j);
	cout<<name;
	gotoxy(32,j);
	cout<<sex;
	gotoxy(42,j);
	cout<<phoneno;
}
int employee::get_empid()
{
	return emp_id;
}
void employee::getnewdata_emp()
{
	cout<<"\n Enter new phone no ";
	cin>>phoneno;
}

//***************************
// Functions of class "item"
//***************************

void itemss::getdata_item(int e)
{
	item_id=e;
	cout<<"\n Item id "<<e;
	cout<<"\n Enter name ";
	gets(name);
	cout<<"\n Enter price ";
	cin>>price;
}
void itemss::showdata_item(int i)
{
	gotoxy(3,i);
	cout<<item_id;
	gotoxy(16,i);
	cout<<name;
	gotoxy(29,i);
	cout<<price;
}
void itemss::showdata_item1(int r)
{
	gotoxy(42,r);
	cout<<name;
	gotoxy(56,r);
	cout<<price;
}
int itemss::get_itemid()
{
	return item_id;
}
float itemss::get_price()
{
	return price;
}
char *itemss::get_name()
{
	return name;
}
void itemss::getnewdata_item()
{
	cout<<"\n Enter new price ";
	cin>>price;
}

//***************************
// Functions of class "user"
//***************************

void user::getdata_user()
{
	cout<<"\n Enter id ";
	gets(usid);
	cout<<"\n Enter password ";
	gets(pass);
}
void user::showdata_user(int i)
{
	gotoxy(3,i);
	cout<<usid;
	gotoxy(16,i);
	cout<<pass;
}
char *user::get_id()
{
	return usid;
}
char *user::get_ps()
{
	return pass;
}

//*******************************
// Functions of class "customer"
//*******************************

void customer::getdata_cust(int a,char b[],char c[],char d[],int e)
{
	cust_id=a;
	strcpy(name,b);
	strcpy(address,c);
	strcpy(phone,d);
	oid=e;
}
void customer::showdata_cust(int i)
{
	gotoxy(3,i);
	cout<<cust_id;
	gotoxy(17,i);
	cout<<name;
	gotoxy(30,i);
	cout<<phone;
	gotoxy(43,i);
	cout<<address;
}
int customer::get_custid()
{
	return cust_id;
}
char *customer::get_name()
{
	return name;
}
int customer::get_oid()
{
	return oid;
}

//****************************
// Functions of class "order"
//****************************

int *order::getitemid()
{
	return itemid;
}
int *order::getqty()
{
	return qty;
}
float *order::getamt()
{
	return amt;
}
int order::getsize()
{
	return size;
}
float order::gettotal()
{
	return total;
}

void order::getdata_order(int a,mydate b,int c[],int d[],float e[],float f,int n)
{
	tme=time(NULL);
	orno=a;
	ordate=b;
	size=n ;
	for(int i=0;i<size;i++)
	{
		itemid[i]=c[i];
		qty[i]=d[i];
		amt[i]=e[i];
	}
	total=f;
}
void order::showdata_order(int j)
{
	gotoxy(3,j);
	cout<<orno;
	gotoxy(15,j);
	cout<<ordate.dd<<"/"<<ordate.mm<<"/"<<ordate.yy;
	gotoxy(30,j);
	cout<<total;
}
int order::get_orderid()
{
	return orno;
}

//****************************
// Functions of class "bill"
//****************************

void bill::getdata_bill(int a,mydate b,char c,float d)
{
	billno=a;
	dt=b;
	status=c;
	amt=d;
}
void bill::showdata_bill(int i)
{
	gotoxy(3,i);
	cout<<billno;
	gotoxy(17,i);
	cout<<status;
	gotoxy(29,i);
	cout<<amt;
	gotoxy(45,i);
	cout<<dt.dd<<"/"<<dt.mm<<"/"<<dt.yy;
}
int bill::get_billno()
{
	return billno;
}

//*****************************
// Function for creating A Box
//*****************************

void box(int r1,int c1,int r2,int c2)
{
	char ch;
	int i;
	gotoxy(c1,r1);
	ch=218;
	cout<<ch;
	gotoxy(c2,r1);
	ch=191;
	cout<<ch;
	gotoxy(c1,r2);
	ch=192;
	cout<<ch;
	gotoxy(c2,r2);
	ch=217;
	cout<<ch;
	ch=196;
	for(i=c1+1;i<c2;i++)
	{
		gotoxy(i,r1);
		cout<<ch;
	}
	ch=196;
	for(i=c1+1;i<c2;i++)
	{
		gotoxy(i,r2);
		cout<<ch;
	}
	ch=179;
	for(i=r1+1;i<r2;i++)
	{
		gotoxy(c1,i);
		cout<<ch;
	}
	ch=179;
	for(i=r1+1;i<r2;i++)
	{
		gotoxy(c2,i);
		cout<<ch;
	}
}

//*********************************
// Function for adding user record
//*********************************

void addrecord_user()
{
	clrscr();
	ofstream f;
	user u;
	f.open("user.dat",ios::binary|ios::app);
	u.getdata_user();
	f.write((char *)&u,sizeof(u));
	f.close();
}

//*********************************
// Function to display user record
//*********************************

void showallrecord_user()
{
	clrscr();
	ifstream f;
	user u;
	int e=5;
	f.open("user.dat",ios::binary);
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<"Emp_ID";
	gotoxy(15,3);
	cout<<"Emp_password";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(f.read((char *)&u,sizeof(u)))
	{
		u.showdata_user(e);
		e++;
	}
	f.close();
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

//**************************************
// Function to get last employee number
//**************************************

int getlastempno()
{
	ifstream f;
	employee e;
	int c=0;
	f.open("employee.dat",ios::binary);
	while(f.read((char *)&e,sizeof(e)))
		c=e.get_empid();
	f.close();
	return c;
}

//*************************************
// Function for adding Employee record
//*************************************

void addrecord_emp()
{
	clrscr();
	ofstream f;
	employee e;
	int en=getlastempno()+1;
	f.open("employee.dat",ios::binary|ios::app);
	e.getdata_emp(en);
	f.write((char *)&e,sizeof(e));
	f.close();
}

//*********************************
// Function to show Employee record
//*********************************

void showallrecord_emp()
{
	clrscr();
	ifstream f;
	employee e;
	int i=5;
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<" Emp_ID ";
	gotoxy(15,3);
	cout<<" Emp_NAME ";
	gotoxy(30,3);
	cout<<" SEX ";
	gotoxy(40,3);
	cout<<" PHONE_NO. ";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	f.open("employee.dat",ios::binary);
	while(f.read((char *)&e,sizeof(e)))
	{
		e.showdata_emp(i);
		i++;
	}
	f.close();
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

//*****************************************
// Function to search Employee information
//*****************************************

void searchrecord_emp()
{
	clrscr();
	int i=7;
	ifstream f;
	employee e;
	int en,flag=0;
	cout<<"\n Enter emp no to search ";
	cin>>en;
	f.open("employee.dat",ios::binary);
	while(f.read((char *)&e,sizeof(e)))
	{
		if(en==e.get_empid())
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" Emp_ID ";
			gotoxy(15,5);
			cout<<" Emp_NAME ";
			gotoxy(30,5);
			cout<<" SEX ";
			gotoxy(40,5);
			cout<<" PHONE_NO. ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			e.showdata_emp(i);
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry empno not exist ";
	}
}

//*****************************************
// Function To delete Employee information
//*****************************************

void deleterecord_emp()
{
	clrscr();
	ifstream f;
	int i=7;
	ofstream g;
	employee e;
	int en,flag=0;
	cout<<"\n Enter emp no to delete ";
	cin>>en;
	f.open("employee.dat",ios::binary);
	g.open("temp.dat",ios::binary);
	while(f.read((char *)&e,sizeof(e)))
	{
		if(en==e.get_empid())
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" Emp_ID ";
			gotoxy(15,5);
			cout<<" Emp_NAME ";
			gotoxy(30,5);
			cout<<" SEX ";
			gotoxy(40,5);
			cout<<" PHONE_NO. ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			e.showdata_emp(i);
			cout<<"\n Record Deleted ";
			flag=1;
		}
		else
		{
			g.write((char *)&e,sizeof(e));
		}
	}
	f.close();
	g.close();
	remove("employee.dat");
	rename("temp.dat","employee.dat");
	if(flag==0)
	{
		cout<<"\n Sorry empno not exist ";
	}
}

//*****************************************
// Function To modify Employee information
//*****************************************

void modifyrecord_emp()
{
	clrscr();
	fstream f;
	employee e;
	int i=7;
	f.open("employee.dat",ios::binary|ios::in|ios::out);
	int en,flag=0;
	cout<<"\n Enter empno to modify ";
	cin>>en;
	while(f.read((char *)&e,sizeof(e)))
	{
		if(e.get_empid()==en)
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" Emp_ID ";
			gotoxy(15,5);
			cout<<" Emp_NAME ";
			gotoxy(30,5);
			cout<<" SEX ";
			gotoxy(40,5);
			cout<<" PHONE_NO. ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			e.showdata_emp(i);
			e.getnewdata_emp();
			f.seekp(f.tellg()-sizeof(e),ios::beg);
			f.write((char *)&e,sizeof(e));
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry emp no not found ";
	}
}

//*****************************************
// Function To get last Item Number
//*****************************************

int getlastitemno()
{
	ifstream f;
	itemss i;
	int c=0;
	f.open("itemss.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
		c=i.get_itemid();
	f.close();
	return c;
}
//*****************************
// Function To add item record
//*****************************

void addrecord_item()
{
	clrscr();
	ofstream f;
	itemss i;
	int en=getlastitemno()+1;
	f.open("itemss.dat",ios::binary|ios::app);
	i.getdata_item(en);
	f.write((char *)&i,sizeof(i));
	f.close();
}

//*********************************
// Function To display item record
//*********************************

void showallrecord_item()
{
	clrscr();
	ifstream f;
	itemss i;
	int e=5;
	f.open("itemss.dat",ios::binary);
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<"ID ";
	gotoxy(15,3);
	cout<<" Name ";
	gotoxy(28,3);
	cout<<" Price ";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(f.read((char *)&i,sizeof(i)))
	{
		i.showdata_item(e);
		e++;
	}
	f.close();
}

void showallrecord_item1()
{
	ifstream f;
	itemss i;
	f.open("itemss.dat",ios::binary);
	box(10,40,25,60);
	int r=11;
	while(f.read((char *)&i,sizeof(i)))
	{
		i.showdata_item1(r);
		r++;
	}
	f.close();
}

//*************************************
// Function To search item information
//*************************************

void searchrecord_item()
{
	clrscr();
	ifstream f;
	itemss i;
	int a=7;
	int in,flag=0;
	cout<<"\n Enter item no to search ";
	cin>>in;
	f.open("itemss.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
	{
		if(in==i.get_itemid())
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" ID ";
			gotoxy(15,5);
			cout<<" NAME ";
			gotoxy(30,5);
			cout<<" PRICE ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			i.showdata_item(a);
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry item not exist ";
	}
}

//*******************************
// Function To return Item price
//*******************************

float getitemprice(char nm[])
{
	ifstream f;
	itemss i;
	float a;
	f.open("itemss.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
	{
		if(strcmp(nm,i.get_name())==0)
		{
			a=i.get_price();
			break;
		}
	}
	f.close();
	return a;
}

//*****************************
// Function To return Item ID
//*****************************

int getitemid(char nm[])
{
	ifstream f;
	itemss i;
	int id;
	f.open("itemss.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
	{
		if(strcmp(nm,i.get_name())==0)
		{
			id=i.get_itemid();
			break;
		}
	}
	f.close();
	return id;
}

//*******************************
// Function To return Item name
//*******************************

char *getitemname(int id)
{
	ifstream f;
	itemss i;
	char nm[20];
	f.open("itemss.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
	{
		if(id==i.get_itemid())
		{
			strcpy(nm,i.get_name());
			break;
		}
	}
	f.close();
	return nm;
}

//*************************************
// Function To delete Item information
//*************************************

void deleterecord_item()
{
	clrscr();
	ifstream f;
	ofstream g;
	int a=7;
	itemss i;
	int in,flag=0;
	cout<<"\n Enter item no to delete ";
	cin>>in;
	f.open("itemss.dat",ios::binary);
	g.open("temp.dat",ios::binary);
	while(f.read((char *)&i,sizeof(i)))
	{
		if(in==i.get_itemid())
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" ID ";
			gotoxy(15,5);
			cout<<" NAME ";
			gotoxy(30,5);
			cout<<" PRICE ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			i.showdata_item(a);
			cout<<"\n Record Deleted ";
			flag=1;
		}
		else
		{
			g.write((char *)&i,sizeof(i));
		}
	}
	f.close();
	g.close();
	remove("itemss.dat");
	rename("temp.dat","itemss.dat");
	if(flag==0)
	{
		cout<<"\n Sorry item not exist ";
	}
}

//*************************************
// Function To modify Item information
//*************************************

void modifyrecord_item()
{
	clrscr();
	fstream f;
	itemss i;
	int a=7;
	f.open("itemss.dat",ios::binary|ios::in|ios::out);
	int in,flag=0;
	cout<<"\n Enter item no to modify ";
	cin>>in;
	while(f.read((char *)&i,sizeof(i)))
	{
		if(i.get_itemid()==in)
		{
			cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<" ID ";
			gotoxy(15,5);
			cout<<" NAME ";
			gotoxy(30,5);
			cout<<" PRICE ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			i.showdata_item(a);
			i.getnewdata_item();
			f.seekp(f.tellg()-sizeof(i),ios::beg);
			f.write((char *)&i,sizeof(i));
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry item not found ";
	}
}

//*************************************
// Function To return last customer ID
//*************************************

int getlastcustomerid()
{
	ifstream f;
	customer cc;
	int c=0;
	f.open("customer.dat",ios::binary);
	while(f.read((char *)&cc,sizeof(cc)))
		c=cc.get_custid();
	f.close();
	return c;
}

//******************************************
// Function To display customer information
//******************************************

void showallrecord_customer()
{
	clrscr();
	ifstream f;
	customer cc;
	int e=5;
	f.open("customer.dat",ios::binary);
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<"Cutomer ID";
	gotoxy(15,3);
	cout<<" Name ";
	gotoxy(28,3);
	cout<<" Phone NO. ";
	gotoxy(41,3);
	cout<<" Address ";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(f.read((char *)&cc,sizeof(cc)))
	{
		cc.showdata_cust(e);
		e++;
	}
	f.close();
}

//******************************************
// Function To search customer information
//******************************************

void searchrecord_customer()
{
	clrscr();
	ifstream f;
	customer cc;
	int ci,flag=0,e=7;
	cout<<"\n Enter customer id to search ";
	cin>>ci;
	f.open("customer.dat",ios::binary);
	while(f.read((char *)&cc,sizeof(cc)))
	{
		if(ci==cc.get_custid())
		{
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			gotoxy(2,5);
			cout<<"Cutomer ID";
			gotoxy(15,5);
			cout<<" Name ";
			gotoxy(28,5);
			cout<<" Phone NO. ";
			gotoxy(41,5);
			cout<<" Address ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cc.showdata_cust(e);
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry customer not exist ";
	}
}

//***********************************
// Function To return customer name
//***********************************

char *getcustomername(int oid)
{
	ifstream f;
	customer cc;
	char nm[20];
	f.open("customer.dat",ios::binary);
	while(f.read((char *)&cc,sizeof(cc)))
	{
		if(oid==cc.get_oid())
		{
			strcpy(nm,cc.get_name());
			break;
		}
	}
	f.close();
	return nm;
}

//**********************************
// Function To return last order ID
//**********************************

int getlastorderid()
{
	ifstream f;
	order oo;
	int c=0;
	f.open("order.dat",ios::binary);
	while(f.read((char *)&oo,sizeof(oo)))
		c=oo.get_orderid();
	f.close();
	return c;
}

//***************************************
// Function To display order information
//***************************************

void showallrecord_order()
{
	clrscr();
	ifstream f;
	order oo;
	int e=5;
	f.open("order.dat",ios::binary);
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<"Order NO.";
	gotoxy(16,3);
	cout<<"Date";
	gotoxy(29,3);
	cout<<"Total";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(f.read((char *)&oo,sizeof(oo)))
	{
		oo.showdata_order(e);
		e++;
	}
	f.close();
}

//**************************************
// Function To search order information
//**************************************

void searchrecord_order()
{
	clrscr();
	ifstream f;
	order oo;
	int oi,flag=0,e=7;
	cout<<"\n Enter order id to search ";
	cin>>oi;
	f.open("order.dat",ios::binary);
	while(f.read((char *)&oo,sizeof(oo)))
	{
		if(oi==oo.get_orderid())
		{
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout<<endl<<"Order NO.";
			gotoxy(16,5);
			cout<<"Date";
			gotoxy(29,5);
			cout<<"Total";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			oo.showdata_order(e);
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry order not exist ";
	}
}

//******************************************
// Function To display bill information
//******************************************

void showallrecord_bill()
{
	clrscr();
	ifstream f;
	bill bb;
	int e=5;
	f.open("bill.dat",ios::binary);
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<endl<<" Bill ID ";
	gotoxy(15,3);
	cout<<" Status ";
	gotoxy(25,3);
	cout<<" Amount ";
	gotoxy(43,3);
	cout<<" Date ";
	cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	while(f.read((char *)&bb,sizeof(bb)))
	{
		bb.showdata_bill(e);
		e++;
	}
	f.close();
}

//******************************************
// Function To search bill information
//******************************************

void searchrecord_bill()
{
	clrscr();
	ifstream f;
	bill bb;
	int bi,flag=0,e=7;
	cout<<"\n Enter order id to search ";
	cin>>bi;
	f.open("order.dat",ios::binary);
	while(f.read((char *)&bb,sizeof(bb)))
	{
		if(bi==bb.get_billno())
		{
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			cout<<endl<<" Bill ID ";
			gotoxy(15,5);
			cout<<" Status ";
			gotoxy(25,5);
			cout<<" Amount ";
			gotoxy(43,3);
			cout<<" Date ";
			cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			bb.showdata_bill(e);
			flag=1;
			break;
		}
	}
	f.close();
	if(flag==0)
	{
		cout<<"\n Sorry bill not exist ";
	}
}

//***************************
// Function To Take an order
//***************************

void get_order()
{
	clrscr();
	int oid,price[5],qty[5],id[5],i=0,q;
	float amt[5],total=0;
	char nm[20],ch;
	struct date d;
	getdate(&d);
	mydate cd;
	cd.yy=d.da_year;
	cd.dd=d.da_day;
	cd.mm=d.da_mon;
	showallrecord_item1();
	gotoxy(3,3);
	oid=getlastorderid()+1;
	cout<<" Today Date : "<<cd.dd<<"/"<<cd.mm<<"/"<<cd.yy;
	gotoxy(43,3);
	cout<<" Order Id "<<oid;
	gotoxy(3,4);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(4,5);
	cout<<"Id";
	gotoxy(10,5);
	cout<<"Qty";
	gotoxy(15,5);
	cout<<"Price";
	gotoxy(23,5);
	cout<<"Amt";
	gotoxy(3,6);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	int cid=getlastcustomerid()+1 ;
	char name[20],phone[20],address[20];
	gotoxy(43,4);
	cout<<" Cust_id "<<cid;
	gotoxy(43,5);
	cout<<" Name ";
	gets(name);
	gotoxy(43,6);
	cout<<" Phone ";
	gets(phone);
	gotoxy(43,7);
	cout<<" Address ";
	gets(address);
	do
	{

		gotoxy(3,20);
		cout<<" Enter items-: ";
		gotoxy(3,21);
		cout<<" Enter name ";
		gets(nm);
		gotoxy(3,22);
		cout<<" Enter qty ";
		cin>>q;
		id[i]=getitemid(nm);
		price[i]=getitemprice(nm);
		qty[i]=q;
		amt[i]=price[i]*qty[i];
		total=total+amt[i];
		gotoxy(4,7+i);
		cout<<id[i];
		gotoxy(10,7+i);
		cout<<qty[i];
		gotoxy(15,7+i);
		cout<<price[i];
		gotoxy(23,7+i);
		cout<<amt[i];
		gotoxy(3,23);
		cout<<" Want more ";
		cin>>ch;
		i++;
		gotoxy(3,20);
		clreol();
		gotoxy(3,21);
		clreol();
		gotoxy(3,22);
		clreol();
		gotoxy(3,23);
		clreol();
		showallrecord_item1();
	}while(ch=='y' && i<4);
	gotoxy(3,7+i);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	gotoxy(4,8+i);
	cout<<" Total Bill "<<total;
	getch();

	customer cc;
	cc.getdata_cust(cid,name,address,phone,oid);
	ofstream fc;
	fc.open("customer.dat",ios::binary|ios::app);
	fc.write((char *)&cc,sizeof(cc));
	fc.close();

	order oo;
	oo.getdata_order(oid,cd,id,qty,amt,total,i);
	ofstream fo;
	fo.open("order.dat",ios::binary|ios::app);
	fo.write((char *)&oo,sizeof(oo));
	fo.close();
}

//***************************
// Function To Generate Bill
//***************************

void generate_bill()
{
	clrscr();
	ifstream f;
	order oo;
	bill bb;
	time_t ot,ct;
	ct=time(NULL);
	int oi,diff,n;
	char st;
	float a;
	mydate dt;
	cout<<"\n Enter order id ";
	cin>>oi;
	f.open("order.dat",ios::binary);
	while(f.read((char *)&oo,sizeof(oo)))
	{
		if(oi==oo.get_orderid())
		{
			ot=oo.gettt();
			dt=oo.getdt();
			a=oo.gettotal();
			diff=difftime(ct,ot);
			if(diff>300)
			{
				a=a-a*15/100;
				st='d';
			}
			else
			{
				st='o';
			}

			box(4,4,20,50);
			struct date d;
			getdate(&d);
			mydate cd;
			cd.yy=d.da_year;
			cd.dd=d.da_day;
			cd.mm=d.da_mon;
			int r=5,i;
			n=oo.getsize();

			gotoxy(5,r);
			cout<<" Today Date : "<<cd.dd<<"/"<<cd.mm<<"/"<<cd.yy;
			gotoxy(35,r);
			cout<<" Order Id "<<oi;
			r++;
			gotoxy(5,r);
			cout<<" Name "<<getcustomername(oi);
			r++;
			for(i=5;i<=49;i++)
			{
				gotoxy(i,r);
				cout<<(char)196;
			}
			r++;
			gotoxy(5,r);
			cout<<" Item Name ";
			gotoxy(20,r);
			cout<<"Qty";
			gotoxy(25,r);
			cout<<"Price";
			gotoxy(33,r);
			cout<<"Amount";
			r++;
			for(i=5;i<=49;i++)
			{
				gotoxy(i,r);
				cout<<(char)196;
			}
			int *id,*qt;
			float *am;
			r++;
			id=oo.getitemid();
			qt=oo.getqty();
			am=oo.getamt();
			for(i=0;i<n;i++)
			{
				gotoxy(6,r);
				cout<<getitemname(*id);
				gotoxy(20,r);
				cout<<*qt;
				gotoxy(25,r);
				cout<<(*am)/(*qt);
				gotoxy(33,r);
				cout<<*am;
				id++;
				qt++;
				am++;
				r++;
			}
			for(i=5;i<=49;i++)
			{
				gotoxy(i,r);
				cout<<(char)196;
			}
			r++;
			gotoxy(25,r);
			cout<<" Total "<<oo.gettotal();
			r++;
			gotoxy(25,r) ;
			if(st=='d')
				cout<<" Discount "<<oo.gettotal()-a;
			else
				cout<<" Discount "<<0;
			r++;
			gotoxy(25,r);
			cout<<" Net Amt  "<<a;

			bb.getdata_bill(oi,dt,st,a);
			ofstream fb;
			fb.open("bill.dat",ios::binary|ios::app);
			fb.write((char *)&bb,sizeof(bb));
			fb.close();

			break;
		}
	}
	f.close();
}

//***************************************************
// Function of a menu to access employee information
//***************************************************

void menu_emp()
{
	char op;
	do
	{
		clrscr();
		box(3,13,13,50);
		gotoxy(14,4);
		cout<<" 1 Add";
		gotoxy(14,5);
		cout<<" 2 Modify ";
		gotoxy(14,6);
		cout<<" 3 Delete ";
		gotoxy(14,7);
		cout<<" 0 Back ";
		gotoxy(14,8);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				addrecord_emp();
			break;
			case '2':
				modifyrecord_emp();
			break;
			case '3':
				deleterecord_emp();
			break;
		}
		getch();
	}while(op!='0');
}

//***************************************************
// Function of a menu to access item information
//***************************************************

void menu_item()
{
	char op;
	do
	{
		clrscr();
		box(3,13,13,50);
		gotoxy(14,4);
		cout<<" 1 Add";
		gotoxy(14,5);
		cout<<" 2 Modify ";
		gotoxy(14,6);
		cout<<" 3 Delete ";
		gotoxy(14,7);
		cout<<" 0 Back ";
		gotoxy(14,8);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				addrecord_item();
			break;
			case '2':
				modifyrecord_item();
			break;
			case '3':
				deleterecord_item();
			break;
		}
		getch();
	}while(op!='0');
}

//*************************************
// Function of a menu for any Queries
//*************************************

void menu_query()
{
	char op;
	do
	{
		clrscr();
		box(3,13,15,50);
		gotoxy(14,4);
		cout<<" 1 Employee ";
		gotoxy(14,5);
		cout<<" 2 Customer ";
		gotoxy(14,6);
		cout<<" 3 Item ";
		gotoxy(14,7);
		cout<<" 4 Order ";
		gotoxy(14,8);
		cout<<" 5 Bill ";
		gotoxy(14,9);
		cout<<" 0 Back ";
		gotoxy(14,10);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				searchrecord_emp();
			break;
			case '2':
				searchrecord_customer();
			break;
			case '3':
				searchrecord_item();
			break;
			case '4':
				searchrecord_order();
			break;
			case '5':
				searchrecord_bill();
			break;
		}
		getch();
	}while(op!='0');
}

//******************************************
// Function of a menu for different reports
//******************************************

void menu_report()
{
	char op;
	do
	{
		clrscr();
		box(3,13,15,50);
		gotoxy(14,4);
		cout<<" 1 Employee ";
		gotoxy(14,5);
		cout<<" 2 Customer ";
		gotoxy(14,6);
		cout<<" 3 Item ";
		gotoxy(14,7);
		cout<<" 4 Order ";
		gotoxy(14,8);
		cout<<" 5 Bill ";
		gotoxy(14,9);
		cout<<" 0 Back ";
		gotoxy(14,10);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				showallrecord_emp();
			break;
			case '2':
				showallrecord_customer();
			break;
			case '3':
				showallrecord_item();
			break;
			case '4':
				showallrecord_order();
			break;
			case '5':
				showallrecord_bill();
			break;
		}
		getch();
	}while(op!='0');
}

//***************************************************
// Function of a menu for accessing user information
//***************************************************

void menu_user()
{
	char op;
	do
	{
		clrscr();
		box(3,13,11,50);
		gotoxy(14,4);
		cout<<" 1 Add ";
		gotoxy(14,5);
		cout<<" 2 Show ";
		gotoxy(14,6);
		cout<<" 0 Back ";
		gotoxy(14,7);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				addrecord_user();
			break;
			case '2':
				showallrecord_user();
			break;
		}
		getch();
	}while(op!='0');
}

//**************************************
// Function of a menu For Admin access
//**************************************

void menu_main()
{
	char op;
	do
	{
		clrscr();
		box(3,13,17,50);
		gotoxy(14,4);
		cout<<" 1 Emp(Add/Modify/Delete) ";
		gotoxy(14,5);
		cout<<" 2 Item(Add/Modify/Delete) ";
		gotoxy(14,6);
		cout<<" 3 Order ";
		gotoxy(14,7);
		cout<<" 4 Generate Bill ";
		gotoxy(14,8);
		cout<<" 5 Query ";
		gotoxy(14,9);
		cout<<" 6 Report ";
		gotoxy(14,10);
		cout<<" 7 Create user ";
		gotoxy(14,11);
		cout<<" 0 Exit ";
		gotoxy(14,12);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				menu_emp();
			break;
			case '2':
				menu_item();
			break;
			case '3':
				get_order();
			break;
			case '4':
				generate_bill();
			break;
			case '5':
				menu_query();
			break;
			case '6':
				menu_report();
			break;
			case '7':
				menu_user();
			break;
		}
		getch();
	}while(op!='0');
}

//*************************************
// Function of a menu for User access
//*************************************

void menu_main1()
{
	char op;
	do
	{
		clrscr();
		box(3,13,13,50);
		gotoxy(14,4);
		cout<<" 1 Order ";
		gotoxy(14,5);
		cout<<" 2 Generate Bill ";
		gotoxy(14,6);
		cout<<" 3 Query ";
		gotoxy(14,7);
		cout<<" 4 Report ";
		gotoxy(14,8);
		cout<<" 0 Exit ";
		gotoxy(14,9);
		cout<<" Enter choice ";
		op=getche();
		switch(op)
		{
			case '1':
				get_order();
			break;
			case '2':
				generate_bill();
			break;
			case '3':
				menu_query();
			break;
			case '4':
				menu_report();
			break;
		}
		getch();
	}while(op!='0');
}

//*****************************
// Function for Welcome Screen
//*****************************

void welcome()
{
	clrscr();
	box(3,3,20,80);
	box(5,19,11,55);
	gotoxy(23,7);
	cout<<"WELCOME";
	gotoxy(33,8);
	cout<<"TO";
	gotoxy(40,9);
	cout<<"SNACKS PARLOUR ";
	for(int i=4;i<80;i++)
	{
		gotoxy(i,18);
		cout<<(char)196;
	}
	gotoxy(50,15);
	cout<<"Made By : -";
	gotoxy(63,16) ;
	cout<<"Paarth Sethi ";
	gotoxy(63,17);
	cout<<"XII A";
	gotoxy(45,19);
	cout<<"Press any key to continue.....";
}
//*************************
// Function For Password
//*************************
void password()
{
	char id[20],ps[20],ch;
	int i=0,flag=0;
	clrscr();
	box(6,13,13,53);
	gotoxy(15,8);
	cout<<"Enter id ";
	gotoxy(35,8);
	gets(id);
	gotoxy(15,9);
	cout<<"Enter pasword ";
	gotoxy(35,9);
	while(1)
	{
		ch=getch();
		if(ch==13)
			break;
		else if(ch==8)
		{
			if(i>0)
			{
				i--;
				gotoxy(35+i,9);
				clreol();
				box(6,13,13,53);
				gotoxy(35+i,9);
			}
		}
		else
		{
			cout<<"*";
			ps[i++]=ch;
		}
	}
	ps[i]='\0';
	if ( (strcmp(id,"admin")==0) && (strcmp(ps,"admin")==0) )
		menu_main();
	else
	{
		ifstream f;
		user u;
		f.open("user.dat",ios::binary);
		while(f.read((char *)&u,sizeof(u)))
		{
			if ( (strcmp(id,u.get_id())==0) && (strcmp(ps,u.get_ps())==0) )
			{
				flag=1;
				break;
			}
		}
		f.close();
		if(flag==1)
			menu_main1();
		else
		{
			gotoxy(15,11);
			cout<<"Sorry Invalid Login";
		}
	}
}

//**************************
// Function for Exit Screen
//**************************

void thank_you()
{
	clrscr();
	box(3,3,20,80);
	box(5,19,11,55);
	gotoxy(23,7);
	cout<<"THANK YOU";
	gotoxy(31,8);
	cout<<"FOR COMING TO ";
	gotoxy(40,9);
	cout<<"SNACKS PARLOUR ";
	for(int i=4;i<80;i++)
	{
		gotoxy(i,18);
		cout<<(char)196;
	}
	gotoxy(50,15);
	cout<<"Made By : -";
	gotoxy(63,16) ;
	cout<<"Paarth Sethi ";
	gotoxy(63,17);
	cout<<"XII A";
	gotoxy(45,19);
	cout<<"Press any key to exit.....";

}

void main()
{
	clrscr();
	welcome();
	getch();
	password();
	getch();
	thank_you();
	getch();
}