#ifndef TESTE
#define TESTE
#include <iostream>
#include <map>
class CounterInstructionType
{
	public:
		static std::map< std::string, int > counter;
		static int load;
		static int store;
		static int integer;
		static int branch;
		static int floatPoints;

		CounterInstructionType()
		{
			
		}

		static void add(char* inst);


		static void print();
		
};

#endif