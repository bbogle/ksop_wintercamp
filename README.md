# ksop_wintercamp
RasberryPi Arduino Car project for KSOP 

라즈베리파이 세팅

1. 전원켜고, 와이파이 연결
2. 라즈베리파이 환경설정
~$ sudo raspi-config  명령어 입력 후
Interfacing Options -> Camera / SSH / VNC  3개 서비스 enable 로 설정
Advanced Options -> Expand Filesystem 
환경설정 종료 후 재부팅

3. 연결된 Wi-Fi SSID 확인, IP 확인
   ~$ ifconfig 명령어 입력 해서 wlan0 부분에 나오는 192.168.~~~~~~   아이피 주소를 확인.

4. PC에서 VNC뷰어 프로그램으로 접속
  user : pi
  password : raspberry

원격 PC에서 계속 진행.

원격 PC(노트북)에서 라즈베리파이에 접속 후 터미널창을 열어서 KSOP 프로젝트에 사용되는 코드 다운로드

~$ cd Desktop
~$ git clone https://github.com/bbogle/ksop_wintercamp

바탕화면에 ksop_wintercamp 폴더가 생겼는지 확인

라즈베리파이 전원 종료 명령
~$ sudo shutdown now

이후 모든 작업은 노트북에서 VNC 뷰어 프로그램으로 진행한다.




#####################  최종 프로젝트 완성 후 ####################
와이파이가 되지 않는 환경에서 자율주행자동차의 프로그램은 라즈베리파이 부팅시 자동시작되도록 등록해놓아야 합니다. 
라즈베리파이 프로그램 자동실행 등록하기 
1. rc.local 
  자동실행 방법 중에 간단하면서도 효과적인 방법 중 하나로서 여기에 명령을 적어주게 되면 
  라즈베리파이가 부팅시에 자동으로 root 권한을 가지고 프로그램을 실행시켜준다. 
  주의해야할 점으로는 프로그램에 에러가 있는 상태에서 명령어 뒤에 & 문자를 입력하지 않을 경우에는 
  부팅이 완료되지 않을 수 있으므로 유의해야 한다. 
  
