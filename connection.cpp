
#include <iostream>
#include <string>
#include "memory.hpp"

struct Data
{
    //std::string screen_tablo = "0";

    std::string proga[36];

    std::string registers[8];

    std::string ball[8];
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



void Connection::command_hendler(int programm_index)
{
    /*std::cout << programm_index << std::endl;

    create_tablo_information();*/

    if ( button_hash % 10 == 1 )
    {
        // command 'p'to registers

        mem.storeRegister( button_hash / 10);

        num_button_flag = false;
    }
    else if ( button_hash % 10 == 2 )
    {
        // command 'f' to x from registers

        mem.loadRegister( button_hash / 10);

        num_button_flag = false;
    }
    else if ( button_hash % 10 == 3 )
    {
        switch ( button_hash / 10)
        {
            case 0:
                create_tablo_information();//  e^ix
                break;

            case 1:
                create_tablo_information();//  ln
                break;

            case 2:
                create_tablo_information(); //pi
                break;

            case 3:
                 create_tablo_information(); // e^x
                break;

            case 4:
                create_tablo_information();
                break;

            case 5:
                create_tablo_information();
                break;

            case 6:
                create_tablo_information();
                break;

            case 7:
                create_tablo_information();
                break;

            case 8:
                create_tablo_information(); // cos
                break;

            case 9:
                create_tablo_information(); // sin
                break;

            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }
        };
    }
    else if ( button_hash % 10 == 4 )
    {
        //mem.roundStack[0] = mem.roundStack[0] * 10 + button_hash / 10;

        //screen_data.screen_tablo = mem.roundStack[0];

        num_button_flag = true;

        mem.storeDigit( button_hash / 10, comma_button_flag);

        //comma_button_flag

        create_tablo_information();
    }
    else if ( button_hash % 10 == 5 )
    {
        num_button_flag = false;

        switch ( button_hash / 10)
        {
            case 0:
                create_tablo_information();//  from x to y
                break;

            case 1:
                create_tablo_information();//  change x and y
                break;

            case 2:
                create_tablo_information();
                break;

            case 3:
                 create_tablo_information();
                break;

            case 4:
                create_tablo_information();// 1/x
                break;

            case 5:
                create_tablo_information();// x^2
                break;

            case 6:
                create_tablo_information();// sqrt
                break;

            case 7:
                create_tablo_information();
                break;

            case 8:
                create_tablo_information();
                break;

            case 9:
                create_tablo_information();
                break;

            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }
        };
    }
    else if ( button_hash % 10 == 6)
    {
        num_button_flag = false;

        switch ( button_hash / 10)
        {
            case 0:
                mem.xyChange();//  from x to y
                break;

            case 1:
                create_tablo_information();//  change x and y
                break;

            case 2:
                mem.dot();
                break;

            case 3:
                 mem.divide();
                break;

            case 4:
                create_tablo_information();// comma
                comma_button_flag = true;
                break;

            case 5:
                mem.opposite();
                break;

            case 6:
                create_tablo_information();// BÏ
                break;

            case 7:
                create_tablo_information();// RESET - CX
                break;

            case 8:
                mem.minus();
                break;

            case 9:
                mem.plus();
                break;

            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }
        };
    }

}

void Connection::create_tablo_information(void)
{
    //mem.roundStack[0];
    //mem.registers[0];

    //std::cout << std::to_string( mem.roundStack[0]) << std::endl;

    //screen_data.screen_tablo = to_string( mem.roundStack[0]);

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        screen_data.ball[ind] = std::to_string( mem.roundStack[ind]);

        screen_data.registers[ind] = std::to_string( mem.registers[ind]);
    }

    std::cout << "--------registers--------" << std::endl;

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        std::cout << screen_data.registers[ind] << std::endl;

    }

    std::cout << "--------ball--------" << std::endl;

    for ( size_t ind = 0; ind < 7; ind++ )
    {
        std::cout << screen_data.ball[ind] << std::endl;

    }
}

void Connection::get_button_num(int button_index)
{
    if (button_index == 'P'
        ||
        button_index == 'F'
       )
    {
        //button_hash = button_index;

        if ( button_index == 'P' )
            button_hash = 1;
        else
            button_hash = 2;

        mode_pressed = true;
    }
    else
    {
        // hendler of P and F mode
        if ( mode_pressed == true )
        {

            if ( button_index % 10 == 4 )
            {
                if ( button_hash == 1)
                    button_hash = button_index - 3;
                else if ( button_hash == 2 )
                    button_hash = button_index - 2;
            }
            else if ( button_index % 10 == 6 )
            {
                if ( button_index == 76)
                {
                    button_hash = 76;
                }
                else if ( button_hash == 1)
                    button_hash = button_index - 3;
                else if ( button_hash == 2 )
                    button_hash = button_index - 1;
                // ERROR HERE WHAT WE NEED TO DO
                //else if ( button_index == 76)

            }
            else if ( button_index % 10 == 8)
            {
                if ( button_hash == 1)
                    button_hash += button_index;
                else if ( button_hash == 2 )
                    button_hash = button_index - 1;
            }
            // reset mode pressed button

            mode_pressed = false;
        }
        else
        {
            button_hash = button_index;
        }

       command_hendler(button_hash);
    }
}

int main()
{
    Connection x;

    x.get_button_num('F');
    x.get_button_num(48);

    x.get_button_num('P');
    x.get_button_num(48);

    x.get_button_num('F');
    x.get_button_num(46);

    x.get_button_num('P');
    x.get_button_num(46);

    x.get_button_num(76);

    x.get_button_num(34);
    x.get_button_num(64);
    x.get_button_num(46);
    x.get_button_num(34);


    //std::cout << "tablo information " << x.screen_data.screen_tablo << std::endl;

    //x.mem.Dump();

    return 0;
}
