#include <stdio.h>
#include <string.h>

struct {
  char name[40];
  int age;
} person, person_copy;

int main ()
{

/*-----------------void *memchr(const void* str, int c, size_t t)-------------------------*/
    char * pch;
    char str[] = "Hoc C co ban va nang cao tai VietJack";
    pch = (char*) memchr (str, 'v', strlen(str)); //Kiem tra ki tu xuat hien lan dau trong string
    if (pch!=NULL)
    printf ("Tim thay 'v' tai vi tri %d.\n", pch-str+1);
    else
    printf ("Khong tim thay ky tu 'v'.\n");

/*-----------------void *memcmp(const void* str1, const void* str2, size_t n)------------------*/
   char str1[15];
   char str2[15];
   int ret;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = memcmp(str1, str2, 5); //Kiem tra do dai cua 2 chuoi toi n byte

   if(ret > 0)
   {
      printf("Chuoi str2 ngan hon chuoi str1\n");
   }
   else if(ret < 0) 
   {
      printf("Chuoi str1 ngan hon chuoi str2\n");
   }
   else 
   {
      printf("Chuoi str1 bang chuoi str2\n");
   }

/*-----------------void *memcpy(const void* str1, const void* str2, size_t n)------------------*/
    char myname[] = "Nguyen Hoang Nam";

    /* su dung ham memcpy de sao chep chuoi: */
    memcpy ( person.name, myname, strlen(myname)+1 );
    person.age = 46;

    /* su dung ham memcpy de sao chep struct: */
    memcpy ( &person_copy, &person, sizeof(person) );

    printf ("person_copy = %s, %d \n", person_copy.name, person_copy.age );


  return 0;
}