#include <iostream>
#include "nscreen.h"
#include <unistd.h>
#include <math.h>
using namespace std;
#define TIME 200000

int main(){
	Nscreen* nscreen = new Nscreen(2);
    string str = "Hope your doing Whale!";
    string str1 = "win 1";
    string str2 = "win 2";

    int i = 50;
   // Animation test
    for( ; ; ){
        double y = 2*sin(i) + 10;
        usleep(TIME);
        nscreen->move(y,i++);
        ifstream b("ascii/whale.txt");
        nscreen->print(b,blue);
        b.close();
        nscreen->move(5,50);
        nscreen->print(str,blue);
        nscreen->clear();

    }
/*    ifstream sq("ascii/square.txt");
    nscreen->print(sq,blue);
    sq.close();
    nscreen->next_win();
    nscreen->print(str2,blue);
    for (;;){}
*/
}
