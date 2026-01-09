#include<stdio.h>
void main() {
	int n,arr[100],key,pos = -1, flag = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);}
		scanf("%d", &key);
	for (int i = 0; i <n; i++){
	if (arr[i] == key){
	pos = i;
	flag = 1;
	break;
	}
	
	
	
	
	}
	if (flag == 1) {
		printf("found at position %d\n", pos);
	} else {
		printf("%d not found\n", key);
	}
}
