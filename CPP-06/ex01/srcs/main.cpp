//
// Created by aurel on 4/12/23.
//
#include "../incs/Serializer.h"

int main()
{
	Data dataPtr;
	uintptr_t serializedData;

	dataPtr.a = 10;
	dataPtr.b = 10.0;
	dataPtr.c = "ten";

	cout << "data adress before serial : " << &dataPtr << endl;
	serializedData = Serializer::serialize(&dataPtr);
	cout << "data adress after serial : " << &serializedData << endl;
	Data *deserializedData = Serializer::deserialize(serializedData);
	cout << "data adress after deserialization : " << deserializedData << endl;
}