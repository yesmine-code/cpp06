#include "A.hpp"
A::A(){
}

A::A(A const & src){
	*this = src;
	return;
}

A::~A(){
}

A &	A::operator=(A const & rhs){
	(void)rhs;
	return *this;
}

std::ostream &	operator<<( std::ostream & os, A const & instance){
	(void)instance;
	os << "A" << std::endl;
	return os;
}