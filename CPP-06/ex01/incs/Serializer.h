//
// Created by aurel on 4/12/23.
//

#pragma once

#include <iostream>
#include "Data.h"
#include <stdint.h>

using std::string;
using std::endl;
using std::cout;

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer();
	~Serializer();
};
