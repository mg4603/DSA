#include <assert.h>
#include <iostream>

#include <sstream>
#include <ostream>

class X {
	int m_a;
	int m_b;
public:
	X(){
        m_a = 1;
        m_b = 2;
    }
    X(int a)
    {
        m_a = a;
        m_b = 2;
    }
    X(int a, int b)
    {
        m_a = a;
        m_b = b;
    }
    X(X *other)
    {
        m_a = other->m_a;
        m_b = other->m_b;
    }

	std::string print(); // used for testing
    void operator=(const X &other);
    void operator+=(const X &other);
    X operator+(const X &other);
    X operator ++();
    X operator ++(int);
    friend std::ostream& operator << (std::ostream &out, const X &other);
};

std::ostream& operator<<(std::ostream &out, const X &other)
{
    out << '[' << other.m_a << ',' << other.m_b << ']';
    return out;
}

X X::operator+(const X &other)
{
    X res{this};
    res.m_a += other.m_a;
    res.m_b += other.m_b;
    return res;
}

void X::operator=(const X &other)
{
    m_a = other.m_a;
    m_b = other.m_b;
}

void X::operator+=(const X &other)
{
    m_a += other.m_a;
    m_b += other.m_b;
}

X X::operator++()
{
    ++m_a;
    ++m_b;
    return this;
}

X X::operator++(int)
{
    X res{this};
    m_a++;
    m_b++;
    return res;
}

std::string X::print()
{
		std::stringstream s;
		s << "[" << m_a << "," << m_b << "]";
		return s.str();
}



void log(std::string str)
{
    std::cout << str << std::endl;
}

/*  Expected:
 *  Use cases of the class that are expected to be working.
*/
/*
  { X{}                   } // see the logs, find out what happens with m_a and m_b
	{ X{1,2};				    	  }
  { X{1};				       	  } // see the logs, find out what happens with m_b
	{ X x{}, y{x};			  	} 
	{ X x{}, y = x;				  } // as expected
	{ X x{}, y{}; y += x;		}
	{ X x{}; ++x;				    }  // ++m_a, ++m_b
	{ X x{}; x++;				    }  // m_a++, m_b++
	{ X x{}, y{}; x + y;		}  // as expected
	{ cout << X{1,2};				}  // shows "[1,2]"
*/


void test_constructors1()
{
    X x{};
    log("X x{};");
    assert(x.print() == ("[1,2]"));
}

void test_constructors2()
{
    X x{3,4};
    log("X x{3,4};");
    assert(x.print() == ("[3,4]"));
}

void test_constructors3()
{
    X x{3};
    log("X x{3};");
    assert(x.print() == ("[3,2]"));
}

void test_copy_constructor()
{ 
    {
        X x{}, y{x};
        log("X x{}, y{x};");
        assert(y.print() == ("[1,2]"));
    }
    {
        X y{X{22,33}};
        log("X y{X(22,33)};");
        assert(y.print() == ("[22,33]"));
    }
}
void basic_assigment() 
{
{
    X x{}, y{}; y = x;
    log("X x{}, y{}; y = x;");
    assert(y.print() == ("[1,2]"));
}
}
void test_addition_assignment() 
{
    { 
        X x{}, y{}; y += x;	
        log("X x{}, y{}; y += x;");
        assert(y.print() == ("[2,4]"));
    }
}
void increment_prefix_postfix()
{
    { 
        X x{}; ++x;
        log("X x{}; ++x;");
        assert(x.print() == ("[2,3]"));
    }

    { 
        X x{2}; ++x;
        log("X x{2}; ++x;");
        assert(x.print() == ("[3,3]"));
    }

    { 
        X x{2,3}, y = x++;
        log(x.print());
        log("X x{2,3}, y = x++;");
        assert(y.print() == ("[2,3]"));
        assert(x.print() == ("[3,4]"));
    }
    
}

int main()
{
    test_constructors1();
    test_constructors2();
    test_constructors3();
    test_copy_constructor();
    basic_assigment();
    test_addition_assignment();
    increment_prefix_postfix();
}