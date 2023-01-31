#include <stdio.h>
#include "prioqueue.h"

void createQueuePQ(PrioQueue *pq){
    IDX_HEAD(*pq) = IDX_UNDEF;
    IDX_TAIL(*pq) = IDX_UNDEF;
}

boolean isEmptyPQ(PrioQueue pq){
    return ((IDX_HEAD(pq) == IDX_UNDEF) && (IDX_TAIL(pq) == IDX_UNDEF));
}

boolean isFullPQ(PrioQueue pq){
    return(IDX_TAIL(pq) == PQCAPACITY-1 && IDX_HEAD(pq) == 0);
}

int lengthPQ(PrioQueue pq){
    if (isEmptyPQ(pq)){
        return 0;
    }else{
        return IDX_TAIL(pq) - IDX_HEAD(pq) + 1;
    }
}

void enqueuePQ(PrioQueue *pq, PQElType val){ //untuk kondisi full, jangan dienqueue, taruh di main
    if (isEmptyPQ(*pq)){
        IDX_HEAD(*pq) = 0;
        IDX_TAIL(*pq) = 0;
    }else{
		IDX_TAIL(*pq) = IDX_TAIL(*pq) + 1;
	}
	TAIL(*pq).foodId = val.foodId;
	TAIL(*pq).cookTime = val.cookTime;
	TAIL(*pq).stayTime = val.stayTime;
	TAIL(*pq).price = val.price;
}

void dequeuePQ(PrioQueue *pq, PQElType *val){
    (*val).foodId = HEAD(*pq).foodId;
	(*val).cookTime = HEAD(*pq).cookTime;
	(*val).stayTime = HEAD(*pq).stayTime;
	(*val).price = HEAD(*pq).price;
    if (IDX_HEAD(*pq) == IDX_TAIL(*pq)){
        IDX_HEAD(*pq) = IDX_UNDEF;
        IDX_TAIL(*pq) = IDX_UNDEF;
    }else{
		int i;
		for(i = 0; i < IDX_TAIL(*pq); i++){
			(*pq).buffer[i].foodId = (*pq).buffer[i + 1].foodId;	
			(*pq).buffer[i].cookTime = (*pq).buffer[i + 1].cookTime;
			(*pq).buffer[i].stayTime = (*pq).buffer[i + 1].stayTime;
			(*pq).buffer[i].price = (*pq).buffer[i + 1].price;	
		}
		IDX_TAIL(*pq)--;
    }
}

PQElType getElmtPQ(PrioQueue pq, int id)
{
	PQElType temp;
	temp.cookTime = 0;
	temp.foodId = 0;
	temp.price = 0;
	temp.stayTime = 0;
	int i = IDX_HEAD(pq);
	while(i <= IDX_TAIL(pq)){
		if(pq.buffer[i].foodId == id){
			return pq.buffer[i];
		}
		i++;
	}
	return temp;
}

boolean isMemberPQ(PrioQueue pq, int id)
{
	int i = IDX_HEAD(pq);
	while(i <= IDX_TAIL(pq)){
		if(pq.buffer[i].foodId == id){
			return true;
		}
		i++;
	}
	return false;
}

/**** Display Queue ****/

void printOrders(PrioQueue pq){
	printf("Daftar Pesanan: \n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("---------------------------------------------\n");
	if (isEmptyPQ(pq)){
		printf("        |                |           |       \n");
	}else{
		PQElType val;
		int i = IDX_HEAD(pq);
		while (i != IDX_TAIL(pq)+1){
			if (pq.buffer[i].foodId < 10){
				printf("M%d      | %d              | %d         | %d\n", pq.buffer[i].foodId, pq.buffer[i].cookTime, pq.buffer[i].stayTime, pq.buffer[i].price);
			} else {
				printf("M%d     | %d              | %d         | %d\n", pq.buffer[i].foodId, pq.buffer[i].cookTime, pq.buffer[i].stayTime, pq.buffer[i].price);
			}
			i++;
		}

	}
}