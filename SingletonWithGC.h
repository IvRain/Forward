class Singleton
{
protected:
    Singleton();

private:
	static Singleton* pSingletonT;

public:
    static Singleton* getInitance(void);
	virtual ~Singleton(void);
	
private:
	class GC
	{
	public :
		GC(void);
		virtual ~GC(void);
	};
	static GC gc;

};
