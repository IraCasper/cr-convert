#include <stdio.h>
#include <stdbool.h>

int main()
{
  bool is_cr = false;
  char line_ending = '\r';
  while(true) {
    int x = getc(stdin);
    switch (x)
      {
      case '\r':
        if (is_cr) {
	  is_cr = false;
          putchar(line_ending);
          is_cr = false;
        }
        is_cr = true;
        break;
      case '\n':
        is_cr = false;
        putchar(line_ending);
        break;
      default:
        if (is_cr) {
          putchar(line_ending);
          is_cr = false;
        }
        if (x != EOF) {
          putchar(x);
        }
      }
    if (x == EOF) {
      break;
    }
  }
}
