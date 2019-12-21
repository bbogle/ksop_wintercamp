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
1. LXDE
  LXDE란 리눅스 환경에서 사용할 수 있는 오픈소스 데스크탑 환경을 의미하며 쉽게 말해 라즈비안에서 statx 명령어를 통해 
  나타나는 GUI 환경을 의미한다. 이 방법은 라즈베리파이가 부팅되면서 xwindow 실행시 자동으로 실행하도록 설정해주는 방식이며
  설정방법은 다음과 같은 명령어를 통해 파일을 읽어온뒤 @문자를 붙인 상태에서 실행할 프로그램의 경로를 지정해주면 된다. 
  경로 설정할 때는 @xscreensaver 라인 아래에 적으면 된다. 
~$ sudo nano /etc/xdg/lxsession/LXDE-pi/autostart

@lxpanel --profile LXDE-pi
@pcmanfm --desktop --profile LXDE-pi
/home/pi/Desktop/camera                  // 실행파일명 전체경로
@xscreensaver -no-splash

수정한 뒤 저장하고 나와서 재부팅 하면 됨.
