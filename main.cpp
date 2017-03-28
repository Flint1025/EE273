//
//  main.cpp
//  EE273_v2.0
//
//  Created by FAN XIAOFENG on 4/3/17.
//  Copyright © 2017 Fan Xiaofeng. All rights reserved.
//
//                       C:\Users\XFAN0\Desktop\Project_EE273-Version2.1\bands.txt
//
//                   mac:     /Users/Flint/Desktop/member.txt

//                         C:\Users\kxb16204\Desktop\bands.txt
// may consider move some functions to a functions.cpp
//#include "stdafx.h"

#include <iostream>
#define bandsize 100
#define membersize 100
#define filelength 2000
#include "Band.hpp"
#define WINDOWS
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <list>
#include <iterator>

using namespace std;


//implementation of add member (from file)

// 1. create all objects put into a global list
// 2. put them into corresponding band class

int record[bandsize]={0};
band bands[bandsize]; //change to dynamically creation later
member members[membersize];

list <member> MemberList;

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
// ***--
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
//  --***


int main(int argc, const char * argv[]) {



    int opt1,opt2,n,n1,n2;
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
		// check filename input       // may try GUI later
		cout << "Indicate your bands database file:" << endl;
		while (1)	
		{
			cin >> fname;
			iF.open(fname.c_str());
			if (!iF)
			{
				cout << "Error opening file! Pls re-input your file:" << endl;
				continue;
			}
			break;
		}
        
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
        }
        

		cout << endl << "Bands database File loaded successfully!" << endl;

		cout << "\n\nInput anything to continue......";
		cin >> c;
#ifdef WINDOWS
		system("cls");
#endif

		cout << "Indicate your artists database file:" << endl;
		while (1)
		{
			cin >> fname2;
			iF2.open(fname2.c_str());
			if (!iF2)
			{
				cout << "Error opening file! Pls re-input your file:" << endl;
				continue;
			}
			break;
		}
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
            //bands[n].addmember.......
            
            for (list<string>::iterator it = bandslist.begin(); it != bandslist.end(); ++it) {
                int p = getbandnumber(*it); // p is the position of band in global bands[] array
                if (p != -1 ) {
                    bands[p].addmember(mb);
                }
                

            }
            
            MemberList.push_back(mb);
            j+=5;

		}

        cout << endl << "Artists database File loaded successfully!" << endl;
        
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
	//implement this main mune after implementing member class
//	cout << "\n\nType any single charactor to go to the main menu.....";
//	cin >> c;
//	// the main menu
//
//	while (1)	
//	{
//#ifdef WINDOWS
//		system("cls");
//#endif // WINDOWS
//		//maybe add reload file
//		cout << "\n\n\t1. View all the bands stored\n\t2. View and modify a single band\n\t3. Search\n\t4. Save into a new file\n\t5. Exit\n\n\tEnter your choice = ";
//		cin >> opt1;
//		switch (opt1)
//		{
//		default:
//			cout << "Invalid input";
//			break;
//		case 1:
//			break;
//		case 2:
//			break;
//		case 3:
//			break;
//		case 4:
//			break;
//		}
//	}
//


	// process the database
    cout<<"\nEnter the band number for which band you want to view or modify details: ";
    cin>>n;
    n = n-1;
    while (1) {
#ifdef WINDOWS
        system("cls");
#endif // WINDOWS
        cout<<"\n\n\n\tBand no = "<<n+1<<"\t"<< bands[n].getBandName() << "\n\n\t1. Edit information for this band\n\t2. Add new member for this band\n\t3. Search\n\t4. Destroy\n\t5. Display all the bands you have input\n\t6. Change to another band to modify\n\t7. Connect two bands\n\t8. Save to a new file\n\t9. Exit\n\n\t\n\n\t12.test see the information about all the members\nEnter your choice = ";
        cin>>opt2;
        cout<<endl;
		string w, x, y,year;
		int z;
		member mb;
        switch(opt2)
        {
            default:
                cout<<"Invalid input";
                break;
                
            case 2:   // implement addnew() as add a new member object into the vector
				getchar();
				cout << "Enter the name:" << endl;
				getline(cin, w);
				
				cout << "Enter the birthyear:" << endl;
				cin >> z;

				getchar();
				cout << "Enter the instrument:" << endl;
				getline(cin, y);
				
				cout << "Enter the staying year in this band:" << endl;
				getline(cin, year);
				
			//	bands[n].addmember(w,x,y,z);  // create the object and push into the list under band class

				mb.setName(w);
				mb.setInstrument(y, bands[n].getBandName(), year);
				mb.setAge(z);

				bands[n].addmember(mb);    // create the object and push into the list under band class
				
				MemberList.push_back(mb); // put this object into the global MemberList for future process
				// It seemed cannot declare a new member inside the switch
                break;
//                
            case 1:
                bands[n].editBand();
				record[n] = 1;
                break;
//
//            case 3:
//                cout<<"Enter name of person to search: ";
//                cin>>name;
//                T[n].show(T[n].search(name));
//                break;
//                
//            case 4:
//                T[n].destroy(T[n].start);
//                cout<<"Tree "<<n<<" has been destroyed sucessfully";
//                break;
//                
            case 5: // show all the band
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
                break;
                
            case 6:  // display the bands which have been stored
                displaybandnums();
                
                cout<< endl << "Enter band number: ";
                cin>>n;
				n--;
                break;
                
            case 7:
                cout<<"Merge __ to __ \n";
                cin>>n2>>n1;
  //              connect(&bands[n1],&bands[n2]);
                break;
                
            case 9:
                return 0;

			case 12:
				for (list<member>::iterator it = MemberList.begin(); it != MemberList.end(); ++it) {
					cout << endl << it->getName() << " born in " << it->getAge() << "." << " Experience: " <<endl;
					it->showInstruments2();
				}
                
        }
        cout<<"\n\nInput anything to continue.....";
        cin>>c;   // bug to be fixed
    }
    return 0;
}


//2 bugs:
//1. only got the first band 2(fixed). display in main menu


// input checking

// implementa new version of display





//  grohl
