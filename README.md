# Pattern-Viewer
FPGA에서 사용되는 pat파일 컴파일러에 대한 패턴 뷰어프로그램입니다. 


Test System에서는 ALPG(algorithmic pattern generator)에서 Test Pattern을 발생시킵니다.
Test Pattern 발생을 제어하는 Program을 Micro Pattern Program이라 합니다.


# 개요
 
  
 ![1](https://user-images.githubusercontent.com/38147253/90470950-c7e06e00-e157-11ea-856f-46d155cfcebb.jpg)
 
 
 
 ## 해당 프로그램은 컴파일된 pat파일을 format대로 정리하여 사용자가 컴파일 이전 파일과 비교할 수 있게 만들어주는 프로그램입니다. 
<h3>1.	Introduction</h3>
본 문서는 FPGA 에서 사용되는 PAT 파일 컴파일러에 대한 Pattern Viewer Program의 소프트웨어 요구사항(Software Requirement Specification)에 대하여 기술한다.

1.1.	Purpose
Pattern Viewer Program의 소프트웨어 요구사항을 분석하고 정의한다. 개발 방향 결정, Software Architecture 설계, Software Function Block 문서의 기준으로 사용하기 위해 작성한다.
본 문서의 기술은 소프트웨어 관점에서 기술한다. 사용자의 요구사항 사항을 분석하고 작성한 문서이다. 사용자 기준에서의 흐름도, UML을 반영한다. 따라서 사용자와 관련 기능을 공유하며 Software 요구사항(기능)이 충족하는지 살펴보는 것을 문서의 기준으로 한다. 결국 사용자의 요구사항 및 요구 기능을 누락 없이 설계에 반영하고 그러한 요구사항을 구현하기 위해서 필요한 부분을 기술하는 문서이다.

1.3.	Reference
	mpat file format.xlsx
	comp_eval_te_op_reg_200726.ASC
	comp_te_eval_op_reg_200726.PAT
	UNI610-RegFor-List_Rev0.67_20200804.xlsx
	UNI610-RegFor-system-control-pg_rev0.7_20200625.xlsx


 ### 개발 환경	
 
▶ 가상화 프로그램 <br>
vmware workstation 15 player 사용

▶ OS
실행환경 <br> linux centos7 <br>  개발 환경 <br> window 10 

▶ 개발 도구 <br>
Qt 5, Source Insight 3
 
▶ 정적 분석 도구 <br>
CPPCHECK

▶ 기타 도구  <br>
tigher-vnc, Binary-Viewer, Notepad++




 
 
 
  
  
 



