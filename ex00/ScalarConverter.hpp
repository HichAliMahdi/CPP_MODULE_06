/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:32:16 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/19 21:12:29 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        enum LiteralType 
        {
          CHAR_TYPE,
          INT_TYPE,
          FLOAT_TYPE,
          DOUBLE_TYPE,
          INVALID_TYPE
        };
        static LiteralType detectType(const std::string& literal);
        static void convertFromChar(char c);
        static void convertFromInt(int value);
        static void convertFromFloat(float value);
        static void convertFromDouble(double value);
        static bool isCharDisplayable(int c);
    
    public:
        static void convert(std::string& value);
};

#endif