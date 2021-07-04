#ifndef SLIDE_H
#define SLIDE_H

#define SLIDE_LEFT 1
#define SLIDE_RIGHT -1

#include <stdlib.h>
#include <stdio.h>

void moving_left(int *line, size_t size);
void moving_right(int *line, size_t size);
int collapse(int *line, size_t size, int direction);
int slide_line(int *line, size_t size, int direction);

#endif /* SLIDE_H */
