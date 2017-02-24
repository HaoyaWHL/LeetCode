#include <iostream>
// #include <algorithm>

using namespace std;
 
int main()
{
	int k = 0;
	int a[5] = { 5, 4, 3, 2, 1 };
	int temp[5] = { 0 };
	temp[k++] = a[0];
	for (int i = 0; i < 5; i++)
	{
		cout << temp[i] << endl;
	}

}