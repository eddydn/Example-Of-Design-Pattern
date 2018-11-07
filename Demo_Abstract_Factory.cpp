
/*
	Name: Demo_Abstract_Factory.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Builder
*/

#include <iostream>
#include <string>

using namespace std;

class Person
{
	protected:
		string name;
		string job;
		
		Person(string newName,string newJob)
			:name(newName),job(newJob)
			{}
		public:
			string getJob(){
				return job;
			}
			void showInfo()
		{
			cout<<"Name: "<<name<<endl;
			cout<<"Job: "<<job<<endl;
		}
			
};

class Student:public Person{
	public:
		Student():Person("Alibaba","Student")
		{}
};

class Programer:public Person{
	public:
		Programer():Person("John","Programer")
		{}
};

/* Abstract factory */

class UIFactory{
	public:
		virtual Person* getPerson()=0;
	
};

// Factory for Student
class StudentUIFactory: public UIFactory
{
	public:
		Person* getPerson()
		{
			return new Student();
		}
		
};

class ProgramerUIFactory: public UIFactory{
		public:
			Person* getPerson()
			{
				return new Programer();
			}
};

int main()
{
	UIFactory* uiStudent = new StudentUIFactory();
	UIFactory* uiProgramer = new ProgramerUIFactory();
	
	//Use factory to build interface
	Person* person = uiStudent->getPerson();
	person->showInfo();
	
	cout<<endl<<endl<<endl;
	
	person = uiProgramer->getPerson();
	person->showInfo();
	
	return 1;
}
