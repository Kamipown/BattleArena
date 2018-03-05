#include "cComponent.hpp"

class CGameObject
{
private:

protected:

public:
	CGameObject(void);
	~CGameObject(void);

	bool AddComponent(const EComponentTypes &type);
	bool RemoveComponent(const EComponentTypes &type);
	bool HasComponent(const EComponentTypes &type);
	// CComponent &GetComponent(void);
};
