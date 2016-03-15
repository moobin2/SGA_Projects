#include "stdafx.h"
#include "keyManager.h"


keyManager::keyManager()
{
}


keyManager::~keyManager()
{
}


HRESULT keyManager::init()
{
	for (int i = 0; i < KEYMAX; i++)
	{
		this->_keyDown.set(i, false);			//���� 0 ���� �ʱ�ȭ
		this->_keyUp.set(i, false);
	}

	return S_OK;								
	//return E_FAIL;
}

void keyManager::release()
{

}

bool keyManager::isOnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)		// Ű�� ���Ȱ� & ó�� ���� ��Ȳ
	{
		if (!this->_keyDown[key])			// false �̸� (�ȴ����� ������)
		{
			this->_keyDown.set(key, true);	// �װ��� true �ٲٰ� 
			return true;					// �������� true�� �����Ѵ�.
		}
	}
	else this->_keyDown.set(key, false);	// �������� Ű(true)���ٸ� 
											// �� ���� false�� �ٲ��ְ�

	return false;							// false �����Ѵ�.
}

bool keyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)		// Ű�� ���Ȱ� & ó�� ���� ��Ȳ 
	{
		this->_keyUp.set(key, true);		// true
	}
	else
	{
		if (this->_keyUp[key])
		{
			this->_keyUp.set(key, false);
			return true;
		}
	}

	return false;
}

bool keyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;
	else return false;
}

bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;
	else return false;
}
