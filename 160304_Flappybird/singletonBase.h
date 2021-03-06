#pragma once

template<typename T>
class singletonBase
{
protected:
	//싱글톤 인스턴스 선언
	static T * singleton;

	
	singletonBase() {}
	~singletonBase() {}
public:
	static T* getSingleton(void);
	void releaseSingleton(void);
};

//싱글톤 초기화
template<typename T>
T* singletonBase<T>::singleton = NULL;

//싱글톤 값 가져온다
template<typename T>
T* singletonBase<T>::getSingleton()
{
	if (!singleton) singleton = new T;	//NULL이면 
	return singleton;					
}

//싱글톤 메모리 해제
template<typename T>
void singletonBase<T>::releaseSingleton()
{
	if (singleton)				//NULL 아니라면 메모리 해지해주고 널포인터 가리켜라
	{
		delete singleton;
		singleton = NULL;
	}
}