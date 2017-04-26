//
//  main.cpp
//  EE273_v2.0
//
//  Created by FAN XIAOFENG on 4/3/17.
//  Copyright © 2017 Fan Xiaofeng. All rights reserved.
//


// 

/*bugs

file encoding bug
input checking


*/



#include "stdafx.h"

#include <iostream>
#define bandsize 500
#define membersize 500
#define filelength 2000
#include "Band.hpp"
#define WINDOWS
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <iterator>

#include<tchar.h>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "main.h"
using namespace std;


// *************************----------------------------------
int record[bandsize]={0};
band bands[bandsize]; 


list <member> MemberList;



// need more instruments (create global for all the possible instruments)

//  ------------------------------------****************************




void savebands();
void saveartists();
// this function will firstly check if this artist has been added into the global memberlist list
// if yes, add this new exprience to this artist then return 1
// if no, return 0
int add_member_global(string name, string band, string instrument, string stayYear) { // return 1 if this artist has been stored
	for (list<member>::iterator it = MemberList.begin(); it != MemberList.end(); ++it) {    // if has been stored, just add a new instrument for this artist
		if (name == it->getName()) {
			it->setInstrument(instrument, band, stayYear);
			return 1;
		}
	}
	return 0;  // return 0 if this artist has not been stored
}

//  ------------------------------------****************************
int getbandnumber(string band){   // to return the position of band in the bands[] array
    for (int i = 0; i < bandsize; i++) {
        if (bands[i].getBandName() == band) {
            return i;
        }
    }
    return -1;  // return -1 if this band hasn't been store yet
}


void displaybandnums(){
    cout << "You have input information for bands:" << endl << endl;
    for (int i = 0; i < bandsize; i++)
    {
        if (record[i] == 1)   // record[i] is 1 if the band has been added
        {
            cout << i+1 << " " << bands[i].getBandName();   // implement another version withour repeated prompt
            cout << endl;
        }
    }
}


int search_member(string name) { // display and return 1 if this artist has been stored
	for (list<member>::iterator it = MemberList.begin(); it != MemberList.end(); ++it) {    
		if (name == it->getName()) {
			cout << endl << name << " was born in " << it->getbirthYear() <<"\nExperience: \n";
			it->showInstruments2();
			return 1;
		}
	}
	return 0;  // return 0 if this artist has not been stored
}


int search() {
	int opt, temp;
	int *r = 0;
	string bandname, inst, artistname;
	while (1)
	{
		system("cls");
		cout << "\n\n\t1. Search information for a band stored\n\t2. Search for an instrument stored\n\t3. Search for an artist stored\n\t9. Back to the main menu\n\n\tEnter your choice(only integer input accepted) = ";
		cin >> opt;
		switch (opt)
		{
			default:
				break;
			case 1:
				getchar();
				cout << "Input the band name:" << endl;
				getline(cin, bandname);
				temp = getbandnumber(bandname);
				if (temp == -1)
				{
					cout << bandname << " has not been stored yet." << endl;
					cout << "________Input any single character to continue________" << endl;
					getchar();
					continue;
				}
				else {
					bands[temp].showBand();
					continue;
				}
				break;

			case 2:
				getchar();
				cout << "Input the instrument type:" << endl;  
				getline(cin, inst);
				inst[0] = toupper(inst[0]);
				for (list<member>::iterator it = MemberList.begin(); it != MemberList.end(); ++it) {
					it->showInstrumentsForSearch(inst); //search all the member and all instruments one by one
				}
				 // ************************* need more types of instruments ****************************************//

				cout << endl << endl << "________Input any single character to continue________" << endl;
				getchar();
				continue;
				break;

			case 3:
				getchar();
				cout << "Input the artist name:" << endl;
				getline(cin, artistname);
				temp = search_member(artistname); // if this artist has been stored, this function will diaplay it and then return 1
				if (temp == 0)   // if this artist has not been stored, then nothing be displayed and function will return 0
				{
					cout << artistname << " has not been stored yet";
					cout << endl << "________Input any single character to continue________" << endl;
					getchar();
					continue;
				}
				else // this artist has been stored and now already be displayed. temp shall be 1 here
				{
					cout << endl << "________Input any single character to continue________" << endl;
					getchar();
					continue;
				}
				break;
			case 9:
				return 0;
			}
		return 0;
	}
}







int modifysingleband(int n, int opt2){
#ifdef WINDOWS
    system("cls");
#endif // WINDOWS
    displaybandnums();
    cout<<"\nEnter the band number for which band you want to view or modify details(only integer input accepted): ";
    cin>>n;
    n = n-1;
    while (1) {
#ifdef WINDOWS
        system("cls");
#endif // WINDOWS
        cout<<"\n\n\n\tBand no = "<<n+1<<"\t"<< bands[n].getBandName() << "\n\n\t1. Edit information for this band\n\t2. Add new member for this band\n\t3. Display information about this band\n\t4. Change to another band to modify\n\t9. Back to the main menu\n\n\t\n\nEnter your choice(only integer input accepted) = ";
        cin>>opt2;
        cout<<endl;

		string name, instrument, stayYear;
        int birthyear;
        member mb;
        switch(opt2)
        {
            default:
                cout<<"Invalid input";
                break;
                
            case 2:   // implement addnew() as add a new member object into the vector
                getchar();
                cout << "Enter the name:" << endl;
                getline(cin, name);
				name[0] = toupper(name[0]);

                cout << "Enter the birthyear:" << endl;
                cin >> birthyear;
                
                getchar();
                cout << "Enter the instrument:" << endl;
                getline(cin, instrument);
				instrument[0] = toupper(instrument[0]);
                
                cout << "Enter the staying year in this band:(e.g. input 1990-2015)" << endl;
                getline(cin, stayYear);
                
                //	bands[n].addmember(w,x,y,z);  // create the object and push into the list under band class
                
                mb.setName(name);
                mb.setInstrument(instrument, bands[n].getBandName(), stayYear);
                mb.setbirthYear(birthyear);
                
                bands[n].addmember(mb);    // create the object and push into the list under band class
                
				if (add_member_global(name, bands[n].getBandName(), instrument, stayYear) == 0)// this will return 1 if this member has been created and added into the global list
				{                                                                      // return 0 if this member has been created and the new "experience" has been stored
					MemberList.push_back(mb); // put this object into the global MemberList for future process
				}
                // It seemed cannot declare a new member inside the switch
                break;
                //
            case 1:
                bands[n].editBand();
                record[n] = 1;
                break;
                //

			case 3:
				bands[n].showBand();
				break;

            case 4:  // display the bands which have been stored
                displaybandnums();
                
                cout<< endl << "Enter band number(only integer input accepted): ";
                cin>>n;
                n--;
                break;

            case 9:
                return 0;
        }
        cout<<"\n\nInput anything to continue.....";
        char c;
        cin>>c;   
    }
}

// *************************----------------------------------
template<typename Out>   // list<string> x = split(string, 'delimeter');

void split(const std::string &s, char delim, Out result) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

list<std::string> split(const std::string &s, char delim) {
    list<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}
//  ------------------------------------****************************


int main(int argc, const char * argv[]) {

    int opt1,opt2=0,n=0,n1,index=0,saveopt;
	char option;
    char c;
	//ask user if he wants to extract information from a file
	cout << "Do you want to extract information from a file? (enter y or n)" << endl;
	cin >> option;
    
    //extract information from the file and build those objects up ready to process
	if (option == 'y')
	{
		string f[filelength], f2[filelength],fname, fname2, fline, fline2;  //fname2, fline2 are used for member file
        ifstream iF,iF2;


		// ****** dialog box ****** //
		char filename[MAX_PATH];

		OPENFILENAME ofn;
		ZeroMemory(&filename, sizeof(filename));
		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;  
		ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
		ofn.lpstrFile = filename;
		ofn.nMaxFile = MAX_PATH;
		ofn.lpstrTitle = "Choose your bands database file";
		ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameA(&ofn))
		{
			std::cout << "You hava sucessfully loaded the file \"" << filename << "\"\n";
		} 
		else
		{
			switch (CommDlgExtendedError())
			{
			case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
			case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
			case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
			case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
			case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
			case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
			case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
			case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
			case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
			case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
			case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
			case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
			case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
			case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
			case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
			default: std::cout << "You cancelled.\n";
			}
		}

		// ****** dialog box ****** //

		      // may try GUI later
		//cout << "Indicate your bands database file:" << endl;
		//while (1)	
		//{
		//	cin >> fname;
		//	iF.open(fname.c_str());
		//	if (!iF)
		//	{
		//		cout << "Error opening file! Pls re-input your file:" << endl;
		//		continue;
		//	}
		//	break;
		//}
		iF.open(filename);
		int count = 0, numberofBands;  //begin to read file
		while (!iF.eof())
		{
			getline(iF, fline);
            f[count] = fline;
            count++;
		}
        numberofBands = count/15;    //15 lines for one band
        
        for (int i=0, j=0; i<numberofBands; i++) {    // i controls which band
            bands[i].setBandName(f[j]);
            bands[i].setBandYear(stoi(f[j+1]), stoi(f[j+2]));
            bands[i].setGenres(f[j+3]);
            bands[i].setDesc(f[j+4]);
            
            list<string> songs;
            for (int q=j+5; q<j+15; q++) {
                songs.push_back(f[q]);
            }
            bands[i].setSongs(songs);
            j+=15;  // every time finish one band, go to next band, j+=15
            record[i] = 1;
			bands[i].status = 1; // 1 means the information about this band is completed. it can be stored into database
			index = i;  // index of last non-empty position of bands[i]
        }
        

	//	cout << endl << "Bands database File loaded successfully!" << endl;

		cout << "\n\nInput anything to continue......";
		cin >> c;
#ifdef WINDOWS
		system("cls");
#endif

		cout << "Choose your artists database file:" << endl;
		char filename2[MAX_PATH];

		OPENFILENAME ofn2;
		ZeroMemory(&filename2, sizeof(filename2));
		ZeroMemory(&ofn2, sizeof(ofn2));
		ofn2.lStructSize = sizeof(ofn2);
		ofn2.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
		ofn2.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
		ofn2.lpstrFile = filename2;
		ofn2.nMaxFile = MAX_PATH;
		ofn2.lpstrTitle = "Choose your artists database file";
		ofn2.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameA(&ofn2))
		{
			std::cout << "You have sucessfully loaded the file \"" << filename2 << "\"\n";
		}
		else
		{
			switch (CommDlgExtendedError())
			{
			case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
			case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
			case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
			case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
			case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
			case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
			case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
			case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
			case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
			case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
			case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
			case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
			case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
			case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
			case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
			default: std::cout << "You cancelled.\n";
			}
		}
		iF2.open(filename2);
		//while (1)
		//{
		//	cin >> fname2;
		//	iF2.open(fname2.c_str());
		//	if (!iF2)
		//	{
		//		cout << "Error opening file! Pls re-input your file:" << endl;
		//		continue;
		//	}
		//	break;
		//}
//
		int count2 = 0, numberofArtists;  //begin to read file
		while (!iF2.eof())
		{
			getline(iF2, fline2);
			f2[count2] = fline2;    // f2 holds the content from the artists database
			count2++;
		}
		numberofArtists = count2 / 5;    //5 lines for one artist

		for (int i = 0, j = 0; i<numberofArtists; i++) { //f2[i] holds the content
            string name, gender, stayYear, instrument;
            int birYear, number;    // number = how many instruments this person has
            name = f2[j];
            birYear = stoi(f2[j+1]);
            list<string> inst = split(f2[j+2], ',');
            list<string> Year = split(f2[j+3], ',');
            list<string> bandslist = split(f2[j+4], ',');
 //           number = inst.size();
            member mb(name, birYear, inst, Year, bandslist);
            
            // link to band class  ********#### need to be implemented ###*********
            //bands[n].addmember....... [done]
            
            for (list<string>::iterator it = bandslist.begin(); it != bandslist.end(); ++it) {
                int p = getbandnumber(*it); // p is the position of band in global bands[] array
                if (p != -1 ) {   // p == -1 means this band has not been stored yet
                    bands[p].addmember(mb);
                }
				else // if this band has not been created and stored yet, then create it based on the bandslist of this member
				{
					bands[index + 1].setBandName(*it);
					//other information for this band is missing at this moment
					bands[index + 1].addmember(mb);
					record[index + 1] = 1;
					index++;
				}

            }
          
            MemberList.push_back(mb);
            j+=5;

		}

 //       cout << endl << "Artists database File loaded successfully!" << endl;
        
        cout << "\n\nInput anything to continue......";
        cin >> c;
#ifdef WINDOWS
        system("cls");
#endif
        
		//show the user which bands have been stored
        displaybandnums();
	}
	else
	{
		cout << "You don't have any bands' information yet." << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << " " << bands[i].getBandName();
			cout << endl;
		}
		cout << "4   ..." << endl;
		cout << "... ..." << endl;
		cout << "... ..." << endl;
		cout << "100 ..." << endl;
	}

	while (1)
	{
#ifdef WINDOWS
		system("cls");
#endif // WINDOWS
//		//maybe add reload file
		cout << "\n\n\t1. View all the bands stored\n\t2. View all the artists stored\n\t3. View and modify a single band\n\t4. Search\n\t5. Save your new modified database\n\t9. Exit\n\n\tEnter your choice(only integer input accepted)= ";
		cin >> opt1;
		switch (opt1)
		{
		default:
			cout << "Invalid input";
			break;
		case 1:
#ifdef WINDOWS
                system("cls");
#endif
                for (int i = 0; i < bandsize; i++)
                {
					if (record[i] == 1)   // record[i] is 1 if the band has been added
					{
						bands[i].showBand2();   // implement another version withour repeated prompt
						cout << endl;
					}
                }
				char c;
				cout << "\n\nInput anything to continue.....";
				cin >> c;
			break;
		case 2:
			system("cls");
			for (list<member>::iterator it = MemberList.begin(); it != MemberList.end(); ++it) {
				cout << endl << it->getName() << " born in " << it->getbirthYear() << "." << " Experience: " << endl;
				it->showInstruments2();
			}

			cout << "\n\nInput anything to continue.....";
			cin >> c;
			break;
		case 3:
			modifysingleband(n, opt2);
				cout << "\n\nInput anything to continue.....";
				cin >> c;
			break;
		case 4:

			search();
			break;
		case 5:
			cout << "\n\n\t1. Save bands database(only the bands with all the information allocated will be saved into your new database e.g. desc,genres,10 songs.)\n\t2. Save artists database\n\n\tEnter your choice(only integer input accepted) = ";
			cin >> saveopt;
			if (saveopt == 1)
			{
				savebands();    // improve the menu later **
			}
			else {
				saveartists();
			}
			break;
		case 9:
			return 0;
		}
	}
    return 0;
}


void savebands() {
	char filename[MAX_PATH];

	OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // put its HANDLE here
	ofn.lpstrFilter = _T("Text Files\0*.txt\0Any File\0*.*\0");
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = _T("Save the database in...");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetSaveFileName(&ofn))
	{
		std::cout << "Your bands database has been saved in \"" << filename << "\"\n";
		string s;
		cout << "__________Input any single character to go back to the main menu__________" << endl;
		getline(cin, s);
		getchar();
	}
	else
	{
		switch (CommDlgExtendedError())
		{
		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
		default: std::cout << "You cancelled.\n";
		}
	}
	ofstream of;
	of.open(filename);
	for (int i = 0; i < bandsize; i++)
	{
		if (record[i] == 0)
		{
			break;
		}
		if (bands[i].status == 1) {
			of << bands[i].getBandName() << endl;
			of << bands[i].getBandYear1() << endl;
			of << bands[i].getBandYear2() << endl;
			of << bands[i].getGenres() << endl;  // enhence the showband & display band by adding genres and desc
			of << bands[i].getDesc() << endl;

			list<string> temp = bands[i].getSongs();
			int count = 0;

				for (list<string>::iterator it = temp.begin(); it != temp.end(); ++it)  // potential bugs if songs less than 10
				{
					of << *it << endl;  // save 10 songs into the database
					count++;
					if (count == 10)
					{
						break;
					}
				}
		
		}  // only chose 10 songs is due to how we decide the format of the database file at the beginning. 
	}

}
void saveartists() {
	char filename[MAX_PATH];

	OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  
	ofn.lpstrFilter = _T("Text Files\0*.txt\0Any File\0*.*\0");
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = _T("Save the artists database in...");
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetSaveFileName(&ofn))
	{
		std::cout << "Your artists database has been saved in \"" << filename << "\"\n";
		string s;
		cout << "__________Input any single character to go back to the main menu__________" << endl ;
		getline(cin, s);
		getchar();
	}
	else
	{
		switch (CommDlgExtendedError())
		{
		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";   break;
		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";  break;
		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";  break;
		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";  break;
		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";  break;
		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";  break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n"; break;
		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";  break;
		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";     break;
		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";          break;
		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";      break;
		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";      break;
		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";  break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n"; break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n"; break;
		default: std::cout << "You cancelled.\n";
		}
	}
	ofstream of;
	of.open(filename);
	for (list<member>::iterator it = MemberList.begin(); it!=MemberList.end(); it++)
	{
		of << it->getName() << endl;
		of << it->getbirthYear() << endl;
		list<string> l1 = it->getInstrument();
		list<string> l2 = it->getstayYears();
		list<string> l3 = it->getbands();
		for (list<string>::iterator it1 = l1.begin(); it1 != l1.end(); ++it1) //write inst one by one
		{
			if (it1 == l1.begin())
			{
				of << *it1;
			}
			else
				of << "," << *it1;
		}
		of << endl;
		for (list<string>::iterator it1 = l2.begin(); it1 != l2.end(); ++it1) //write inst one by one
		{
			if (it1 == l2.begin())
			{
				of << *it1;
			}
			else
				of << "," << *it1;
		}
		of << endl;
		for (list<string>::iterator it1 = l3.begin(); it1 != l3.end(); ++it1) //write inst one by one
		{
			if (it1 == l3.begin())
			{
				of << *it1;
			}
			else
				of << "," << *it1;
		}
		of << endl;
	}

}