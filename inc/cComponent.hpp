enum EComponentTypes
{
	Transform,
	Collider
};

class CComponent
{
private:
	EComponentTypes type;
protected:

public:
	CComponent(void);
	~CComponent(void);
};

// class CTransform: CComponent
// {
// private:
// 	float x;
// 	float y;
// 	float rotation;
// };
