

#ifndef Member_hpp
#define Member_hpp

#include <stdio.h>
#include <string>
#include <list>
using namespace std;


class member{
private:
	string name;

	list<string> instruments;  //two lists corresponds to each other one to one
	list<string> bands;
	list<string> stayYears;
	int birthyear;



public:
	member();
	member(string, string, int);
    member(string, int, list<string>, list<string>, list<string>);  //reading from database
    
	void setName(string);
//	void setGender(string);
	void setInstrument(string,string,string);
	void setbirthYear(int);

	string getInstrument(string);
	string getstayYear(string bname); // used when seeing this artist inside a single band

	void showInstruments2();

	void showInstrumentsForSearch(string inst);//display this artist's inst experience


	string getName();
//	string getGender();
	list<string> getInstrument();

	list<string> getbands();


	list<string> getstayYears();//return the whole list

	int getbirthYear();


	//list of instruments
};


#endif /* Member_hpp */
