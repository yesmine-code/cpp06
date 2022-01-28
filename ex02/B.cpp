#include "B.hpp"

B::B(){
}

B::B(B const & src){
	*this = src;
	return;
}

B::~B(){
}

B &	B::operator=(B const &src){
	(void)src;
	return *this;
}

std::ostream &	operator<<(std::ostream & os, B const & instance){
	(void)instance;
	os << "B" << std::endl;
	return os;
}