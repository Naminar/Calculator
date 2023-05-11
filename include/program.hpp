#include <iostream>
#include <unistd.h>

// template<typename T = double>
#define precision 0.00001

class Program
{
	unsigned int position = 0;
	int address(int hex);

public:
	unsigned char program_memory[36] = {};
	void add(unsigned char code); // запись кода в массив
	unsigned char operator[](int pos); // it = prog[13];
	void set_position(int pos);
	void fin_subprogram();
	void fin_program();
	void next_cell(); // подвинуть на один вперед
	void previous_cell(); // подвинуть на один назад
	int condition(double *x_register_ptr); // условные переходы
	void clear(); // обнулить массив
	unsigned int get_position();
	
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
	};
	*/	
};

//class Iterator: protected Program
