
/*
	Name: Demo_Builder.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn aka eddydn@gmail.com
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Builder
*/

#include <iostream>

using namespace std;

class FacultyLecturer{
	public:
		int basicSalary;
	
};

class VisitingLecturer{
	public:
		int hourSalary;
		int numOfHour;
		int realSalary;
};

class Lecturer{
	public:
		FacultyLecturer* salaryFacultyLecturer;
		VisitingLecturer* salaryVisitingLecturer;
		
		void showInformation()
		{
			
			cout<< "Faculty Lecturer are paid : "<< salaryFacultyLecturer->basicSalary<<" USD/month"<<endl;
			cout<< "Visiting Lecturer has : "<< salaryVisitingLecturer->numOfHour<<" hours teach with price: "<<salaryVisitingLecturer->hourSalary<<" USD/h"<<endl;
			cout<< "Visiting Lecturer are paid : "<< salaryVisitingLecturer->realSalary<<" USD/month"<<endl;
		}
		
	
};

class Builder{
	public:
		virtual FacultyLecturer* getFacultySalary() = 0;
		virtual VisitingLecturer* getVisitingSalary()=0;
};

class Director{
	Builder* builder;
	
	public:
		void setBuilder(Builder* newBuilder)
		{
			builder = newBuilder;
		}
		
		Lecturer *getLecturer()
		{
			Lecturer* gv = new Lecturer();
			gv->salaryFacultyLecturer = builder->getFacultySalary();
			gv->salaryVisitingLecturer = builder->getVisitingSalary(); 
			
			return gv;
		}
};

//Create new Lecturer
class ITLecturer : public Builder{
	
	public:
		FacultyLecturer* getFacultySalary()
		{
			FacultyLecturer* gv = new FacultyLecturer();
			gv->basicSalary = 500;
			return gv;
		}
		VisitingLecturer* getVisitingSalary()
		{
			VisitingLecturer* gv = new VisitingLecturer();
			gv->hourSalary = 20;
			gv->numOfHour = 100;
			gv->realSalary = gv->numOfHour*gv->hourSalary;
			return gv;
		}
};

class TelecomLecturer : public Builder{
	
	public:
		FacultyLecturer* getFacultySalary()
		{
			FacultyLecturer* gv = new FacultyLecturer();
			gv->basicSalary = 300;
			return gv;
		}
		VisitingLecturer* getVisitingSalary()
		{
			VisitingLecturer* gv = new VisitingLecturer();
			gv->hourSalary = 30;
			gv->numOfHour = 50;
			gv->realSalary = gv->numOfHour*gv->hourSalary;
			return gv;
		}
};

int main(){
	
	Lecturer* gv; // Nguoi giang vien
	Director director;
	
	/* builder*/
	ITLecturer lecturerOne;
	TelecomLecturer lecturerTwo;
	
	//IT Lecturer
	cout<< "Salary of IT Lecturer :"<<endl;
	director.setBuilder(&lecturerOne); // instace of IT Lecturer
	gv = director.getLecturer();
	gv->showInformation();
	
	cout<<endl<<endl<<endl;
	
		//Tao 1 giang vien DTVT moi
	cout<< "Salary of Telecom Lecturer :"<<endl;
	director.setBuilder(&lecturerTwo); // instace of Telecom Lecturer
	gv = director.getLecturer();
	gv->showInformation();
	
	
	return 1;
}
