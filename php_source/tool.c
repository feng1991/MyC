
// printf string
void dump(char* str,int out){
	if(str == NULL){
		printf("NULL\n");	
	}else{
		printf("%s\n",str);
	}
	if(out == 1){
		exit(1);
	}
}


// printf int
void dump_d(int i,int out){
	printf("%d\n",i);
	if(out == 1){
		exit(1);
	}
}


/**
 * format the string to lower case
 * string can be a const chars
 * remember to free the return value
 **/
char* strtolower(char* str){
	int len = strlen(str);
	char* buf;
	buf = (char *)malloc( sizeof(char) * len);
	strcpy(buf,str);
	int j = 0;
	for(j = 0;j < len;j ++){
		if(buf[j] >= 65 && buf[j] <= 90){
			buf[j] += 32;
		}
	}
	return buf;
}


/**
 * format the string to upper case
 * string can be a const chars
 * remember to free the return value
 **/
char* strtoupper(char* str){
	int len = strlen(str);
	char* buf;
	buf = (char *)malloc( sizeof(char) * len);
	strcpy(buf,str);
	int j = 0;
	for(j = 0;j < len;j ++){
		if(buf[j] >= 97 && buf[j] <= 122){
			buf[j] -= 32;
		}
	}
	return buf;
}


/**
 * read file and get all the content
 * remember to free the return value
 **/
char* read_file(char* s){
	FILE* file = fopen(s,"r");
	int flen = 0;
	char* str = NULL;
	if(file == NULL){
		dump("Could not open file",1);
	}
	fseek(file,0,SEEK_END);
	flen = ftell(file);
	fseek(file,0,SEEK_SET);
	str = (char *)malloc(flen);
	fread(str,1,flen,file);
	fclose(file);
	file = NULL;
	return str;
}

