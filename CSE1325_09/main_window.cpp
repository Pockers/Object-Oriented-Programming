#include "main_window.h"

Main_window::Main_window() {
	
	set_default_size(400,200);
	Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0));
	add(*vbox);
	
	//Menu
	Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
	vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
	
	//File
	Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
	menubar->append(*menuitem_file);
	Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
	menuitem_file->set_submenu(*filemenu);
	
	//Quit -- File
	Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
	menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_quit_click));
	filemenu->append(*menuitem_quit);
	
	//View
	Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
	menubar->append(*menuitem_view);
	Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
	menuitem_view->set_submenu(*viewmenu);
	
	//All Products -- View
	Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
	menuitem_all_products->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_view_all_click));
	viewmenu->append(*menuitem_all_products);
	
	//Create
	Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
	menubar->append(*menuitem_create);
	Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
	menuitem_create->set_submenu(*createmenu);
	
	//Coffee -- Create
	Gtk::MenuItem *menuitem_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
	menuitem_coffee->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_coffee_click));
	createmenu->append(*menuitem_coffee);
	
	//Donut -- Create
	Gtk::MenuItem *menuitem_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
	menuitem_donut->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_create_donut_click));
	createmenu->append(*menuitem_donut);
	
	vbox->show_all();
}

Main_window::~Main_window() {}

void Main_window::on_quit_click()
{
	hide();
}

void Main_window::on_view_all_click()
{
	//store.all_products();
}

void Main_window::on_create_coffee_click()
{
	
}

void Main_window::on_create_donut_click()
{

}
