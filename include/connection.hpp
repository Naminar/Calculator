
#include <iostream>
#include <string>
#include "program.hpp"

#define RP 100
#define RR 101

#define CP 78
#define P 1
#define F 2
#define ON_OFF_BUTTON 102
#define END_OF_PROGRAM 78
#define BEGIN_SUBPROGRAM 68
#define END_SUBPROGRAM 48

#define START_EXE_PROGRAM 78
#define RESET_INDEX_OF_PROGRAM 48

#define CX 76
#define NUMBER_OF_REGISTERS 8

struct Data
{
    //std::string screen_tablo = "0";
    std::string tablo;
    
    std::string proga[36];

    std::string registers[7];

    std::string ball[7];

    std::string program_memory[36];
};

class Connection
{
    int button_hash   = 0;
    bool mode_pressed = false;
    bool num_button_flag = false; // the last tap was number button
    bool comma_button_flag = false;

    bool mode_enter_progarm = false;
    bool mode_program_execution = false;
    //int (**called_function)(struct memory) = nullptr;

    public:

    Memory<double> mem;

    Program program_mem;

    public:

    Data screen_data;

    void get_button_num(int button_index);

    void command_handler(void);

    void create_tablo_information(bool str_here = false, std::string error_line = "0");

    void add_program_handler(void);

    private:

    std::string create_tablo_string(void);

    void program_execution_handler(void);

    void reset_all_flags(void);
};

