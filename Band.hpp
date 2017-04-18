//
//  Band.hpp
//  EE273_v2.0
//
//  Created by FAN XIAOFENG on 4/3/17.
//  Copyright © 2017 Fan Xiaofeng. All rights reserved.
//

#ifndef Band_hpp
#define Band_hpp


#include "Member.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;


class band{
private:
    string BandName;   //name of this band
    string genres;
    string desc;
    list<string> songslist;
    
    int BandYear[2];   //BandYear[0] -  BandYear[1]
    
    list<member> memberlist;     // a vector of pointers which points to objects
	list<string> memberyear;     // one to one corresponding
public:

    band();
    band(string fn); // constructor using data from a flie named fn

	int status;

	//setter functions
    void setBandName(string name);
    void setBandYear(int sYear, int eYear); //sYear -- starting year of the band
    void setGenres(string geners);
//    void setProducers(string producers);
    void setSongs(list<string> songs);
	list<string> getSongs();
    void setDesc(string desc);

	void updata_status();
	int getBandYear1();
	int getBandYear2();
	//getter functions
	string getBandName();
	string getGenres();

	string getDesc();
	

    void editBand();
    void showBand();

	void addmember(member mb);

	void addmember(string w, string y, int z);


	void showBand2();
};




#endif /* Band_hpp */
