#include <iostream>
#include "nscreen.h"
#include <unistd.h>
#include <math.h>
using namespace std;

#define TIME 200000

int main(){
	Nscreen* nscreen = new Nscreen();
    string str = "Hope your doing Whale!";
    int i = 50;
    for( ; ; ){
        double y = 2*sin(i) + 10;
        usleep(TIME);
        nscreen->move(y,i++);
	    ifstream b("whale.txt");
        nscreen->print_color(b,blue);
        b.close();
        nscreen->move(5,50);
        nscreen->print_color(str,blue);
        nscreen->clear();

    }
}
