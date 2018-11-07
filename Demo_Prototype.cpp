/*
	Name: Demo_Prototype.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn  aka eddydn@gmail.com
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Builder
*/
#include <iostream>
#include <string>

using namespace std;

class Animal
{
			protected:
				string type;
				int age;
				
			public:
				virtual Animal* clone() = 0;
				
				string getType()
				{
					return type;
				}
				
				int getAge()
				{
					return age;
				}
};

class Bird:public Animal{
	public:
		Bird(int num)
		{
			type = "Bird";
			age = num;
		}
		
	 	Animal* clone()
	 	{
	 		return new Bird(*this);
		 }
};

class Dog:public Animal{
	public:
		Dog(int num)
		{
			type = "Dog";
			age = num;
		}
		
	 	Animal* clone()
	 	{
	 		return new Dog(*this);
		 }
};

class ObjectFactory
{
		static Animal* dog;
		static Animal* bird;
		
		public:
			static void init()
			{
				dog = new Dog(10);
				bird = new Bird(5);
				}	
				
				static Animal* getDog()
				{
					return dog->clone();
				}
				
				static Animal* getBird()
				{
					return bird->clone();
				}
};

Animal* ObjectFactory::dog = 0;
Animal* ObjectFactory::bird = 0;

int main()
{
	ObjectFactory::init();
	Animal* object;
	
	//All object were created by cloning the prototype
	object = ObjectFactory::getDog();
	cout<<"This is "<<object->getType()<<" with age: "<<object->getAge()<<endl;
	
	cout<<endl<<endl<<endl;
		object = ObjectFactory::getBird();
	cout<<"This is "<<object->getType()<<" with age: "<<object->getAge()<<endl;
	
	
	return 1;
}
