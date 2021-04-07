OBJS = SortedListDriver.o SortedList.o Student.o
COMPILE = g++ -g -c -std=gnu++0x -o $@

.PHONY: run

SortedListDriver:	$(OBJS)
					g++ -o $@ $(OBJS)

SortedListDriver.o:	SortedListDr.cpp
						$(COMPILE) SortedListDr.cpp

SortedList.o:	SortedList.h SortedList.cpp
				$(COMPILE) SortedList.cpp

Student.o:	Student.h Student.cpp
			$(COMPILE) Student.cpp

run:	$ SortedListDriver
		./$ SortedListDriver

clean:
		$(RM) $(OBJS)

cleanall:	clean
			$(RM) SortedListDriver
