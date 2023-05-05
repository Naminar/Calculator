#include "program.hpp"

void Program::add(unsigned char code)  // запись кода в массив
{ 
		program_memory[position] = code; 
		position++;
}

unsigned char Program::operator[](int pos)  // it = prog[13];
{
	return program_memory[pos];
}

void Program::set_position(int pos)
{
	position = pos;
}

void Program::fin_subprogram()
{
	position = 0;
}

void Program::fin_program() {  }

void Program::next_cell()  // подвинуть на один вперед
{
	position++;
}

void Program::previous_cell()  // подвинуть на один назад
{
	position--;
}

void Program::clear()  // обнулить массив
{
	for(int i = 0; i < 36; i++) program_memory[i] = 0;
}

unsigned int Program::get_position()
{
	return position;
}

int Program::address(int hex)
{
	// пересчитываем шестиричный адрес в десятичный
	// -1 возвращается, если адреса не существует
	if (hex % 10 > 6)
	{
		return -1;
	}
	return (hex / 10) + (hex % 10) - 1;
};

int Program::condition(auto x_register_ptr)
{
	std::cout << "Condition" << std::endl;
	int jump;
	jump = address(program_memory[position + 1]);
	switch ( program_memory[position] / 10)
	{
		case 4:
		{
			std::cout << "case 49: >= 0" << std::endl;
			if (*x_register_ptr >= 0)
			{
				std::cout << "condition 49 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 49 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 5:
		{
			std::cout << "case 59: = 0" << std::endl;
			if (*x_register_ptr >= -precision && *x_register_ptr <= precision)
			{
				std::cout << "condition 59 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 59 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 6:
		{
			std::cout << "case 69: < 0" << std::endl;
			if (*x_register_ptr < 0)
			{
				std::cout << "condition 69 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 69 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		case 7:
		{
			std::cout << "case 79: != 0" << std::endl;
			if (*x_register_ptr >= precision || *x_register_ptr <= -precision)
			{
				std::cout << "condition 79 met" << std::endl;
				position += 2;
				break;
			}
			std::cout << "condition 79 is not met, jumping" << std::endl;
			if (jump != -1)
			{
				position = jump;
				return 0;
			}
			return -1;
		}
		default:
		{
			std::cout << "This is not a condition" << std::endl;
			return -2;
			break;
		}
	}
};