#ifndef __NSCREEN_H_INCLUDED__
#define __NSCREEN_H_INCLUDED__

#define MAXCHAR 256


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <typeinfo>
#include "nwindow.h"
extern "C"
{
   #include <ncurses.h>
}

using namespace std;


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
    void print_color(string str, COLOR c);

    //template<typename T, typename U>void move(T y, U x);
    void clear();
    template<typename T,typename U> void move(T y, U x){
      nwindows[0].move(y,x);
    }
};

#endif
