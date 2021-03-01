/*
* Filename:  main.cc
* Date:      02/07/2020
* Author:    Rutvij Shah
* Email:     rutvij.shah@utdallas.edu
* Course:    CS3377.502 Spring 2020
* Version:   1.0
* Copyright: © 2020 Rutvij Shah. All rights reserved.
*
* Description:
*     Main driver code for assignment 2.
*/

#include "prog.h"

using namespace TCLAP;
using namespace std;

int main(int argc, char** argv){
  try {
      const char* desc = "Switch case of given text file";
    
      CmdLine cmd(desc, ' ', "1.0");
    
      SwitchArg upper("u", "upper", "Switch Case to upper", cmd, false);
    
      SwitchArg lower("l", "lower", "Switch Case to lower", cmd, false);
      
      ValueArg<string> outfile("o", "outfile", "The name of the output file",
                                    false, "output.txt", "output filename");

      UnlabeledValueArg<string> infile("infile", "The name of the input file.",
                                 true, "infile.txt", "input filename", false);
    
      cmd.add(outfile);
    
      cmd.add(infile);
    
      cmd.parse( argc, argv);

      map<int, string> argMap;
      
      argMap[IFILE] = infile.getValue();
      
      argMap[OFILE] = outfile.getValue();
      
      argMap[UPPER] = BoolToString(upper.getValue());
      
      argMap[LOWER] = BoolToString(lower.getValue());
      
      argParser(argMap, cmd);
           

  } catch (ArgException &e){
        cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
      }
  
  // do {
  //    cout << '\n' << "Press the Enter key to continue.";
  //  } while (cin.get() != '\n');
    
    return 0;
}

inline const char* BoolToString(bool b)
{
  return b ? "true" : "false";
}
