#include <iostream>
using namespace std;

class Car{
public:
	Car(){
		cout<<"Car createing"<<endl;
	}
	virtual ~Car(){
		cout<<"Car destroy"<<endl;
	}
	virtual void CreateCar() = 0;
};

class BenzCar:public Car{
public:
	BenzCar(){
		cout<<"Benz Car Constructor"<<endl;
	}
	virtual ~BenzCar(){
		cout<<"Benz Car Destructor"<<endl;
	}
	virtual void CreateCar(){
		cout<<"Benz Car Create"<<endl;
	}
};

class BMWCar:public Car{
public:
	BMWCar(){
		cout<<"BMW Car Constructor"<<endl;
	}
	virtual ~BMWCar(){
		cout<<"BMW Car Destructor"<<endl;
	}
	virtual void CreateCar(){
		cout<<"BMWCar Car Create"<<endl;
	}
};

class Factory{
public:
		Factory()
		{
			cout<<"Factory constructor"<<endl;
		}
		virtual ~Factory()
		{
			cout<<"Factory destructor"<<endl;
		}
		virtual Car* createSpecialCar() = 0;	
};

class BenzFactory:public Factory{
public:
	BenzFactory(){
		cout<<"BenzFactory constructor"<<endl;
	}
	~BenzFactory(){
		cout<<"BenzFactory destructor"<<endl;
	}
	virtual Car* createSpecialCar()
	{
		return new BenzCar();
	}
};

class BMWFactory:public Factory{
public:
	BMWFactory(){
		cout<<"BMWFactory constructor"<<endl;
	}
	~BMWFactory(){
		cout<<"BMWFactory destructor"<<endl;
	}
	virtual Car* createSpecialCar()
	{
		return new BMWCar();
	}
};


int main()
{
	Factory *benzfactory = new BenzFactory();
	Factory *bmwfactory = new BMWFactory();
	
	Car *bencar = benzfactory->createSpecialCar();
	Car *bmwcar = bmwfactory->createSpecialCar();
	
	delete bencar;
	delete bmwcar;
	delete benzfactory;
	delete bmwfactory;
}

