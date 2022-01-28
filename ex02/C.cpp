#include "C.hpp"
C::C(){
}

C::C(C const & src){
	*this = src;
	return;
}

C::~C(){
}

C &	C::operator=(C const & src){
	(void)src;
	return *this;
}

std::ostream &	operator<<(std::ostream & os, C const & instance){
	(void)instance;
	os << "C" << std::endl;
	return os;
}