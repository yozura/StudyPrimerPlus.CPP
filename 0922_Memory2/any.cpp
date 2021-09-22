#include <iostream>
#include "golf.h"

void examm()
{
	golf golfs[5];

	for (int i = 0; i < 5; i++)
	{
		if (setgolf(golfs[i]) != 1)
			break;
	}

	for (int i = 0; i < 5; i++)
		showgolf(golfs[i]);

	handicap(golfs[0], 999);
	handicap(golfs[3], 123);

	for (int i = 0; i < 5; i++)
		showgolf(golfs[i]);
}