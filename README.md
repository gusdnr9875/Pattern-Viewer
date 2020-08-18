# Pattern-Viewer
FPGA에서 사용되는 pat파일 컴파일러에 대한 패턴 뷰어프로그램입니다. 


Test System에서는 ALPG(algorithmic pattern generator)에서 Test Pattern을 발생시킨다.
Test Pattern 발생을 제어하는 Program을 Micro Pattern Program이라 한다.



 
  
 ![1](https://user-images.githubusercontent.com/38147253/90470950-c7e06e00-e157-11ea-856f-46d155cfcebb.jpg)
 
 
 ### 	Micro Pattern Program의 구성
 MPAT문
PROGRAM의 시작 부분에 기술됩니다. 
Object File name을 지정（선택적）.
Object File name을 생략하면 Source File name으로 작성된다.

▶COMMON: DEFINE PART
COMMON PART의 RDX, IL_MODE, MODE, REGISTER문 등이 기술됩니다. 모두 생략이 가능 하며 생략 시 Default 값이 Set됩니다. Common Part에 기술된 Define문들은 Module Part의 default가 됩니다. 

▶START문
시작 ADDRESS LINE NUMBER를 기술합니다. START문은 PATTERN PROGRAM PART를 기술하기 바로 전에 꼭 기술 하여야 합니다. 
 
▶COMMON: PATTERN PROGRAM PART
ALPG의 SEQUENCE 제어명령과 ALU 명령을 기술합니다. 

▶MODULE BEGIN문
Module part의 시작부분에 기술이 됩니다. 
Module문은 16개까지 기술 가능합니다.

▶MODULE: DEFINE PART
MODULE PART의 RDX, IL_MODE, MODE, REGISTER문 등이 기술됩니다. 모두 생략이 가능 하며 생략 시 Default 값이 Set됩니다. MODULE Part에 기술된 Define문들은 Common Part define문들보다 우선합니다. 

▶MODULE: PATTERN PROGRAM PART
ALPG의 SEQUENCE 제어명령과 ALU 명령을 기술합니다. 

▶MODULE END문
Module part의 끝부분에 기술이 됩니다. 

▶END문
PROGRAM의 마지막 부분에 기술됩니다.


 
 
 
  
  
 



