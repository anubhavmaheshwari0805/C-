#include<iostream>
#include<string.h>
using namespace std;
class person
{
	protected:
		char name[20];
		float paid,htp,total;
	public:
		int code;
		char reason[50];
		person()
		{
			paid=0;
			htp=0;
			total=0;
		}
		read(char a[20],int c)
		{
			strcpy(name,a);
			code=c;
		}
		int check(char b[20],int c)
		{
			int i=0;
			if(!strcmp(name,b))
			{
			    cout<<"Enter different name."<<endl;
			    i+=1;
		    }
		    if(code==c)
		    {
		    	cout<<"Enter different code."<<endl;
		    	i+=2;
			}
			return i;
		}
		void display()
		{
			cout<<name<<"\t-\t"<<code<<endl;
		}
		person operator -= (float i)
		{
			paid+=i;
			return *this;
		}
		person operator += (float j)
		{
			htp+=j;
		}
		void calculate()
		{
			total=htp;
			htp-=paid;
		}
		void show()
		{
			cout<<"Paid = "<<paid<<"\tHave to Pay = "<<htp<<"\tTotal Expenses = "<<total<<"Reason ="<<reason<<endl;
		}
};
int main()
{
	int n;
	cout<<"Enter the no. of peoples : ";
	cin>>n;
	person p[n];
	char name[20];
	int code,i,j;
	cout<<"Enter the names with a numeric code(except 0) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" - ";
		cin>>name>>code;
		for(j=0;j<i;j++)
		{
			int k=p[j].check(name,code);
			if(k==1)
			cin>>name;
			else if(k==2)
			cin>>code;
			else if(k==3)
			cin>>name>>code;
		}
		p[i].read(name,code);
	}
	cout<<"Person's name with their name code (Use these codes for entries) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" -\t";
		p[i].display();
	}
	cout<<"Note:\n\t1. In amount column, write amount paid.\n\t2. In Name Code column, write the code of the person who paid.\n\t3. In For Whom column, write the no. of persons whose bill is paid followed by code of persons (Ex. 3 1 3 5) and for all write 0 .\n\t4. In Reason column, write the reason in one word or without space.\n\t5. If the entries are over then write 0 .\nEntries : "<<endl;
	cout<<"Amount\t-\tName Code\t-\tFor Whom\t-\tReason(in 1 word)\n";
	float amount;
	int no,c[n];
	char reason[50];
	int k=1;
	cout<<k<<" - ";
	cin>>amount;
	while(amount!=0)
	{
		cin>>code;
		for(i=0;i<n;i++)
		{
			if(p[i].code==code)
			p[i]-=amount;
		}
		cin>>no;
		if(no==0)
		{
			for(i=0;i<n;i++)
			p[i]+=amount/n;
		}
		else if(no!=0)
		{
			for(i=0;i<no;i++)
			{
				cin>>c[i];
				for(j=0;j<n;j++)
				{
					if(c[i]==p[j].code)
					p[j]+=amount/no;
				}
			}
		}
		cin>>reason;
		for(i=0;i<n;i++)
		{
			if(p[i].code==code)
			strcpy(p[i].reason,reason);
		}
		k++;
		cout<<k<<" - ";
		cin>>amount;
	}
	for(i=0;i<n;i++)
	{
	    p[i].calculate();
	    p[i].show();
    }
	return 0;
}
