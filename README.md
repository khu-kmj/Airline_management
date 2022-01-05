<!-- PROJECT LOGO -->
# Airline management






<!-- ABOUT THE PROJECT -->
## About The Project

[![Page][product-screenshot]](https://2019110627.osschatbot.ga:23023/)

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

<p align="right">(<a href="#top">back to top</a>)</p>



### Built With

* [C](https://namu.wiki/w/C%EC%96%B8%EC%96%B4)


<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* npm
  ```sh
  npm install npm@latest -g
  ```

### Installation


1. Get a free API Key at [https://developers.nexon.com/kart](https://developers.nexon.com/kart)
2. Clone the repo
   ```sh
   git clone http://khuhub.khu.ac.kr/2019110627/kartrider.git
   ```
3. Install NPM packages
   ```sh
   npm install 
   ```
4. Enter your API in `search.js`
   ```js
   //require("dotenv").config({path: ".env"}); 
   const key = 'ENTER YOUR API';
   ```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

main.js

``` JS
/* AWS */
const fs = require('fs');
const path = require('path');
const HTTPS = require('https');
const domain = "DOMAIN";
const sslport = "SSLPORT";

try {
    const option = {
      ca: fs.readFileSync('/etc/letsencrypt/live/' + domain +'/fullchain.pem'),
      key: fs.readFileSync(path.resolve(process.cwd(), '/etc/letsencrypt/live/' + domain +'/privkey.pem'), 'utf8').toString(),
      cert: fs.readFileSync(path.resolve(process.cwd(), '/etc/letsencrypt/live/' + domain +'/cert.pem'), 'utf8').toString(),
    };
  
    HTTPS.createServer(option, app).listen(sslport, () => {
      console.log(`[HTTPS] Server is started on port ${sslport}`);
    });
  } catch (error) {
    console.log('[HTTPS] HTTPS 오류가 발생하였습니다. HTTPS 서버는 실행되지 않습니다.');
    console.log(error);
  }
  
/* local server
app.listen("8080",function(req,res){
    console.log('server listening at port no. 8080');
});
*/
```

HOME PAGE
![homepage][homepage]


TEST PAGE
![testpage][test]
![resultpage][test_r]


SEARCH PAGE
![testpage][search]
![resultpage][search_r]
<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [x] Add back to top links
- [x] Add AWS version
- [x] Add Home page
- [x] Add Additional Templates
- [x] Add "components" document to easily copy & paste sections of the readme
- [ ] Multi-language Support
    - [x] Korean
    - [ ] Chinese
    - [ ] Spanish

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
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/othneildrew/Best-README-Template.svg?style=for-the-badge
[contributors-url]: https://github.com/othneildrew/Best-README-Template/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/othneildrew/Best-README-Template.svg?style=for-the-badge
[forks-url]: https://github.com/othneildrew/Best-README-Template/network/members
[stars-shield]: https://img.shields.io/github/stars/othneildrew/Best-README-Template.svg?style=for-the-badge
[stars-url]: https://github.com/othneildrew/Best-README-Template/stargazers
[issues-shield]: https://img.shields.io/github/issues/othneildrew/Best-README-Template.svg?style=for-the-badge
[issues-url]: https://github.com/othneildrew/Best-README-Template/issues
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/othneildrew/Best-README-Template/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/othneildrew
[product-screenshot]: images/kart.png
[homepage]:images/homepage.png
[search]:images/search.png
[search_r]:images/search_r.png
[test]:images/test.png
[test_r]:images/test_r.png
