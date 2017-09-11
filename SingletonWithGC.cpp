#include "Singleton.h"
#include <iostream>

//Singleton* Singleton::pSingletonT = new(std::nothrow) Singleton();
Singleton* Singleton::pSingletonT;
Singleton::GC Singleton::gc;

Singleton::Singleton(void)
{
	//std::cout<<"Singleton construct"<<std::endl;
};

Singleton::~Singleton(void)
{
	//std::cout<<"Singleton destruct"<<std::endl;
};

Singleton* Singleton::getInitance(void)
{
	return Singleton::pSingletonT;
};

Singleton::GC::GC()
{
	//std::cout<<"GC construct"<<std::endl;

	Singleton::pSingletonT = NULL;
	for(int i=0;i<10&&pSingletonT == NULL;++i)
	{
		Singleton::pSingletonT = new(std::nothrow) Singleton();
	}
	/*if(pSingletonT != NULL)
	{
		std::cout<<"Singleton new successed"<<std::endl;
	}*/
	
};

Singleton::GC::~GC()
{
	//std::cout<<"GC destruct"<<std::endl;
	// We can destory all the resouce here, eg:db connector, file handle and so on
	if (pSingletonT != NULL )
	{
		delete Singleton::pSingletonT;
		Singleton::pSingletonT = NULL;
		//std::cout<<"Singleton delete"<<std::endl;
	}
	
};
