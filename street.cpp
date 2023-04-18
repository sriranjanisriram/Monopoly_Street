/*

This file defines multiple classes used to create a street in monopoly.
I assumed that the player class is deifned in the main and called before this file.


*/


// This class defines all the common parameters for business transactions.
class intrestRates{

    public:
        // percentage values to be used for trasitions.
        int mortgate_intrest = 15;
        int sale_loss = 50;

};


/* 
This class acts as a parent class for class street.
This class deifnes all the properties which are triggered based on color grouping in monopoly
*/

class street_group{
    
    public:
        std::string color;
        int num_of_street_in_group;
        bool own_all_street = false;
        bool equal_house_in_all_street = false;

        street_group(std::string color, int num_of_street_in_group): color(color), num_of_street_in_group(num_of_street_in_group){}

};


/* 
This class acts as another parent class for class street.
This class deifnes all the properties that are to be used for transitions in monopoly
*/

class street_ownership: public intrestRates{
    
    private:
        bool mortgaged = false;
    protected:
        player* street_owner = NULL; // "player" is the player class that defines all the player properties

    public:

        bool owned() // a function to check the wheather the property is owned by a player
        {   
            if(street_owner) return true;
            else return false;
        }
        bool is_mortgaged() // a function to check the wheather the property is mortgaged
        {
            return mortgaged;
        }

        void mortgage_street() // a function that mortgages a street
        {
            if(!mortgaged)
            {
                mortgaged = true;
            }
        }

        std::string get_owner_name() // a function that returns the current owner name.
        {   
            std::string owner_name = "notOwned";
            if(street_owner)
            {
                owner_name = street_owner->get_name();
            }
            return owner_name;

        }
        
        virtual void change_owner(player* new_player){return;}; // virtual function for changing owner name.
        virtual float get_morgate_return_value(){return 0.0;}; // virtual function for getting total morgage return value.
        
};

class street: public street_ownership, street_group {

    private:
        std::string name;
        int cost;
        int rent;
        int max_houses = 3;
        int per_house_cost;
        int max_hotels = 1;
        int per_hotel_cost;
        float mortgage_value;
    
    public:
        street(std::string name, int cost, int rent, int max_houses, int per_house_cost, int max_hotels, int per_hotel_cost, 
            float mortgage_value, std::string color, int num_of_street_in_group):
            name(name), cost(cost), rent(rent), max_houses(max_houses), per_house_cost(per_house_cost), max_hotels(max_hotels), 
            per_hotel_cost(per_hotel_cost), mortgage_value(mortgage_value), street_group(color, num_of_street_in_group){} ;
        
        std::string get_street_name() // a function that returns the street name.
        {
            return name;
        }
        std::string get_street_color() // a function that returns the street color.
        {
            return color;
        }
        int get_street_cost() // a function that returns the cost of the street.
        {
            return cost;
        }

        void change_owner(player* new_player) // a function that changes the owner of the street.
        { 
            street_owner = new_player;
        }
        
        float get_morgate_return_value() // a function that returns the total money to be paid to retun a mortgage.
        {
            return mortgage_value + mortgage_value*mortgate_intrest/100;
        }
};



