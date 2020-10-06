// BessonovAlexanderEvgenivich functions
// Author e-mail:bessonomap@yandex.ru

void bae_null_to_array(char *str);
void bae_replace_char_in_str(char *str,char search, char replace);
void bae_str_replace(char *str, char *from, char *to);
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
        char new_str[10000];
        bae_null_to_array(new_str);
        //printf("DEBUG0 %s %s\n",str,from);
        fpos = strstr(str,from);
        if(fpos != -1){
                //printf("DEBUG1 %s is founded in %d \n",from,fpos);
                z=0;
                for(i=0;i<strlen(str);i++){
                        new_str[z] = str[i];
                        printf(" DEBUG new_str -- %c \n",new_str[z]);
                        for(j=0; j < strlen(from) ; j++){
                               if((i+j) > strlen(str)-1) {fpos = 0;break;break;}
                               if(str[i+j] == from[j]){
                                        //printf("DEBUG2 YES  in str[%d] from[%d] \n",i,j);
                                fpos=1;
                               } else {
                                        //printf("DEBUG2 NO  in str[%d] from[%d] \n",i,j);
                                fpos=0;
                                break;
                               }
                        }
                        if(fpos == 1){
                                for(j=0;j<strlen(to);j++){
                                        if(to[j] != '\0'){
                                                new_str[z+j] = to[j];
                                        }
                                      //printf("%s",new_str[z+j]);
                                }
                                z+=strlen(to)-1;
                                i+=strlen(from)-1;
                                fpos = 0;
                        }
                        z++;

                }


                printf("DEBUG END %s\n",new_str);
                bae_null_to_array(str);
                strcat(str,new_str);
        }
        

}
