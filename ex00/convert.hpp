#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <stdexcept>
# include <limits>
# include <cmath>

class convert
{
private:
	static const int noType = -1;
	static const int charType = 0;
	static const int intType = 1;
	static const int floatType = 2;
	static const int doubleType = 3;
	int		type;
	char	toChar;
	int		toInt;
	float	toFloat;
	double	toDouble;
	bool ft_isdigit(char c);
	bool isAChar(double number);
	const char	*printZero(double number);
	bool	canConvertToFloat(double number);
	bool	canConvertToInt(double number);
	void	fillAttribute(char *input);
	bool 	canConvertToChar(char *input);
	int		ifSpecialCase(char *input);
	bool 	findType(char *input);
	int		CaseOfNum(char *input);
	void	printChar();
	void	printDouble();
	void	printInt();
	void	printFloat();
	void	inputCheker(char *input);
	void	fillWith0();


public:
	convert();
	~convert();
	convert(char *input);
	convert(const convert &src);
	convert	&operator=(const convert &src);
	void	printResult(char *input);

public:

	class WrongArgNum: public std::exception{
	public:
		virtual const char* what() const throw(){
			return "wrong number of arguments !";
		}
	};

	class CannotAnalyse: public std::exception{
	public:
		virtual const char* what() const throw(){
			return "invalid input";
		}
	};
};


#endif