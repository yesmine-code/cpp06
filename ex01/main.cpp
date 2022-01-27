#include <iostream>
#include <stdint.h>
#include <string>

typedef struct	s_Data{
	std::string data;
}				Data;

uintptr_t	serialize(Data *ptr){    //	Unsigned integer of size equal to a pointer so we can convert obj = obj pointer = scalartype ...
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int	main( void )
{
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t	lol;

	ptr->data = "cpp06";
	lol = serialize(ptr);
	std::cout << "new_ptr->data = " << lol << std::endl;
	new_ptr = deserialize(lol);
	std::cout << "new_ptr->data = " << new_ptr->data << std::endl;
	delete(ptr);
}