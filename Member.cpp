//
// Member.cpp
// EE273
//
// Created by FAN XIAOFENG on 6/3/17.
// Copyright © 2017 Fan Xiaofeng. All rights reserved.
//

#include "stdafx.h"

#include "Member.hpp"
#include <iostream>
using namespace std;

member::member(){

	name = "";
//	gender = 'x';
	birthyear = 0;

}

member::member(string w, string y, int z){

	// w = name, x = gender, y = instrument, z = age
	name = w;
//	gender = x;
	instruments.push_back(y);
	birthyear = z;

}
member::member(string name, int birthYear, list<string> inst, list<string> year, list<string> band){
    this-> name = name;
    birthyear = birthYear;
    instruments = inst;
    stayYears = year;
    bands = band;
}



void member::setName(string n){
	name = n;
}

//void member::setGender(string g){
//	gender = g;
//}

void member::setInstrument(string i, string b, string y){
	instruments.push_back(i);
	bands.push_back(b);  // one to one
	stayYears.push_back(y);
}

void member::setbirthYear(int a){
	birthyear = a;
}



string member::getInstrument(string bname)  // version when seeing the artilsts inside a band
{
	for (list<string>::iterator it1 = instruments.begin(), it2 = bands.begin(); it1 != instruments.end(); ++it1, ++it2) {
		if (*it2 == bname) return *it1;
	}
    return 0;// add checking for 0
}

string member::getstayYear(string bname)  // version when seeing the artilsts inside a band
{
	for (list<string>::iterator it1 = stayYears.begin(), it2 = bands.begin(); it1 != stayYears.end(); ++it1, ++it2) {
		if (*it2 == bname) return *it1;
	}
    return 0; // add checking for 0
}


void member::showInstruments2()  // seeing all the artilsts stored
{
	for (list<string>::iterator it1 = instruments.begin(), it2 = bands.begin(), it3 = stayYears.begin(); it1 != instruments.end(); ++it1, ++it2, ++it3) {
		cout << *it1 << " in " << *it2 << " from " << *it3<< endl;
	}
}


void member::showInstrumentsForSearch(string inst) {//
	for (list<string>::iterator it1 = instruments.begin(), it2 = bands.begin(), it3 = stayYears.begin(); it1 != instruments.end(); ++it1, ++it2, ++it3) {
		if (inst == *it1)
		{
			cout << name << " in " << *it2 << " from " << *it3 << endl;
		}
	}
}

// attribute getters

string member::getName(){
	return name;
}

//string member::getGender(){
//	return gender;
//}


// used in save artists   to copy the three lists then able to write to the file one by one
list<string> member::getInstrument(){
	return instruments;
}

list<string> member::getbands() {
	return bands;
}

list<string> member::getstayYears() {//return the whole list
	return stayYears;
}
int member::getbirthYear(){
	return birthyear;
}


