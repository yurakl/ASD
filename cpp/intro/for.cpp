#include <iostream>

//~ Цикли в С++
int main()
{
	
	int array[5] = {1, 2, 3, 4, 5};
	
	//~ Класичний варіант циклу - доступ до елементів через індекси
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] << std::endl;
	}

	//~ Цикл по діапазону - range-based loop
	//~ Цикл по масиву array
	//~ На кожній ітерації element - це посилання на інший елемент масиву
	
	//~ В цьому варіанті можна було б використати і такий варіант:  for (int& element : array)
		//~ auto - даємо компілятору визначити тип
		//~ const  - щоб element не можна змінити
	for (const auto& element : array)
	{
		std::cout << element << std::endl; 
	}

	//~ Якщо НЕ використати посилання: (int element : array)
	//~ то element - це КОПІЯ елемента масиву.
	//~ Якщо ви зміните element - масив НЕ зміниться

	
	return 0;
}
