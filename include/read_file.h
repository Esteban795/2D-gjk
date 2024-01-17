#ifndef READ_FILE_H
#define READ_FILE_H

#define WIDTH 1068
#define HEIGHT 720

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vec2.h"
#include "polygon.h"

polygon* readFile(char* filename,int* count);

#endif