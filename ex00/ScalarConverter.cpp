/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:52 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/15 13:22:10 by hali-mah         ###   ########.fr       */
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