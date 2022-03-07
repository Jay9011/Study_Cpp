#pragma once
template<typename T>
class ClassTemplate
{
public:
	ClassTemplate();
	~ClassTemplate();

private:
	T* pTemplateMember;

public:
	void function(const T& data);
};
/*
*	클래스 템플릿을 지정하면,
*	main쪽에서 클래스 템플릿을 호출할 때, class가 선언되어 있는 헤더 파일의 치환문자를 변경시킨다.
*	하지만, cpp 파일에 있는 구현부분은 처음 선언부분을 생성할 때 호출되지 않기 때문에 치환문자가 변경되지 않은 상태로 남아있게 된다.
* 
*	따라서! 클래스 템플릿을 구현을 하기 위해서는 class 선언부분이 존재하는 헤더에서 한 번에 구현해야 한다.
* 
*/
template<typename T>
inline ClassTemplate<T>::ClassTemplate()
{
	// 클래스 템플릿 생성자
	// 클래스 명명부분을 템플릿 치환문자를 포함한 ClassTemplate<T>로 알려줘야 한다.
}

template<typename T>
inline ClassTemplate<T>::~ClassTemplate()
{
}

template<typename T>
inline void ClassTemplate<T>::function(const T& data)
{
}