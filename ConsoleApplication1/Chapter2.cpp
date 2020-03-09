#include <iostream>
#include <complex>
#include <string>
#include <variant>
#include <vector>

using namespace std;

struct Vector1 {
	int sz; // number of elements
	double* elem; // pointer to elements


};

void vector_init(Vector1& v, int s)
{
	v.elem = new double[s]; // allocate an array of s doubles
	v.sz = s;
}

double read_and_sum1(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
	Vector1 v;
	vector_init(v,s); //allocate s elements for v
	for (int i=0; i!=s; ++i)
		cin>>v.elem[i]; // read into elements
	double sum = 0;
	for (int i=0; i!=s; ++i)
		sum+=v.elem[i]; // compute the sum of the elements
	return sum;
}

class Vector {
	public:
		Vector(int s) :elem{new double[s]}, sz{s} { } // construct a Vector
		double& operator[](int i) { return elem[i]; } // element access: subscripting (a double& allows both reading and writing!)
		int size() { return sz; }
	private:
		double* elem; // pointer to the elements
		int sz; // the number of elements
};

double read_and_sum(int s)
{
	Vector v(s); // make a vector of s elements
	for (int i=0; i!=v.size(); ++i)
		cin>>v[i]; //read into elements
	double sum = 0;
	for (int i=0; i!=v.size(); ++i)
		sum+=v[i]; //take the sum of the elements
	return sum;
}

class Node {};
enum Type { ptr, num }; // a Type can hold values ptr and num (§2.5)
struct Entry {
	string name; // string is a standard-librar y type
	Type t;
	Node* p; // use p if t==ptr
	int i; // use i if t==num
};

union Value {
	Node* p;
	int i;
};

void f(Entry* pe)
{
	if (pe->t == num)
		cout << pe->i;
	// ...
}

struct Entry2 {
	string name;
	variant<Node*,int> v;
};

enum Color { red, blue , green };	// this is a plain enum which can be easily cast to the underlying int 
enum class Traffic_light { green, yellow, red };

Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
	switch (t) {
		case Traffic_light::green: return t=Traffic_light::yellow;
		case Traffic_light::yellow: return t=Traffic_light::red;
		case Traffic_light::red: return t=Traffic_light::green;
	}
}

int main()
{
	Vector1 v1;

	double result = read_and_sum1(3);
	cout << result << endl;

	Vector v2(2);
	result = read_and_sum1(2);
	cout << result << endl;

	Color col = Color::red;
	int col2 = green;
	Traffic_light light = Traffic_light::red;
	Traffic_light next = ++light; // next becomes Traffic_light::green
}