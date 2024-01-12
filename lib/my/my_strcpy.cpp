char *my_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i]; // Copy the character
        i++;
    }
    dest[i] = '\0'; // Add the null character
    return dest;
}