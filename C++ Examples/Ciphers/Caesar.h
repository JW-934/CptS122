#pragma once

#include <iostream>
#include <string>
#include "Cipher.h"

using std::cout;
using std::endl;

using std::string;

class Caesar : private Cipher
{
public:
	string encode(const string& msg);	// Not virtual because nothing will be derived from Caesar
	string decode(const string& msg);

private:
	int mKey;

};

