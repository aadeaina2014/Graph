

#include <iostream>

using namespace std;
class Outer
{
	class Inner
	{
	public:
		Inner(Outer& x) : parent(x) {}
		void func()
		{
			std::string a = "myconst1";
			std::cout << parent.var << std::endl;

			if (a == MYCONST)
			{
				std::cout << "string same" << std::endl;
			}
			else
			{
				std::cout << "string not same" << std::endl;
			}
		}
	private:
		Outer&  parent;
	};

public:
	Outer()
		:i(*this)
		, var(4)
	{}
	Outer(Outer& other)
		:i(other)
		, var(22)
	{}
	void func()
	{
		i.func();
	}
private:
	static const char* const MYCONST;
	Inner i;
	int var;
};


int main(void)
{

}