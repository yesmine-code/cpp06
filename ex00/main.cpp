#include "convert.hpp"

int main(int ac, char** av){

	try{
		if (ac != 2)
			throw (convert::WrongArgNum());
		convert convert;
		convert.printResult(av[1]);
		
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}



