#pragma once
#include <iostream>

using namespace std;

class DynamicArray
{
	friend ostream& operator<<(ostream &, const DynamicArray&);
public:

	DynamicArray();
	DynamicArray(int);
	DynamicArray(const DynamicArray&);
	
	~DynamicArray(); 

	const int&		operator[](int) const;
	int&			operator[](int);
	//DynamicArray	operator=(const DynamicArray&);
	
	int				binarySearch(int) const;
	int				getLength() const;
	int				min() const;
	int				max() const;

	void			add(int);
	void			trim();
	void			qSort(int, int);
	void			qSort();//ÊÎÑÒÛËÜ
	void			insertTo(int, int);
	void			remove(int);

private:
	int*			innerArray; 
	
	int				length; 
	int				capacity;

	const int		growFactor		= 2;
	const int		defaulCapacity  = 4 ;

	static void		resizeArray(int*&, int, int);
	static void		copyArray(int*, int, int*);
	static int*		allocateMemory(int);

	void			setLength(int);
};

