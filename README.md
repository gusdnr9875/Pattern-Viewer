# Pattern-Viewer
FPGA에서 사용되는 pat파일 컴파일러에 대한 패턴 뷰어프로그램입니다. 


Test System에서는 ALPG(algorithmic pattern generator)에서 Test Pattern을 발생시킵니다.
Test Pattern 발생을 제어하는 Program을 Micro Pattern Program이라 합니다.



 
  
 ![1](https://user-images.githubusercontent.com/38147253/90470950-c7e06e00-e157-11ea-856f-46d155cfcebb.jpg)
 
 
 
 ## 해당 프로그램은 컴파일된 pat파일을 format대로 정리하여 사용자가 컴파일 이전 파일과 비교할 수 있게 만들어주는 프로그램입니다. <br><br><br>
 
<h3> 1.	Introduction </h3>
FPGA 에서 사용되는 PAT 파일 컴파일러에 대한 Pattern Viewer Program의 소프트웨어 요구사항(Software Requirement Specification)에 대하여 기술한다.

<h3> 1.1.	Purpose </h3>
Pattern Viewer Program의 소프트웨어 요구사항을 분석하고 정의한다. 개발 방향 결정, Software Architecture 설계, Software Function Block 문서의 기준으로 사용하기 위해 작성한다.
본 문서의 기술은 소프트웨어 관점에서 기술한다. 사용자의 요구사항 사항을 분석하고 작성한 문서이다. 사용자 기준에서의 흐름도, UML을 반영한다. 따라서 사용자와 관련 기능을 공유하며 Software 요구사항(기능)이 충족하는지 살펴보는 것을 문서의 기준으로 한다. 결국 사용자의 요구사항 및 요구 기능을 누락 없이 설계에 반영하고 그러한 요구사항을 구현하기 위해서 필요한 부분을 기술하는 문서이다.
<br><br>
<h31.3.	Reference</h3
	mpat file format.xlsx
	comp_eval_te_op_reg_200726.ASC
	comp_te_eval_op_reg_200726.PAT
	UNI610-RegFor-List_Rev0.67_20200804.xlsx
	UNI610-RegFor-system-control-pg_rev0.7_20200625.xlsx

<br><br>

![image](https://user-images.githubusercontent.com/38147253/90740975-09187f80-e30a-11ea-9ec7-3ec3d2c47a5f.png)

#### 그림 1. Pattern Viewer Program System
<br>

	Pattern Viewer Program은 PAT file을 읽어들여 내용을 구성한다.

	mpat file format의 내용을 기반으로 사용자에게 정보를 전달한다.
  
	사용자에게 exe 실행 파일 형식으로 전달한다

<br>


![use diagram](https://user-images.githubusercontent.com/38147253/90741505-2baa9880-e30a-11ea-8832-eec4b8cfa0d1.png)


#### 그림 2. Use Case Diagram

	사용자는 ASC file, micro manual을 토대로 컴파일된 pat 파일이 올바른지 검증할 수 있다. <br>
	pat파일을 업로드하고 문자열 검색, 바이너리 뷰, 포맷 바이너리 뷰, 포맷 양식 등을 확인한다.



![image](https://user-images.githubusercontent.com/38147253/90745199-2732af80-e30b-11ea-884d-0e664f361011.png)
<br>

#### 그림 3. Flow Chart <br>

	프로그램이 실행될 때 사용자는 pat파일을 등록한다. Reopen 버튼을 통해서 언제든지 pat 파일을 재 등록할 수 있다.
	등록 후 변환된 바이너리 값들을 hex 값으로 확인할 수 있다.
	특정 문자열을 입력하여 검색이 가능하다. 검색 후 기존 edit text에서 확인이 가능하다.
	단축키와 파일 포맷도 확인이 가능하다. 

<br><br>

![flow chart](https://user-images.githubusercontent.com/38147253/90741775-3e24d200-e30a-11ea-929b-384cc0b18dfa.png)

#### 그림 4. Class Diagram <br>

	widget에서 gui를 생성한다. <br>
	file에서는 pat파일 open과 read를 담당한다. format에서는 pat file format에 맞춰 데이터를 변경한다. <br>
	file과 format 클래스에서 데이터를 받아 widget에서 처리한다. <br>

<br><br>
<br><br><br><br>
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




 
 
 
  
  
 



