//
//  Member.cpp
//  EE273_v2.0
//
//  Created by FAN XIAOFENG on 6/3/17.
//  Copyright © 2017 Fan Xiaofeng. All rights reserved.
//

#include "stdafx.h"

#include "Member.hpp"
#include <iostream>
using namespace std;

// attribute configuration
member::member(){

	name = "";
	gender = 'x';
	age = 0;

}

member::member(string w, string x, string y, int z){

	// w = name, x = gender, y = instrument, z = age
	name = w;
	gender = x;
	instruments.push_back(y);
	age = z;

}


// attribute setters, n for name and a for age etc.

void member::setName(string n){
	name = n;
}

void member::setGender(string g){
	gender = g;
}

void member::setInstrument(string i, string b){
	instruments.push_back(i);
	bands.push_back(b);  // one to one
}

void member::setAge(int a){
	age = a;
}



string member::getInstrument(string bname)  // version when seeing the artilsts inside a band
{
	for (list<string>::iterator it1 = instruments.begin(), it2 = bands.begin(); it1 != instruments.end(); ++it1, ++it2) {
		if (*it2 == bname) return *it1;
	}
}

void member::showInstruments2()  // version when seeing all the artilsts
{
	for (list<string>::iterator it1 = instruments.begin(), it2=bands.begin(); it1 != instruments.end(); ++it1,++it2) {
		cout << " was " << *it1 << " in " << *it2 << endl;
	}
}




// attribute getters

string member::getName(){
	return name;
}

string member::getGender(){
	return gender;
}

list<string> member::getInstrument(){
	return instruments;
}

int member::getAge(){
	return age;
}


