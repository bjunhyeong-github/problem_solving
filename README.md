problem_solving
201934021/백준형

■ 2023.04.15 week6_MidTest=======================================

<BFS알고리즘을 이용한 길찾기 구현>

사용자로부터 맵 사이즈,장애물 개수, 출발점, 도착점을 입력받아 콘솔창에 맵 출력 후 

출발점에서 도착점까지의 최단경로를 출력한다

■ 2023.03.00 week5=======================================

<최단경로 길찾기_미완성>

사용자로부터 출발좌표,도착좌표를 입력받아 정해진 맵에서 최단경로를 출력

■ 2023.03.00 week4=======================================

<트리 자료구조를 구현>

■ 2023.03.20 week3=======================================

<로마숫자 입력기 예외처리 추가내용>

1.로마자 이외에 대문자를 입력받았을시 오류메세지 출력

2.백스페이스 키를 입력받았을시 메세지 출력후 다시 입력받기

■ 2023.03.15 week2=======================================

<로마숫자입력기 설명>

로마자를 사용자로부터 입력받은 후 로마자를 정수로 변환하는 함수를 이용하여 정수로 변환하여 출력함.

예외처리로는 영어 소문자, 각종기호, 숫자 등을 넣었을 때는 오류발생이라는 메세지가 뜨고 다시입력하라는 글이 출력됨.

키보드ESC 키를 누르면 프로그램이 종료됨.

<세부설명>
romanToInt 함수를 이용하여 입력받은 로마자를 정수로 변환

ex){ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} }; 

while문을 사용하여 Esc키를 누르기 전까지 프로그램이 계속 동작하고, Esc키를 누르면 프로그램이 종료됨.

로마자이외(숫자,기호,소문자)를 입력받지 않기 위해 if~else if문을 사용하여 로마자(대문자) 이외에 문자를 입력받을시 오류메세지가 뜨도록
코드를 작성함

