/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:52 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/19 21:40:47 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string& literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
        return CHAR_TYPE;
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return FLOAT_TYPE;
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return DOUBLE_TYPE;
    if (literal.find('.') != std::string::npos)
    {
        if (literal.back() == 'f' || literal.back() == 'F')
            return FLOAT_TYPE;
        else
            return DOUBLE_TYPE;
    }
    std::stringstream ss(literal);
    int temp;
    if (ss >> temp && ss.eof())
        return INT_TYPE;
    return INVALID_TYPE;
}

bool ScalarConverter::isCharDisplayable(int c)
{
    return (c >= 32 && c <= 126);
}

void ScalarConverter::convertFromChar(char c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void ScalarConverter::convertFromInt(int value)
{
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!isCharDisplayable(value))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
}

void ScalarConverter::convertFromFloat(float value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isCharDisplayable(static_cast<int>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
    
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
    
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    }

    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(value)) {
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
    }
}

void ScalarConverter::convertFromDouble(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!isCharDisplayable(static_cast<int>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    if (std::isnan(value))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
    
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
