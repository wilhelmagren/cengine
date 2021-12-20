#!/bin/bash
clear
gcc instance.c render.c mesh.c polygon.c matrices.c vecs.c camera.c rewrite.c -lm -lSDL2
