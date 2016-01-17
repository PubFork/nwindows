#ifndef __NWINDOW_H_INCLUDED__
#define __NWINDOW_H_INCLUDED__

#define MAXCHAR 256

class Nwindow;
class Nscreen;

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <typeinfo>

extern "C"
{
   #include <ncurses.h>
}

using namespace std;

enum COLOR{red, white, blue};

class Nscreen{
	int MAX_X,MAX_Y, numwindows;
  SCREEN* scrptr;
  vector<Nwindow> nwindows;
	public:

		Nscreen();
    ~Nscreen();
    void init_windows();
		void switch_window(int numwin);
    void print_color(ifstream& file, COLOR c);
    void move(int y, int x);
    void clear();

};


class Nwindow{
	int pos_x, pos_y, MAX_X = 0;
	int prev_x,prev_y, MAX_Y =0 ;
  WINDOW* winptr;

    public:
       
       Nwindow();
       Nwindow(int len_y, int len_x, int x, int y);

       template<typename T>void move(T y, T x);
       template<typename T>void move_over(T x, T y);

       template<typename T> void print_color(T x, COLOR c ) {
           cout <<"Variable " <<typeid(T).name() << " is not supported" << endl;
       }
       void print_color(ifstream& file, COLOR c);
       void print_color(string str, COLOR c);
       void print_color(double* da, COLOR c, int startp);
       void clear();

    private: 
    	 
       void print_line(string line, COLOR c);
       void initialize_colors();
       void reset_color();
       void set_color(COLOR c);
       int get_start(string str);
       int get_end(string str);

        
};

#endif
 
