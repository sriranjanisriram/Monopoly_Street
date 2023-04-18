#include <string>

/*
player class to define each player.
currently player class contains only the player name. 
*/

class player{
    std::string player_name;
    public:
        player(std::string name)
        {
            player_name = name;
        }

        std::string get_name()
        {
            return player_name;
        }
};