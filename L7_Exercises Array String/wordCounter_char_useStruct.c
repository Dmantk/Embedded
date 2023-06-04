#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
	char* address;
	int size;
}words;

void replaceChars(char* arr){
  char normalChars[] = ",.:;'()-_=+!@#$%^&*<>?/";
  for (int i=0;arr[i]!='\0';i++){
		for(int j=0;normalChars[j]!='\0';j++){
			if (arr[i] == normalChars[j]){
				arr[i] = ' ';
				break;
			}
		}
	}
}

void splitWords(char* arr, int size, words* word, int* numWords){
	int index = 0;
	int count = 0;
	for(int i=0;i<size;i++){
		if(arr[i]!=' '){
			count++;
			if(i==0||arr[i-1]==' '){
				word[index].address = &arr[i];
			}
			if(i==size-1){
				word[index].size = count;
				count=0;
				index++;
			}
		}
		else{
			if(count>0&&arr[i-1]!=' '){
				word[index].size = count;
				count = 0;
				index++;
			}
		}
		word = realloc(word, (index+2) * sizeof(words));
		if(word == NULL){
			printf("Cap phat them bo nho bi loi.\n");
			return;
		}
	}
	*numWords = index;
}

void wordCounter(words* word, int numWords){
	for(int i=0;i<numWords;i++){
		int count=0;

		for(int j=0;j<numWords;j++){
			if(*word[i].address==*word[j].address && word[i].size==word[j].size){
				int flag=0;
				for(int k=0;k<word[i].size;k++){
					if(*(word[i].address+k)==*(word[j].address+k)){
						flag++;
					}
					else break;
				}
				if(flag==word[i].size){
					count++;
					if(count>1){
						for(int n=0;n<word[i].size;n++){
							*(word[j].address+n)=' ';
						}
					}
				}
			}
		}
		if(*word[i].address!=' '){
			printf("Chu \"");
			for(int j=0;j<word[i].size;j++){
				printf("%c",*(word[i].address+j));	
			}
			printf("\" xuat hien %d lan\n",count);
		}
	}
}


int main() {
	char arr[] = "mot hai ba, hai ba mot ";
	int size = sizeof(arr)/sizeof(arr[0])-1;
	replaceChars(arr);
	words* listWord = malloc(sizeof(words));
  if (listWord == NULL) {
  	printf("Cap phat loi.\n");
		return 1;
  }
    
  int numWords;
	splitWords(arr,size,listWord,&numWords);
	wordCounter(listWord,numWords);
	
	free(listWord);
	return 0;
}
