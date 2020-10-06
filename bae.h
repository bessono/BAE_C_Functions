// BessonovAlexanderEvgenivich functions
// Author e-mail:bessonomap@yandex.ru

//=========================================================================

// insert \0 in all char array elements
void bae_null_to_array(char *str);

// replace one char in char array 
void bae_replace_char_in_str(char *str,char search, char replace);

// replace part of string in char array
void bae_str_replace(char *str, char *from, char *to);

// explode string by delimiter 
void bae_simple_explode(char *result1, char *result2,char *str, char delimiter);


//==========================================================================
void bae_null_to_array(char *str){
        int i;
        for(i=0; i < strlen(str); i++){
                str[i] = '\0';
        }
}
//---------------------------------------------------------------------------
void bae_replace_char(char *str,char search, char replace){
        int i;
        for(i=0; i < strlen(str); i++){
             if(str[i] == search){
                str[i] = replace;
             }
        }
}
//----------------------------------------------------------------------------
void bae_str_replace(char *str, char *from, char *to){
        int i,j,fpos=0,z=0;
        int fpost =0;
        char new_str[100000];
        bae_null_to_array(new_str);

        if(strstr(str,from) != NULL){
                z=0;
                for(i=0;i<strlen(str);i++){
                        new_str[z] = str[i];
                        for(j=0; j < strlen(from) ; j++){
                               if((i+j) > strlen(str)-1) {fpos = 0;break;break;}
                               if(str[i+j] == from[j]){
                                fpos=1;
                               } else {
                                fpos=0;
                                break;
                               }
                        }
                        if(fpos == 1){
                                for(j=0;j<strlen(to);j++){
                                        if(to[j] != '\0'){
                                                new_str[z+j] = to[j];
                                        }
                                }
                                z+=strlen(to)-1;
                                i+=strlen(from)-1;
                                fpos = 0;
                        }
                        z++;
                }
                bae_null_to_array(str);
                strcat(str,new_str);
        }
}
//-------------------------------------------------------------------
void bae_simple_explode(char *result1, char *result2,char *str, char delimiter){
        int i,j;
        bae_null_to_array(result1);
        bae_null_to_array(result2);
        if(strstr(str,&delimiter) != NULL){
                for(i = 0; i < strlen(str); i++){
                        if(str[i] == delimiter) {break;}
                        result1[i] = str[i];
                }
                result1[i+1] = '\0';
                i++;
                j=0;
                for(i=i;i < strlen(str); i++){
                        result2[j] = str[i];
                        j++;
                }
                result2[j] = '\0';
        }
}
