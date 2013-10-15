#!/bin/bash
rm -fr ./daemon
g++ daemon.cpp -lboost_thread -o daemon
