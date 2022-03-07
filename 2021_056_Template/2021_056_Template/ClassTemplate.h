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
*	Ŭ���� ���ø��� �����ϸ�,
*	main�ʿ��� Ŭ���� ���ø��� ȣ���� ��, class�� ����Ǿ� �ִ� ��� ������ ġȯ���ڸ� �����Ų��.
*	������, cpp ���Ͽ� �ִ� �����κ��� ó�� ����κ��� ������ �� ȣ����� �ʱ� ������ ġȯ���ڰ� ������� ���� ���·� �����ְ� �ȴ�.
* 
*	����! Ŭ���� ���ø��� ������ �ϱ� ���ؼ��� class ����κ��� �����ϴ� ������� �� ���� �����ؾ� �Ѵ�.
* 
*/
template<typename T>
inline ClassTemplate<T>::ClassTemplate()
{
	// Ŭ���� ���ø� ������
	// Ŭ���� ���κ��� ���ø� ġȯ���ڸ� ������ ClassTemplate<T>�� �˷���� �Ѵ�.
}

template<typename T>
inline ClassTemplate<T>::~ClassTemplate()
{
}

template<typename T>
inline void ClassTemplate<T>::function(const T& data)
{
}