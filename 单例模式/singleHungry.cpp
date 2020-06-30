#include <iostream>
using namespace std;

class Singleton{
private:
		Singleton(){
			cout<<"Singleton constructor"<<endl;
			count++;
		}
		
		class ReleaseSingle{
		public:
			ReleaseSingle(){
				cout<<"ReleaseSingle constructor"<<endl;
			}
			virtual ~ReleaseSingle(){
				cout<<"ReleaseSingle destructor"<<endl;
				delete Singleton::instance;
			}
		};
		
		
		Singleton &operator=(const Singleton&)=delete;//不允许赋值
		Singleton(const Singleton&)=delete;//不允许复制
		static Singleton *instance;
		
		static int count;
public:
		virtual ~Singleton(){
			cout<<"Singleton destructor"<<endl;
		}
		
		//getInstance 是静态函数，否则需要对象去调用
		static Singleton *getInstance()
		{
			static ReleaseSingle releaseInstance;
			return instance;
		}
		void print()
		{
			cout<<"count = "<<count<<endl;
		}
};

//静态变量的初始化在类外，并且不在需要static修饰
Singleton* Singleton::instance = new Singleton();
int Singleton::count = 0;

int main()
{
	Singleton *instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();
	instance1->print();
	instance2->print();
}
