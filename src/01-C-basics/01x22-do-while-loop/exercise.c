#include <stdio.h>
#include "exercise.h"

void print_numbers_reverse(int start, int end)
{
  do
  {
    printf("%d\n", start);
    start--;
  } while (start >= end);
};
