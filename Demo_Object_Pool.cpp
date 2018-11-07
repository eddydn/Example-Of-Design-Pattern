
/*
	Name: Demo_Object_Pool.cpp
	Copyright: 2018
	Author: nguyenthoanglinh@dtu.edu.vn
	Date: 07/11/18 13:58
	Description: Cai dat design pattern Builder
*/
#include <string>
#include <iostream>
#include <list>

using namespace std;

class Data{
	int drawable;
	
	public:
		Data()
		{
			drawable = 0;
		}
		
		void reset(){
			drawable = 0;
		}
		
		int getDrawable(){
			return drawable;
		}
		
		void setDrawable(int value)
		{
			drawable = value;
		}
};

class ObjectPool{
	private:
		list<Data*> listData;
		static ObjectPool* instance;
		ObjectPool() {
		}
		
		public:
			static ObjectPool* getInstance()
			{
				if(instance == 0)
					instance = new ObjectPool();
				return instance;
			}
			
			Data* getData()
			{
				if(listData.empty())
				{
					cout<<"Tao moi " << endl;
					return new Data;
				}
				else
				{
					cout<<"Da co san data"<<endl;
					Data* data = listData.front();
					listData.pop_front();
					return data;
				}
			}
			
			void returnData(Data* object)
			{
				object->reset();
				listData.push_back(object);
			}
	
};

ObjectPool* ObjectPool::instance = 0;

int main()
{
	 ObjectPool* pool = ObjectPool::getInstance();
	 
	 Data* drawableOne;
	 Data* drawableTwo;
	 
	 drawableOne = pool->getData();
	 drawableOne->setDrawable(1000);
	 
	 cout<<"Gia tri cua drawableOne la "<< drawableOne->getDrawable()<<endl;
	 
     drawableTwo = pool->getData();
	 drawableTwo->setDrawable(3000);
	 
	 cout<<"Gia tri cua drawableTwo la "<< drawableOne->getDrawable()<<endl;
	 

	pool->returnData(drawableOne);
    pool->returnData(drawableTwo);
    
    drawableOne = pool->getData();
    cout<<"Gia tri cua drawableOne la "<< drawableOne->getDrawable()<<endl;
    
     drawableTwo = pool->getData();
    cout<<"Gia tri cua drawableTwo la "<< drawableOne->getDrawable()<<endl;
	 
	 
	return 1;
}

