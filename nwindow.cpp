#include "nwindow.h"
#include <assert.h>

Nscreen::Nscreen(){
	//default constructor uses stdin and out
	numwindows = 1;
    scrptr = newterm("xterm",stdin,stdout);    
    set_term(scrptr);
    getmaxyx(stdscr,MAX_Y, MAX_X);

    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    
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

void Nscreen::move(int y, int x){
	nwindows[0].move(y,x);

}

void Nscreen::clear(){
	nwindows[0].clear();
}

Nwindow::Nwindow(){
	/*needs to get screen data*/
	winptr = NULL;
}

Nwindow::Nwindow(int len_y, int len_x, int x, int y){
    winptr = newwin(len_y, len_x, y, x);
	wattron(winptr,COLOR_PAIR(0));

    pos_y = 0; pos_x =0;
    MAX_Y = len_y; 
    MAX_X = len_x;
}

template<typename T> void Nwindow::move(T y, T x){
	pos_y = int(y)%MAX_Y; pos_x = int(x)%MAX_X;
	wmove(winptr,pos_y,pos_x);
	wrefresh(winptr);

}

template<typename T> void Nwindow::move_over(T dy,T dx){
	pos_y += int(dy); pos_x += int(dx);
	wmove(winptr,pos_y,pos_x);
}

void Nwindow::print_color(ifstream& file,COLOR c){
	
	 char line[MAXCHAR]; int i = 0;
	 while(!file.eof()){
		 //if the max line is greater than term*
		 //if (++i > MAX_Y) return;
		 file.getline(line, MAXCHAR);
		 //if ( file.gcount() > MAX_X) return;
		 print_line(string(line),c);
	 }
	 
}


void Nwindow::print_color(string str, COLOR c){
     mvwprintw(winptr,pos_y, pos_x,str.c_str());
     //wprintw(winptr,"%s",str.c_str());
     wrefresh(winptr);
     //reset_color();
} 




void Nwindow::print_color(double* da, COLOR color, int startp){

}

void Nwindow::clear(){
	werase(winptr);
}

void Nwindow::print_line(string line, COLOR c){
		 int aspace = get_end(line);
		 int bspace = get_start(line);

		 if ( bspace < 0 || aspace < 0 ) return;
		 int prev_x = pos_x;
		 move(pos_y,pos_x + bspace);
		 assert(bspace != aspace);
		 print_color(line.substr(bspace,line.length() - aspace),c);
		 move(pos_y +1,prev_x);

		
}

int Nwindow::get_end(string str){
	auto it = str.rbegin();
    for(; it != str.rend() ; ++it){
	    if(!isspace(*it)){
		   return distance(str.rbegin(),it);
		}
	}
	return -1;
}

int Nwindow::get_start(string str){
	auto it = str.begin();
    for(; it != str.end() ; ++it){
	    if(!isspace(*it)){
		   return distance(str.begin(),it);
		}
	}
	return -1;
}


void Nwindow::set_color(COLOR c){
	wattron(winptr,COLOR_PAIR(0));
}


void Nwindow::reset_color(void){
	wattroff(winptr,COLOR_PAIR(0));
}


