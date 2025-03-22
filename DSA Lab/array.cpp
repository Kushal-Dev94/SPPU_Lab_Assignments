#include<iostream>
using namespace std;
int main()
{
	int a[5];
	int i;
	cout << "Enter array elements";
	for (i = 0; i < 5; i++)
	{
	 cout << "/n/t Enter " << i+1 << "th element :";
	 cin >> a[i];
	}
	for (i = 0; i < 5; i++)
	{
	cout << "\n[" << i+1 << "] = " << a[i] << endl;
	}
	return 0;
}
