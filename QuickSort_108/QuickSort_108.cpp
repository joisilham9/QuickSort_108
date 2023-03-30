#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}
	cout << "\n________________" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n__________________" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)
		return;

	pivot = arr[low];
	
	i = low + 1;
	j = high;

	while (i <= j)
	{
		while ((arr[i] <= pivot) && (i<= high))
		{
			i++;
			cmp_count++;
		}
		cmp_count++;

		while ((arr[j] > pivot) && (j >= low))
		{
			j--;
			cmp_count++;
		}
		cmp_count++;

	
		if (i < j)
		{
			swap(i, j);
			mov_count++;
			}
	}
	if (low < j)
	{
		swap(low, j);
		mov_count++;
	}
	q_short(low, j - 1);

	q_short(j + 1, high);
}

void display() {
	cout << "\n--------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n--------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n - 1);
	display();
	system("pause");
	
	return 0;
}