#include <iostream>
#include <unistd.h>
#include "memory.hpp"

// template<typename T = double>

class Program
{
	unsigned int position = 0;

public:
	unsigned char program_memory[36] = {};
	void add(unsigned char code) { 
		program_memory[position] = code; 
		position++;
	} // запись кода в массив
	unsigned char operator[](int pos) { return program_memory[pos]; } // it = prog[13];
	void set_position(int pos) { position = pos; }
	void fin_subprogram() { position = 0; }
	void fin_program() {  }
	void next_cell() { position++; } // подвинуть на один вперед
	void previous_cell() { position--; } // подвинуть на один назад
	void condition(auto x_register_ptr); // условные переходы
	/*
	class Iterator
	{
		unsigned int position;
		public:
		Iterator();

		Iterator& operator=(unsigned char*); // it = prog.begin();
		Iterator& operator++(int); // подвинуть вправо
		Iterator& operator--(int); // подвинуть влево
		unsigned char operator*(); // позиция итератора
		int take(unsigned char*); // если итератор проходится по массиву в режиме RUN
	
		void place(unsigned char);
		unsigned char read();
		void move_right();
		void move_left();
	}; */	
};

//class Iterator: protected Program

void Program::condition(auto x_register_ptr)
{
	switch ( program_memory[position] / 10)
	{
		case 4:
		{
			if (*x_register_ptr >= 0)
			{
				position += 2;
				break;
			}
			position = program_memory[position + 1];
			break;
		}
		case 5:
		{
			if (*x_register_ptr == 0)
			{
				position += 2;
				break;
			}
			position = program_memory[position + 1];
			break;
		}
		case 6:
		{
			if (*x_register_ptr < 0)
			{
				position += 2;
				break;
			}
			position = program_memory[position + 1];
			break;
		}
		case 7:
		{
			if (*x_register_ptr != 0)
			{
				position += 2;
				break;
			}
			position = program_memory[position + 1];
			break;
		}
		default:
		{
			std::cout << "This is not a condition" << std::endl;
			break;
		}
	}
}
