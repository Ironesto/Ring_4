#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <iomanip>

class PMerge {
	public:
		static void DoThings(int argc, char **argv);

	private:
		PMerge();
		PMerge(const PMerge &src);
		PMerge &operator=(const PMerge &src);
		~PMerge();
};


