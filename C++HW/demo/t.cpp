/*#include <stdio.h>
#include <string.h>
char num[100];
int nums[51];
int target[51];

int main(){
    printf("%d", target[1]);
	int length;
	int i;
	int m;
	int number;
	scanf("%s",num);
	length=strlen(num);
	m=(length+9)/2;
	for(i=0;i<length;i++){
		nums[i]=num[i]-48;
	}
	if(length<10){
		for(i=0;i<length-1;i++){
			printf("%d ",nums[i]);
		}
		printf("%d",nums[length-1]);
	}
	else{
		for(i=0;i<length-2;i++){
			number=nums[i]*10+nums[i+1];
			if(number<=m&&target[number]!=1){
				printf("%d ",number);
				i++;
				target[number]=1;
			}
			else{
				printf("%d ",nums[i]);
				target[nums[i]]=1;
			}
		}
		if(i==length-2){
			number=nums[i]*10+nums[i+1];
			if(number<=m&&target[number]!=1){
				printf("%d",number);
			}
			else{
				printf("%d %d",nums[i],nums[i+1]);
			}
		}
	}
	return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> show;
vector<int> give = {1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> result;
void func(int size, vector<int> give, vector<int> result, int num, int M)
{
    for (int i = size; i >= num ; i--)
    {
        result[num - 1] = i - 1;
        if (num >= 1)
        {
            func(size - 1, give, result, num - 1, M);
        }
        else
        {
            for (int j = 0; j < M; j++)
                show.push_back(give[result[j]]);
        }   
    }
};

int main()
{
    result.resize(500);
    func(9, give, result, 4, 4);
    for(int i = 0; i < show.size(); i++)
    {
        cout<<show[i]<<' ';
    }
    return 0;
}