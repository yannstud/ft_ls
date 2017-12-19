// #include <sys/ioctl.h>
// #include <stdio.h>
// #include <unistd.h>
// #include "libft/libft.h"

// int
// main(void)
// {
// 	int i;
// 	int j;
// 	int count = 0;
// 	int col = 0;

// 	struct winsize ws;
// 	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
// 	char *str = "coucou";
// 	char *str1 = "testtest";
// 	char *str2 = "bonjour les gens";
// 	char *str3 = "bye";
// 	i = 0;
// 	while (i < 50)
// 	{
// 		j = 0;
// 		while (str[j])
// 			j++;
// 		j++;
// 		count += j;
// 		j = 0;
// 		while (str1[j])
// 			j++;
// 		j++;
// 		count += j;
// 		j = 0;
// 		while (str2[j])
// 			j++;
// 		j++;
// 		count += j;
// 		j = 0;
// 		while (str3[j])
// 			j++;
// 		j++;
// 		count += j;
// 		printf("count ====> %d\n", count);
// 		i++;
// 	}

// 	col = count / ws.ws_col;
// 	printf("col ===> %d\n", col);
// 	printf ("lines %d\n", ws.ws_row);
// 	printf ("columns %d\n", ws.ws_col);

// 	return (0);
// }

// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <sys/stat.h>
// #include <time.h>

// int main(int argc, char *argv[])
// {
//     struct stat st;
//     char *f = "Makefile";
//     if (stat(f, &st) == -1) {
//         perror("stat");
//         exit(1);
//     }
//     char mtime[80];
//     time_t t = st.st_mtime; /*st_mtime is type time_t */
//     struct tm lt;
//     localtime_r(&t, &lt); /* convert to struct tm */
//     strftime(mtime, sizeof mtime,"%b %d %R", &lt);
// 	char *str = (char *)t;
// 	printf("%s  ", str);
//     printf("%s\n", mtime);
//     return 0;
// }
