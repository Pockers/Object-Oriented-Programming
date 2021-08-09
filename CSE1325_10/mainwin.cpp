#include "mainwin.h"
#include "java.h"
#include "donut.h"
#include <ostream>
#include <iostream>

Mainwin::Mainwin() : _store{Store{"JADE"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_title("Java and Donut Express (JADE)");
    set_default_size(800, 600);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_quit_click));
    filemenu->append(*menuitem_quit);

    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);

    //         A L L   P R O D U C T S
    // Append All Products to the File menu
    Gtk::MenuItem *menuitem_all_products = Gtk::manage(new Gtk::MenuItem("_All Products", true));
    menuitem_all_products->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_view_all_click));
    viewmenu->append(*menuitem_all_products);

    //     C R E A T E   C O F F E E
    // Create a new coffee menu and add to the menu bar
    Gtk::MenuItem *menuitem_create = Gtk::manage(new Gtk::MenuItem("_Create", true));
    menubar->append(*menuitem_create);
    Gtk::Menu *createmenu = Gtk::manage(new Gtk::Menu());
    menuitem_create->set_submenu(*createmenu);
    
    // Create a new customer -- S P R I NT 2 
    Gtk::MenuItem *menuitem_new_customer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_new_customer->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_new_customer_click));
    createmenu->append(*menuitem_new_customer);
    
    // View all customers -- S P R I N T 2
    Gtk::MenuItem *menuitem_view_customers = Gtk::manage(new Gtk::MenuItem("_View", true));
    menuitem_view_customers->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_list_customers_click));
    createmenu->append(*menuitem_view_customers);

    //           N E W   C O F F E E
    // Append New Coffee to the Create menu
    menuitem_new_coffee = Gtk::manage(new Gtk::MenuItem("_Coffee", true));
    menuitem_new_coffee->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_coffee_click));
    createmenu->append(*menuitem_new_coffee);

    //           N E W   D O N U T
    // Append New Donut to the Create menu
    menuitem_new_donut = Gtk::manage(new Gtk::MenuItem("_Donut", true));
    menuitem_new_donut->signal_activate().connect(sigc::mem_fun(*this, &Mainwin::on_create_donut_click));
    createmenu->append(*menuitem_new_donut);

    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_view_all_click() { // View all products
   std::ostringstream oss;
   oss << _store << std::endl;
   Gtk::MessageDialog d{*this, oss.str()};
   int result = d.run();
}


void Mainwin::on_create_coffee_click() { // Create a new coffee product -- adjusted for Spring 2
   /*int darkness = rand() % DARK_LEVELS;
   double price = 5.00;
   double cost = 2.00;
   Java* c = new Java{"Coffee", price, cost, darkness};
   int shot_clock = rand() % 4; // vary the number of shots
   while (shot_clock--) {
       Shot shot = (Shot)((rand() % (shot_to_string.size()-1))+1);
       c->add_shot(shot); 
   }
   _store.add_product(c); */
   
   std::string javaName;
   double javaPrice, javaCost;
   int javaDarkness;
   
   Gtk::Dialog* dialog = new Gtk::Dialog;
   dialog->set_title("Create a Coffee");
   
   dialog->set_transient_for(*this);
   
   //Entry for Name
   Gtk::HBox _name;
   Gtk::Label *name = new Gtk::Label{"Name:"};
   name->set_width_chars(15);
   _name.pack_start(*name, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entryname = new Gtk::Entry{};
   entryname->set_max_length(50);
   entryname->show();
   _name.pack_start(*entryname, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_name, Gtk::PACK_SHRINK);
   
   //Entry for Price
   Gtk::HBox _price;
   Gtk::Label *price = new Gtk::Label{"Price:"};
   price->set_width_chars(15);
   _price.pack_start(*price, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entryprice = new Gtk::Entry{};
   entryprice->set_max_length(50);
   entryprice->show();
   _price.pack_start(*entryprice, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_price, Gtk::PACK_SHRINK);
   
   //Entry for Cost
   Gtk::HBox _cost;
   Gtk::Label *cost = new Gtk::Label{"Cost:"};
   cost->set_width_chars(15);
   _cost.pack_start(*cost, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entrycost = new Gtk::Entry{};
   entrycost->set_max_length(50);
   entrycost->show();
   _cost.pack_start(*entrycost, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_cost, Gtk::PACK_SHRINK);
   
   //Combox for Darkness
   Gtk::HBox _darkness;
   Gtk::Label *darkness = new Gtk::Label{"Darkness:"};
   darkness->set_width_chars(15);
   _darkness.pack_start(*darkness, Gtk::PACK_SHRINK);
   
   Gtk::ComboBoxText *combodarkness = new Gtk::ComboBoxText{};
   combodarkness->set_size_request(160);
   combodarkness->append("Blonde");
   combodarkness->append("Dark Blonde");
   combodarkness->append("Medium");
   combodarkness->append("Dark");
   combodarkness->append("Extra Dark");
   _darkness.pack_start(*combodarkness, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_darkness, Gtk::PACK_SHRINK);
   
   dialog->add_button("Next",1);
   dialog->add_button("Cancel",0);
   dialog->show_all();
   int result = dialog->run();
   dialog->close();
   while (Gtk::Main::events_pending()) Gtk::Main::iteration();
   
   javaName = entryname->get_text();
   javaPrice = std::stoi(entryprice->get_text());
   javaCost = std::stoi(entrycost->get_text());
   javaDarkness = combodarkness->get_active_row_number();
   
   // M O V E T O S H O T S
   if (result == 1) {
   		Java* c = new Java{javaName,javaPrice,javaCost,javaDarkness};
   		//_store.add_product(c);
   		
   		bool continueShots = true;
   		int javaShots;
   		
   		//Test code below
   		while(continueShots) {
   		Gtk::Dialog* dialog = new Gtk::Dialog;
		dialog->set_title("Add a Shot");
		dialog->set_transient_for(*this);
	
		Gtk::ComboBoxText *comboshots = new Gtk::ComboBoxText{};
		comboshots->set_size_request(160);
		comboshots->append("None");
		comboshots->append("Chocolate");
		comboshots->append("Vanilla");
		comboshots->append("Peppermint");
		comboshots->append("Hazelnut");
	
		//comboshots->pack_start(*comboshots, Gtk::PACK_SHRINK);
		dialog->get_vbox()->pack_start(*comboshots, Gtk::PACK_SHRINK);
	
   		dialog->add_button("Cancel",0);
   		dialog->add_button("Create",1);
   		dialog->add_button("Add",2);
   		dialog->show_all();
   		int result = dialog->run();
   
        dialog->close();
   		while (Gtk::Main::events_pending()) Gtk::Main::iteration();
   
   		javaShots = comboshots->get_active_row_number();
   		if (result == 1)
   		{
   			c->add_shot((Shot)javaShots);
   			continueShots = false;
   			break;
   		}
   		if (result == 2)
   		{
   			c->add_shot((Shot)javaShots);
   			continueShots = true;
   		}
   		if (result == 0)
   		{
   			break;
   		}
   		}
   		
   		_store.add_product(c);
   } 
   
   delete entryname;
   delete entryprice;
   delete entrycost;
   delete combodarkness;
   delete dialog;
}


void Mainwin::on_create_donut_click() { // Create a new donut product
   /*Frosting frosting = (Frosting)(rand()%frosting_to_string.size());
   Filling filling = (Filling)(rand()%filling_to_string.size());
   Donut* d = new Donut{"Donut", 0.75, 0.25, frosting, true, filling};
   _store.add_product(d); */
   std::string donutName;
   double donutCost, donutPrice;
   int donutFrosting, donutFilling;
   bool donutSprinkles;
   
   Gtk::Dialog* dialog = new Gtk::Dialog;
   dialog->set_title("Create a Donut");
   
   dialog->set_transient_for(*this);
   
   //Entry for donut name
   Gtk::HBox _name;
   Gtk::Label *name = new Gtk::Label{"Name:"};
   name->set_width_chars(15);
   _name.pack_start(*name, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entryname = new Gtk::Entry{};
   entryname->set_max_length(50);
   entryname->show();
   _name.pack_start(*entryname, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_name, Gtk::PACK_SHRINK);
   
   //Entry for donut Price
   Gtk::HBox _price;
   Gtk::Label *price = new Gtk::Label{"Price:"};
   price->set_width_chars(15);
   _price.pack_start(*price, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entryprice = new Gtk::Entry{};
   entryprice->set_max_length(50);
   entryprice->show();
   _price.pack_start(*entryprice, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_price, Gtk::PACK_SHRINK);
   
   //Entry for donut Cost
   Gtk::HBox _cost;
   Gtk::Label *cost = new Gtk::Label{"Cost:"};
   cost->set_width_chars(15);
   _cost.pack_start(*cost, Gtk::PACK_SHRINK);
   
   Gtk::Entry *entrycost = new Gtk::Entry{};
   entrycost->set_max_length(50);
   entrycost->show();
   _cost.pack_start(*entrycost, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_cost, Gtk::PACK_SHRINK);
   
   //Dropdown for Frosting
   Gtk::HBox _frosting;
   Gtk::Label *frosting = new Gtk::Label{"Frosting:"};
   frosting->set_width_chars(15);
   _frosting.pack_start(*frosting, Gtk::PACK_SHRINK);
   
   Gtk::ComboBoxText *combofrosting = new Gtk::ComboBoxText{};
   combofrosting->set_size_request(160);
   combofrosting->append("Unfrosted");
   combofrosting->append("Chocolate");
   combofrosting->append("Vanilla");
   combofrosting->append("Pink");
   //combofrosting->pack_start(*combofrosting, Gtk::PACK_SHRINK);
   _frosting.pack_start(*combofrosting, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_frosting, Gtk::PACK_SHRINK);
   //dialog->get_vbox()->pack_start(*combofrosting), Gtk::PACK_SHRINK;
   
   //Dropdown for Filling
   Gtk::HBox _filling;
   Gtk::Label *filling = new Gtk::Label{"Filling:"};
   filling->set_width_chars(15);
   _filling.pack_start(*filling, Gtk::PACK_SHRINK);
   
   Gtk::ComboBoxText *combofilling = new Gtk::ComboBoxText{};
   combofilling->set_size_request(160);
   combofilling->append("Unfilled");
   combofilling->append("Creme");
   combofilling->append("Bavarian");
   combofilling->append("Strawberry");
   _filling.pack_start(*combofilling, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(_filling, Gtk::PACK_SHRINK);
   
   //Bool for Sprinkles -- HELP
   Gtk::CheckButton *boolsprinkles = new Gtk::CheckButton{"Sprinkles"};
   //_sprinkles.pack_start(*boolsprinkles, Gtk::PACK_SHRINK);
   dialog->get_vbox()->pack_start(*boolsprinkles);
   
   dialog->add_button("Create",0);
   dialog->add_button("Cancel",1);
   dialog->show_all();
   int result = dialog->run();
   
   dialog->close();
   while (Gtk::Main::events_pending()) Gtk::Main::iteration();
   donutName = entryname->get_text();
   donutPrice = std::stoi(entryprice->get_text());
   donutCost = std::stoi(entrycost->get_text());
   donutFrosting = combofrosting->get_active_row_number();
   donutSprinkles = boolsprinkles->get_active();
   donutFilling = combofilling->get_active_row_number();
   
   if (result ==0) {
   _store.add_product(new Donut{donutName,donutPrice,donutCost,(Frosting)donutFrosting,donutSprinkles,(Filling)donutFilling});
   }
   
   delete entryname;
   delete entryprice;
   delete entrycost;
   delete combofrosting;
   delete boolsprinkles;
   delete dialog;
}

//S P R I N T 2
void Mainwin::on_new_customer_click() { // Create a new customer
	Gtk::Dialog* dialog = new Gtk::Dialog;
	dialog->set_title("Create a Customer");
	
	dialog->set_transient_for(*this);
	
	//Entry for Customer name
	Gtk::Entry *entry1 = new Gtk::Entry{};
	entry1->set_max_length(50);
	entry1->show();
	dialog->get_vbox()->pack_start(*entry1);
	
	//Entry for Customer number
	Gtk::Entry *entry2 = new Gtk::Entry{};
	entry2->set_max_length(50);
	entry2->show();
	dialog->get_vbox()->pack_start(*entry2);
	
	//Dialog buttons
	dialog->add_button("Cancel",0);
	dialog->add_button("OK",1);
	dialog->set_default_response(1);
	
	//int result = dialog->run();
	
	//Regex
	std::regex phone{"(\\d{3,3}-)?\\d{3,3}-\\d{4,4}"};
	//std::regex phone2{"(\\d{3,3}-)?\\d{4,4})"};
	bool fail = true;
	while (fail) {
		int result = dialog->run();
		std::string input1 = entry1->get_text();
		std::string input2 = entry2->get_text();
		
		if(result == 1 && !std::regex_match(input2,phone))
		{
			entry2->set_text("### Invalid ###");
		}
		else 
		{
			fail = false;
			_store.add_customer(new Customer{input1, input2});
		}
	}
	
	dialog->close();
	while (Gtk::Main::events_pending()) Gtk::Main::iteration();
	delete entry1;
	delete entry2;
	delete dialog;
}

void Mainwin::on_list_customers_click(){ // Show all customers

   std::ostringstream oss;
   for (int i = 0; i < _store.number_of_customers(); i++)
   {
   		oss << _store.customer_to_string(i);
   }
   Gtk::MessageDialog d{*this, oss.str()};
   int result = d.run();
}
void Mainwin::on_quit_click() {         // Exit the program
    close();
}

// /////////////////
// U T I L I T I E S
// /////////////////


