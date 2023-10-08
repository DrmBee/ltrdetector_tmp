CXX= g++
CXXFLAGS = -Wall -O3 -ffast-math -Ilib/ -std=c++11 -DNDEBUG
.PHONY : clean
#
# Objects
#
Omain = ..\bin\main.o
Oscore = ..\bin\score.o

OBJS = $(Omain) $(Oscore) 

#
# Targets
#
TLTRDetector = ..\bin\ltrdetector.exe

#
# Make LTRDetector
#

$(TLTRDetector): $(OBJS)
	$(CXX) -o $(TLTRDetector) $(OBJS)

# nonltr/KmerHashTable.cpp
$(Omain): main.cpp main.h score.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(Omain)

$(Oscore): main.h score.h
	$(CXX) $(CXXFLAGS) -c score.cpp -o $(Oscore)


#
# Make clean
#

clean:
	del $(TLTRDetector) $(OBJS)