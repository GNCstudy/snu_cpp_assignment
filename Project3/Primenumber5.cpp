#include <stdio.h>
// stdio 헤더 
#include <stdlib.h>
// stdlib 헤더
#include <time.h>
// 시간 측정을 위한 time 헤더
#include <pthread.h>
// 멀티 스레딩을 위한 pthread 헤더
#define NUM1    2
// NUM1 지정
#define NUM2    1000000000
// NUM2 지정 (10억까지 해봄. 약 39초 걸림)
#define NUMOFTHREADS    4
// 스레딩의 수

/* PPTC와 PRTC 참고 
   stackoverflow.com/questions/36493974/calculating-prime-numbers-pthread */

void *PPTC(void *threadid);
// *PPTC를 불러오기
void PRCT(int num1, long long num2, int numofThreads);
// PRCT를 불러오기
static long long count=0;
// 소수의 갯수를 우선 0으로 지정
static long long check2[NUM2+10]={false};
// NUM2까지의 자연수 배열 생성, 우선 원소를 false로 지정

int main(){
    time_t start_time=time(NULL);
    // 시작 시간 측정
    double elapsed_time;
    // 측정 시간의 변수를 할당
    PRCT(NUM1, NUM2, NUMOFTHREADS);
    // PRCT 함수 활용
    for (long long k=2; k<=NUM2; k++){
        if(check2[k]==false){
            count++;}
    // 배열에서 소수가 있으면 count를 1씩 증가
    }
    printf("소수의 갯수: %lld",count);
    printf("\n");
    time_t end_time=time(NULL);
    // 종료 시간 측정
    elapsed_time=(double)(end_time-start_time);
    // 종료 시간과 시작 시간 사이의 간격 측정
    printf("프로그램 수행 시간: %.0f 초", elapsed_time);
    // 측정 시간에 대한 구문 출력
    printf("\n");
    pthread_exit(NULL);
    // 스레드 종료
    return 0;
}

void *PPTC(void *threadid){
    static int cnt=1;
    // cnt는 스레드 번호, 1이 아닌 0에서 시작하면 프로그램 내에서 충돌 발생
    int i;
    // i 변수 할당
    int NUMOFTHREADS1=NUMOFTHREADS;
    // #define에서 지정했던 것을 토대로 NUMOFTHREADS1 변수 할당
    long long NUM22=NUM2;
    // #define에서 지정했던 것을 토대로 NUM22 변수 할당
    long long j;
    // j 변수 할당
    for(int i=1+cnt;i*i<=NUM22;i+=NUMOFTHREADS1){
    // 스레드별로 i에 대해 할당.
        if(check2[i]==false){
            for(long long j=i*i;j<=NUM22;j+=i){
                check2[j]=true;
            }
        }
    }
    // 위의 for 구문은 에라토스 테네스의 체
    cnt+=1;
    // 다음 스레드를 위해 cnt 1 증가
}

void PRCT(int num1, long long num2, int numOfThreads){
    pthread_t threads[numOfThreads];
    // 스레드 지정
    int rc;
    // rc 변수 할당
    long long t;
    // t 변수 할당
    for (t=0;t<numOfThreads;t++){
    // 스레드 생성을 위한 for 구문
        rc=pthread_create(&threads[t],NULL,PPTC,(void *)t);
        // 스레드들을 생성하여 rc에 지정
        if (rc) {
            printf("ERROR. return code from pthread_create() is %d\n",rc);
            exit(-1);
        // 에러 구문 출력
        } pthread_join(threads[t],NULL);
        // 스레드 조인
    }
}

