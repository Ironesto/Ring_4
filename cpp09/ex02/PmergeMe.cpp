#include "PmergeMe.hpp"

PMerge::PMerge() {}
PMerge::PMerge(const PMerge &src) { *this = src; }
PMerge &PMerge::operator=(const PMerge &src) { (void)src; return *this; }
PMerge::~PMerge() {}

template <typename T>
static void Order(T left, T right, T &src)
{
	size_t i = 0;
	size_t r = 0;
	size_t l = 0;
	while (l < left.size() && r < right.size())
	{
		if (left[l] < right[r])
		{
			src[i] = left[l];
			l++;
		}
		else
		{
			src[i] = right[r];
			r++;
		}
		i++;
	}
	while (l < left.size())
	{
		src[i] = left[l];
		i++;
		l++;
	}
	while (r < right.size())
	{
		src[i] = right[r];
		i++;
		r++;
	}
}

template <typename T>
static void Split(T &src)
{
	if (src.size() < 2)
		return ;
	T left;
	T right;
	for (size_t i = 0; i < src.size(); i++)
	{
		if (i < src.size() / 2)
			left.push_back(src[i]);
		else
			right.push_back(src[i]);
	}
	Split(left);
	Split(right);
	Order(left, right, src);
}

static void AllIsFine(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string temp(argv[i]);
		if (temp.find_first_not_of("0123456789") != std::string::npos)
			throw std::string("Error: invalid argument");
	}
}


void PMerge::DoThings(int argc, char **argv)
{

	AllIsFine(argc, argv);
	std::vector<int> vec;
	std::deque<int> deq;
	clock_t tvec;
	clock_t tdeq;
	for (int i = 1; i < argc; i++)
	{
		vec.push_back(atoi(argv[i]));
		deq.push_back(atoi(argv[i]));
	}

	std::cout << "before:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout  << " " << vec[i];
	std::cout << std::endl;

	tvec = clock();
	Split(vec);
	tvec = clock() - tvec;
	tdeq = clock();
	Split(deq);
	tdeq = clock() - tdeq;

	std::cout << "after:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout  << " " << vec[i];
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc << " elements with std::vector : " 
			<< static_cast<double>(tvec) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
	std::cout << "Time to process a range of " << argc << " elements with std::deque  : " 
			<< static_cast<double>(tdeq) / CLOCKS_PER_SEC * 1e6 << " us" << std::endl;
}
