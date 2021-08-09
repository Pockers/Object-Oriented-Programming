#include <iostream>
#include <gtkmm.h>
#include "main_window.h"


int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.main");
	Main_window win;
	win.set_title("Parks Mall JAVA");
	return app->run(win);
	/*Donut donut("Testing", 2.20, 3.20, Frosting::CHOCOLATE_TOP, true, Filling::BAVARIAN);
	std::cout << donut.to_string() << std::endl;
	Java java("Blah", 2.20, 3.30, 2);
	java.add_shots(Shot::VANILLA);
	java.add_shots(Shot::CHOCOLATE);
	std::cout << java.to_string() << std::endl;
	
	Store store("Parks Mall JAVA");*/
}
