#!/bin/bash

mkdir ../build
cd ../build && cmake ../.. -G"spaceInvaders" -DCMAKE_BUILD_TYPE=Release && spaceInvaders