#include "nwindow.h"
#include <assert.h>



Nwindow::Nwindow(){
	/*needs to get screen data*/
	winptr = NULL;
}

Nwindow::Nwindow(int len_y, int len_x, int x, int y){
    winptr = newwin(len_y, len_x, y, x);

    pos_y = 0; pos_x =0;
    MAX_Y = len_y; 
    MAX_X = len_x;
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
     set_color(c);
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
	//wattrset(winptr,COLOR_PAIR(1));
    wbkgd(winptr,COLOR_PAIR(1));

}


void Nwindow::reset_color(void){
	wattroff(winptr,COLOR_PAIR(1));
}


