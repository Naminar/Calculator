
#include "../include/connection.hpp"


void Connection::command_handler()
{
    /*std::cout << programm_index << std::endl;

    create_tablo_information();*/

    bool error_key = false;

    std::string error_line;

    if ( button_hash % 10 != 4 && degree_flag == true )
    {
        mem.storePower( degree_hash );

        //degree_hash = 0;
        
        degree_flag = false;
    }

    if ( button_hash % 10 == 1 )
    {
        // command 'p'to registers
        // DEBUG TAG
        if ( button_hash / 10 > 0 && ( button_hash / 10 <= NUMBER_OF_REGISTERS ) )
            mem.storeRegister( button_hash / 10 - 1);

        num_button_flag = false;
        degree_flag     = false;

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 2 )
    {
        // command 'f' to x from registers
        if ( button_hash / 10 > 0 && ( button_hash / 10 <= NUMBER_OF_REGISTERS ) )
            mem.loadRegister( button_hash / 10 - 1);

        num_button_flag = false;
        degree_flag     = false;

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 3 )
    {
        degree_flag     = false;
        
        switch ( button_hash / 10)
        {
            case 0:
                mem.cosinus(); // e^ix
                break;

            case 1:
            {
                try {  mem.ln(); }// ln
                catch( ... ) { error_key = true; error_line = "ERROR"; }

                break;
            }

            case 2:
                mem.pi(); // pi
                break;

            case 3:
                 mem.expPower(); // e^x
                break;

            
            
            case 4:
                mem.leftRotate();
                break;

            case 5:
                mem.rightRotate();
                break;
            /*
            case 6:
                create_tablo_information();
                break;

            case 7:
                create_tablo_information();
                break;
            
            */

            case 8:
                mem.cosinus(); //create_tablo_information(); } // cos
                break;

            case 9:
                mem.sinus(); // sin
                break;

            /*
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }
            
            */
        };

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 4 )
    {
        //mem.roundStack[0] = mem.roundStack[0] * 10 + button_hash / 10;

        //screen_data.screen_tablo = mem.roundStack[0];

        //num_button_flag = true;
        if ( degree_flag == true )
        {
            if ( degree_hash < 10 && degree_hash >= 0 )
            {
                degree_hash *= 10;

                degree_hash += button_hash / 10;
            }
            else if ( degree_hash > -10 && degree_hash <= 0 )
            {
                degree_hash *= 10;

                degree_hash -= button_hash / 10;
            }

            // else nothing
        }
        else
        {
            if ( num_button_flag == false ) 
            {
                mem.storeDigit( 0, true);
                mem.storeDigit( 0, false);

                num_button_flag = true;
                comma_button_flag = false;
            }

            mem.storeDigit( button_hash / 10, comma_button_flag);
        }
        
        //comma_button_flag

        //create_tablo_information();
    }
    else if ( button_hash % 10 == 5 )
    {
        num_button_flag = false;
        degree_flag     = false;

        switch ( button_hash / 10)
        {
            /*
            
            case 0:
                create_tablo_information();
                break;

            case 1:
                create_tablo_information();
                break;

            case 2:
                create_tablo_information();
                break;

            case 3:
                 create_tablo_information();
                break;
            
            */

            case 4:
            {
                try { mem.reciprocal(); }
                catch( ... ) { error_key = true; error_line = "ERROR"; }//screen_data.ball[0] = "ERROR"; std::cout << screen_data.ball[0] << std::endl; } //create_tablo_information();// 1/x

                break;
            }
        
            case 5:
            {
                mem.square(); //create_tablo_information();// x^2
                
                //create_tablo_information();

                break;
            }
            case 6:
            {
                //create_tablo_information();// sqrt
                try { mem.squareRoot(); }
                catch( ... ) { error_key = true; error_line = "ERROR"; }

                //create_tablo_information();
                
                break;
            }
            /*
            
            case 7:
                create_tablo_information();
                break;

            case 8:
                create_tablo_information();
                break;

            case 9:
                create_tablo_information();
                break;
            
            */


            /*
            
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }

            */
        };
    }
    else if ( button_hash % 10 == 6 )
    {
        num_button_flag = false;
        degree_flag     = false;

        switch ( button_hash / 10)
        {
            case 0:
                mem.storeRegister(0); // from x to y
                break;

            case 1:
                mem.swapXY(); // change x and y
                break;

            case 2:
                mem.dot();
                break;

            case 3:
            {
                try { mem.divide(); }
                catch( ... ) { error_key = true; error_line = "ERROR"; }
                
                break;
            }

            case 4:
                // comma
                comma_button_flag = true;
                num_button_flag = true;
                break;

            case 5:
                mem.opposite();
                break;

            /*
            
            case 6:
                create_tablo_information();// BH
                break;

            case 7:
                create_tablo_information();// RESET - CX
                break;
            */

            case 8:
                mem.minus();
                break;

            case 9:
                mem.plus();
                break;

            /*
            
            default:
            {
                std::cout << __PRETTY_FUNCTION__ << std::endl;

                exit(3);
            }

            */
        };
    
        //create_tablo_information();
    }
    else if ( button_hash == 38 )
    {
        mem.power();
    }
    else if ( mode_program_execution == true && button_hash == RESET_INDEX_OF_PROGRAM ) //  B/O
    {
        program_mem.set_position( 0);
    }
    else if ( mode_program_execution == true && button_hash == START_EXE_PROGRAM ) // C/P
    {
        program_execution_handler();

        program_mem.set_position(0);

        reset_all_flags();
    }

    create_tablo_information(error_key, error_line);

}

void Connection::reset_all_flags()
{
    int button_hash         = 0;
    bool mode_pressed       = false;
    bool num_button_flag    = false; 
    bool comma_button_flag  = false;

    bool mode_enter_progarm = false;
    bool mode_program_execution = false;
}

void Connection::program_execution_handler()
{
    auto position_ = program_mem.get_position();

    bool exit_flag = false;
    
    while ( program_mem.program_memory[position_] != END_OF_PROGRAM 
            && 
            exit_flag == false
          )
    {
        
        //std::cout << (int) program_mem.program_memory[position_] << std::endl;
        
        switch ( program_mem.program_memory[position_] )
        {
            
            case 39:
            {
                
                program_mem.next_cell();

                break;
            }
            
            
            case 49:
            {
                if ( program_mem.condition( &(mem.roundStack[0])) < 0)
                {
                    exit_flag = true;
                };

                break;
            }

            case 59:
            {
                if ( program_mem.condition( &(mem.roundStack[0])) < 0)
                {
                    exit_flag = true;
                };
                
                break;
            }

            case 69:
            {
                if ( program_mem.condition( &(mem.roundStack[0])) < 0)
                {
                    exit_flag = true;
                };
                
                break;
            }

            case 79:
            {
                if ( program_mem.condition( &(mem.roundStack[0])) < 0)
                {
                    exit_flag = true;
                };
                
                break;
            }

            default:
            {
                button_hash = program_mem.program_memory[position_];
                
                command_handler();

                button_hash = 0;

                program_mem.next_cell();    
            }
        };

        position_ = program_mem.get_position();        
    }

    if ( exit_flag == true )
    {
        create_tablo_information( true, "ERROR");
    }
}

void Connection::add_program_handler()
{
    program_mem.add(button_hash);
}

void create_number_string(std::string& screen_string, const std::string& default_string, auto number_to_convert)
{
    Number number_representation = standard( number_to_convert);
         
    if ( number_representation.power == 0 )
        screen_string = default_string;
    else
    {
        screen_string = std::to_string( number_representation.body);

        if ( screen_string.size() > 8 )
            screen_string.resize( 8);
        
        if ( number_representation.power > 0 )
            screen_string = screen_string + " +";        
        else
            screen_string = screen_string + " -";
                                        
        screen_string = screen_string + std::to_string( number_representation.power);
    }
}

void Connection::create_tablo_information(bool str_here, std::string error_line)
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

    if ( str_here == true )
        screen_data.tablo = error_line;
    else if ( degree_flag == true )
    {
        //Number number_representation = mem.standard( mem.roundStack[0]);
        
        screen_data.tablo = screen_data.ball[0] + std::to_string( degree_hash);
    }
    else
    {
        create_number_string( screen_data.tablo, screen_data.ball[0], mem.roundStack[0]);
        
        /*
         Number number_representation = standard( mem.roundStack[0]);
         
         if ( number_representation.power == 0)
            screen_data.tablo = screen_data.ball[0];
        else
        {
            screen_data.tablo = std::to_string( number_representation.body);
            
            if ( number_representation.power > 0 )
                screen_data.tablo = screen_data.tablo + " +";        
            else
                screen_data.tablo = screen_data.tablo + " -";
                                         
            screen_data.tablo = screen_data.tablo + std::to_string( number_representation.power);
        }
        */


    }
    
    for ( size_t ind = 0; ind < 36; ind++ )
    {                    
            screen_data.program_memory[ind] = std::to_string( program_mem.program_memory[ind]);
    }

}

void Connection::get_button_num(int button_index)
{
    if (button_index == P
        ||
        button_index == F
       )
    {
        //button_hash = button_index;

        if ( button_index == P )
            button_hash = 1;
        else
            button_hash = 2;

        mode_pressed = true;
    }
    else if ( button_index == 76 )
    {
        /*reset_all_flags();

        mem.reset();
        program_mem.clear();

        program_mem.set_position( 0); */

        mem.storeDigit( 0, true);
        mem.storeDigit( 0, false);
        
        create_tablo_information();    
    }
    else if ( button_index == VP && num_button_flag == true )
    {
        button_hash = 0;

        num_button_flag = false;

        degree_flag = true;
        degree_hash = 0;
    }
    else if ( button_index == RP && mode_pressed == true )
    {
        mode_enter_progarm = true;
    //--------------------------------
        //std::cout << "enter_progrmm"<< std::endl;

    //------ all flags and hash ------
        
        button_hash = 0;

        num_button_flag = false;

        mode_pressed = false;

        comma_button_flag = false;
    }
    else if ( button_index == RR && mode_pressed == true )
    {
        mode_program_execution = true;
    //--------------------------------
        button_hash = 0;
        
        mode_pressed = false;

        comma_button_flag = false;

        num_button_flag = false;

        mode_enter_progarm = false;
    }
    else if ( mode_enter_progarm == true 
              && ( button_hash == END_OF_PROGRAM || button_hash == END_SUBPROGRAM) 
              && button_index != BEGIN_SUBPROGRAM
            )
    {
        mode_enter_progarm = false;

        button_hash = 0;

        get_button_num( button_index);
    }
    else if ( button_index == ON_OFF_BUTTON )
    {
        mode_enter_progarm = false;
        
        button_hash = 0;

        num_button_flag = false;

        mode_pressed = false;

        comma_button_flag = false;

        bool mode_program_execution = false;

        mem.reset();
        program_mem.clear();

        program_mem.set_position( 0);
        //program_mem.();
    }
    else
    {
        // handler of P and F mode
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
            else if ( button_index % 10 == 8 )
            {
                if ( button_hash == 1)
                    button_hash += button_index;
                else if ( button_hash == 2 )
                    button_hash = button_index - 1;
            }
            /*else if ( button_index == RP )
            {
                mode_enter_progarm = true;

                std::cout << "enter_progrmm"<< std::endl;

            //------ all flags and hash ------
                
                button_hash = 0;

                num_button_flag = false;

                mode_pressed = false;

                comma_button_flag = false;
            
                continue;
            }
            */
            // reset mode pressed button

            mode_pressed = false;
        }
        else
        {
            button_hash = button_index;
        }

        if ( mode_enter_progarm == true )
        {
            add_program_handler();
            
            /*
            auto position_ = program_mem.get_position() - 1;
            
            std::string prev_code_on_tablo = std::to_string( program_mem.program_memory[ position_]);

            if ( position_ > 0 && position_ < 2)
            {
                prev_code_on_tablo += " " + std::to_string( program_mem.program_memory[ position_ - 1]);
            }
            else if ( position_ > 1 )
            {
                prev_code_on_tablo += " " + std::to_string( program_mem.program_memory[ position_ - 1])
                                      +
                                      " " + std::to_string( program_mem.program_memory[ position_ - 2]);
            }
            */

            create_tablo_information( true, create_tablo_string());//prev_code_on_tablo);

            if ( button_hash == CP || button_hash == END_SUBPROGRAM ) // end of enter mode with button C/P
            {
                //std::cout << "end of program enter" << std::endl;
                
                //mode_enter_progarm = false;
                
                //button_hash = 0;

                num_button_flag = false;

                mode_pressed = false;

                comma_button_flag = false;
            }
        }
        else
            command_handler();
    }
}

std::string Connection::create_tablo_string()
{
    auto position_ = program_mem.get_position() - 1;
            
    std::string prev_code_on_tablo = std::to_string( program_mem.program_memory[ position_]);

    if ( position_ > 0 && position_ < 2)
    {
        prev_code_on_tablo += " " + std::to_string( program_mem.program_memory[ position_ - 1]);
    }
    else if ( position_ > 1 )
    {
        prev_code_on_tablo += " " + std::to_string( program_mem.program_memory[ position_ - 1])
                                +
                                " " + std::to_string( program_mem.program_memory[ position_ - 2]);
    }
    
    return prev_code_on_tablo;
}


/*/
int main()
{
    Connection x;

    x.get_button_num(F);
    x.get_button_num(48);

    x.get_button_num(P);
    x.get_button_num(48);

    x.get_button_num(F);
    x.get_button_num(46);

    x.get_button_num(P);
    x.get_button_num(46);

    x.get_button_num(76);

    x.get_button_num(34);
    x.get_button_num(64);
    x.get_button_num(46);
    x.get_button_num(34);

    x.get_button_num(P);
    x.get_button_num(86);

    x.get_button_num(16);

    x.get_button_num(P);
    x.get_button_num(RP);

    x.get_button_num(P);
    x.get_button_num(6);

    x.get_button_num(P);
    x.get_button_num(6);

    x.get_button_num(P);
    x.get_button_num(6);

    x.get_button_num(CP);

    //std::cout << "tablo information " << x.screen_data.screen_tablo << std::endl;

    //x.mem.dump();

    return 0;
}
//*/
