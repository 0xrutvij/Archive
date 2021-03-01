# Filename:  Makefile
# Date:      04/28/2020
# Author:    Rutvij Shah
# Email:     rutvij.shah@utdallas.edu
# Course:    CS3377.502 Spring 2020
# Version:   1.0
# Copyright: 2020, All Rights Reserved
#
# Description:
#		Makefile to build matrix_display exec file.     
#

CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall -I/scratch/perkins/include
LDFLAGS = -L/scratch/perkins/lib
LDLIBS = -lcdk -lcurses

EXECFILE = matrix_display

PROJECTNAME = Program6

# Auto include all .cc files
SOURCES := $(wildcard *.cc)

OBJS = $(SOURCES:.cc=.o)

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) *~ \#* *.d

$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

%.d:%.cc
	@echo Updating .d Dependency File
	@set -e; rm -f $@; \
	$(CXX) -MM $(CPPFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

Makefile: $(SOURCES:.cc=.d)

# Backup Target
backup:	clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename `pwd`))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!


# Include the dependency files created by the PreProcessor.  The
# dash in front of the command keeps the system from complaining
# if the files do not exist.

-include $(SOURCES:.cc=.d)

