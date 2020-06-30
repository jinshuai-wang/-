#include <iostream>
using namespace std;

typedef enum{
	BENZCAR,
	BMWCAR
}CarType;


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
		~Factory()
		{
			cout<<"Factory destructor"<<endl;
		}
		Car* createSpecialCar(CarType type)
		{
			switch(type)
			{
				case BENZCAR:
				{
					return new BenzCar();
					break;
				}
				case BMWCAR:
				{
					return new BMWCar();
					break;
				}
			}
		}
};


int main()
{
	Factory *factory = new Factory();
	Car *benzCar = factory->createSpecialCar(BENZCAR);
	Car *bmwCar = factory->createSpecialCar(BMWCAR);
	delete benzCar;
	delete bmwCar;
	delete factory;
}

