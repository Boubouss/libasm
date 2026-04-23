#include <libasm.h>

void  test_strlen(const char* str) {
  printf("test strlen de '%s'\n", str);
  printf("strlen : %zu\n", strlen(str));
  printf("ft_strlen : %zu\n\n", ft_strlen(str));
}

void  test_strcpy(const char* str) {
  printf("test strcpy de '%s'\n", str);
  printf("utilisation d'un buffer de taille suffisante (<= %zu)\n", strlen(str));
  char* buf = malloc(strlen(str) + 1);
  if (!buf) {
    printf("echec du malloc pour strcpy test\n");
    return;
  }
  strcpy(buf, str);
  printf("test avec strlen :\nsrc : '%s'\ndest : '%s'\n", str, buf);
  bzero(buf, strlen(buf));
  ft_strcpy(buf, str);
  printf("test avec ft_strlen :\nsrc : '%s'\ndest : '%s'\n\n", str, buf);
  free(buf);
}

void test_strcmp(const char* str) {
  const char* same = "Hello, World !";
  const char* pos = "A";
  const char* neg = "Z";
  
  printf("test strcmp de '%s'\n", str);
  
  printf("s1 : '%s'; s2 : '%s'\n", str, same);
  printf("strcmp : %d\nft_strcmp : %d\n", strcmp(str, same), ft_strcmp(str, same));

  printf("s1 : '%s'; s2 : '%s'\n", str, pos);
  printf("strcmp : %d\nft_strcmp : %d\n", strcmp(str, pos), ft_strcmp(str, pos));
  
  printf("s1 : '%s'; s2 : '%s'\n", str, neg);
  printf("strcmp : %d\nft_strcmp : %d\n\n", strcmp(str, neg), ft_strcmp(str, neg));
}

void test_strdup(const char* str) {
  printf("test strdup de '%s'\n", str);
  char* dup = strdup(str);
  if (!dup) {
    printf("echec du strdup pour strcdup test\n");
    return;
  }
  printf("strdup : \nsrc : '%s' => %zu\ndup : '%s' => %zu\n", str, strlen(str), dup, strlen(dup));
  free(dup);
  dup = ft_strdup(str);
  if (!dup) {
    printf("echec du ft_strdup pour strcdup test\n");
    return;
  }
  printf("ft_strdup : \nsrc : '%s' => %zu\ndup : '%s' => %zu\n\n", str, strlen(str), dup, strlen(dup));
  free(dup);
}

void test_write(const char* str) {
  printf("test write de '%s'\n", str);
  printf("stdout :\n");
  
  printf("write : '");
  write(1, str, strlen(str));
  write(1, "'\n", 2);

  printf("ft_write : '");
  ft_write(1, str, strlen(str));
  ft_write(1, "'\n", 2);
  
  printf("wrong fd :\n");
  
  printf("write : %zd\n", write(-1, str, strlen(str)));
  printf("errno => %d\n", errno);
  
  printf("ft_write : %zd\n", ft_write(-1, str, strlen(str)));
  printf("errno => %d\n\n", errno);
}

void    test_read(const char* str) {
  printf("test read de '%s'\n", str);
  int fd = open("test_file.txt",  O_RDWR | O_CREAT, 0644);
  if (fd < 0) {
    printf("echec de la creation du fichier dans test_read\n\n");
    return;
  }
  write(fd, str, strlen(str));
  lseek(fd, 0, SEEK_SET);
  char* buf = malloc(strlen(str) + 1);
  if (!buf) {
    close(fd);
    printf("echec du malloc buffer dans test_read\n\n");
    return;
  }
  
  printf("read %zd bytes : '%s'\n", read(fd, buf, strlen(str)), buf);
  lseek(fd, 0, SEEK_SET);
  bzero(buf, strlen(str));
  printf("ft_read %zd bytes : '%s'\n", ft_read(fd, buf, strlen(str)), buf);
  
  printf("read : %zd\n", read(-1, str, strlen(str)));
  printf("errno => %d\n", errno);
  
  printf("ft_read : %zd\n", ft_read(-1, str, strlen(str)));
  printf("errno => %d\n\n", errno);


  free(buf);
  close(fd);
}

int   main() {
  const char* str = "Hello, World !";
  
  test_strlen(str);
  test_strcpy(str);
  test_strcmp(str);
  test_strdup(str);
  test_write(str);
  test_read(str);
  return 0;
}

