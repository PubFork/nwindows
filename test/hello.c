#include <ncurses.h>

int main()
{
        int MAX_X, MAX_Y;	
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
        getmaxyx(stdscr,MAX_Y, MAX_X);

	return 0;
}
