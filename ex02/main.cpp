#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base	*generate( void ){
	int	ran = rand() % 3;
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();

	switch (ran)
	{
	case 0:
		delete(b);
		delete(c);
		return a;
	case 1:
		delete(a);
		delete(c);
		return b;
	case 2:
		delete(a);
		delete(b);
		return c;
	default:
		delete(a);
		delete(b);
		delete(c);
		throw new std::exception();
	}
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}

void	identify(Base *p)
{
	A *a;
	if ((a = dynamic_cast<A*>(p)))
		std::cout << "A" << std::endl;
	B *b;
	if ((b = dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	C *c;
	if ((c = dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}

int		main( void )
{
	Base	*base;
	Base 	*a = new A;
	
	std::cout << "sure tests :" << std::endl;
	identify(a);
	identify(*a);
	delete(a);

	std::cout << "Identify with pointer :" << std::endl;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << std::endl << "Identify with reference:" << std::endl
		<< std::endl;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;
}