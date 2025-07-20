/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:16:06 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/20 15:31:39 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Serializer.hpp"

int main()
{
    Data info;
    info.value = 42;
    info.name = "heilbronn";
    std::cout << "Original Data:" << std::endl;
    std::cout << "Address: " << &info << std::endl;
    std::cout << "Value: " << info.value << std::endl;
    std::cout << "Name: " << info.name << std::endl << std::endl;

    uintptr_t serialized = Serializer::serialize(&info);
    std::cout << "Serialized: 0x" << std::hex << serialized << std::dec << std::endl << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "Value: " << deserialized->value << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl << std::endl;

    if (deserialized == &info)
        std::cout << "✓ Success: Pointers match!" << std::endl;
    else
        std::cout << "✗ Error: Pointers don't match!" << std::endl;

    return 0;
}
