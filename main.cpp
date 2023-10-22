////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// vector //////////////////////////////////////////////////////////
// #include <time.h>
// #include <iostream>
// #include "vector.hpp"
// #include <vector>
// #include <fstream>
// #include <time.h>

// static void printvector(ft::vector<std::string>& v, std::ofstream& ftFile) {
// 	for (size_t i = 0; i < v.size(); i++) {
// 		ftFile << v[i] << " ";
// 	}
// 	ftFile << std::endl;
// }

// static void ft_test(std::ofstream& ftFile) {
// 	clock_t g_start = clock();

// 	ft::vector<std::string> v1;
// 	v1.push_back("the");
// 	v1.push_back("frogurt");
// 	v1.push_back("is");
// 	v1.push_back("also");
// 	v1.push_back("cursed");

// 	ftFile << "v1: ";
// 	printvector(v1, ftFile);

// 	ft::vector<std::string> v2(v1.begin(), v1.end());
// 	ftFile << "v2: ";
// 	printvector(v2, ftFile);

// 	ft::vector<std::string> v3(v2);
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);


// 	ftFile << "v3[1]: " << v3.at(1) << std::endl;
// 	ftFile << "v3[2]: " << v3[2] << std::endl;
// 	ftFile << "v3 front: " << v3.front() << std::endl;
// 	ftFile << "v3 back: " << v3.back() << std::endl;

// 	ft::vector<std::string>::iterator it = v3.begin();
// 	for (; it < v3.end(); it++) {
// 		ftFile << "it: " << *it << " ";
// 	}
// 	ftFile << std::endl;

// 	ft::vector<std::string>::reverse_iterator rvrIt = v3.rbegin();

// 	for (; rvrIt < v3.rend(); rvrIt++) {
// 		ftFile << "rvrIt: " << *rvrIt << " ";
// 	}
// 	ftFile << std::endl;

// 	ftFile << "v3 empty: " << (v3.empty() ? "true" : "false") << std::endl;
// 	ftFile << "v3 size: " << v3.size() << std::endl;
// 	ftFile << "v3 max_size: " << v3.max_size() << std::endl;
// 	int i = -1;
// 	while (++i < 10)
// 	{
// 		v1.push_back("1");
// 		ftFile << "v3 capacity: " << v1.capacity() << std::endl;
// 		ftFile << "v3 size: " << v1.size() << std::endl;
// 	}


// 	ftFile << "v3 clear\n";
// 	v3.clear();
// 	ftFile << "v3 size: " << v3.size() << std::endl;
// 	ftFile << "v3 insert (from v2)\n";
// 	v3.insert(v3.begin(), v2.begin(), v2.end());
// 	ftFile << "v3 size: " << v3.size() << std::endl;
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	ftFile << "erase first\n";
// 	v3.erase(v3.begin() + 1);
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	v3.push_back("foo");
// 	v3.push_back("bar");
// 	v3.push_back("kek");
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	v3.pop_back();
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	v3.resize(4);
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	v3.assign(2, "newWord");
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	v3.swap(v2);
// 	ftFile << "v3: ";
// 	printvector(v3, ftFile);

// 	ftFile << "v3 == v2: " << (v3 == v2 ? "true" : "false") << std::endl;
// 	ftFile << "v3 < v2: " << (v3 < v2 ? "true" : "false") << std::endl;
// 	ftFile << "v3 >= v2: " << (v3 >= v2 ? "true" : "false") << std::endl;

// 	ft::vector<int> v4;
// 	for (int i = 0; i < 300000; i++) {
// 		v4.push_back(i);
// 	}

// 	clock_t g_end = clock();
// 	ftFile << "ft_vector_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }

// static void printVector(const std::vector<std::string>& v, std::ofstream& stlFile) {
// 	for (size_t i = 0; i < v.size(); i++) {
// 		stlFile << v[i] << " ";
// 	}
// 	stlFile << std::endl;
// }

// static void stl_test(std::ofstream& stlFile) {
// 	clock_t g_start = clock();

// 	std::vector<std::string> v1;
// 	v1.push_back("the");
// 	v1.push_back("frogurt");
// 	v1.push_back("is");
// 	v1.push_back("also");
// 	v1.push_back("cursed");


// 	stlFile << "v1: ";
// 	printVector(v1, stlFile);

// 	std::vector<std::string> v2(v1.begin(), v1.end());
// 	stlFile << "v2: ";
// 	printVector(v2, stlFile);

// 	std::vector<std::string> v3(v2);
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	stlFile << "v3[1]: " << v3.at(1) << std::endl;
// 	stlFile << "v3[2]: " << v3[2] << std::endl;
// 	stlFile << "v3 front: " << v3.front() << std::endl;
// 	stlFile << "v3 back: " << v3.back() << std::endl;

// 	std::vector<std::string>::iterator it = v3.begin();
// 	for (; it < v3.end(); it++) {
// 		stlFile << "it: " << *it << " ";
// 	}
// 	stlFile << std::endl;

// 	std::vector<std::string>::reverse_iterator rvrIt = v3.rbegin();
// 	for (; rvrIt < v3.rend(); rvrIt++) {
// 		stlFile << "rvrIt: " << *rvrIt << " ";
// 	}
// 	stlFile << std::endl;

// 	stlFile << "v3 empty: " << (v3.empty() ? "true" : "false") << std::endl;
// 	stlFile << "v3 size: " << v3.size() << std::endl;
// 	stlFile << "v3 max_size: " << v3.max_size() << std::endl;
// 	int i = -1;
// 	while (++i < 10)
// 	{
// 		v1.push_back("1");
// 		stlFile << "v3 capacity: " << v1.capacity() << std::endl;
// 		stlFile << "v3 size: " << v1.size() << std::endl;
// 	}

// 	stlFile << "v3 clear\n";
// 	v3.clear();
// 	stlFile << "v3 size: " << v3.size() << std::endl;
// 	stlFile << "v3 insert (from v2)\n";
// 	v3.insert(v3.begin(), v2.begin(), v2.end());
// 	stlFile << "v3 size: " << v3.size() << std::endl;
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	stlFile << "erase first\n";
// 	v3.erase(v3.begin() + 1);
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	v3.push_back("foo");
// 	v3.push_back("bar");
// 	v3.push_back("kek");
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	v3.pop_back();
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	v3.resize(4);
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	v3.assign(2, "newWord");
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	v3.swap(v2);
// 	stlFile << "v3: ";
// 	printVector(v3, stlFile);

// 	stlFile << "v3 == v2: " << (v3 == v2 ? "true" : "false") << std::endl;
// 	stlFile << "v3 < v2: " << (v3 < v2 ? "true" : "false") << std::endl;
// 	stlFile << "v3 >= v2: " << (v3 >= v2 ? "true" : "false") << std::endl;

// 	std::vector<int> v4;
// 	for (int i = 0; i < 300000; i++) {
// 		v4.push_back(i);
// 	}

// 	clock_t g_end = clock();
// 	stlFile << "stl_vector_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }

// int main()
// {
//     std::ofstream stlFile("./stlFile.txt");
// 	if (stlFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}
//     std::ofstream ftFile("./ftFile.txt");
// 	if (ftFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}

//     ftFile << "\n***** VECTOR TEST *****\n" << std::endl;
// 	ft_test(ftFile);
// 	ftFile.close();

//     stlFile << "\n***** VECTOR TEST *****\n" << std::endl;
// 	stl_test(stlFile);
// 	stlFile.close();

// 	system("leaks test");
// 	system("diff ftFile.txt stlFile.txt");
// }



////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// stack ///////////////////////////////////////////////////////////
// #include <time.h>
// #include <iostream>
// #include "stack.hpp"
// #include <stack>
// #include <fstream>
// #include <time.h>

// static void stl_test(std::ofstream& stlFile) {
// 	clock_t g_start = clock();

// 	std::stack<int> st;
// 	for (int i = 0; i < 100000; i++) {
// 		st.push(i * 3);
// 	}
// 	stlFile << "Top element (st): " << st.top() << std::endl;
// 	stlFile << "stack size (st): " << (st.empty() ? "true" : "false")
// 						<< std::endl;

// 	std::stack<int> st2(st);
// 	stlFile << "Top element (st2): " << st2.top() << std::endl;
// 	stlFile << "stack size (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;
// 	stlFile << "stack empty (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;

// 	st2.push(99);
// 	st2.push(42);
// 	stlFile << "Top element (st2): " << st2.top() << std::endl;
// 	stlFile << "stack size (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;

// 	std::stack<int> st3 = st2;
// 	stlFile << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;

// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	stlFile << "Top element (st3): " << st2.top() << std::endl;
// 	stlFile << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;
// 	stlFile << "st2 != st3: " << (st2 != st3 ? "true" : "false") << std::endl;
// 	stlFile << "st2 < st3: " << (st2 < st3 ? "true" : "false") << std::endl;
// 	stlFile << "st2 >= st3: " << (st2 >= st3 ? "true" : "false") << std::endl;

// 	int count = 0;
// 	while (!st3.empty()) {
// 		count++;
// 		st3.pop();
// 	}
// 	stlFile << "Count of pop operations (st3): " << count << std::endl;
// 	stlFile << "stack empty (st3): " << (st3.empty() ? "true" : "false")
// 						<< std::endl;

// 	clock_t g_end = clock();
// 	stlFile << "stl_stack_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }

// static void ft_test(std::ofstream& ftFile) {
// 	clock_t g_start = clock();
// 	ft::stack<int> st;
// 	for (int i = 0; i < 100000; i++) {
// 		st.push(i * 3);
// 	}
// 	ftFile << "Top element (st): " << st.top() << std::endl;
// 	ftFile << "stack size (st): " << (st.empty() ? "true" : "false")
// 						<< std::endl;

// 	ft::stack<int> st2(st);
// 	ftFile << "Top element (st2): " << st2.top() << std::endl;
// 	ftFile << "stack size (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;
// 	ftFile << "stack empty (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;

// 	st2.push(99);
// 	st2.push(42);
// 	ftFile << "Top element (st2): " << st2.top() << std::endl;
// 	ftFile << "stack size (st2): " << (st2.empty() ? "true" : "false")
// 						<< std::endl;

// 	ft::stack<int> st3 = st2;
// 	ftFile << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;

// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	st3.pop();
// 	ftFile << "Top element (st3): " << st2.top() << std::endl;
// 	ftFile << "st2 == st3: " << (st2 == st3 ? "true" : "false") << std::endl;
// 	ftFile << "st2 != st3: " << (st2 != st3 ? "true" : "false") << std::endl;
// 	ftFile << "st2 < st3: " << (st2 < st3 ? "true" : "false") << std::endl;
// 	ftFile << "st2 >= st3: " << (st2 >= st3 ? "true" : "false") << std::endl;

// 	int count = 0;
// 	while (!st3.empty()) {
// 		count++;
// 		st3.pop();
// 	}
// 	ftFile << "Count of pop operations (st3): " << count << std::endl;
// 	ftFile << "stack empty (st3): " << (st3.empty() ? "true" : "false")
// 						<< std::endl;
// 	clock_t g_end = clock();
// 	ftFile << "ft_stack_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }


// int main()
// {
//     std::ofstream stlFile("./stlFile.txt");
// 	if (stlFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}
//     std::ofstream ftFile("./ftFile.txt");
// 	if (ftFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}

//     ftFile << "\n***** STACK TEST *****\n" << std::endl;
// 	ft_test(ftFile);
// 	ftFile.close();

//     stlFile << "\n***** STACK TEST *****\n" << std::endl;
// 	stl_test(stlFile);
// 	stlFile.close();

// 	system("diff ftFile.txt stlFile.txt");
// }


////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// map /////////////////////////////////////////////////////////////
// #include <time.h>
// #include <iostream>
// #include "map.hpp"
// #include <map>
// #include <fstream>
// #include <time.h>

// static void printmap(ft::map<std::string, int>& m, std::ofstream& ftFile) {
// 	ftFile << '{';
// 	ft::map<std::string, int>::const_iterator b = m.begin();
// 	ft::map<std::string, int>::const_iterator e = m.end();
// 	while (b != e) {
// 		ftFile << b->first << ':' << b->second << ' ';
// 		b++;
// 	}
// 	ftFile << "}\n";
// }

// static void ft_test(std::ofstream& ftFile) {
// 	clock_t g_start = clock();

// 	ft::map<std::string, int> mp1;
// 	mp1["something"] = 21;
// 	mp1["anything"] = 42;
// 	mp1["that thing"] = 121;
// 	mp1["whatever"] = 555;
// 	ftFile << "mp1: ";
// 	printmap(mp1, ftFile);

// 	ft::map<std::string, int> mp2(mp1.find("anything"), mp1.end());
// 	ftFile << "mp2: ";
// 	printmap(mp2, ftFile);

// 	ft::map<std::string, int> mp3(mp1);
// 	ftFile << "mp3: ";
// 	printmap(mp3, ftFile);

// 	ftFile << "mp3[anything] with []: " << mp3["anything"] << std::endl;
// 	ftFile << "mp3[non_existing] with []: " << mp3["non_existing"]
// 						<< std::endl;
// 	printmap(mp3, ftFile);

// 	ft::map<std::string, int>::reverse_iterator rvrIt = mp3.rbegin();
// 	ftFile << '{';
// 	for (; rvrIt != mp3.rend(); rvrIt++) {
// 		ftFile << rvrIt->first << ':' << rvrIt->second << ' ';
// 	}
// 	ftFile << "}\n";

// 	ftFile << "mp3 empty: " << (mp3.empty() ? "true" : "false") << std::endl;
// 	ftFile << "mp3 size: " << mp3.size() << std::endl;

// 	ftFile << "mp3 clear\n";
// 	mp3.clear();
// 	ftFile << "mp3 size: " << mp3.size() << std::endl;
// 	ftFile << "mp3 insert (from mp2)\n";
// 	mp3.insert(mp2.begin(), mp2.end());
// 	ftFile << "mp3 size: " << mp3.size() << std::endl;
// 	ftFile << "mp3: ";
// 	printmap(mp3, ftFile);

// 	ftFile << "erase 'that_thing'\n";
// 	mp3.erase(mp3.find("that thing"));
// 	ftFile << "erase 'non_existing'\n";
// 	mp3.erase("non_existing");
// 	ftFile << "mp3: ";
// 	printmap(mp3, ftFile);

// 	mp3.swap(mp2);
// 	ftFile << "mp3: ";
// 	printmap(mp3, ftFile);

// 	ftFile << "mp3 == mp2: " << (mp3 == mp2 ? "true" : "false") << std::endl;
// 	ftFile << "mp3 < mp2: " << (mp3 < mp2 ? "true" : "false") << std::endl;
// 	ftFile << "mp3 >= mp2: " << (mp3 >= mp2 ? "true" : "false") << std::endl;

// 	ft::map<int, int> mp4;
// 	for (int i = 0, j = 100; i < 300000; i++, j++) {
// 		mp4.insert(ft::make_pair(i * 2, j));
// 	}
// 	ftFile << "count 41: " << mp4.count(41) << std::endl;
// 	ftFile << "count 50: " << mp4.count(50) << std::endl;
// 	ftFile << "count 300005: " << mp4.count(300005) << std::endl;
// 	ftFile << "find 26: " << mp4.find(26)->first << std::endl;
// 	ftFile << "lower bound 127: " << mp4.lower_bound(127)->first << std::endl;
// 	ftFile << "upper bound 244: " << mp4.upper_bound(244)->first << std::endl;

// 	clock_t g_end = clock();
// 	ftFile << "ft_map_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }


// static void printMap(const std::map<std::string, int>& m, std::ofstream& stlFile) {
// 	stlFile << '{';
// 	std::map<std::string, int>::const_iterator b = m.begin();
// 	std::map<std::string, int>::const_iterator e = m.end();
// 	while (b != e) {
// 		stlFile << b->first << ':' << b->second << ' ';
// 		b++;
// 	}
// 	stlFile << "}\n";
// }

// static void stl_test(std::ofstream& stlFile) {
// 	clock_t g_start = clock();

// 	std::map<std::string, int> mp1;
// 	mp1["something"] = 21;
// 	mp1["anything"] = 42;
// 	mp1["that thing"] = 121;
// 	mp1["whatever"] = 555;
// 	stlFile << "mp1: ";
// 	printMap(mp1, stlFile);

// 	std::map<std::string, int> mp2(mp1.find("anything"), mp1.end());
// 	stlFile << "mp2: ";
// 	printMap(mp2, stlFile);

// 	std::map<std::string, int> mp3(mp1);
// 	stlFile << "mp3: ";
// 	printMap(mp3, stlFile);

// 	stlFile << "mp3[anything] with []: " << mp3["anything"] << std::endl;
// 	stlFile << "mp3[non_existing] with []: " << mp3["non_existing"]
// 	<< std::endl;
// 	printMap(mp3, stlFile);

// 	std::map<std::string, int>::reverse_iterator rvrIt = mp3.rbegin();
// 	stlFile << '{';
// 	for (; rvrIt != mp3.rend(); rvrIt++) {
// 		stlFile << rvrIt->first << ':' << rvrIt->second << ' ';
// 	}
// 	stlFile << "}\n";

// 	stlFile << "mp3 empty: " << (mp3.empty() ? "true" : "false") << std::endl;
// 	stlFile << "mp3 size: " << mp3.size() << std::endl;

// 	stlFile << "mp3 clear\n";
// 	mp3.clear();
// 	stlFile << "mp3 size: " << mp3.size() << std::endl;
// 	stlFile << "mp3 insert (from mp2)\n";
// 	mp3.insert(mp2.begin(), mp2.end());
// 	stlFile << "mp3 size: " << mp3.size() << std::endl;
// 	stlFile << "mp3: ";
// 	printMap(mp3, stlFile);

// 	stlFile << "erase 'that_thing'\n";
// 	mp3.erase(mp3.find("that thing"));
// 	stlFile << "erase 'non_existing'\n";
// 	mp3.erase("non_existing");
// 	stlFile << "mp3: ";
// 	printMap(mp3, stlFile);

// 	mp3.swap(mp2);
// 	stlFile << "mp3: ";
// 	printMap(mp3, stlFile);

// 	stlFile << "mp3 == mp2: " << (mp3 == mp2 ? "true" : "false") << std::endl;
// 	stlFile << "mp3 < mp2: " << (mp3 < mp2 ? "true" : "false") << std::endl;
// 	stlFile << "mp3 >= mp2: " << (mp3 >= mp2 ? "true" : "false") << std::endl;

// 	std::map<int, int> mp4;
// 	for (int i = 0, j = 100; i < 300000; i++, j++) {
// 		mp4.insert(std::make_pair(i * 2, j));
// 	}
// 	stlFile << "count 41: " << mp4.count(41) << std::endl;
// 	stlFile << "count 50: " << mp4.count(50) << std::endl;
// 	stlFile << "count 300005: " << mp4.count(300005) << std::endl;
// 	stlFile << "find 26: " << mp4.find(26)->first << std::endl;
// 	stlFile << "lower bound 127: " << mp4.lower_bound(127)->first << std::endl;
// 	stlFile << "upper bound 244: " << mp4.upper_bound(244)->first << std::endl;

// 	clock_t g_end = clock();
// 	stlFile << "stl_map_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }

// int main()
// {
//     std::ofstream stlFile("./stlFile.txt");
// 	if (stlFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}
//     std::ofstream ftFile("./ftFile.txt");
// 	if (ftFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}

//     ftFile << "\n***** MAP TEST *****\n" << std::endl;
// 	ft_test(ftFile);
// 	ftFile.close();

//     stlFile << "\n***** MAP TEST *****\n" << std::endl;
// 	stl_test(stlFile);
// 	stlFile.close();

// 	system("leaks test");
// 	system("diff ftFile.txt stlFile.txt");
// }
////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// map /////////////////////////////////////////////////////////////

// #include <time.h>
// #include <iostream>
// #include "set.hpp"
// #include <set>
// #include <fstream>
// #include <time.h>


// static void print_title(std::string title, std::string sub,std::ofstream& ftFile) {
// 	ftFile << "\n";
// 	ftFile << title << ": " << sub << "\n\n";
// }

// static void print_title(std::string title, std::ofstream& ftFile) {
// 	ftFile << "\n";
// 	ftFile << title << "\n\n";
// }

// static void print_set(ft::set<char> set, std::string name, std::ofstream& ftFile)
// {
// 	ftFile << name << ":\n";
// 	for (ft::set<char>::iterator it = set.begin(); it != set.end(); it++)
// 		ftFile << *it << ", ";
// 	ftFile << std::endl;
// 	ftFile << std::endl;
// }

// static void print_size(ft::set<char> set, std::string name, std::ofstream& ftFile)
// {
// 	ftFile << name << " size: " << set.size() << std::endl;
// 	ftFile << name << std::boolalpha << " empty(): " << set.empty() << std::noboolalpha << std::endl;
// 	ftFile << std::endl;
// }

// static void ft_test(std::ofstream& ftFile) {
// 	clock_t g_start = clock();

// 	print_title("CONSTRUCTOR", "set", ftFile);
// 	ft::set<char> ft_set;
// 	print_size(ft_set, "set", ftFile);

// 	char c = 'a';
// 	for (int i = 1; i <= 13; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set(ft_set, "set", ftFile);
// 	print_size(ft_set, "set", ftFile);

// 	print_title("RANGE", "set", ftFile);
// 	ft::set<char> ft_set_range(ft_set.begin(), ft_set.end());
// 	print_size(ft_set_range, "set_range", ftFile);
// 	print_set(ft_set_range, "set_range", ftFile);

// 	print_title("COPY CONSTRUCTOR (copy of range)", "set", ftFile);
// 	ft::set<char> ft_set_copy(ft_set_range);
// 	print_size(ft_set_copy, "set_copy", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);


// 	print_title("ASSIGNATION OPERATOR", "set", ftFile);
// 	ft::set<char> ft_set_assignation;
// 	ft_set_assignation = ft_set_copy;
// 	print_size(ft_set_assignation, "set_assignation", ftFile);
// 	print_set(ft_set_assignation, "set_assignation", ftFile);


// 	print_title("ITERATORS TESTS", ftFile);
// 	ftFile << "set (iterator): ";
// 	for (ft::set<char>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
// 		ftFile << *it << ", ";
// 	ftFile << "\n" << std::endl;
// 	ftFile << "set (const_iterator): ";
// 	for (ft::set<char>::const_iterator it = ft_set.begin(); it != ft_set.end(); it++)
// 		ftFile << *it << ", ";
// 	ftFile << "\n" << std::endl;
// 	ftFile << "set (reverse_iterator): ";
// 	for (ft::set<char>::reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
// 		ftFile << *rit << ", ";
// 	ftFile << "\n" << std::endl;
// 	ftFile << "set (const_reverse_iterator): ";
// 	for (ft::set<char>::const_reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
// 		ftFile << *rit << ", ";
// 	ftFile << "\n" << std::endl;

// 	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty", ftFile);
// 	print_size(ft_set, "set", ftFile);

// 	print_title("SET INSERT(val)", ftFile);
// 	for (int i = 14; i <= 19; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set(ft_set, "set", ftFile);
// 	print_size(ft_set, "set", ftFile);

// 	print_title("SET INSERT(position, val)", ftFile);
// 	for (int i = 20; i <= 26; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set(ft_set, "set", ftFile);
// 	print_size(ft_set, "set", ftFile);

// 	print_title("SET INSERT(first, last)", "set -> set_copy", ftFile);
// 	print_title("BEFORE INSERT", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);

// 	print_title("AFTER INSERT", ftFile);
// 	ft_set_copy.insert(ft_set.begin(), ft_set.end());
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET ERASE(position)", "erasing first half of set_copy", ftFile);
// 	ft::set<char>::iterator std_it_half = ft_set_copy.find('n');
// 	ft::set<char>::iterator it2 = ft_set_copy.begin();
// 	while (it2 != std_it_half)
// 		ft_set_copy.erase(it2++);
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET ERASE(key)", "erasing another half of set_copy", ftFile);
// 	c = 'n';
// 	for (int i = 0; i < 6; i++, c++)
// 	{
// 		ft_set_copy.erase(c);
// 	}
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET ERASE(first, last)", "finishing the job set_copy", ftFile);
// 	ft_set_copy.erase(ft_set_copy.begin(), ft_set_copy.end());
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET SWAP() (MEMBER)", "swaping set_range and set_copy", ftFile);
// 	print_title("BEFORE SWAP", ftFile);
// 	print_set(ft_set_range, "set_range", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	ft_set_range.swap(ft_set_copy);
// 	print_title("AFTER SWAP", ftFile);
// 	print_set(ft_set_range, "set_range", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET CLEAR", "clearing set copy again", ftFile);
// 	print_title("BEFORE", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);
// 	ft_set_copy.clear();
// 	print_title("AFTER", ftFile);
// 	print_set(ft_set_copy, "set_copy", ftFile);
// 	print_size(ft_set_copy, "set_copy", ftFile);

// 	print_title("SET FIND(key) const and non_const", ftFile);
// 	ft::set<char>::iterator find_a = ft_set.find('a');
// 	ft::set<char>::const_iterator find_z = ft_set.find('z');
// 	ftFile << "find('a'): " << *find_a << '\n';
// 	ftFile << "find('z'): " << *find_z << '\n';

// 	print_title("SET COUNT(key)", ftFile);
// 	ftFile << 'a';
// 	if (ft_set.count('a') > 0)
// 		ftFile << " is an element of set.\n";
// 	else
// 		ftFile << " is not an element of set.\n";
// 	ftFile << '1';
// 	if (ft_set.count('1') > 0)
// 		ftFile << " is an element of set.\n";
// 	else
// 		ftFile << " is not an element of set.\n";

// 	print_title("SET LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g", ftFile);
// 	ft::set<char>::iterator itlow = ft_set.lower_bound('b');
// 	ft::set<char>::iterator itup = ft_set.upper_bound('g');
// 	ft_set.erase(itlow, itup);
// 	print_set(ft_set, "set", ftFile);
// 	print_size(ft_set, "set", ftFile);

// 	print_title("SET EQUAL_RANGE", "for h", ftFile);
// 	ft::pair<ft::set<char>::iterator,ft::set<char>::iterator> ret;
// 	ret = ft_set.equal_range('h');
// 	ftFile << "lower bound points to: ";
// 	ftFile << *(ret.first) << '\n';
// 	ftFile << "upper bound points to: ";
// 	ftFile << *(ret.second) << '\n';

// 	print_title("SET KEY_COMP AND VALUE_COMP", "display everything lower than m", ftFile);
// 	ft::set<char>::key_compare mycomp = ft_set.key_comp();

// 	char highest_key = 'm';
// 	char highest = *ft_set.find('m');

// 	ft::set<char>::iterator it = ft_set.begin();
// 	while (ft_set.value_comp()(*it, highest) && mycomp(*it, highest_key))
// 	{
// 		ftFile << *it << '\n';
// 		it++;
// 	}

// 	clock_t g_end = clock();
// 	ftFile << "stl_set_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }



// static void print_set_std(std::set<char> set, std::string name, std::ofstream& stlFile) {
// 	stlFile << name << ":\n";
// 	for (std::set<char>::iterator it = set.begin(); it != set.end(); it++)
// 		stlFile << *it << ", ";
// 	stlFile << std::endl;
// 	stlFile << std::endl;
// }

// static void print_size_std(std::set<char> set, std::string name, std::ofstream& stlFile)
// {
// 	stlFile << name << " size: " << set.size() << std::endl;
// 	stlFile << name << std::boolalpha << " empty(): " << set.empty() << std::noboolalpha << std::endl;
// 	stlFile << std::endl;
// }


// static void stl_test(std::ofstream& stlFile) {
// 	clock_t g_start = clock();

// 	print_title("CONSTRUCTOR", "set", stlFile);
// 	std::set<char> ft_set;
// 	print_size_std(ft_set, "set", stlFile);

// 	char c = 'a';
// 	for (int i = 1; i <= 13; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set_std(ft_set, "set", stlFile);
// 	print_size_std(ft_set, "set", stlFile);

// 	print_title("RANGE", "set", stlFile);
// 	std::set<char> ft_set_range(ft_set.begin(), ft_set.end());
// 	print_size_std(ft_set_range, "set_range", stlFile);
// 	print_set_std(ft_set_range, "set_range", stlFile);

// 	print_title("COPY CONSTRUCTOR (copy of range)", "set", stlFile);
// 	std::set<char> ft_set_copy(ft_set_range);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);


// 	print_title("ASSIGNATION OPERATOR", "set", stlFile);
// 	std::set<char> ft_set_assignation;
// 	ft_set_assignation = ft_set_copy;
// 	print_size_std(ft_set_assignation, "set_assignation", stlFile);
// 	print_set_std(ft_set_assignation, "set_assignation", stlFile);


// 	print_title("ITERATORS TESTS", stlFile);
// 	stlFile << "set (iterator): ";
// 	for (std::set<char>::iterator it = ft_set.begin(); it != ft_set.end(); it++)
// 		stlFile << *it << ", ";
// 	stlFile << "\n" << std::endl;
// 	stlFile << "set (const_iterator): ";
// 	for (std::set<char>::const_iterator it = ft_set.begin(); it != ft_set.end(); it++)
// 		stlFile << *it << ", ";
// 	stlFile << "\n" << std::endl;
// 	stlFile << "set (reverse_iterator): ";
// 	for (std::set<char>::reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
// 		stlFile << *rit << ", ";
// 	stlFile << "\n" << std::endl;
// 	stlFile << "set (const_reverse_iterator): ";
// 	for (std::set<char>::const_reverse_iterator rit = ft_set.rbegin(); rit != ft_set.rend(); rit++)
// 		stlFile << *rit << ", ";
// 	stlFile << "\n" << std::endl;

// 	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, empty", stlFile);
// 	print_size_std(ft_set, "set", stlFile);

// 	print_title("SET INSERT(val)", stlFile);
// 	for (int i = 14; i <= 19; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set_std(ft_set, "set", stlFile);
// 	print_size_std(ft_set, "set", stlFile);

// 	print_title("SET INSERT(position, val)", stlFile);
// 	for (int i = 20; i <= 26; i++, c++)
// 	{
// 		ft_set.insert(c);
// 	}
// 	print_set_std(ft_set, "set", stlFile);
// 	print_size_std(ft_set, "set", stlFile);

// 	print_title("SET INSERT(first, last)", "set -> set_copy", stlFile);
// 	print_title("BEFORE INSERT", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("AFTER INSERT", stlFile);
// 	ft_set_copy.insert(ft_set.begin(), ft_set.end());
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET ERASE(position)", "erasing first half of set_copy", stlFile);
// 	std::set<char>::iterator std_it_half = ft_set_copy.find('n');
// 	std::set<char>::iterator it2 = ft_set_copy.begin();
// 	while (it2 != std_it_half)
// 		ft_set_copy.erase(it2++);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET ERASE(key)", "erasing another half of set_copy", stlFile);
// 	c = 'n';
// 	for (int i = 0; i < 6; i++, c++)
// 	{
// 		ft_set_copy.erase(c);
// 	}
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET ERASE(first, last)", "finishing the job set_copy", stlFile);
// 	ft_set_copy.erase(ft_set_copy.begin(), ft_set_copy.end());
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET SWAP() (MEMBER)", "swaping set_range and set_copy", stlFile);
// 	print_title("BEFORE SWAP", stlFile);
// 	print_set_std(ft_set_range, "set_range", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	ft_set_range.swap(ft_set_copy);
// 	print_title("AFTER SWAP", stlFile);
// 	print_set_std(ft_set_range, "set_range", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET CLEAR", "clearing set copy again", stlFile);
// 	print_title("BEFORE", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);
// 	ft_set_copy.clear();
// 	print_title("AFTER", stlFile);
// 	print_set_std(ft_set_copy, "set_copy", stlFile);
// 	print_size_std(ft_set_copy, "set_copy", stlFile);

// 	print_title("SET FIND(key) const and non_const", stlFile);
// 	std::set<char>::iterator find_a = ft_set.find('a');
// 	std::set<char>::const_iterator find_z = ft_set.find('z');
// 	stlFile << "find('a'): " << *find_a << '\n';
// 	stlFile << "find('z'): " << *find_z << '\n';

// 	print_title("SET COUNT(key)", stlFile);
// 	stlFile << 'a';
// 	if (ft_set.count('a') > 0)
// 		stlFile << " is an element of set.\n";
// 	else
// 		stlFile << " is not an element of set.\n";
// 	stlFile << '1';
// 	if (ft_set.count('1') > 0)
// 		stlFile << " is an element of set.\n";
// 	else
// 		stlFile << " is not an element of set.\n";

// 	print_title("SET LOWER_BOUND AND UPPER_BOUND", "using it to erase from b to g", stlFile);
// 	std::set<char>::iterator itlow = ft_set.lower_bound('b');
// 	std::set<char>::iterator itup = ft_set.upper_bound('g');
// 	ft_set.erase(itlow, itup);
// 	print_set_std(ft_set, "set", stlFile);
// 	print_size_std(ft_set, "set", stlFile);

// 	print_title("SET EQUAL_RANGE", "for h", stlFile);
// 	std::pair<std::set<char>::iterator,std::set<char>::iterator> ret;
// 	ret = ft_set.equal_range('h');
// 	stlFile << "lower bound points to: ";
// 	stlFile << *(ret.first) << '\n';
// 	stlFile << "upper bound points to: ";
// 	stlFile << *(ret.second) << '\n';

// 	print_title("SET KEY_COMP AND VALUE_COMP", "display everything lower than m", stlFile);
// 	std::set<char>::key_compare mycomp = ft_set.key_comp();

// 	char highest_key = 'm';
// 	char highest = *ft_set.find('m');

// 	std::set<char>::iterator it = ft_set.begin();
// 	while (ft_set.value_comp()(*it, highest) && mycomp(*it, highest_key))
// 	{
// 		stlFile << *it << '\n';
// 		it++;
// 	}

// 	clock_t g_end = clock();
// 	stlFile << "stl_set_Execution time (ms): " << (double)(g_end - g_start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
// }

// int main()
// {
//     std::ofstream stlFile("./stlFile.txt");
// 	if (stlFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}
//     std::ofstream ftFile("./ftFile.txt");
// 	if (ftFile.fail())
// 	{
// 		std::cerr << "Error!" << std::endl;
// 	}

//     ftFile << "\n***** SET TEST *****\n" << std::endl;
// 	ft_test(ftFile);
// 	ftFile.close();

//     stlFile << "\n***** SET TEST *****\n" << std::endl;
// 	stl_test(stlFile);
// 	stlFile.close();

// 	system("leaks test");
// 	system("diff ftFile.txt stlFile.txt");
// }
///////////////////////////////////////////////////////////////////////////////////////////
//////////////////////// intra ////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
// #endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename ft::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}