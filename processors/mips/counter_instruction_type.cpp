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