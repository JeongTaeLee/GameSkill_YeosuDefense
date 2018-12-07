#pragma once

template <class T>
class singleton
{
private:
	static T * t;
public:
	static T & GetInst()
	{
		if (!t)
			t = new T;
		return *t;
	}
	static void ReleaseInst()
	{
		SAFE_DELETE(t);
	}
};


template<class T>
T * singleton<T>::t = nullptr;