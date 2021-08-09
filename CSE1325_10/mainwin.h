#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include <regex>
#include "store.h"
#include "java.h"

class Mainwin : public Gtk::Window
{
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();            // Exit the program
        void on_view_all_click();        // View all products
        void on_create_coffee_click();   // Create a new coffee product
        void on_create_donut_click();    // Create a new donut product
        //S P R I NT 2
        void on_new_customer_click();
        void on_list_customers_click();
        //void on_shots_click();
        void on_about_click();
    private:
        Store _store;
        Gtk::Label *msg;                      // Status message display
        Gtk::MenuItem *menuitem_new_coffee;   // Create -> Coffee
        Gtk::MenuItem *menuitem_new_donut;    // Create -> Donut
};
#endif 

