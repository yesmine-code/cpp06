#ifndef A_HPP
# define A_HPP
# include <iostream>
# include "Base.hpp"

class A: public Base{
public:

	A();
	A(const A &src);
	~A();
	A	&operator=(const A &src);

private:

};

std::ostream	&operator<<( std::ostream &os, const A &instance );

#endif