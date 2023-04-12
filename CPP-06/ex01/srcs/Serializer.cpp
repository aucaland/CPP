//
// Created by aurel on 4/12/23.
//

#include "../incs/Serializer.h"

using std::cout;
using std::endl;

Serializer::Serializer()
{
	cout << "Constructor Serializer called" << endl;
}

Serializer::~Serializer()
{
	cout << "Destructor Serializer called" << endl;
}

uintptr_t Serializer::serialize( Data *ptr )
{
	return reinterpret_cast<uintptr_t >(ptr);
}

Data *Serializer::deserialize( uintptr_t raw )
{
	return reinterpret_cast<Data *>(raw);
}