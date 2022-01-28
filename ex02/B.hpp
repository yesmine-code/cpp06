#ifndef B_HPP
# define B_HPP
# include <iostream>
# include "Base.hpp"

class B: public Base{
public:

	B();
	B(const B &src);
	~B();
	B	&operator=(const B &src);

private:

};

std::ostream	&operator<<( std::ostream &os, const B &instance );

#endif