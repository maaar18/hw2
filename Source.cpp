#include "Header.h"


//task1

void swap(int* a1, int* b1)
	{
	std::cout << "task #1" << std::endl;

		int temp = *a1;
		*a1 = *b1;
		*b1 = temp;

	}


//task2

int task_2() {
	std::cout << "task #2 " << std::endl;
	int n, temp;
	std::cout << "Enter size of massive: " << std::endl;
	std::cin >> n;
	int* a = new int[n]; //Указатель массива
	int* pa = &a[0]; //Указатель на первый элемент массива
	int* pla = &a[n - 1]; //указатель на последний элемент массива
	std::cout << "Enter massive: " << std::endl;
	for (int i = 0; i < n; i++) //Вывод массива
		std::cin >> a[i];
	temp = *pa; //Меняем местами последний и первый элемент 
	*pa = *pla;
	*pla = temp;
	std::cout << "New massive: " << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << " " << std::endl;
	delete[] a;
	return 0;
}

//task3

int task_3()
{
	std::cout << "task #3" << std::endl;
	double a = 2;
	double* b = &a;
	double** p = &b; //указатель на число
	std::cout << **p << std::endl; //выводим 2 через указатель

	
	return 0;
}



//task4

int task_4() {
	std::cout << "task #4" << std::endl;
	int arr[12] = { 18,26,25,25,24,14,19,27,20,20,20,11 };

	int temp, numOfSwaps = 0;

	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			if (arr[j] < arr[j + 1])//Сортируем массив
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				numOfSwaps++;//При каждой перестановке переменная numOfSwaps увеличивается
			}
		}
	}
	std::cout << " New array: " << std::endl;
	for (int k = 0; k < 12; k++) {
		std::cout << arr[k] << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "Number of swaps: " << numOfSwaps << std::endl;


	return 0;
}

//task6

int task_6() {
	std::cout << "task #6" << std::endl;
	int arr1[14] = { 18,26,25,25,24,14,19,27,20,20,20,11,12,16 };

	int t, numOfSwaps = 0;
	int len = sizeof(arr1) / sizeof(arr1[0]) / 2; //Перемеравная равная половине массива

	for (int i = 0; i < len; i++)
	{
		int t = arr1[i]; //Меняем элементы массива местами, так что первый элемент меняется с элементом, у которого индекс больше на len, половину массива

		arr1[i] = arr1[len + i];

		arr1[len + i] = t;
		numOfSwaps++;// При кажой перестановке переменная numOfSwaps увеличивается на 1
	}
	std::cout << " New array: " << std::endl;
	for (int k = 0; k < 14; k++) {
		std::cout << arr1[k] << " ";
	}
	std::cout << " " << std::endl;
	std::cout << "Number of swaps: " << numOfSwaps << std::endl;
	return 0;
}


//task7

int task_7()
{
	std::cout << "task #7" << std::endl;
	srand((unsigned)time(NULL));
	int count = 0; //счетчик локальных минимумов
	int size; //размер массива
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	int* arr = new int[size];

	//заполнение массива
	std::cout << "The array: ";
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl; 

	//цикл для подсчета локального минимума
	for (int i = 0; i < size; i++)
	{
		if (i == 0 && arr[i] < arr[i + 1]) count++;
		else if (i > 0 && i < size - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) count++;
		else if (i == size - 1 && arr[i] < arr[i - 1]) count++;
	}
	std::cout << "Number of local minima: " << count << std::endl;
	delete[]arr;

	return 0;
}

//task8

int task_8() {
	std::cout << "task 8" << std::endl;
	int m[5][5] = {
  {1, 0, 2, 3, 0},
  {0, 4, 0, 5, 6},
  {7, 8, 0, 9, 0},
  {11, 0, 12, 13, 0},
  {15, 16, 0, 17, 0}
	};
	int* p = &m[0][0];
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << " Sum:";
		while (*p != 0) {
			p++;
		}
		p++;
		while (*p != 0) {
			sum += *p;
			p++;
		}

		p++;
		std::cout << sum << std::endl;
		sum = 0;
	}
	return 0;
}



//task10

int task_10() {
	std::cout << "task #10" << std::endl;
	int n;
	std::cout << "Enter size of massive: ";
	std::cin >> n;
	int* arr1 = new int[n]; // Выделение памяти для массива
	std::cout << "Enter 1 massive: " << std::endl;
	for (int i = 0; i < n; i++) {
		// Заполнение массива и вывод значений его элементов
		std::cin >> arr1[i];
	}
	int* arr2 = new int[n];
	std::cout << "Enter  2 massive: " << std::endl;
	for (int i = 0; i < n; i++) {
		// Заполнение массива и вывод значений его элементов
		std::cin >> arr2[i];
	}

	int max1 = arr1[0];
	int max2 = arr2[0];
	int pos1 = 0;
	int pos2 = 0;
	for (int i = 0; i < n; i++) { //Находим маусимальный элемент и его индекс
		if (arr1[i] > max1) {
			max1 = arr1[i]; pos1 = i;
		}
		if (arr2[i] > max2) {
			max2 = arr2[i]; pos2 = i;
		}
	} int temp = arr1[pos1]; //Меняем местами максимальные элементы
	arr1[pos1] = arr2[pos2];
	arr2[pos2] = temp;
	std::cout << "New massives:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << arr2[i] << " ";
	}
	delete[] arr1;
	delete[] arr2;
	std::cout << std::endl;
	return 0;
}



//task12
int task_12()
{
	const size_t n = 3;
	const size_t m = 4;

	int arr1[n][m];


	std::cout << "Input matrix with 3 rows and 4 columns" << std::endl;
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < m; ++j)
			std::cin >> arr1[i][j];

	for (int k = 0; k < 3; k++) {
		for (int m = 0; m < 4; m++) {
			std::cout << arr1[k][m] << " ";
		}
	}


	int max_sum = 0;
	int min_sum = 0;
	int max_row = 0;
	int min_row = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += arr1[i][j];
		}
		if (sum > max_sum)
		{
			max_sum = sum;
			max_row = i;
		}
		if (sum < min_sum)
		{
			min_sum = sum;
			min_row = i;
		}
	}
	std::cout << "max: " << max_row + 1 << std::endl;
	std::cout << "min: " << min_row << std::endl;
	return 0;
}



//task15

int task_15()
{
	std::cout << "task #15" << std::endl;
	int i, j, k;
	int value, rows;
	std::cout << "Enter the number of rows: ";
	std::cin >> rows;
	

	for (i = 0; i < rows; i++)
	{
		value = 1;
		for (j = 0; j < rows - 1 - i; j++)
		{
			std::cout << " ";
		}
		
		for (k = 0; k <= i; k++)
		{
			std::cout << " " << value;
			value = value * (i - k) / (k + 1);
			
		}
		std::cout << " ";
		
	}
	return 0;
}




int main()
{
	//task1:
	// int a = 5;
	// int b = 8;
    //std::cout <<"Initial values of the arguments:" << " a = " << a << ", b = " << b << std::endl;
    //swap(&a, &b);
	//std::cout << "The values of the arguments after the swap function:" << " a = " << a << ", b = " << b << std::endl; 

	//task_2();
	//task_3();
	//task_4();
	//task_6();
	//task_7();
	//task_8();
	//task_10();
	//task_12();
	//task_15();
	
}