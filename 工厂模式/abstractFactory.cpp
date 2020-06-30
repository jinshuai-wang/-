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

class HighCar{
public:
	HighCar(){
		cout<<"HighCar createing"<<endl;
	}
	virtual ~HighCar(){
		cout<<"HighCar destroy"<<endl;
	}
	virtual void CreateCar() = 0;
};

class HighBenzCar:public HighCar{
public:
	HighBenzCar(){
		cout<<"HighBenzCar Car Constructor"<<endl;
	}
	virtual ~HighBenzCar(){
		cout<<"HighBenzCar Car Destructor"<<endl;
	}
	virtual void CreateCar(){
		cout<<"High Benz Car Create"<<endl;
	}
};

class HighBMWCar:public HighCar{
public:
	HighBMWCar(){
		cout<<"High BMW Car Constructor"<<endl;
	}
	virtual ~HighBMWCar(){
		cout<<"High BMW Car Destructor"<<endl;
	}
	virtual void CreateCar(){
		cout<<"HighBMWCar Car Create"<<endl;
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
		virtual HighCar* createSpecialHighCar() = 0;
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
	virtual HighCar* createSpecialHighCar()
	{
		return new HighBenzCar();
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
	virtual HighCar* createSpecialHighCar()
	{
		return new HighBMWCar();
	}
};


int main()
{
	Factory *benzfactory = new BenzFactory();
	Factory *bmwfactory = new BMWFactory();
	
	Car *bencar = benzfactory->createSpecialCar();
	Car *bmwcar = bmwfactory->createSpecialCar();
	
	HighCar *highbencar = benzfactory->createSpecialHighCar();
	HighCar *highbmwcar = bmwfactory->createSpecialHighCar();
	
	delete bencar;
	delete bmwcar;
	delete highbencar;
	delete highbmwcar;
	delete benzfactory;
	delete bmwfactory;
}

