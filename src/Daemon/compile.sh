#!/bin/bash
rm -fr ./debug
rm -fr ./release
make debug
make release
