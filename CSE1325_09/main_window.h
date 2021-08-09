#ifndef MAIN_WINDOW_H_INCLUDED
#define MAIN_WINDOW_H_INCLUDED
#include <gtkmm.h>
#include "store.h"

class Main_window : public Gtk::Window
{
	public:
		Main_window();
		virtual ~Main_window();
	protected:
		void on_quit_click();
		void on_view_all_click();
		void on_create_coffee_click();
		void on_create_donut_click();
	private:
		Store store();
		Gtk::Label *msg; //
};

#endif
