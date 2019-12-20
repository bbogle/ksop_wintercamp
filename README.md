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

원격 PC에서 계속 진행.


라즈베리파이 전원 종료 명령
~$ sudo shutdown now

