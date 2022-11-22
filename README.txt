These arguments are necessary to build a C++ project with wxWidgets:
g++ -o main main.cpp `wx-config --cxxflags --libs`

Replace hello with *, I might just make a makefile to do this later.

Also, for installing wxWidgets on mac, you can use:
brew install wxwidgets

For Linux and Windows, here's the guide to install:
https://docs.wxwidgets.org/3.2.0/overview_install.html


