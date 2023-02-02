#include <stdio.h>
#include <limits.h>
#include <float.h>

int ft_printf(const char *str, ...);

int main() 
{
  int i = INT_MAX;
  char c = CHAR_MAX;
  double d = DBL_MAX;
  char s[] = "";
  int arr[] = {};
  void *ptr1 = &i;
  void *ptr2 = &c;
  void *ptr3 = &d;
  void *ptr4 = &s;
  void *ptr5 = &arr;
  void *ptr_null = NULL;

  printf("Test 1: Regular input:\n");
  printf("printf: %p\n", ptr1);
  ft_printf("ft_printf: %p\n", ptr1);

  printf("\nTest 2: Edge input:\n");
  printf("printf: %p\n", ptr_null);
  ft_printf("ft_printf: %p\n", ptr_null);

  printf("\nTest 3: Multiple inputs:\n");
  printf("printf: %p %p %p %p %p\n", ptr1, ptr2, ptr3, ptr4, ptr5);
  ft_printf("ft_printf: %p %p %p %p %p\n", ptr1, ptr2, ptr3, ptr4, ptr5);

  return 0;
}

/*
int	main(void)
{
	int	n = 1256;
	int	modrem;
	uintptr_t a;

	char	*hex = "0123456789abcdef";
	
	a = (uintptr_t) &n;
	printf("%p\n\n", &n);
	int i = count_digits(a);
	char *ptr = (char *)malloc(sizeof(char) * (i + 1));

	ptr[i] = '\0';
	i--;

	while (i >= 0)
	{
		ptr[i] = hex[a % 16];
		a = a / 16;
		i--;
	}
	
	printf("0x%s", ptr);
	
	return (0);
}*/

