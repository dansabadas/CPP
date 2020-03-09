#include <iostream> // include (‘‘import’’) the declarations for the I/O stream library
#include <complex>
#include <vector>

using namespace std; // make names from std visible without std:: (§3.4)

double square(double x)
{
    return x*x;
}

void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) << "\n";
}

double sum(const vector<double>& v) // sum will not modify its argument (§1.7)
{
    return v.size();
}

constexpr double square2(double x) { return x*x; }

constexpr double nth(double x, int n) // assume 0<=n
{
    double res = 1;
    int i = 0;
    while (i<n) { // while-loop: do while the condition is true (§1.7.1)
        res*=x;
        ++i;
    }
    return res;
}

void copy_fct()
{
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10]; // to become a copy of v1
    for (auto i=0; i!=10; ++i) // copy elements
    v2[i]=v1[i];
    // ...
}

void print2()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto x : v) // for each x in v
        cout << x << '\n';
    for (auto x : {10,21,32,43,54,65})
        cout << x << '\n';
    // ...
}

//void print3(int& v[])
//{
//    for (auto& x : v) // for each x in v
//        cout << x << '\n';
//}

void increment()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto& x : v) // add 1 to each x in v
    ++x;
// ...
}

int count_x(const char* p, char x)
// count the number of occurrences of x in p[]
// p is assumed to point to a zero-terminated array of char (or to nothing)
{
    if (p==nullptr)
        return 0;

    int count = 0;
    for (; *p!=0; ++p)
        if (*p==x)
            ++count;

    return count;
}

bool accept2()
{
    cout << "Do you want to proceed (y or n)?\n"; // wr ite question
    char answer = 0; // initialize to a value that will not appear on input
    cin >> answer; // read answer
    switch (answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "I'll take that for a no.\n";
            return false;
    }
}
int main()
{
    print_square(1.234);
    cout << sizeof(bool) << "\n";
    double d1 = 2.3; // initialize d1 to 2.3
    double d2 {2.3}; // initialize d2 to 2.3
    double d3 = {2.3}; // initialize d3 to 2.3 (the = is optional with { ... })
    complex<double> z1 = 1; // a complex number with double-precision floating-point scalars
    complex<double> z2 {d1,d2};
    complex<double> z3 = {d1,d2}; // the = is optional with { ... }

    auto b = true; // a bool
    auto ch = 'x'; // a char
    auto i = 123; // an int
    auto d = 1.2; // a double
    auto y = 9;
    auto z = sqrt(y); // z has the type of whatever sqrt(y) returns
    auto bb {true}; // bb is a bool

    constexpr int dmv = 17; // dmv is a named constant
    int var = 17; // var is not a constant
    const double sqv = sqrt(var); // sqv is a named constant, possibly computed at run time

    vector<double> v {1.2, 3.4, 4.5}; // v is not a constant
    const double s1 = sum(v); // OK: sum(v) is evaluated at run time
    //constexpr double s2 = sum(v); // error : sum(v) is not a constant expression

    cout << s1 << "\n";

    constexpr double max1 = 1.4*square2(17); // OK 1.4*square(17) is a constant expression
//constexpr double max2 = 1.4*square2(var); // error : var is not a constant expression
    const double max3 = 1.4*square2(var); //OK, may be evaluated at run time

    constexpr double nth1 = nth(2, 4);
    cout << nth1 << "\n";

    print2();

    double* pd = nullptr;
    //Link<Record>* lst = nullptr; // pointer to a Link to a Record

    accept2();
}



