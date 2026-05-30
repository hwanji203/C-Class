#include "Defines.h"
class Single
{
private:
	Single() = default;
public:
	static Single* GetInst()
	{
		if (m_pInst == nullptr)
			m_pInst = new Single;
		return m_pInst;
	}
	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	static Single* m_pInst;
};
Single* Single::m_pInst = nullptr;