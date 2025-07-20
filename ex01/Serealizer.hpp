/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serealizer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:24:01 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/20 15:08:44 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include <string>
# include <iostream>

struct Data
{
    int value;
    std::string name;
    double price;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer&) = delete;
        Serializer& operator=(const Serializer&) = delete;
    public:
        static unitptr_t serialize(Data* ptr);
        static Data* deserialize(unitptr_t raw);
};

#endif