#include <iostream>
#include <vector>
#include <time.h>

void print(std::vector<std::vector<int>> &array)
{
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size(); j++)
		{
			std::cout << array[i][j] << " ";

			// для красивого вывода все это

			int num = array[i][j];
			int count = 0;

			while (num > 0)
			{
				num /= 10;
				count++;
			} 

			for (int k = 0; k < 4 - count; k++)
			{
				std::cout << " ";
			}
		}

		std::cout << "\n";
	}
}

int main()
{
	srand(time(0));
	rand();

	std::vector<std::vector<int>> array;

	for (int i = 0; i < 5; i++)
	{
		array.push_back(std::vector<int> {});

		for (int j = 0; j < 5; j++)
		{
			int num = 0 + rand() % ((1000 + 1) - 0);
			array[i].push_back(num);
		}
	}

	std::cout << "Before: \n";
	print(array);

	for (int i = 0; i < array.size(); i++)
	{
		for (int k = 0; k < array[i].size(); k++)
		{
			for (int j = array[i].size() - 1; j > 0; j--)
			{
				if (array[i][j] < array[i][j - 1])
				{
					int temp = array[i][j];
					array[i][j] = array[i][j - 1];
					array[i][j - 1] = temp;
				}
			}
		}
	}

	std::cout << "\nAfter: \n";
	print(array);
}