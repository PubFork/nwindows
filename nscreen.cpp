#include "nscreen.h"


Nscreen::Nscreen(){
	//default constructor uses stdin and out
	numwindows = 1;
    scrptr = newterm("xterm",stdin,stdout);    
    set_term(scrptr);
    getmaxyx(stdscr,MAX_Y, MAX_X);

    start_color();
    init_pair(1,COLOR_WHITE,COLOR_BLUE);

    init_windows();
}


Nscreen::~Nscreen(){
   delscreen(scrptr);
}


void Nscreen::init_windows(){
    nwindows = vector<Nwindow>(numwindows);
    for (int i = 0 ; i< numwindows;++i){
        nwindows[i] = Nwindow(MAX_Y/numwindows,MAX_X, 
        	                i*(MAX_Y/numwindows) , 0);
    }
}

void Nscreen::print_color(ifstream& file ,COLOR c){
	nwindows[0].print_color(file,c);
}

void Nscreen::print_color(string str ,COLOR c){
    nwindows[0].print_color(str,c);
}


void Nscreen::clear(){
	nwindows[0].clear();
}