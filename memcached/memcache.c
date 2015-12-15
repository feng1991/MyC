
#define MAX_MEM_LENGTH 255

//the key struct which store the key-value variables
typedef struct Mem{
	char* key;
	char* value;
	int ctime;
	int utime;
}Mem;

//global 
Mem mem[MAX_MEM_LENGTH];
int mem_len = 0;

//add a key-value to mem
int mem_add(char* key,char* value){
	if(mem_len >= MAX_MEM_LENGTH){
		return -1;
	}
	mem[mem_len].key = (char*)malloc( sizeof(char) * strlen(key) );
	mem[mem_len].value = (char*)malloc( sizeof(char) * strlen(value) );
	strcpy(mem[mem_len].key,key);
	strcpy(mem[mem_len].value,value);
	int t = time(0);
	mem[mem_len].ctime  = t;
	mem[mem_len].utime  = t;
	mem_len ++;
	return 0;
}

//get a value in mem from a designated key
char* mem_get(char* key){
	int i;
	for(i = 0;i < mem_len;i ++){
		if(0 == strcmp(key,mem[i].key)){
			return mem[i].value;
		}
	}
	return NULL;
}

//get the location of a key in mem
int mem_get_location(char* key){
	int i;
	for(i = 0;i < mem_len;i ++){
		if(0 == strcmp(key,mem[i].key)){
			return i;
		}
	}
	return -1;
}

//set a key-value to mem,if key exists,update the value
int mem_set(char* key,char* value){
	int location = mem_get_location(key);
	if(-1 == location){
		return mem_add(key,value);
	}else{
		strcpy(mem[location].value,value);
		mem[location].utime = time(0);
		return 0;
	}
}

//print all the key-value in men
void mem_dump(){
	int i;
	printf("\nstart dumping from mem\n");
	for(i =0 ;i < mem_len;i ++){
		printf("%s : %s\n",mem[i].key,mem[i].value);
	}
	printf("stop dumping from mem\n\n");
}
