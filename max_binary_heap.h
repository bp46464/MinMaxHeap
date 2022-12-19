#pragma once
#include<string>
template<typename T>
class max_binary_heap
{
private:
	void heap_down(T);
	void heap_up(T);
public:
	int size = 2;
	int current_size;

	T* tab;
	max_binary_heap();
	void insert(T);
	void grow_heap();

	std::string toString();
	void clear();
	T poll();
	T get(int);
};

template<typename T>
inline max_binary_heap<T>::max_binary_heap()
{
	current_size = 0;
	tab = new T[size];
}

template<typename T>
inline void max_binary_heap<T>::insert(T value)
{
	int i = current_size;
	if (current_size == size)
		grow_heap();

	if (current_size == 0)
		tab[0] = value;
	else
		tab[i] = value; // w sumie tożsame z tym u góry

	//heap_up
	heap_up(i);

	current_size++;
}

template<typename T>
inline void max_binary_heap<T>::grow_heap()
{
	T* temp = new T[size * 2];
	for (int i = 0; i < size; i++)
		temp[i] = tab[i];

	delete[] tab;
	tab = temp;
	size = size * 2;
}

template<typename T>
inline void max_binary_heap<T>::heap_down(T value)
{
	T wiekszy = value;
	int left = 2 * value + 1;
	int right = left + 1;
	if ((2 * value + 1) < size && tab[2 * value + 1] > tab[value])
		wiekszy = (2 * value) + 1;

	if ((2 * value + 2) < size && tab[2 * value + 2] > tab[wiekszy])
		wiekszy = (2 * value) + 2;

	if (wiekszy != value)
	{
		T temp = tab[value];
		tab[value] = tab[wiekszy];
		tab[wiekszy] = temp;
		heap_down(wiekszy);
	}

}

template<typename T>
inline void max_binary_heap<T>::heap_up(T value)
{
	T wiekszy = value;

	if (tab[value] > tab[(value - 1) / 2])
	{
		wiekszy = (value - 1) / 2;
		std::swap(tab[value], tab[wiekszy]);
		heap_up(wiekszy);
	}
}

template<typename T>
inline std::string max_binary_heap<T>::toString()
{
	std::string s;

	for (int i = 0; i < current_size; i++)
	{
		s.append(std::to_string(tab[i]));
		s.append(" ");

	}

	return s;
}

template<typename T>
inline void max_binary_heap<T>::clear()
{
	size = 2;
	current_size = 0;
	delete[] tab;
	tab = new T[size];
}

template<typename T>
inline T max_binary_heap<T>::poll()
{
	current_size--;
	T value = tab[0];
	tab[0] = tab[current_size];

	heap_down(0);


	return value;
}

template<typename T>
inline T max_binary_heap<T>::get(int index)
{
	return tab[index];
}
