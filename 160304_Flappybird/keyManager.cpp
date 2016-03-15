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
		this->_keyDown.set(i, false);			//전부 0 으로 초기화
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
	if (GetAsyncKeyState(key) & 0x8000)		// 키가 눌렸고 & 처음 눌린 상황
	{
		if (!this->_keyDown[key])			// false 이면 (안눌려져 있으면)
		{
			this->_keyDown.set(key, true);	// 그값을 true 바꾸고 
			return true;					// 눌렸으니 true를 리턴한다.
		}
	}
	else this->_keyDown.set(key, false);	// 눌려졌던 키(true)였다면 
											// 그 값을 false로 바꿔주고

	return false;							// false 리턴한다.
}

bool keyManager::isOnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)		// 키가 눌렸고 & 처음 눌린 상황 
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
