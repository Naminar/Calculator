
#include <iostream>
#include <string>
#include "memory.hpp"

struct Data
{
    //std::string screen_tablo = "0";

    std::string proga[36];

    std::string registers[8];

    std::string ball[8];

    std::string program_memory[36];
};

class Connection
{
    int button_hash   = 0;
    bool mode_pressed = false;
    bool num_button_flag = false; // the last tap was number button
    bool comma_button_flag = false;
    //int (**called_function)(struct memory) = nullptr;

    public:

    Memory<double> mem;

    public:

    Data screen_data;

    void get_button_num(int button_index);

    void command_hendler(int programm_index);

    void create_tablo_information(void);
};

