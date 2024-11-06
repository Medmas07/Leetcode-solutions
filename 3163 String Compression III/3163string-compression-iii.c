char* compressedString(char* word) {
    char*ch=malloc(sizeof(char)*strlen(word)*3+1);
    ch[0]='\0';
    char*ch1=malloc(3);
    char c;
    int i=0,j=0,l=strlen(word),k=0;
    
    for(i=0;i<l;)
    {
        c=word[i];
        j=0;
        while(j<9 && word[i]==c && j<l)
        {
            j++;
            i++;
        }
        sprintf(ch1,"%d%c",j,c);
        
        strcat(ch+k,ch1);
        k+=2;
   
        
    }
    return ch;
//      size_t length = strlen(word);
//     size_t maxLength = length * 3 + 1; // Estimation de la taille maximale
//     char* ch = malloc(maxLength);
    
//     if (ch == NULL) {
//         return NULL; // Vérification de l'allocation
//     }
    
//     size_t index = 0; // Indice pour écrire dans ch
//     char c;
//     int count;

//     for (size_t i = 0; i < length; ) {
//         c = word[i];
//         count = 0;

//         // Compte les occurrences du même caractère
//         while (i < length && word[i] == c && count < 9) {
//             count++;
//             i++;
//         }

//         // Écrit le caractère et le compte dans ch
//         index += snprintf(ch + index, maxLength - index, "%d%c", count, c);
//     }

//     return ch;
}