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
1. 손패에 있는 카드등록,
2. 손패의 랭크판정,
3. 결과판정.
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
	//문양 대조 : flush 판단
	for(int i=0; i<NUM_SUITS;i++){
		//flush판단.
		if(num_in_suit[i]==5){
			flush=true;
			goto EXIT_suit;
		}
	}
	EXIT_suit:

	//숫자 대조 : pair, three, four, straight 판단
	//if문으로 분할하는 것보다 스위치문이 가독성이 뛰어나서 스위치로 작성.

	int str_count = 0; //
	for(int i=0;i<NUM_RANKS;i++){
		switch(num_in_rank[i]){
			case 0:
				break;
			case 1: //스트레이트 판별
				if(i!=4&&num_in_rank[i]==num_in_rank[i+1]){
					str_count++;
				}
				if(str_count==4){	//연속 횟수가 4이면 5장 카드 모두 연속인 것으로 판단. - straight.
					straight=true;
				}
				break;
			case 2:	//페어판별 1이면 원페어, 2면 투페어
				pairs++;
				break;
			case 3:	//트리플 판별
				three = true;
				break;
			case 4:	//포카드 판별
				four = true;
				break;
			default:
				break;
		}
	}
	

}
void result(void){
	
}
