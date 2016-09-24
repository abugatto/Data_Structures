/**
 * @file ListInterface.h
 *
 * @brief Interface file for the List ADT
 * 
 * @author  Anthony Bugatto
 * 
 * @details Specifies the implementation contract of the List ADT
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 */

#ifndef PVE_H
#define PVE_H

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep: public logic_error {
public:
	/** Outputs error messages
    @param message is the error message string*/
	PrecondViolatedExcep(const string& message = "");
};

#include "PrecondViolatedExcep.cpp"
#endif