
// printf string
void dump(char* str){
	if(str == NULL){
		printf("NULL\n");	
	}else{
		printf("%s\n",str);
	}
}

// printf int
void dump_d(int i){
	printf("%d\n",i);
}

// format the string to lower case
// string can be a const chars
// remember to free the return value
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


// format the string to upper case
// string can be a const chars
// remember to free the return value
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
