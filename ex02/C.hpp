#ifndef C_HPP
# define C_HPP
# include <iostream>
# include "Base.hpp"

class C: public Base{
public:

	C();
	C(const C &src);
	~C();
	C	&operator=(const C &src);

private:

};

std::ostream	&operator<<( std::ostream &os, const C &instance );

#endif