int CounterInstructionType::load = 0;
int CounterInstructionType::store = 0;
int CounterInstructionType::integer = 0;
int CounterInstructionType::branch = 0;
int CounterInstructionType::floatPoints = 0;
std::map<std::string, int> CounterInstructionType::counter;

void CounterInstructionType::add(char * inst)
{
	if(counter.find(inst) == counter.end())
	{
	    counter[inst] = 0;
	}
	
	counter[inst] += 1;
	return;
}

void CounterInstructionType::print()
{
	int a = 0;
	printf("\nInstruções executadas: \n");
	for (std::map<std::string,int>::iterator it = counter.begin(); it != counter.end(); ++it){
		std::cout << it->first << " => " << it->second << '\n';
		a += it->second;
	}
	printf("Total: %d\n", a);
}