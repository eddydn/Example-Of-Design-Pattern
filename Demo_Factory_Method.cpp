
/*
	Name: Demo_Factory_Method.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn aka eddydn@gmail.com
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Builder
*/

#include <iostream>
#include <string>

using namespace std;

class Pencil{
	public:
		Pencil():color(""){
		}
		string color;
		
		static Pencil* getPencil(string color);
		
		void showInformation()
		{
			cout<<"This is "<<color<<" pencil";
		}
};

class BluePencil: public Pencil{
	public:
		BluePencil(){
			color = "blue";
		}
		
};

class RedPencil: public Pencil{
	public:
		RedPencil(){
			color = "red";
		}
		
};

Pencil* Pencil::getPencil(string color)
{
	if(color == "red")
		return new RedPencil();
	else if(color == "blue")
		return new BluePencil();
	else
		return 0;
}

int main()
{
	Pencil* redPencil = Pencil::getPencil("red");
	redPencil->showInformation();
	
	cout<<endl<<endl<<endl;
	
	Pencil* bluePencil = Pencil::getPencil("blue");
	bluePencil->showInformation();
	return 1;
}
