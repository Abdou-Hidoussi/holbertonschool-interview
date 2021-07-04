#ifndef SLIDE_H
#define SLIDE_H

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

#include <stdlib.h>
#include <stdio.h>

void left_shift(int *line, size_t size);
void right_shift(int *line, size_t size);
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_H */
