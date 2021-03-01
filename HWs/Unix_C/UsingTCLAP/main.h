/*
* Filename:  main.h
* Date:      02/07/2020
* Author:    Rutvij Shah
* Email:     rutvij.shah@utdallas.edu
* Course:    CS3377.502 Spring 2020
* Version:   1.0
* Copyright: © 2020 Rutvij Shah. All rights reserved.
*
* Description:
*    Function prototypes for those defined in main.cc and enums shared between main.cc and parser.cc
*/

#ifndef MAIN_H
#define MAIN_H

enum flags {IFILE, OFILE, UPPER, LOWER};

inline const char* BoolToString(bool b);

#endif /* main_h */
