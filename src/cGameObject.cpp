#include <iostream>
#include "cGameObject.hpp"

CGameObject::CGameObject(void)
{
	std::cout << "CGameobject Constructor" << std::endl;
}

CGameObject::~CGameObject(void)
{
	std::cout << "CGameobject Destructor" << std::endl;
}

bool		CGameObject::AddComponent(const EComponentTypes &type)
{
	std::cout << type << std::endl;
	return (true);
}

bool 		CGameObject::RemoveComponent(const EComponentTypes &type)
{
	std::cout << type << std::endl;
	return (true);
}

bool 		CGameObject::HasComponent(const EComponentTypes &type)
{
	std::cout << type << std::endl;
	return (true);
}

// CComponent 	&CGameObject::GetComponent(void)
// {
// 	return (true);
// }
