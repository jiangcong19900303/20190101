#include "ThroughDice.h"

int main()
{
	
	ThroughDicing my_dice(1, 2, 3, 4, 5, 6);
	string s = "ǰ �� ǰ ǰ ǰ �� ǰ �� �� �� �� �� �� �� ��";		
	char delim = ' ';
	my_dice.ReadThroughAction(s, delim);
	my_dice.Through();
	my_dice.print_result();
	
	return 0;

}