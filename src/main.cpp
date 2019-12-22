#include <iostream>

#include "../include/player.h"
#include "../include/window.h"
using namespace std;

GLFWwindow* main_window;

int main()
{
	player p;
	window w(main_window);

	do
	{
		w.clear();
		w.swap();
	} while (w.esc() == false);

	p.do_something();
	cout << "hello!" << endl;

	w.terminate();

	return 0;
}