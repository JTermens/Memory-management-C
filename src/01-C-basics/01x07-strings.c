#include <stdio.h>

int main()
{
  char *will_never_hear_again = "Hey Joan, where is the memory course in C gonna be done?"; // single chars require '', while char arrays need "".

  printf("%s\n", will_never_hear_again);
  return 0;
}
