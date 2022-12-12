# Installation and Build

For installing wxWidgets on mac, you can use:
brew install wxwidgets

These arguments are necessary to build a C++ project with wxWidgets for MAC:
g++ -std=c++11 -o main *.cpp `wx-config --cxxflags --libs`


For Linux and Windows, here's the guide to install:
https://docs.wxwidgets.org/3.2.0/overview_install.html

run using vcpkg package manager and a vs project

# Notes

The app is primarily made from 4 wxPanels: menuPanel, blackjackPanel, roullettePanel, oddsArePanel. 
These are all held by a global controller gameFrame which stores balance and other variables.

Each panel contains the game UI and the game logic is stored in the respectively named implementation files.

ENJOY and Happy Holdays!!
