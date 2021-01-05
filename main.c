#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Compare two Case-Sensitive strings
_Bool equals(const char *str1, const char *str2);
void strCompSens();
//Compare between two Non-Case-Sensitive strings
_Bool equalsNonSensitive(const char *str1, const char *str2);
void strCompNoSens();
void toLowerString(const char *str, char *lowerStr);
//Prints the string from an introduced index
void askInput();
void substring(char *dest, const char *str, size_t pos);
//Prints the string from an introduced index until another.
void askInput2();
void substring2(char *dest, const char *str, size_t pos1, size_t pos2);
//Analize from right to left first matching string on its frist index.
void askInput3();
size_t lastIndexOf(const char *cad, const char *subcad);

int main()
{
    printf("Ingresa la opcion que desees probar\n1.Compara Sensitivamente\n2.Compara No sensitivo\n3.Expone la frase desde el indice que indique\n4.Expone la frase desde y hasta el indice que indique\n5.Da la ocurrencia de la subcadena comparando de derecha a izquierda\n\n");

    char opcion = getchar();
    while(getchar()!='\n');

    switch(opcion)
    {
    case '1':
        strCompSens();
        break;
    case '2':
        strCompNoSens();
        break;
    case '3':
        askInput();
        break;
    case '4':
        askInput2();
        break;
    case '5':
        askInput3();
        break;
    }

//    strCompSens(); //Compara strings CASE SENSITIVE
//    nextExcercice();
//    strCompNoSens(); //Compara strings NO CASE SENSITIVE
//    askInput();
//    askInput2();
//    askInput3();
    return 0;
}

_Bool equals(const char *str1, const char *str2)
{
    int salida = strcmp(str1,str2);
    return salida;
}

_Bool equalsNonSensitive(const char *str1, const char *str2)
{
    char lowerStr1[50];
    char lowerStr2[50];

    toLowerString(str1, lowerStr1);
    toLowerString(str2, lowerStr2);

    int salida = strcmp(lowerStr1,lowerStr2);
    return salida;
}

//Acepts an string str to be lowered, and stores the result in lowerStr
void toLowerString(const char *str, char *lowerStr)
{
    int i = 0;
    while(str[i])
    {
        lowerStr[i]=tolower(str[i]);
        i++;
    }
    lowerStr[i]='\0';
}

void strCompSens()
{
    char str1[50];
    char str2[50];

    printf("Ingrese una frase\n");
    scanf("%s",str1);
    printf("Ingrese una frase a comparar\n");
    scanf("%s",str2);

    _Bool iguales = equals(str1,str2);
    if( iguales == 0)
        printf("Las frases son iguales\n");
    else
        printf("Las frases son distintas\n");
}

void strCompNoSens()
{
    char str1[50];
    char str2[50];

    printf("Ingrese una frase\n");
    scanf("%s",str1);
    printf("Ingrese una frase a comparar\n");
    scanf("%s",str2);

    _Bool iguales2 = equalsNonSensitive(str1, str2);

    if( iguales2 == 0)
        printf("Las frases son iguales");
    else
        printf("Las frases son distintas");
}

void askInput()
{
    char str1[50];
    char str2[50];
    size_t pos;

    printf("Ingrese una frase \n");
    fgets(str1,50,stdin);
    str1[strlen(str1)-1]='\0';
    printf("\nIngrese un numero de posición donde desee insertar la subcadena\n");
    scanf("%ld",&pos);
    while(getchar()!='\n');
    substring(str2,str1, pos);
    printf("\nLa subcadena es:\"%s\".\n",str2);
}

void substring(char *dest, const char *str, size_t pos)
{
    int i = pos;
    int j = 0;
    while(str[i]!='\0')
    {
        dest[j]=str[i];
        i++;
        j++;
    }
    dest[j]='\0';
}

void askInput2()
{
    char str1[50];
    char str2[50];
    size_t pos1;
    size_t pos2;

    printf("Ingrese una frase \n");
    fgets(str1,50,stdin);
    str1[strlen(str1)-1]='\0';

    printf("\nIngrese un numero de posición donde desee iniciar la subcadena\n");
    scanf("%ld",&pos1);
    while(getchar()!='\n');
    printf("\nIngrese un numero de posición hasta donde desee leer la subcadena\n");
    scanf("%ld",&pos2);
    while(getchar()!='\n');

    substring2(str2,str1, pos1, pos2);
    printf("\nLa subcadena es:\"%s\".\n",str2);
}

void substring2(char *dest, const char *str, size_t pos1, size_t pos2)
{
    int j = 0;
//    int i = pos1;
//    while(str[i]!='\0' && i <= pos2){
//        dest[j]=str[i];
//        i++;
//        j++;
//    }
//    dest[j]='\0';

    if(pos1 >= strlen(str))
    {
        printf("La posicion inicial es incorrecta, no se comprobara el input");
        dest[0]='\0';
        return;
    }
    else if( pos2 < pos1)
    {
        printf("La posicion final es incorrecta, no se comprobara el input");
        dest[0]='\0';
        return;
    }
    else if( pos2 >= strlen(str))
    {
        printf("La posicion final es incorrecta, se copiara hasta el final de la frase");
        pos2 = strlen(str)-1;
    }

    for(int i = pos1; i <= pos2; i++,j++)
        dest[j]=str[i];
    dest[j]='\0';
}

void askInput3()
{
    char cad[50];
    char subCad[50];

    //Obtener input del usuario
    printf("\n\nIngrese una cadena de texto: \n");
    scanf("%[^\n]", cad);
    while(getchar()!='\n');

    printf("\n\nIngrese una subcadena de texto: \n");
    scanf("%[^\n]", subCad);
    while(getchar()!='\n');

    if(strlen(cad) == 0 || strlen(subCad) == 0)
    {
        printf("No se admiten cadenas vacias\n");
        return;
    }

    if (strlen(subCad) > strlen(cad))
    {
        printf("Subcadena no encontrada!\n");
        return;
    }
    lastIndexOf(cad,subCad);
}

void reverse(const char *str, char *reverseStr)
{
    int n = strlen(str);
    reverseStr[n]= '\0';

    int j = n-1;
    for (int i = 0; i < n; i++)
    {
        reverseStr[j] = str[i];
        j--;
    }
}

size_t lastIndexOf(const char *cad, const char *subCad)
{
    //Reverse strings
    char reverseCad[50];
    char reverseSubCad[50];

    reverse(cad, reverseCad);
    reverse(subCad, reverseSubCad);

    // Printfs de comprobacion
    //printf("cad: -%s-", cad);
    //printf("   reverseCad: -%s-\n", reverseCad);
    //printf("subCad: -%s-", subCad);
    //printf("   reverseSubCad: -%s-\n", reverseSubCad);

    // Get the first occurrence in the reversed strings
    char *occurrence = strstr(reverseCad, reverseSubCad); //0x3505
    if (occurrence != NULL)
        printf("Subcadena encontrada en el string!!\n\n");
    else
    {
        printf("Subcadena no encontrada!\n");
        return 0;
    }

    size_t occurrencePosition = occurrence - reverseCad;

    //Get the position occurrence in terms of the straight string.
    size_t position = ((strlen(cad) - 1) - occurrencePosition) - (strlen(subCad) - 1);
    printf("La ultima occurrencia de la subcadena \'%s\' occurre en la posicion: %ld\n\n", subCad, position);
    for (int i= (strlen(cad) - 1); i >= 0; i--)
        printf("%*d", 3, i);
    printf("\n");
    for(int i=0; i< strlen(cad); i++)
        printf("%*c", 3, cad[i]);
    printf("\n");
    for(int i=0; i< strlen(cad); i++)
        printf("%*d", 3, i);
    printf("\n");

    return position;
}



