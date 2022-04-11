#pragma once

#include <iostream>
#include <string>

using std::cout;
using std::endl;

using std::string;

class Cipher
{
public:
	virtual string encode(const string &msg) = 0;
	virtual string decode(const string &msg) = 0;

private:

};

