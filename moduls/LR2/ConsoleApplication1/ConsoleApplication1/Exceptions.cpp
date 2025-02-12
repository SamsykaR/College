#include "Methods.h"
#include <iostream>
#include <string>

ArrayException::ArrayException(std::string error) : message(error){}
const char* ArrayException::what() const noexcept { return message.c_str(); }

SizeNotrange::SizeNotrange(std::string error, int maxsize) : ArrayException(error + (char)maxsize){}
const char* SizeNotrange::what() const noexcept { return ArrayException::what(); }