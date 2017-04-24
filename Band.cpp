

#include "Band.hpp"
#define WINDOWS
band::band(){
	BandName = "Unnamed Band";
	desc = "None";
	genres = "None";
	BandYear[0] = 0;
	BandYear[1] = 0;
	status = 0;
}

band::band(string fn){   // fn is the file name
	
}

void band::setBandName(string name){
    BandName = name;
}

void band::setBandYear(int sY, int eY){
    BandYear[0] = sY;
    BandYear[1] = eY;
}

void band::setGenres(string genres){
    this -> genres = genres;
}

void band::setSongs(list<string> songs){
    songslist = songs;
}

list<string> band::getSongs() {
	return songslist;
}


void band::setDesc(string desc){
    this->desc = desc;
}

string band::getGenres() {
	return genres;
}

string band::getDesc() {
	return desc;
}

void band::updata_status()
{
	if (songslist.size()!=0 && BandName!= "Unnamed Band" && genres != "None" && desc != "None" && BandYear[0] != 0 && BandYear[1] != 0)
	{
		status = 1;
	}
}

int band::getBandYear1() {
	return BandYear[0];
}
int band::getBandYear2() {
	return BandYear[1];
}
string band::getBandName(){
	return BandName;
}



void band::showBand(){
    char c;
    cout << "Band: " << BandName << " was formed in " << BandYear[0] << " and active until " << BandYear[1] << endl;
	cout << desc << endl;
	cout << "Genres: " << genres << endl << endl; 
	cout << "Members: " << endl;
	for (list<member>::iterator it = memberlist.begin(); it != memberlist.end(); ++it) {
		cout << endl << it->getName() << " as the " << it->getInstrument(BandName) << " for " << it->getstayYear(BandName);
	}
	cout << endl << endl << "Songs: ";
    for (list<string>::iterator it=songslist.begin(); it!=songslist.end(); ++it) {
        cout << endl << *it;   
    }

    cout << endl << endl << endl << "____Press any key to continue____" << endl;
    cin >> c;
    cout << endl;
}

void band::addmember(member mb)
{
	memberlist.push_back(mb);
}

void band::addmember(string w, string y, int z)
{
	member mb(w,y,z);
	memberlist.push_back(mb);
}

void band::showBand2(){
	char c;
	cout << "-------------------******************-------------------" << endl;
	cout << "Band: " << BandName << " was formed in " << BandYear[0] << " and active until " << BandYear[1] << endl;
	cout << "Genres: " << genres << endl;
	cout << "Members: " << endl;
	for (list<member>::iterator it = memberlist.begin(); it != memberlist.end(); ++it) {
		cout << endl << it->getName() << " as the " << it->getInstrument(BandName) << " for " << it->getstayYear(BandName);
	}
	cout << endl << endl << "Songs: ";
	for (list<string>::iterator it = songslist.begin(); it != songslist.end(); ++it) {
        cout << endl << *it;
	}
	cout << endl << endl << endl;
}

void band::editBand(){
    int opt,temp1, temp2;
    bool end = false;
    char c;
    string temp;
    while (1 && !end) {
#ifdef WINDOWS
        system("cls");
#endif // WINDOWS
        cout<<"\n\n\n\tBand: "<< BandName <<"\n\n\t1. Change the name of this band\n\t2. Change the year of this band\n\t3. Change genres of this band\n\t4. Change descrption of this band\n\t5. Add new song to this band\n\t6. Display information for this band\n\t7. Back to edition menu\n\n\tEnter your choice = ";
        cin>>opt;
        cout<<endl;
	
        switch(opt)
        {
            default:
                cout<<"Invalid input" << opt;
                break;
            case 1:
                getchar();
                cout << "Enter the new name for this band:" << endl;
                getline(cin, temp);    // bug input a line  // '\n' in the buffer
                setBandName(temp);
				updata_status();
                break;
            case 2:
                cout << "Enter the year when the band was formed:" << endl;
                cin >> temp1;
                cout << "Enter the last year when the band was active: " << endl;
                cin >> temp2;
                setBandYear(temp1, temp2);
				updata_status();
                break;
            case 3:
                getchar();
                cout << "Enter the genres of this band:" << endl;
                getline(cin, temp);
                setGenres(temp);
				updata_status();
                break;
			case 4:
				getchar();
				cout << "Enter the descrption of this band:" << endl;
				getline(cin, temp);
				setDesc(temp);
				updata_status();
				break;

            case 5:
                getchar();
                cout << "Enter new song of this band:" << endl;
                getline(cin, temp);
                songslist.push_back(temp);
				updata_status();
                break;
            case 6:
                showBand();
				updata_status();
                break;
            case 7:
                end = true;
                break;
        }
   
    }
}
