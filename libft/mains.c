
//strlcat
int main ()
{
    char str1[27] = "coucou ";
    char str2[] = "tout le monde";

    printf("%s\n", str1);
    ft_strlcat(str1, str2, 27);
    printf("%s", str1);
    return(0);
}

//substr

int main()
{
	char * s = ft_substr("tripouille", 0, 42000);
	printf("=>%s\n", s);

	s = ft_substr("42", 0, 0);
	printf("=>%s\n", s);
	s = ft_substr("tripouille", 1, 1);
	printf("=>%s\n", s);
	s = ft_substr("tripouille", 100, 1);
	printf("=>%s\n", s);
}

#include <string.h>
int main()
{
    //char s1[] = "Hey hey !";
    //char s2[] = "Hey hey2";

	//char	*s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	//char	*s2 = "\x12\x02";

	char	*s1 = "omg1||||||||||||||||";
	char	*s2 = "omg4";

    printf("original : %lu\n", strlcat(s1, s2, sizeof(s1)));
    printf("result : %lu", ft_strlcat(s1, s2, sizeof(s1)));
}

//topupper
int main()
{
 printf("%c", ft_toupper('z'));
}

//strchr
int main()
{
 char s[] = "Debout tout le monde";
 printf("%s\n", ft_strchr(s, 'm'));
 puts("coucou");
 return(0);
}


#include <string.h>
int main()
{
	char	*src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	char	*d1 = strrchr(src, '\0');
	char	*d2 = ft_strrchr(src, '\0');
	printf("=>%s\n=>%s", d1, d2);
}

//strncmp

#include <string.h>
int main()
{
    //char s1[] = "Hey hey !";
    //char s2[] = "Hey hey2";

	//char	*s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	//char	*s2 = "\x12\x02";

	char	*s1 = "omg1||||||||||||||||";
	char	*s2 = "omg4";

    printf("original : %d\n", strncmp(s1, s2, sizeof(s1)));
    printf("result : %d", ft_strncmp(s1, s2, sizeof(s1)));
}
//cpy
#include <string.h>
int main()
{
    char s1[] = "  ";
    char s2[] = "";

	//char	*s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	//char	*s2 = "\x12\x02";

	//char	*s1 = "omg1||||||||||||||||";
	//char	*s2 = "omg4";
	printf("result : %zu", ft_strlcpy(s1, s2, sizeof(s1)));
	printf("%s", s1);
   //printf("original : %zu\n", strlcpy(s1, s2, sizeof(s1)));

}

//memchr
int main()
{
 char s[] = "Debout tout le monde";
 printf("%s\n", (char ) ft_memchr((void) s, 'm', sizeof(s)));
 puts("coucou");
 return(0);
}

int main()
{
    char s1[] = "Hey hey !";
    char s2[] = "Hey hey !";

    printf("original : %d\n", memcmp((void )s1, (void)s2, sizeof(s1)));
    printf("result : %d", ft_memcmp((void )s1, (void)s2, sizeof(s1)));
}




#include <strings.h>
int main()
{
    //char s1[] = "Hey hey linoleum!";
    //char s2[] = "lino";
	char	*s1 = "MZIRIBMZIRIBMZE123";
	char	*s2 = "MZIRIBMZE";
	size_t	max = strlen(s2);

    printf("origin : %s\n", strnstr(s1, s2, max));
    printf("result : %s\n\n", ft_strnstr(s1, s2, max));

	printf("origin : %s\n", strnstr(s1, "fake", 0));
    printf("result : %s\n\n", ft_strnstr(s1, "fake", 0));

    printf("origin : %s\n", strnstr("chou-ffleur", "fleur", sizeof(s1)));
    printf("result : %s", ft_strnstr("chou-ffleur", "fleur", sizeof(s1)));
}


int main()
{
    printf("origin : %d\n", atoi("  -235"));
    printf("result : %d\n\n", ft_atoi("  -235"));
    printf("origin : %d\n", atoi("0"));
    printf("result : %d\n\n", ft_atoi("0"));
}//strdup
#include <string.h>
int	main()
{
	printf("%s \n", strdup(" coucou"));
	printf("%s \n", ft_strdup(" coucou"));

}

//split

int main()
{
	char **res = ft_split("Bonjour   tout  le monde  !", ' ');
	int	i = 0;

	while (res[i])
	{
		printf("- %s \n", res[i]);
		i ++;
	}
}

??itow


int main()
{
	char *res = ft_itoa(456123);
	printf("%s \n", res);
}

// mapi


char	tolowe(unsigned int i, char c)
{
	i++;
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

int main()
{

	printf("%s \n", ft_strmapi("COUCOU LES AMIS", tolowe));
}

//ierti
void	tolowe(unsigned int i, char *c)
{
	if (c[i] >= 65 && c[i] <= 90)
	{
		c[i] = c[i] + 32;
	}
	return ;
}

int main()
{
	char res[] = "COUCOU COUCOU";
	ft_striteri(res, tolowe);
	printf("%s \n", res);
}

list

int main()
{
	char	str[] = "hey";
	t_list	*list;
	list = ft_lstnew((void *)str);
	printf("%s" , (char*)list->content);
}

listaddfron

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_front(&list, add);
	while (list)
	{
		printf("%s \n", (char *) list->content);
		list = list->next ;
	}
}

lstsize

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	int		i;
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_front(&list, add);
	i = ft_lstsize(list);
	printf("%d", i);
	return (0);
}

lstlast
int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_front(&list, add);
	printf("%s \n", (char *) ft_lstlast(list)->content);
}

lstaddback

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_back(&list, add);
	while (list)
	{
		printf("%s \n", (char *) list->content);
		list = list->next ;
	}
}
/* int main()
{
	//char	str[] = "hey";
	char	str2[] = "hey0";
	t_list	*list;
	t_list	*add;
	t_list	*l2;

	l2 = NULL;
	list = NULL;
	add = ft_lstnew((void *)str2);
	ft_lstadd_back(&list, add);
	ft_lstadd_back(&list, ft_lstnew((void *)"hey1"));
	ft_lstadd_back(&l2, ft_lstnew((void *)"hey2"));
	ft_lstadd_back(&l2, ft_lstnew((void *) "hey3"));
	ft_lstadd_back(&list, l2);
	while (list)
	{
		printf("%s \n", (char *) list->content);
		list = list->next ;
	}
} */

lstclear
void	del(void *elem)
{
	t_list	*tmp;

	tmp = (t_list *)(elem);
	printf("%s", (char *)(tmp)->content);
}

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_back(&list, add);
	ft_lstclear(&list, del);
	printf("%p", list);
}

lstiter



void	makea(void *elem)
{
	printf("%s \n", (char *) elem);
}

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_back(&list, add);
	ft_lstiter(list, makea);
}

map
void	*makea(void *elem)
{
	printf("%s \n", (char *) elem);
	return (elem);
}

void	del(void *elem)
{
	printf("%s \n", (char *) elem);
}

int main()
{
	char	str[] = "hey";
	char	str2[] = "hey2";
	t_list	*list;
	t_list	*add;

	list = ft_lstnew((void *)str);
	add = ft_lstnew((void *)str2);
	ft_lstadd_back(&list, add);
	ft_lstmap(list, makea, del);
}
