#include <iostream>
using namespace std;

class Singleton{
private:
		Singleton(){
			cout<<"Singleton constructor"<<endl;
			count++;
		}
		static Singleton *instance;
		static int count;
public:
		virtual ~Singleton(){
			cout<<"Singleton destructor"<<endl;
		}
		
		//getInstance 是静态函数，否则需要对象去调用
		static Singleton *getInstance()
		{
			if(instance == nullptr)
			{
				instance = new Singleton();
			}
			
			return instance;
		}
		void print()
		{
			cout<<"count = "<<count<<endl;
		}
};

//静态变量的初始化在类外，并且不在需要static修饰
Singleton* Singleton::instance = nullptr;
int Singleton::count = 0;

int main()
{
	Singleton *instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();
	instance1->print();
	instance2->print();
}
