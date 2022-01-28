#include "convert.hpp"

convert::convert(){
	fillWith0();
}
convert::~convert(){
}
convert::convert(char *input){
	inputCheker(input);
}
convert::convert(const convert &src){
	*this = src;
	return;
}
convert	&convert::operator=(const convert &src){
	this->type = src.type;
	this->toInt = src.toInt;
	this->toFloat = src.toFloat;
	this->toDouble = src.toDouble;
	this->toChar = src.toChar;
	return *this;
}
void	convert::fillAttribute(char *input)
{
	if (type == charType)
		this->toChar = input[0];
	else if (type == intType)
		this->toInt = atoi(input);
	else if (type == floatType)
		this->toFloat = atof(input);
	else if (type == doubleType)
		this->toDouble = atof(input);
}
void	convert::inputCheker(char *input){
	fillWith0();
	if (!this->findType(input))
		throw convert::CannotAnalyse();
	fillAttribute(input);
}

void	convert::fillWith0(){
	this->type = noType;
	this->toInt = 0;
	this->toDouble = 0;
	this->toFloat = 0;
	this->toChar = 0;
}

bool convert::findType(char *input){

	this->type = ifSpecialCase(input);
	if (this->type != convert::noType)
		return true;
	if ((input[0] >= '0' && input[0] <= '9') || input[0] == '-' || input[0] == '.'){
		this->type = CaseOfNum(input);
		if (this->type != convert::noType)
			return true;
	}
	if (input[1])
		return false;
	this->type = convert::charType;
	return true;
}

int		convert::ifSpecialCase(char *input){

	if ("inf" == std::string (input) || "+inf" == std::string (input) || "-inf" == std::string (input) || "nan" == std::string (input))
		return doubleType;
	else if ("inff" == std::string (input) || "+inff" == std::string (input) || "-inff" == std::string (input) || "nanf" == std::string (input))
		return floatType;
	return noType;
}

int		convert::CaseOfNum(char *input){
	int	i = 0;
	int	j = 0;

	if (input[0] == '-' && input[1])
		i++;
	if (input[i] == '.' && (input[i + 1] == 'f' || input[i + 1] == 0))
		return noType;
	while (input[i] == '.' || ft_isdigit(input[i]))
	{
		if (input[i] == '.')
			j++;
		if (j > 1)
			return noType;
		i++;
	}
	if (input[i] == '\0'){
		if (j == 1)
			return doubleType;
		return intType;
	}
	else if (input[i] == 'f' && !input[i + 1] && j == 1)
		return floatType;
	return noType;
}

bool convert::ft_isdigit(char c){
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

bool	convert::isAChar(double number)
{
	if (number - static_cast<int>(number) != 0 || number > 127 || number < 0){
		std::cout << "char: impossible" << std::endl;
		return false;
	}
	else if (number <= 31 || number == 127){
		std::cout << "char: Non displayable" << std::endl;
		return false;
	}
	return true;
}

void	convert::printChar(){
	if (type == intType){ 
		if (isAChar(toInt))
			std::cout << "char: " << static_cast<char>(toInt)<< std::endl;}
	else if (type == convert::floatType){
	 if (isAChar(toFloat)) 
			std::cout << "char: " << static_cast<char>(toFloat)<< std::endl;}
	else if (type == convert::doubleType){
		if(isAChar(toDouble))
			std::cout << "char: " << static_cast<char>(toDouble)<< std::endl;}
	else
		std::cout << "char: " << static_cast<char>(toChar)<< std::endl;

}

void	convert::printInt()
{
	if (type == charType)
		std::cout << "int: " << static_cast<int>(toChar)<< std::endl;
	else if (type == intType)
		std::cout << "int: " << toInt << std::endl;
	else if (type == floatType){
		if (canConvertToInt(toFloat))
			std::cout << "int: " << static_cast<int>(this->toFloat)<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
	else if (type == doubleType){
		if (canConvertToInt(toDouble))
			std::cout << "int: " << static_cast<int>(toDouble)<< std::endl;
		else
			std::cout << "int: impossible" << std::endl;
	}
}

void	convert::printFloat()
{
	if (type == charType)
		std::cout << "float: " << static_cast<float>(toChar) << ".0f"<< std::endl;
	else if (type == intType)
		std::cout << "float: " << static_cast<float>(toInt) << ".0f"<< std::endl;
	else if (type == floatType)
		std::cout << "float: " << toFloat<< printZero(static_cast<float>(toFloat)) << "f"<< std::endl;
	else if (type == doubleType){
		if (canConvertToFloat(toDouble))
			std::cout << "float: " << static_cast<float>(toDouble)<< printZero(static_cast<float>(toDouble)) << "f"<< std::endl;
		else
			std::cout << "float: impossible" << std::endl;
	}
}

void	convert::printDouble()
{
	if (type == charType)
		std::cout << "double: " << static_cast<double>(toChar) << ".0" << std::endl;
	else if (type == intType)
		std::cout << "double: " << static_cast<double>(toInt) << ".0" << std::endl;
	else if (type == floatType)
		std::cout << "double: " << static_cast<double>(toFloat)<< printZero(static_cast<double>(toFloat))<< std::endl;
	else if (type == doubleType)
		std::cout << "double: " << toDouble << printZero(static_cast<double>(toDouble))<< std::endl;
}

bool	convert::canConvertToInt(double number){
	if(number <= std::numeric_limits<int>::max() && number >= std::numeric_limits<int>::min())
		return true;
	return false;
}

bool	convert::canConvertToFloat(double number){
	if((number <= std::numeric_limits<float>::max() && number >= std::numeric_limits<float>::min())
		|| number == std::numeric_limits<double>::infinity() || number == -std::numeric_limits<double>::infinity() || std::isnan(number))
		return true;
	return false;
}

const char	*convert::printZero( double number ){
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}

void	convert::printResult(char *input)
{
	inputCheker(input);
	if (type == noType)
		std::cout << "No type set" << std::endl;
	printChar();
	printInt();
	printFloat();
	printDouble();
}