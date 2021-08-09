#include "java.h"
#include <iostream>
#include <string>

Java::Java(std::string name, double price, double cost, int darkness)
	: Product::Product(name, price, cost), _darkness{darkness} {}

std::string Java::to_string() const
{
    //std::string convertedShot = Donut::convert_shot(_shots[0]);
    std::string javaString;
    std::string totalShots;
   
    for(int i=0; i<_shots.size(); i++)
    {
    	totalShots += Java::convert_shot(_shots[i]) + " ";
    }
    
    //Switch statement for darkness
    std::string darknessString;
    switch(_darkness)
    {
    	case 1 : {darknessString = "Blonde"; break;}
    	case 2 : {darknessString = "Dark Blonde"; break;}
    	case 3 : {darknessString = "Medium"; break;}
    	case 4 : {darknessString = "Dark"; break;}
    	case 5 : {darknessString = "Extra Dark"; break;}
    	default : {darknessString = "Blonde"; break;}
    	    	
    }
    javaString = totalShots + "shots and " + darknessString + " Darkness Java.";
    //Product::_name = javaString;
    return javaString;
}

std::string Java::convert_shot(Shot s) const
{
    std::map<Shot, std::string> s_to_str =
    {
        {Shot::NONE, "None"},
        {Shot::CHOCOLATE, "Chocolate"},
        {Shot::VANILLA, "Vanilla"},
        {Shot::PEPPERMINT, "Peppermint"},
        {Shot::HAZELNUT, "Hazelnut"},
    };
    return s_to_str[s];
}

void Java::add_shots(Shot s)
{
	_shots.push_back(s);
}
