#include <iostream>
#include <mutex>
using namespace std;

class Singleton{
private:
		Singleton(){
			cout<<"Singleton constructor"<<endl;
			count++;
		}
		Singleton(const Singleton&) = delete;
		Singleton &operator=(const Singleton&) = delete;
		static Singleton *instance;
		static int count;
		static mutex mut;
public:
		virtual ~Singleton(){
			cout<<"Singleton destructor"<<endl;
		}
		
		//getInstance 是静态函数，否则需要对象去调用
		static Singleton *getInstance()
		{
			mut.lock();
			if(instance == nullptr)
			{
				instance = new Singleton();
			}
			mut.unlock();
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
mutex Singleton::mut;

int main()
{
	Singleton *instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();
	instance1->print();
	instance2->print();
}
