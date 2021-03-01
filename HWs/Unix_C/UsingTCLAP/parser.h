/*
* Filename:  parser.h
* Date:      02/07/2020
* Author:    Rutvij Shah
* Email:     rutvij.shah@utdallas.edu
* Course:    CS3377.502 Spring 2020
* Version:   1.0
* Copyright: © 2020 Rutvij Shah. All rights reserved.
*
* Description:
*    Function prototypes for those defined in parser.cc
*/
#include <tclap/CmdLine.h>
#include <map>

using namespace std;
using namespace TCLAP;

#ifndef PARSER_H
#define PARSER_H

void PrintUsage(CmdLine& cmd);

void argParser(map<int, string> argMap, CmdLine &cmd);

inline const bool StringToBool(string s);

#endif
