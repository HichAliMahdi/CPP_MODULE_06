/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hali-mah <hali-mah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:55:57 by hali-mah          #+#    #+#             */
/*   Updated: 2025/07/20 16:03:06 by hali-mah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base* generate(void)
{
    srand(time(NULL));
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return new A();
    }
}

void identify(Base* p)
{
    A* a = dynamic_cast<A*>(p);
    if (a != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
    
    B* b = dynamic_cast<B*>(p);
    if (b != NULL) {
        std::cout << "B" << std::endl;
        return;
    }
    
    C* c = dynamic_cast<C*>(p);
    if (c != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (...) {}
    
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}
    
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}
}

int main()
{
    std::cout << "=== Testing dynamic_cast with pointers and references ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\nTest " << (i + 1) << ":" << std::endl;
        Base* obj = generate();
        std::cout << "Identify by pointer: ";
        identify(obj);
        std::cout << "Identify by reference: ";
        identify(*obj);
        delete obj;
        std::cout << std::endl;
    }
    
    std::cout << "=== Testing specific object types ===" << std::endl;
    
    // Test each class specifically
    Base* a = new A();
    Base* b = new B();
    Base* c = new C();
    
    std::cout << "\nTesting A object:" << std::endl;
    std::cout << "Pointer: "; identify(a);
    std::cout << "Reference: "; identify(*a);
    
    std::cout << "\nTesting B object:" << std::endl;
    std::cout << "Pointer: "; identify(b);
    std::cout << "Reference: "; identify(*b);
    
    std::cout << "\nTesting C object:" << std::endl;
    std::cout << "Pointer: "; identify(c);
    std::cout << "Reference: "; identify(*c);
    
    std::cout << "\nCleaning up..." << std::endl;
    delete a;
    delete b;
    delete c;
    
    return 0;
}
