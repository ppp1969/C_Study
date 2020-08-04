#include<stdio.h>
#include<stdbool.h>
#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

int num_in_rank[NUM_RANKS];	//index : 0~12 	//data : 0~4
int num_in_suit[NUM_SUITS];	//index : 0~3	//data : 0~5

bool straight, flush, four, three;
int pairs;

/*
1. ���п� �ִ� ī����,
2. ������ ��ũ����,
3. �������.
*/

void in_hand(void);
void classify(void);
void result(void);

int main(void){
	for(;;){
		in_hand();
		classyfy();
		result();
	}
	
	return 0;
}

void in_hand(void){
	
}
void classify(void){
	//���� ���� : flush �Ǵ�
	for(int i=0; i<NUM_SUITS;i++){
		//flush�Ǵ�.
		if(num_in_suit[i]==5){
			flush=true;
			goto EXIT_suit;
		}
	}
	EXIT_suit:

	//���� ���� : pair, three, four, straight �Ǵ�
	//if������ �����ϴ� �ͺ��� ����ġ���� �������� �پ�� ����ġ�� �ۼ�.

	int str_count = 0; //
	for(int i=0;i<NUM_RANKS;i++){
		switch(num_in_rank[i]){
			case 0:
				break;
			case 1: //��Ʈ����Ʈ �Ǻ�
				if(i!=4&&num_in_rank[i]==num_in_rank[i+1]){
					str_count++;
				}
				if(str_count==4){	//���� Ƚ���� 4�̸� 5�� ī�� ��� ������ ������ �Ǵ�. - straight.
					straight=true;
				}
				break;
			case 2:	//����Ǻ� 1�̸� �����, 2�� �����
				pairs++;
				break;
			case 3:	//Ʈ���� �Ǻ�
				three = true;
				break;
			case 4:	//��ī�� �Ǻ�
				four = true;
				break;
			default:
				break;
		}
	}
	

}
void result(void){
	
}
