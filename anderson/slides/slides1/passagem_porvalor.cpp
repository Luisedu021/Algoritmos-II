#include <stdio.h>
#include <string.h>


int main() {
char v[10],s[10];
strcpy(v,"Ola,");
strcpy(s," Mundo!");
strcat(v,s);
printf("String resultante: %s\n",v);
return 0;
}