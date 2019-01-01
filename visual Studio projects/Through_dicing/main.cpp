#include "ThroughDice.h"

int main()
{
	
	ThroughDicing my_dice(1, 2, 3, 4, 5, 6);
	string s = "前 后 前 前 前 左 前 右 左 后 左 右 左 右 左";		
	char delim = ' ';
	my_dice.ReadThroughAction(s, delim);
	my_dice.Through();
	my_dice.print_result();
	
	return 0;

}