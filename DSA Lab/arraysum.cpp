#include<iostream>
using namespace std;
int main()
{
	int a[5], i, sum = 0;
	cout << "Enter array elements";
	for (i = 0; i < 5; i++)
	{
	 cout << "\n\t Enter " << i+1 << "th element :";
	 cin >> a[i];
	}
	for (i = 0; i < 5; i++)
	{
	sum = sum + a[i];
	}
	cout << "\n\tAdditon is " << sum;
	return 0;
}
