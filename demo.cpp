#include <iostream>
#include "nwindow.h"
#include <unistd.h>
#include <math.h>
using namespace std;

#define TIME 200000

int main(){
	COLOR c = red;
	Nscreen* nscreen = new Nscreen();
	ifstream file("ascii_art.txt");
    nscreen->print_color(file,red);
    file.close();
    int i = 50;
    for( ; ; ){
        double y = 2*sin(i) + 10;
        usleep(TIME);
        nscreen->move(y,i++);
	    ifstream b("ascii_art.txt");
        nscreen->print_color(b,red);
        b.close();
        nscreen->clear();

    }
}
