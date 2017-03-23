//
//  Member.hpp
//  EE273_v2.0
//
//  Created by FAN XIAOFENG on 6/3/17.
//  Copyright © 2017 Fan Xiaofeng. All rights reserved.
//

#ifndef Member_hpp
#define Member_hpp

#include <stdio.h>
#include <string>
#include <list>
using namespace std;


class member{
private:
	string name;
//	string gender;
	list<string> instruments;  //two lists corresponds to each other one to one
	list<string> bands;
	list<string> stayYears;
	int age;



public:
	member();
	member(string, string, int);
    member(string, int, list<string>, list<string>, list<string>);  //reading from database
    
	void setName(string);
//	void setGender(string);
	void setInstrument(string,string,string);
	void setAge(int);

	string getInstrument(string);
	string getstayYear(string bname);
	void showInstruments2();

	string getName();
//	string getGender();
	list<string> getInstrument();


	int getAge();


	//list of instruments
};


#endif /* Member_hpp */
