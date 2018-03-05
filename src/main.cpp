#include "cEngine.hpp"
#include "cGameObject.hpp"

int		main(void)
{
	CEngine *engine = new CEngine();
	CGameObject *gameObject = new CGameObject();

	gameObject->AddComponent(Transform);
	delete (gameObject);
	delete (engine);
	return (0);
}
