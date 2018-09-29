#include <ncurses.h>
#include <term.h>
#include <stdio.h>

int	main()
{
  char	buff[10];
  int	r;
  char	*s;
  int	ret;

  r = setupterm("xterm", 1, &ret);
  r = tgetnum("cols");
  printf("%d\n", r);
  s = tigetstr("smkx");
  if (s != 0)
    printf(" ntm %s \n", s);

  read(0, buff, 10);
  printf("%d %d %d\n", buff[0], buff[1], buff[2]);
  return (0);
}
