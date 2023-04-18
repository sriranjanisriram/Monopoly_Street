#include<iostream>

#include "player.cpp"
#include "street.cpp"

int main(){

    player player_1("sriranjani");
    player player_2("sriram");
    
    
    std::cout<<"Name of player 1: "<<player_1.get_name()<<std::endl;
    std::cout<<"Name of player 2: "<<player_2.get_name()<<std::endl;
    std::cout<<std::endl;

    street street_1("chennai", 360, 50, 4, 50, 1, 100, 181, "green", 3);
    std::cout<<"Name of first street is "<<street_1.get_street_name()<<std::endl;
    std::cout<<"Color of first street is "<<street_1.get_street_color()<<std::endl;
    std::cout<<std::endl;

    std::cout<< "is " << street_1.get_street_name() << " owned? : "<< std::boolalpha<<street_1.owned()<<std::endl;
    std::cout<<street_1.get_street_name()<<" is owned by: "<<street_1.get_owner_name()<<std::endl;
    std::cout<<std::endl;

    street_1.change_owner(&player_1);
    std::cout<<"Now "<<street_1.get_street_name()<<" is owned by: "<<street_1.get_owner_name()<<std::endl;
    std::cout<<std::endl;

    street_1.change_owner(&player_2);
    std::cout<<"Now "<<street_1.get_street_name()<<" is owned by: "<<street_1.get_owner_name()<<std::endl;
    std::cout<<std::endl;

    std::cout<< "is " << street_1.get_street_name() << " mortgaged? : "<< std::boolalpha<<street_1.is_mortgaged()<<std::endl;

    street_1.mortgage_street();
    std::cout<< "is " << street_1.get_street_name() << " mortgaged? : "<< std::boolalpha<<street_1.is_mortgaged()<<std::endl;
    std::cout<<"mortgate return value of "<<street_1.get_street_name()<<" is "<<street_1.get_morgate_return_value()<<std::endl;

    return 0;
}