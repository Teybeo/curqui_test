#include "libunit.h"

static void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, strlen(s));
}

static void	ft_putstr_col(char *str, char *color, char *colreset)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(colreset);
}

static void	ft_putnbr(int n)
{
	if (n / 10 == 0 && n % 10 < 0)
	{
		putchar('-');
		putchar(-1 * (n % 10) + '0');
	}
	else if (n / 10 == 0)
		putchar(n % 10 + '0');
	else
	{
		ft_putnbr(n / 10);
		if (n < 0)
			putchar(-1 * (n % 10) + '0');
		else
			putchar(n % 10 + '0');
	}
}

static void	ft_putnbr_col(int n, char *color, char *colreset)
{
	ft_putstr(color);
	ft_putnbr(n);
	ft_putstr(colreset);
}

static void	ft_putname(t_test *test)
{
	int		i;

	ft_putstr(BEFORE_TEST_NAME);
	ft_putstr(test->name);
	i = strlen(test->name);
	while (i < MAX_NAME_LEN)
	{
		putchar(' ');
		i++;
	}
	putchar('\t');
}

void		ft_putrslt(t_test *test)
{
	ft_putname(test);
	if (test->sigret == SIGSEGV)
		ft_putstr_col("[SEGV]\n", RED, DEF);
	else if (test->sigret == SIGBUS)
		ft_putstr_col("[BUSE]\n", RED, DEF);
	else if (test->sigret == SIGALRM)
		ft_putstr_col("[TIMEOUT]\n", RED, DEF);
	else if (test->sigret == SIGABRT)
		ft_putstr_col("[ABORT]\n", RED, DEF);
	else if (test->success == -1)
		ft_putstr_col("[KO]\n", RED, DEF);
	else
		ft_putstr_col("[OK]\n", GREEN, DEF);
}

void		ft_putnbrtests(int cnt_success, int cnt_total)
{
	char	*col;

	putchar('\n');
	if (cnt_total == cnt_success)
		col = strdup(GREEN);
	else
		col = strdup(RED);
	ft_putstr_col(" >> ", col, DEF);
	ft_putnbr_col(cnt_success, col, DEF);
	ft_putstr_col("/", col, DEF);
	ft_putnbr_col(cnt_total, col, DEF);
	ft_putstr_col(" tests checked\n", col, DEF);
	free(col);
}
