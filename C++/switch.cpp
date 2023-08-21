#include<iostream>
using namespace std;
int main()
{
	int a,b,c,ch;
	cout << "\n\t enter a & b: ";
	cin >> a >> b;
	do
	{
		cout << "\n\t 1. Add";
		cout << "\n\t 2. Subtract";
		cout << "\n\t 3. Multiply";
		cout << "\n\t 4. divide";
		cout << "\n\t 5. Exit";
		cout << "\n\t Enter your choice: ";
		cin >> ch;
		
		switch(ch)
		{
		 case 1: c = a + b;
		 	cout << "\n\t Addition is " << c << endl;
		 	break;
		 case 2: c = a - b;
		 	cout << "\n\t Subtraction is " << c << endl;
		 	break;
		 case 3: c = a * b;
		 	cout << "\n\t Multiplication is " << c << endl;
		 	break;
		 case 4: c = a / b;
		 	cout << "\n\t Division is " << c << endl;
		 	break;
		 case 5:exit(0);
		 	break;
		}
	}
	while(ch != 5);
	return 0;
}
