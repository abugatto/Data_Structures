/**
 * @file ListInterface.h
 *
 * @brief Interface file for the List ADT
 * 
 * @author Anthony Bugatto 
 * 
 * @details Specifies the implementation contract of the List ADT
 *
 * @version 0.10
 *
 * @Note Adapted from Frank M. Carrano and Timothy M. Henry
 *       Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
 */

#ifndef PVE_CPP
#define PVE_CPP

#include "PrecondViolatedExcep.h"

using namespace std;

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception:" + message) {
}

#endif