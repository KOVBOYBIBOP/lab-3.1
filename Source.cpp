#include <iostream>
using namespace std;
int const SIZE = 1000;


int arr[SIZE]{ 0 };

void exit();
int size() 

{
	int count;
	cout << "������� ������ �������: ";
	cin >> count;
	return count;
}
void menu()
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ����� ���������, ������� �� ������ �� ��������� \n";
	cout << "1 - ��������� ����� ��  �� ����������� (�� ����� 1000 ��������� �� ���) \n";
	cout << "2 - ��������� ����� �� ����������� (�� ����� 1000 ��������� �� ���) \n";
	cout << "3 - ��������� ����� �������� (�� ����� 1000 ��������� �� ���)\n";
	cout << "����� ���������: ";

}

void massiv(int arr[], const int SIZE, int count)//���� �������������� �������
{
	setlocale(LC_ALL, "Rus");



	cout << "������� �������� �������" << endl;

	for (int i = 0; i < count; i++)
	{
		cin >> arr[i];
	}


}

void massivc(char acc[],int countc) // ���� ����������� �������
{
	setlocale(LC_ALL, "Rus");
	cin >> acc;
	
}

void func31(int arr3[], int l, int r, int count ) 
{
	int fleft = l, mid = l +  (r - l) / 2, sleft = mid + 1,carr = 0,sarr[SIZE];
	while (fleft <= mid && sleft <= r) 
	{
		if (arr3[fleft] <= arr3[sleft]) 
		{
			sarr[carr] = arr3[fleft];
			fleft++;
		}

		else 
		{
			sarr[carr] = arr3[sleft];
			sleft++;
		}
		carr++;
	}
	while (fleft <= mid) 
	{
		sarr[carr] = arr3[fleft];
		fleft++;
		carr++;
	}
	while (sleft <= r) 
	{
		sarr[carr] = arr3[sleft];
		sleft++;
		carr++;
	}
	for (fleft = 0; fleft < carr; fleft++) 
	{
		arr3[l + fleft] = sarr[fleft];
	}
}

void func32 (int arr3[], int l, int r) {
	if (l < r) {
		if ((r - l) == 1)
		{
			if (arr3[l] > arr3[r]) {
				swap(arr3[l], arr3[r]);
			}
		}
		else {
			func32(arr3, l, l + (r - l) / 2);
			func32(arr3, l + (r - l )/ 2 + 1, r);
			func31(arr3, l, r, r + 1);
		}
	}
}
void func33()
{
	int count = size();
	int arr3[SIZE]{ 0 };
	massiv(arr3, SIZE, count);

	func32(arr3, 0, count - 1);

	cout << "��������������� ������: ";
	for (int i = 0; i < count; i++)
	{
		cout << arr3[i] << " ";
	}
	cout << endl;
	exit();
}
void func1()//����� ���������� ���������
{
	int count = size();

	massiv(arr, SIZE, count);

	for (int i = 0; i <count; i++)
	{
		for (int j = i; j < count -1; j++)
		{
			if (arr[i] > arr[j + 1])
			{
				swap(arr[i], arr[j + 1]);
				

			}
		}
	}
	cout << "��������������� ������: ";
	for (int k = 0; k < count; k++)
	{
		cout << arr[k]<< " " ;
	}
	exit();
}

void func2()//���������� ���������� ������� �� ��������� ���������
{

	char acc[SIZE];
	int countc = size();

	cout << "������� ������ �� �������� ��2��������� ��������: ";
	massivc(acc, countc);
	setlocale(LC_ALL, "Rus");
	int att[26]{}, j, i;
	

	for (int i = 0; i < countc; i++)
	{
		j = int(acc[i] - int('a'));
		att[j]++;
		
	}
	i = 0;
	j = 0;
	while (j < 26)
	{
		if (att[j] > 0)
		{
			acc[i] = char(int('a') + j);
			i++;
			att[j]--;

		}
		else
		{
			j++;
		}

	}
	cout << "��������������� ������: ";
	for (int k = 0; k < countc; k++)
	{
		cout << acc[k];

	}
	cout << endl;
	exit();
}


void exit()
{
	for (int i = 0; i < 10; i++)
	{
		cout <<  endl;
	}
}

int main()
{	
	while (true)
	{


		setlocale(LC_ALL, "Rus");
		menu();
		int triger;
		cin >> triger;
		switch (triger)
		{
		case 1:
		{
			func1();
			break;
		}
		case 2:
		{
			func2();
			break;
		}
		case 3:
		{
			func33();
			break;

		}
		default:
			return 0;
			break;
		}
	}
	
}