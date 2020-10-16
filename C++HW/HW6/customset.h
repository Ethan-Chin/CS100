#ifndef CUSTOMSET_H_
#define CUSTOMSET_H_
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

template <typename T>
class CustomSet
{
public:
// Constructors and destructor:
	CustomSet()
    {
    };
	// Default constructor
	
	CustomSet(const CustomSet& other)
    {
        theSet.assign((other.theSet).begin(), (other.theSet).end());
    };
	// Copy constructor. Should construct a copy of "other".
	
	CustomSet(T arr[], int size)
    {	
		theSet.reserve(size);
		for (int i = 0; i < size; i++)
		{
			theSet.push_back(arr[i]);
		}
		sort(theSet.begin(), theSet.end());
		theSet.resize(unique(theSet.begin(), theSet.end()) - theSet.begin());
    };
	// Constructor using an array. 
	// Note that if there are duplicates in the array, you should ignore them.
	// And then the size of your "CustomSet" will be different from the "size" given!
	
	~CustomSet()
    {
    };
	// Destructor. Pay attention to memory leaks!
	
// Other member functions:
	const int size() const
    {
        return theSet.size();
    };
	// Returns the size of the set.

	bool add(const T& item)
	{
		if (count(theSet.begin(), theSet.end(), item))
		{
			return false;
		}
		theSet.push_back(item);
		return true;
	};
	// If "item" is already in the set, return false. 
	// Otherwise, add it to the set and return true.

	const T* find(const T& item) const
	{
		for (int i = 0; i < this->size(); i++)
		{
			if (theSet[i]== item)
			{
				return &(theSet[i]);
			}
		}
		return nullptr;
	};
	// If an object in the set equals "item", return a pointer to it.
	// If "item" is not found, return nullptr(NULL).
 
	bool erase(const T& item)
	{
		typename vector<T>::iterator it = theSet.begin();
		for (; it != theSet.end(); it++)
		{
			if (*it == item)
			{
				theSet.erase(it);
				return true;
			}
		}
		return false;
	};
	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.
	const CustomSet intersection(const CustomSet& other) const
	{
		CustomSet<T> interCustomset;
		for (int i = 0; i < this->size(); i++)
		{
			for (int j = 0; j < other.size(); j++)
			{
				if (theSet[i] == other.theSet[j])
				{
					interCustomset.theSet.push_back(theSet[i]);
				}
			}
		}
		return interCustomset;
	};
	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.

	void sortSet()
	{
		sort(theSet.begin(), theSet.end());
	};
	// This function sorts the objects in the set in ascending order.
	// Directly using (std::)sort is enough, if you are using an STL container.

	void printSet() const
	{
		cout<<'{';
		for (int i = 0;i < this->size(); i++)
		{
			if ((i + 1) != this->size())
			{
				cout<<theSet[i];
				cout<<", ";
			}
			else
			{
				cout<<theSet[i];
			}
		}
		cout<<'}'<<'\n';
	};
	// This function prints the set, seperating elements by { , , , }.
	// It's safe to assume that it supports operator<< of ostream (cout).
	// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
	// This function will print: "{2, 4, -2, 800}\n"
	// Note that there are spaces between a comma(,) and the next object.
	// Print a newline at the end. (indicated by the '\n' above)
	bool inBound(T const minlim, T const maxlim)
	{
		this->sortSet();
		if (theSet[0] >= minlim && theSet[this->size() - 1] <= maxlim)
		{
			return true;
		}
		return false;
	};

	void initialize()
	{
		theSet.clear();
	};
// Operators:
	const CustomSet operator+ (const T& item) const
	{
		CustomSet result(*this);
		result.add(item);
		return result;
	};
	const CustomSet operator+ (const CustomSet& that) const
	{
		CustomSet result(*this);
		for (int i = 0; i < that.size(); i++)
		{
			result.add(that.theSet[i]);
		}
		return result;
	};
	CustomSet& operator+= (const T& item)
	{
		this->add(item);
		return *this;
	};
	CustomSet& operator+= (const CustomSet& that)
	{
		for (int i = 0; i < that.size(); i++)
		{
			*this += that.theSet[i];
		}
		return *this;
	};
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item. S
	// A set "plus" a set means taking the union of two sets.
	// However, the difference between + and += is not written here.
	// Try to figure out on your own!

	const CustomSet operator- (const T& item) const
	{
		CustomSet result(*this);
		result.erase(item);
		return result;
	};
	const CustomSet operator- (const CustomSet& that) const
	{
		CustomSet result(*this);
		for (int i = 0; i < that.size(); i++)
		{
			result.erase(that.theSet[i]);
		}
		return result;
	};
	CustomSet& operator-= (const T& item)
	{
		this->erase(item);
		return *this;
	};
	CustomSet& operator-= (const CustomSet& that)
	{
		for (int i = 0; i < that.size(); i++)
		{
			*this -= that.theSet[i];
		}
		return *this;
	};
	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item. 
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	// However, the difference between - and -= is not written here.
	// Try to figure out on your own!
	
	
	const CustomSet<pair<T, T>> operator* (const CustomSet& that) const
	{
		CustomSet<pair<T, T>> result;
		for (int i = 0; i < this->size(); i++)
		{
			for (int j = 0;  j < that.size(); j++)
			{
				result.add(make_pair(theSet[i], that.theSet[j]));
			}
		}
		return result;
	};
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!

private:
	vector<T> theSet;
};
#endif
