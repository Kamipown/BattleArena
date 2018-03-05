#include <iostream>
#include "cComponent.hpp"

CComponent::CComponent(void)
{
	std::cout << "CComponent Constructor" << std::endl;
}

CComponent::~CComponent(void)
{
	std::cout << "CComponent Destructor" << std::endl;
}
