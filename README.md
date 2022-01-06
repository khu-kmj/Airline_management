# Airline management

## About The Project


<p align="center"><img src="view/intro.png"></p>


항공사 고객 정보를 바탕으로 마일리지 상품, 우선순위에 따른 오름차순 정렬, 고객 정보 찾기 등을 수행할 수 있는 프로그램이다.
이 프로젝트는 C언어를 기반으로한 파일 입출력을 다루고 있다. 그리고 세부적인 내용으로 bst, quick sort등의 자료구조를 사용했다.
이 프로그램은 다음과 같은 서비스를 제공하고 있다.
* 전체 정보 조회
* 우선순위를 바탕으로 오름차순 후 정보 조회
  * 우선순위 공식 : gue[i].num - gue[i].score / (float)c_max * 10 - arr[i] / (float)d_max * 5; 
* 사용자 추가
* 사용자 삭제
* 마일리지 계산을 통한 상품 추천
* 특정 회원 조회




### Built With

* [C](https://namu.wiki/w/C%EC%96%B8%EC%96%B4)





<!-- USAGE EXAMPLES -->
## Usage

main.c

``` Visual Studio
// 키 설명
	while (1)
	{
		Menu(x, y); // 메뉴
		key = getch();
		switch (key)
		{
		case UP:
			y = y - 2;
			if (y < 11)
				y = 21;
			break;

		case DOWN:
			y = y + 2;
			if (y > 21)
				y = 11;
			break;
		}
		system("cls");
		if (key == ENTER && y == 11) // 1. 초기정보를 선택했을 때
		{
			Base(gue, count);
			break;
		}
		else if (key == ENTER && y == 13) // 2. 오름차순을 선택했을 때
		{
			ascending_order(gue, count);
			break;
		}
		else if (key == ENTER && y == 15) // 3. 정보추가를 선택했을 때
		{
			
		}
		else if (key == ENTER && y == 17) // 4. 정보삭제를 선택했을 때
		{
			
		}
		else if (key == ENTER && y == 19)  //5. 마일리지 상품을 선택했을 때
		{
			
		}
		else if (key == ENTER && y == 21) // 6.프로그램을 종료한다. 
		{
	
		}
	}
```

### (1) HOME


![home][home]


### (2) 정보조회(오름차순, 초기정보) 


![look][look]


### (3) 이름 검색 


![search][search]



### (4) 정보 추가 


![add][add]



### (5)  마일리지 


![dup][dup]


![mile][mile]
<p align="right">(<a href="#top">back to top</a>)</p>


<!-- ROADMAP -->
## Roadmap

- [x] 전체 정보 조회
- [x] 오름차순 정보 조회
- [x] 특정 정보 검색
- [x] 정보 삽입, 삭제
- [x] 마일리지 상품 조회
- [X] 이름 중복 처리
- [ ] Multi-language Support
    - [x] Korean
    - [ ] Chinese
    - [ ] English

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch 
3. Commit your Changes 
4. Push to the Branch
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>







<!-- CONTACT -->
## Contact

mjoo1106@naver.com

<p align="right">(<a href="#top">back to top</a>)</p>





<!-- MARKDOWN LINKS & IMAGES -->
[home]:view/home.png
[look]:view/inf.png
[search]:view/search.png
[add]:view/add.png
[dup]:view/dup.png
[mile]:view/mile.png
